#include<bits/stdc++.h>
using namespace std;
const int maxn = 2010;
char s1[maxn], s2[maxn];
long long dp[maxn][maxn];
const int mod = 1e9+7;
void solve(){
    int n;
    cin >> n;
    scanf("%s%s", s1 + 1, s2 + 1);
    int t1 = 0, t2 = 0, z1 = 0, z2 = 0;
    for (int i = 1; i <= n; i++) {
        if (s1[i] != '1') s1[++t1] = s1[i];
        if (s2[i] != '1') s2[++t2] = s2[i];
        if (s1[i] == '0') z1 = t1;
        if (s2[i] == '0') z2 = t2;
    }
    for (int i = 1; i <= t1; i++) dp[i][t2 + 1] = 1;
    for (int i = 1; i <= t2; i++) dp[t1 + 1][i] = 1;
    dp[t1 + 1][t2 + 1] = 1;
    for (int i = t1; i >= 1; i--)
        for (int j = t2; j >= 1; j--)
            if (s1[i] == '+' && s2[j] == '+') {
                dp[i][j] = (dp[i + 1][j] + dp[i][j + 1] - dp[i + 1][j + 1]) % mod;
            }else if (s1[i] != '+' && s2[j] != '+'){
                dp[i][j] = (dp[i + 1][j] + dp[i][j + 1] - dp[i + 1][j + 1]) % mod;
            }else{
                dp[i][j] = (dp[i + 1][j] + dp[i][j + 1]) % mod;
            }
    long long ans = 0;
    if (z1 == 0 && z2 == 0) {
        ans = dp[1][1];
    }else{
        ans = dp[z1 + 1][z2 + 1];
        if (z1 != 0) {
            for (int i = z2 + 1; i <= t2; i++) if (s2[i] == '+') ans += dp[z1 + 1][i + 1];
        }
        if (z2 != 0){
            for (int i = z1 + 1; i <= t1; i++) if (s1[i] == '+') ans += dp[i + 1][z2 + 1];
        }
    }
    ans %= mod;
    if (ans < 0) ans += mod;
    cout << ans << endl;
}
int main(){
    int T;
    cin >> T;
    while (T--) solve();
}