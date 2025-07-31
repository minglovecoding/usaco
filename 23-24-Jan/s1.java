import java.util.Arrays;
import java.util.Scanner;
import java.util.stream.IntStream;

public class Main {
	//定义内部类SegTree，实现一个线段树数据结构
    static class SegTree { 
	//定义内部类Node，表示线段树的每个节点
        class Node {
            int sum = 0; //节点存储的区间和
            boolean put = false; //延迟更新标志，用于延迟传播
            int val = 0; //节点的值，用于区间更新

	//更新节点
            void apply(int l, int r, int v) {
                put = true; //设置延迟更新标志
                val = v; //更新节点值
                sum = v * (r - l + 1); //更新总和为v乘以区间长度
            }
        }

        Node[] tree; 
        int n;
	
	//构造函数初始化线段树
        public SegTree(int _n) {
            n = _n;
            tree = new Node[2 * n - 1]; //初始化线段数组
            for (int i = 0; i < tree.length; i++) {
                tree[i] = new Node(); //为每个节点分配内存
            }
            build(0, 0, n - 1); //从根节点开始构建线段树
        }

	//递归构建线段树
        private void build(int x, int l, int r) {
            if (l == r) {
                return; //如果区间缩减到一个点，返回
            }
            int y = (l + r) >> 1; //找到区间中间的点
            int z = x + ((y - l + 1) << 1); //计算右子树的根节点索引
            build(x + 1, l, y);
            build(z, y + 1, r);
            pull(x, z); //合并子树信息到当前节点
        }

	//合并两个字节点的信息
        private Node unite(Node a, Node b) {
            Node res = new Node();
            res.sum = Math.max(a.sum, b.sum); //合并逻辑，这里取两个字节点的最大和
            return res;
        }

	//向下传递延迟更新的信息
        private void push(int x, int l, int r) {
            int y = (l + r) >> 1; //计算区间中点
            int z = x + ((y - l + 1) << 1); //计算右子树的根节点索引
            if (tree[x].put) { //如果当前节点标记为延迟更新
		//将更新到右子树
                tree[x + 1].apply(l, y, tree[x].val);
                tree[z].apply(y + 1, r, tree[x].val);
                tree[x].put = false; //清除当前节点的延迟更新标志
            }
        }

	//合并子节点的信息，更新当前节点
        private void pull(int x, int z) {
            tree[x] = unite(tree[x + 1], tree[z]);
        }

	//查询指定区间的值
        public Node get(int x, int l, int r, int ll, int rr) {
            if (ll <= l && r <= rr) { //如果查询区间完全覆盖当前区间
                return tree[x]; //直接返回当前节点
            }
            int y = (l + r) >> 1;
            int z = x + ((y - l + 1) << 1);
            push(x, l, r);
            Node res = new Node();
            if (rr <= y) {
                res = get(x + 1, l, y, ll, rr);
            } else if (ll > y) {
                res = get(z, y + 1, r, ll, rr);
            } else {
                res = unite(get(x + 1, l, y, ll, rr), get(z, y + 1, r, ll, rr));
            }
            pull(x, z);
            return res;
        }

	//修改操作
        public void modify(int x, int l, int r, int ll, int rr, int v) {
            if (ll <= l && r <= rr) {
                tree[x].apply(l, r, v);
                return;
            }
            int y = (l + r) >> 1;
            int z = x + ((y - l + 1) << 1);
            push(x, l, r);
            if (ll <= y) {
                modify(x + 1, l, y, ll, rr, v);
            }
            if (rr > y) {
                modify(z, y + 1, r, ll, rr, v);
            }
            pull(x, z);
        }

	//对外提供的修改接口，查询ll到rr区间的值
        public Node get(int ll, int rr) {
            return get(0, 0, n - 1, ll, rr);
        }

	//修改ll到rr区间的值为v
        public void modify(int ll, int rr, int v) {
            modify(0, 0, n - 1, ll, rr, v);
        }
    }

	//主函数
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int t = scanner.nextInt();
        while (t-- > 0) {
            solve(scanner);
        }
    }

	//处理一个测试案例的解决函数
    private static void solve(Scanner scanner) {
    int n = scanner.nextInt();
    int q = scanner.nextInt();
    int C = scanner.nextInt();
    int[] originalValues = new int[n];
    int[] updatedValues = new int[n];
    SegTree segTree = new SegTree(n);

    for (int i = 0; i < n; i++) {
        originalValues[i] = scanner.nextInt();
        updatedValues[i] = originalValues[i];
        segTree.modify(i, i, originalValues[i]);
    }

    int[][] queries = new int[q][2];
    for (int i = 0; i < q; i++) {
        queries[i][0] = scanner.nextInt() - 1;
        queries[i][1] = scanner.nextInt() - 1;
    }

    Arrays.sort(queries, (a, b) -> a[0] - b[0]);

    if (originalValues[0] == 0) {
        originalValues[0] = 1;
        segTree.modify(0, 0, 1);
    }

    for (int[] query : queries) {
        int l = query[0];
        int r = query[1];
        int leftSum = segTree.get(0, l).sum;
        int rightSum = segTree.get(0, r - 1).sum;
        int currentSum = segTree.get(0, r).sum;

        if (leftSum == currentSum) {
            if (originalValues[r] != 0) {
                System.out.println(-1);
                return;
            }
            originalValues[r] = leftSum + 1;
            segTree.modify(r, r, leftSum + 1);
        }

        if (leftSum < rightSum) {
            for (int j = l; j >= 0; j--) {
                if (updatedValues[j] == 0) {
                    originalValues[j] = rightSum;
                    segTree.modify(j, j, rightSum);
                    break;
                }
            }
        }
    }

    for (int i = 0; i < n; i++) {
        if (originalValues[i] == 0) {
            originalValues[i] = 1;
            segTree.modify(i, i, 1);
        }
    }

    if (IntStream.of(originalValues).max().getAsInt() > C) {
        System.out.println(-1);
        return;
    }

    for (int[] query : queries) {
        int l = query[0];
        int r = query[1];
        int leftSum = segTree.get(0, l).sum;
        int rightSum = segTree.get(0, r - 1).sum;
        int currentSum = segTree.get(0, r).sum;

        if (leftSum == currentSum || leftSum < rightSum) {
            System.out.println(-1);
            return;
        }
    }

    for (int i = 0; i < n; i++) {
        System.out.print(originalValues[i] + (i == n - 1 ? "\n" : " "));
    }
}