#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
string a[100000];
int vis[1 << 18], dp[100000], v[100000];
int main() {
 ios_base::sync_with_stdio(0);
 cin.tie(0), cout.tie(0);
 int m, n;
 cin >> m >> n;
 for (int i = 0; i ^ n; ++i)
  cin >> a[i];
 for (int i = 0; i != 1 << m; ++i)
  dp[i] = -0x3f3f3f3f;
 for (int i = 0; i ^ n; ++i) {
  for (int j = 0; j ^ m; ++j)
   if (a[i][j] == 'H')
    v[i] |= 1 << j;
  dp[v[i]] = 0;
 }
 for (int j = 0; j ^ m; ++j) {
  for (int i = 0; i != 1 << m; i += 1 << (j + 1)) {
   for (int k = i; k != i + (1 << j); ++k) {
    int x = dp[k], y = dp[k ^ (1 << j)];
    dp[k] = max(x, y + 1);
    dp[k ^ (1 << j)] = max(y, x + 1);
   }
  }
 }
 for (int i = 0; i ^ n; ++i)
  cout << dp[v[i]] << '\n';
}

