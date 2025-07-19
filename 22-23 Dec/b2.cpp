#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <map>
#include <queue>
#include <string.h>
#include <vector>
using namespace std;

int T, n, k;
string a;
short b[100010];
int len;

// G: 1
// H: 2
int find_idx(int pos, short type) {
  if (pos >= len) {
    pos = len - 1;
  }
  while (b[pos] != 0) {
    pos -= 1;
  }
  b[pos] = type;
  return pos;
}

int main() {
  cin >> T;
  while (T--) {
    memset(b, 0, sizeof(b));
    int cnt = 0;
    cin >> n >> k;
    cin >> a;
    len = a.length();
    int g = -1, h = -1;
    for (int i = 0; i < len; i++) {
      if (a[i] == 'G') {
        if (g == -1 || i - g > k) {
          g = find_idx(i + k, 1);
          cnt += 1;
        }
      } else {
        if (h == -1 || i - h > k) {
          h = find_idx(i + k, 2);
          cnt += 1;
        }
      }
    }
    cout << cnt << endl;
    for (int i = 0; i < len; i++) {
      if (b[i] == 1) {
        cout << "G";
      } else if (b[i] == 2) {
        cout << "H";
      } else {
        cout << ".";
      }
    }
    cout << endl;
  }
  return 0;
}
