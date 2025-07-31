import java.util.Arrays;
import java.util.Scanner;
import java.util.Vector;

class Pair {
    long a, b;

    public Pair(long a, long b) {
        this.a = a;
        this.b = b;
    }
}

public class s1 {
    static final long N = 2000000;

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        long n, m, k;
        n = scanner.nextLong();
        k = scanner.nextLong();
        m = scanner.nextLong();

        Pair[] a = new Pair[(int) N];

        for (int i = 1; i <= n; i++) {
            a[i] = new Pair(scanner.nextLong(), scanner.nextLong());
        }

        Arrays.sort(a, 1, (int) n + 1, (x, y) -> Long.compare(x.a, y.a));

        Vector<Pair> ve = new Vector<>();
        ve.add(new Pair(-1000000000, k));
        long now = 0;
        long ans = 0;

        for (int i = 1; i <= n; i++) {
            long num = 0;

            for (long j = now; j < ve.size(); j++) {
                if (a[i].a - m >= ve.get((int) j).a) {
                    if (a[i].b >= ve.get((int) j).b) {
                        num += ve.get((int) j).b;
                        a[i].b -= ve.get((int) j).b;
                        now++;
                    } else {
                        ve.get((int) j).b -= a[i].b;
                        num += a[i].b;
                        break;
                    }
                } else {
                    break;
                }
            }

            ans += num;
            ve.add(new Pair(a[i].a, num));
        }

        System.out.println(ans);
    }
}
