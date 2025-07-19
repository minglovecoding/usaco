// Author:  HolyK
// Created: Sat Feb 25 20:58:37 2023
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

struct Interv {
  LL s;
  int l, r;
  bool operator<(const Interv &rhs) const {
    return s < rhs.s;
  }
  bool contains(int i) {
    return l <= i && i <= r;
  }
};

void solve() {
  int n;
  std::cin >> n;
  
  std::vector<LL> a(n + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
    a[i] += a[i - 1];
  }

  std::vector<Interv> v;
  for (int i = 1; i <= n; i++) {
    for (int j = i; j <= n; j++) {
      v.push_back({a[j] - a[i - 1], i, j});
    }
  }
  std::sort(v.begin(), v.end());

  for (int i = 1; i <= n; i++) {
    LL ans = LLONG_MAX;
    for (int j = 1; j < v.size(); j++) {
      if (v[j - 1].contains(i) != v[j].contains(i)) {
        smin(ans, v[j].s - v[j - 1].s);
      }
    }
    std::cout << ans << "\n";
  }
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
