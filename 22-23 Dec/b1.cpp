#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <map>
#include <queue>
#include <string.h>
#include <vector>
using namespace std;

const int N = 100100;
int a[N];
int n;
long long maxn = -0x3f3f3f3f;

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
  }
  sort(a + 1, a + 1 + n);
  long long tmp = -1;
  int x = 0;
  for (int i = 1; i <= n; i++) {
    tmp = (long long)a[i] * (long long)(n - i + 1);
    if (tmp > maxn) {
      maxn = tmp;
      x = a[i];
    }
  }
  printf("%lld %d\n", maxn, x);
  return 0;
}
