#include <algorithm>
#include <iostream>
#include <unordered_map>
using namespace std;
int n;
int a[100005], b[100005];

void read() {
    ios::sync_with_stdio(false);
    cin >> n;
    for(int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    for(int i = 1; i <= n; ++i) {
        int x;
        cin >> x;
        b[x] = i;
    }
}

int solve() {
    int mx = 0;
    int ans = 0;
    for(int i = 1; i <= n; ++i) {
        int x = b[a[i]];
        ans += (mx > x);
        mx = max(mx, x);
    }
    return ans;
}

int main() {
    read();
    cout << solve() << endl;
    return 0;
}