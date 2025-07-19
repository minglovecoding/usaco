import java.util.*;

public class Main1 {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int n = input.nextInt();
        long[] a = new long[n+1];
        long[] b = new long[n+1];
        long[] pre = new long[n+1];
        long[] suf = new long[n+2];
        long[] suf1 = new long[n+2];
        
        for (int i = 1; i <= n; ++i) {
            a[i] = input.nextLong();
            b[i] = a[i];
        }
        
        Arrays.sort(b, 1, n+1);
        
        for (int i = 1; i <= n; ++i) {
            pre[i] = pre[i-1] + b[i] * i;
        }
        
        for (int i = n; i >= 1; --i) {
            suf[i] = suf[i+1] + b[i] * (i-1);
        }
        
        for (int i = n; i >= 1; --i) {
            suf1[i] = suf1[i+1] + b[i] * (i+1);
        }
        
        int q = input.nextInt();
        
        while (q-- > 0) {
            int p = input.nextInt();
            long x = input.nextLong();
            int v = Arrays.binarySearch(b, 1, n+1, a[p]);
            v = v >= 0 ? v : -v - 1;
            int u = Arrays.binarySearch(b, 1, n+1, x);
            u = u >= 0 ? u : -u - 1;
            
            long ans = pre[Math.min(v-1, u-1)];
            
            if (v < u) {
                ans += suf[v+1] - suf[u];
                ans += x * (u-1);
                ans += pre[n] - pre[u-1];
            } else {
                ans += pre[n] - pre[v];
                ans += suf1[u] - suf1[v];
                ans += x * u;
            }
            
            System.out.println(ans);
        }
    }
}
