#include <bits/stdc++.h>
using namespace std;

void fastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
}

typedef long long ll;

int N;
ll h[5100];

int main() {
    fastIO();
    cin >> N;
    for (int i = 1; i <= N; i++) { cin >> h[i]; }
    int Q;
    cin >> Q;
    for (int i = 1; i <= Q; i++) {
        int x, y;
        cin >> x >> y;
        h[x] += y;
        int ans = 0;
        for (int j = 1; j <= N; j++) {
            ll bh = 0, bd = -1;
            for (int k = j + 1; k <= N; k++) {
                if (bd == -1) {
                    ans++;
                    bd = 1, bh = h[k] - h[j];
                } else if ((ll)(h[k] - h[j]) * bd >= (ll)bh * (k - j)) {
                    ans++;
                    bd = k - j, bh = h[k] - h[j];
                }
            }
        }
        cout << ans << "\n";
    }
}