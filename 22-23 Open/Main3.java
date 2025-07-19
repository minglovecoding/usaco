import java.util.*;
import java.io.*;

public class Main3 {
    static String x = "bessie";
    static long[][][] dp = new long[6][2][2];
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String s = br.readLine();
        int n = s.length();
        long ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 6; j++) {
                dp[j][0][~i & 1] = 0;
                dp[j][1][~i & 1] = 0;
            }
            ++dp[0][0][i & 1];
            for (int j = 0; j < 6; j++) {
                int p = (j + 1) % 6;
                if (s.charAt(i) == x.charAt(j)) {
                    dp[p][0][~i & 1] += dp[j][0][i & 1];
                    dp[p][1][~i & 1] += dp[j][1][i & 1];
                    if (p == 0)
                        dp[p][1][~i & 1] += dp[j][0][i & 1];
                } else {
                    dp[j][0][~i & 1] += dp[j][0][i & 1];
                    dp[j][1][~i & 1] += dp[j][1][i & 1];
                }
            }
            for (int j = 0; j < 6; j++)
                ans += dp[j][1][~i & 1];
        }
        System.out.println(ans);
    }
}
