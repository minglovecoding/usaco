import java.util.Arrays;
import java.util.Scanner;

public class s2 {
    static final int N = 2000000;

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int n, m;
        n = scanner.nextInt();
        m = scanner.nextInt();

        int[] a = new int[N];
        int[] b = new int[N];
        int[] pos1 = new int[N];
        int[] pos2 = new int[N];
        int[] f = new int[N];

        for (int i = 1; i <= m; i++) {
            a[i] = scanner.nextInt();
            pos1[a[i]] = i;
        }

        for (int i = 1; i <= m; i++) {
            b[i] = scanner.nextInt();
            pos2[b[i]] = i;
        }

        for (int i = 1; i <= n; i++) {
            if (pos1[i] > 0 && pos2[i] > 0) {
                f[(pos1[i] - pos2[i] + m) % m]++;
            }
        }

        int ans = 0;
        for (int i = 0; i <= n; i++) {
            ans = Math.max(ans, f[i]);
        }

        Arrays.fill(f, 0);
        Arrays.fill(pos1, 0);
        Arrays.fill(pos2, 0);

        for (int i = 1; i <= m; i++) {
            pos1[a[i]] = i;
        }

        for (int i = 1; i <= m; i++) {
            pos2[b[i]] = i;
        }

        for (int i = 1; i <= n; i++) {
            if (pos1[i] > 0 && pos2[i] > 0) {
                f[(pos1[i] - pos2[i] + m) % m]++;
            }
        }

        for (int i = 0; i <= n; i++) {
            ans = Math.max(ans, f[i]);
        }

        int ans2 = 0;
        for (int i = 1; i <= n; i++) {
            if (pos1[i] > 0 && pos2[i] == 0) {
                ans2++;
            }
        }

        System.out.println(n - (m - ans) - ans2);
    }
}
