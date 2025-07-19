// Author:  HolyK
// Created: Sat Feb 25 21:09:36 2023
#include "bits/stdc++.h"

template <class T, class U>
inline bool smin(T &x, const U &y) {
  return y < x ? x = y, 1 : 0;
}
template <class T, class U>
inline bool smax(T &x, const U &y) {
  return x < y ? x = y, 1 : 0;
}

using LL = long long;
using PII = std::pair<int, int>;

constexpr int N(2e5 + 5);
std::vector<int> g[N];
int a[N], p[N], siz[N], dep[N];
LL sum[N], f[N], cs[N];
void solve() {
  int n, t;
  std::cin >> n >> t;
  for (int i = 2; i <= n; i++) {
    std::cin >> p[i] >> a[i];
    g[p[i]].push_back(i);
  }
  for (int i = 1; i <= n; i++) {
    siz[i] = 1;
    sum[i] = a[i];
  }
  
  for (int i = n; i > 1; i--) {
    siz[p[i]] += siz[i];
    sum[p[i]] += sum[i];
  }

  for (int i = 1; i <= n; i++) {
    std::sort(g[i].begin(), g[i].end(), [&](int i, int j) {
      return 1LL * siz[i] * sum[j] < 1LL * siz[j] * sum[i];
    });
  }

  for (int i = n; i; i--) {
    int c = 0;
    LL s = 0;
    for (int j : g[i]) {
      f[i] += LL(c + 1) * sum[j] + f[j];
      c += 2 * siz[j];
      s += sum[j];
    }
    c = 0;
    for (int j : g[i]) {
      s -= sum[j];
      cs[j] = f[i] - 1LL * c * sum[j] - f[j] - 2LL * siz[j] * s + LL(siz[i] - 1 - siz[j]) * 2 * sum[j];
      c += 2 * siz[j];
    }
    // std::cerr << "f " << i << " " << f[i] << "\n";
  }

  if (!t) {
    std::cout << (n - 1) * 2 << " " << f[1] << "\n";
    return;
  }

  int maxdep = 0;
  for (int i = 2; i <= n; i++) {
    dep[i] = dep[p[i]] + 1;
    cs[i] += cs[p[i]];
    smax(maxdep, dep[i]);
    // std::cerr << "cs " << i << " " << cs[i] << "\n";
  }

  LL ans = LLONG_MAX;
  for (int i = 1; i <= n; i++) {
    if (dep[i] == maxdep) {
      smin(ans, cs[i]);
    }
  }

  std::cout << 2 * n - 2 - maxdep << " " << ans << "\n";
}

int main() {
  // freopen("t.in", "r", stdin);
  // freopen("t.out", "w", stdout);
  
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  
  int t = 1;
  
  // std::cin >> t;
  
  while (t--) {
    solve();
  }
  return 0;
}
