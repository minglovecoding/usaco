import java.util.ArrayList;
import java.util.Scanner;
import java.util.Vector;

public class s2 {
    static final int N = 1000010;
    static int n;
    static int[] a = new int[N];
    static int[] ok = new int[N];
    static int[] leafNum = new int[N];
    static ArrayList<Integer>[] G = new ArrayList[N];
    static int ans;

    public static void dfs1(int u, int f) {
        int isLeaf = 1;
        for (int v : G[u]) {
            if (v == f) {
                continue;
            }
            isLeaf = 0;
            dfs1(v, u);
            leafNum[u] += leafNum[v];
        }
        if (isLeaf == 1) {
            leafNum[u] = 1;
        }
    }

    public static void dfs2(int u, int f) {
        leafNum[u] = 0;
        int isLeaf = 1;
        for (int v : G[u]) {
            if (v == f) {
                continue;
            }
            isLeaf = 0;
            dfs2(v, u);
            leafNum[u] += leafNum[v];
        }

        if (isLeaf == 1) {
            leafNum[u] = 1;
        }
        if (leafNum[u] > 0) {
            int temp = Math.min(leafNum[u], ok[u]);
            leafNum[u] -= temp;
            ans += temp;
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        for (int i = 1; i <= n; ++i) {
            a[i] = sc.nextInt();
        }
        for (int i = 0; i < N; ++i) {
            G[i] = new ArrayList<>();
        }
        for (int i = 1; i < n; ++i) {
            int u = sc.nextInt();
            int v = sc.nextInt();
            G[u].add(v);
            G[v].add(u);
        }
        dfs1(1, -1);
        for (int i = 1; i <= n; ++i) {
            assert leafNum[i] > 0;
        }
        for (int i = 1; i <= leafNum[1]; ++i) {
            ok[a[i]]++;
        }
        dfs2(1, -1);
        System.out.println(ans);
    }
}
