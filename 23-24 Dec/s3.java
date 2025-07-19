import java.util.BitSet;
import java.util.Scanner;

public class s3 {
    static final int N = 2000010;

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int now = 0;
        int n, m;
        n = scanner.nextInt();
        m = scanner.nextInt();

        int[] a = new int[N];
        int[] pref = new int[N];
        int[] prel = new int[N];
        int[] prer = new int[N];
        int[] f = new int[N];

        BitSet B = new BitSet(100010);
        BitSet B1 = new BitSet(100010);
        BitSet B2 = new BitSet(100010);
        BitSet tmp = new BitSet(100010);
        BitSet B1y1 = new BitSet(100010);
        BitSet B1y2 = new BitSet(100010);
        BitSet B1z1 = new BitSet(100010);
        BitSet B1z2 = new BitSet(100010);

        for (int i = 1; i <= n; i++) {
            a[i] = scanner.nextInt();
        }

        String s = scanner.next();
        int pos = 0;

        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) == 'L') {
                pos--;
            }
            if (s.charAt(i) == 'R') {
                pos++;
            }
            now = Math.min(now, pos);
        }

        for (int i = 0; i < s.length() - 1; i++) {
            if (s.charAt(i) == 'L') {
                prel[i] = i;
            }
            if (s.charAt(i) == 'R') {
                prer[i] = i;
            }
            if (s.charAt(i) == 'F') {
                pref[i] = i;
            }
            prel[i + 1] = prel[i];
            prer[i + 1] = prer[i];
            pref[i + 1] = pref[i];
        }

        pos = 0;
        now = -now + 5;

        for (int i = 1; i <= n; i++) {
            if (a[i] + now >= 0) {
                B.set(a[i] + now);
            }
        }

        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) == 'L') {
                pos--;
            }
            if (s.charAt(i) == 'R') {
                pos++;
            }
            if (s.charAt(i) == 'F') {
                f[pos + now]++;
                B1.set(pos + now, true);
                if (pos + now - 1 >= 0) B1z1.set(pos + now - 1, true);
                if (pos + now - 2 >= 0) B1z2.set(pos + now - 2, true);
                B1y1.set(pos + now + 1, true);
                B1y2.set(pos + now + 2, true);
            }
        }

        B1.and(B);
        B1z1.and(B);
        B1z2.and(B);
        B1y1.and(B);
        B1y2.and(B);

        pos = 0;
        int ans = B1.cardinality();

        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) == 'F') {
                f[pos + now]--;
                if (f[pos + now] == 0) {
                    B1.set(pos + now, false);
                    if (pos + now - 1 >= 0) B1z1.set(pos + now - 1, false);
                    if (pos + now - 2 >= 0) B1z2.set(pos + now - 2, false);
                    B1y1.set(pos + now + 1, false);
                    B1y2.set(pos + now + 2, false);
                }
            }
            if (s.charAt(i) == 'L') {
                if (B2.get(pos + now) == false && B.get(pos + now) == true) {
                    B2.set(pos + now);
                    BitSet temp1 = (BitSet) B2.clone();
                    temp1.or(B1y1);
                    ans = Math.max(ans, temp1.cardinality());
                    B2.set(pos + now, false);
                }
                if (i > 0 && pref[i] >= prel[i - 1]) {
                    BitSet temp1 = (BitSet) B2.clone();
                    temp1.or(B1y2);
                    ans = Math.max(ans, temp1.cardinality());
                }
            } else if (s.charAt(i) == 'R') {
                if (B2.get(pos + now) == false && B.get(pos + now) == true) {
                    B2.set(pos + now);
                    BitSet temp1 = (BitSet) B2.clone();
                    temp1.or(B1z1);
                    ans = Math.max(ans, temp1.cardinality());
                    B2.set(pos + now, false);
                }
                if (i > 0 && pref[i] >= prer[i - 1]) {
                    BitSet temp1 = (BitSet) B2.clone();
                    temp1.or(B1z2);
                    ans = Math.max(ans, temp1.cardinality());
                }
            } else {
                BitSet temp1 = (BitSet) B2.clone();
                temp1.or(B1y1);
                ans = Math.max(ans, temp1.cardinality());
                BitSet temp2 = (BitSet) B2.clone();
                temp2.or(B1z1);
                ans = Math.max(ans, temp2.cardinality());
            }
            if (s.charAt(i) == 'L') {
                pos--;
            }
            if (s.charAt(i) == 'R') {
                pos++;
            }
            if (s.charAt(i) == 'F') {
                if (B.get(pos + now) == true) {
                    B2.set(pos + now);
                }
            }
        }

        System.out.println(ans);
    }
}
