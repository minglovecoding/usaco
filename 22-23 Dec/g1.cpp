#include <bits/stdc++.h>
using namespace std;
 
const int N = 2000 + 1;
 
int dp[N][2 * N];
 
void set_max(int &a, int b) {
    if (b > a) a = b;
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int n, moonie, cones;
    cin >> n >> moonie >> cones;
 
    vector<array<int, 3>> cows(n);
    for (auto &[x, p, c] : cows) {
        cin >> p >> c >> x;
    }
    sort(cows.begin(), cows.end());
 
    memset(dp, -1, sizeof dp);
 
    dp[0][moonie + cones] = 0;
    for (int i = 0; i < n; ++i) {
        auto [x, p, c] = cows[i];
        for (int j = 0; j <= moonie + cones; ++j) {
            if (dp[i][j] == -1) continue;
 
            set_max(dp[i + 1][j], dp[i][j]);
            if (j - c * x >= moonie) {
                set_max(dp[i + 1][j - c * x], dp[i][j] + p);
            } else if (j > moonie) {
                int cost_left = c - (j - moonie) / x;
                if (moonie - cost_left >= 0)
                    set_max(dp[i + 1][moonie - cost_left], dp[i][j] + p);
            } else if (j <= moonie && j - c >= 0) {
                set_max(dp[i + 1][j - c], dp[i][j] + p);
            }
        }
    }
 
    cout << *max_element(dp[n], dp[n] + moonie + cones + 1) << "\n";
}