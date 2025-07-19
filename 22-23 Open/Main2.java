import java.util.Scanner;

public class Main2 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int m = scanner.nextInt();
        int n = scanner.nextInt();
        String[] a = new String[n];
        int[] dp = new int[1 << m];
        int[] v = new int[n];

        for (int i = 0; i < n; ++i) {
            a[i] = scanner.next();
        }

        for (int i = 0; i < (1 << m); ++i) {
            dp[i] = -0x3f3f3f3f;
        }

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (a[i].charAt(j) == 'H') {
                    v[i] |= 1 << j;
                }
            }
            dp[v[i]] = 0;
        }

        for (int j = 0; j < m; ++j) {
            for (int i = 0; i < (1 << m); i += 1 << (j + 1)) {
                for (int k = i; k < i + (1 << j); ++k) {
                    int x = dp[k];
                    int y = dp[k ^ (1 << j)];
                    dp[k] = Math.max(x, y + 1);
                    dp[k ^ (1 << j)] = Math.max(y, x + 1);
                }
            }
        }

        for (int i = 0; i < n; ++i) {
            System.out.println(dp[v[i]]);
        }
    }
}
