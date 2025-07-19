import java.util.*;
import java.io.*;

public class g2 {
    static final int N = 5 * 100000 + 5;
    static int[] a = new int[N];
    static String ss = "bessie";
    static long[][] dp = new long[N][6];
    static long[][] dp2 = new long[N][6];
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        String s = in.next();
        int n = s.length();
        for (int i = 1; i <= n; i++) {
            a[i] = in.nextInt();
        }
        for (int i = 0; i <= N - 1; i++) {
            Arrays.fill(dp[i], 1L << 60);
        }
        dp[0][0] = 0;
        for (int i = 1; i <= n; i++) {
            Arrays.fill(dp2[i], -1);
            for (int j = 0; j <= 5; j++) {
                if (dp[i - 1][j] < (1L << 60)) {
                    if (s.charAt(i - 1) == ss.charAt(j)) {
                        int num = (int)dp2[i - 1][j];
                        if (j == 5) {
                            num++;
                        }
                        if (num > dp2[i][(j + 1) % 6] || (num == dp2[i][(j + 1) % 6] && dp[i - 1][j] < dp[i][(j + 1) % 6])) {
                            dp2[i][(j + 1) % 6] = num;
                            dp[i][(j + 1) % 6] = dp[i - 1][j];
                        }
                    }
                    int cost = 0;
                    if (j != 0) {
                        cost = a[i];
                    }
                    if (dp2[i - 1][j] > dp2[i][j] || (dp2[i - 1][j] == dp2[i][j] && dp[i - 1][j] + cost < dp[i][j])) {
                        dp2[i][j] = dp2[i - 1][j];
                        dp[i][j] = dp[i - 1][j] + cost;
                    }
                }
            }
        }
        System.out.println(dp2[n][0] + "\n" + dp[n][0]);
    }
}
