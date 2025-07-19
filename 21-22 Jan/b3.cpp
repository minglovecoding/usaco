#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5+5;
int T;
int n;
long long h[MAXN], x[MAXN];

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) {
            scanf("%lld", &h[i]);
        }
        for (int i = 2; i < n; i+=2) {
            x[i] = h[i] - h[i-1] + x[i-2];
        }
        for (int i = 1; i < n; i+=2) {
            x[i] = h[i] - x[i-1];
        }
        if (n&1) {
            long long H = h[n] - x[n-1];
            if (H < 0) {
                puts("-1"); continue;
            }
            for (int i = 1; i < n; i+=2) x[i] -= H; 
        } else {
            if (x[n-1] != h[n]) {
                puts("-1"); continue;
            }
            long long H = 1e17+1;
            for (int i = 1; i < n; i+=2) H = min(H, x[i]);
            if (H < 0) {
                puts("-1"); continue;
            }
            for (int i = 1; i < n; i+=2) x[i] -= H;
        }
        long long ans = 0;
        for (int i = 1; i < n; i++) {
            if (x[i] < 0) {
                ans = -1; break;
            }
            ans += x[i] * 2ll;
        }
        printf("%lld\n", ans);
    }
}