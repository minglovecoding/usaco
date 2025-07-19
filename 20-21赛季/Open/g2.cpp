/*
 * @Date: 2021-04-04 14:14:47
 * @LastEditTime: 2021-04-04 17:25:03
 * @Author's blog: blog.nuoyanli.com
 * @Description: Plum blossom from the bchter cold!
 */
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define lowbit(x) ((x) & (-(x)))
#define mid ((l + r) >> 1)
#define lson rt << 1, l, mid
#define rson rt << 1 | 1, mid + 1, r
#define fors(i, a, b) for (int i = (a); i < (b); ++i)
#define all(vec) vec.begin(), vec.end()
const int maxn = 2e5 + 5;
int n;
struct node {
  int c;
  int x1, y1, x2, y2;
  bool operator<(const node &a) const { return c < a.c; }
} e[maxn];
int fa[maxn];
int fnd(int x) { return x == fa[x] ? x : fa[x] = fnd(fa[x]); }
bool link(int x, int y) {
  x = fnd(x);
  y = fnd(y);
  fa[x] = y;
  return x != y;
}
int main() {
  fors(i, 1, maxn) fa[i] = i;
  cin >> n;
  fors(i, 1, n + 1) {
    scanf("%d%d%d%d%d", &e[i].c, &e[i].x1, &e[i].y1, &e[i].x2, &e[i].y2);
    link(e[i].x1, e[i].y1);
    link(e[i].x2, e[i].y2);
  }
  sort(e + 1, e + 1 + n);
  int ans = 0;
  fors(i, 1, n + 1) {
    if (link(e[i].y1, e[i].x2))
      ans += e[i].c;
  }
  cout << ans << endl;
  return 0;
}
/*
5
10 1 4 8 9
11 1 2 5 6
12 9 10 2 3
3 4 3 6 7
15 10 8 7 5

13
*/