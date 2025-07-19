#include<bits/stdc++.h>
using namespace std;
string x = "bessie";
long long dp[6][2][2];
int main() {
 ios_base::sync_with_stdio(0);
 cin.tie(0), cout.tie(0);
 string s;
 cin >> s;
 int n = s.size();
 long long ans = 0;
 for (int i = 0; i ^ n; ++i) {
  for (int j = 0; j ^ 6; ++j) {
   dp[j][0][~i & 1] = 0;
   dp[j][1][~i & 1] = 0;
  }
  ++dp[0][0][i & 1];
  for (int j = 0; j ^ 6; ++j) {
   int p = (j + 1) % 6;
   if (s[i] == x[j]) {
    dp[p][0][~i & 1] += dp[j][0][i & 1];
    dp[p][1][~i & 1] += dp[j][1][i & 1];
    if (!p)
     dp[p][1][~i & 1] += dp[j][0][i & 1];
   }
   else {
    dp[j][0][~i & 1] += dp[j][0][i & 1];
    dp[j][1][~i & 1] += dp[j][1][i & 1];
   }
  }
  for (int j = 0; j ^ 6; ++j)
   ans += dp[j][1][~i & 1];
 }
 cout << ans << '\n';
}