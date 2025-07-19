import java.util.*;

public class Cannonball {
    static int N, S;
    static int[] q, v;
    static Set<Integer> set = new HashSet<>();
    static int cnt = 0;
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        N = sc.nextInt();
        S = sc.nextInt();
        q = new int[N+1];
        v = new int[N+1];
        for (int i = 1; i <= N; i++) {
            q[i] = sc.nextInt();
            v[i] = sc.nextInt();
        }
        jump(S, 1, true);
        System.out.println(set.size());
    }

    // 要注意跳跃陷入死循环的情况: 连跳大于N步后，set中的答案没有任何变化
    public static void jump(int pos, int power, boolean direction){
        cnt++;
        if(cnt > N){
            return;
        }
        if(q[pos] == 1){  // target
            if(v[pos] <= power) {
                int lastSize = set.size();
                set.add(pos);
                if(lastSize != set.size()){
                    cnt = 0;
                }
            }
            if(direction && pos + power <= N){
                jump(pos + power, power, true);
            }
            else if(!direction && pos - power > 0){
                jump(pos - power, power, false);
            }
        }
        else if(q[pos] == 0){   // jump pad
            power += v[pos];
            if(direction && pos - power > 0){
                jump(pos - power, power, false);
            }
            else if(!direction && pos + power <= N){
                jump(pos + power, power, true);
            }
        }
    }
}
