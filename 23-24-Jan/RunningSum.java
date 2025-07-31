import java.util.Scanner;

public class RunningSum {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        long[] a = new long[n + 1];
        long times = 0;
        long ans = 0;
        long tot = 0;
        long base = 0;

        for (int i = 1; i <= n; ++i) {
            a[i] = scanner.nextLong();

            tot += base;

            a[i] = a[i] + tot;

            ans += Math.abs(a[i]);

            base = base - a[i];
            tot += -a[i];
        }

        System.out.println(ans);
    }
}
