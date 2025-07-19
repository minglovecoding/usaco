#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n, k;
int a[105];
vector<int> G[105];
int ans;

bool cmp(int x, int y) {
    return a[x] < a[y];
}

int make_metal(int x) {
    if(a[x] > 0) {
        a[x] -= 1;
        return 1;
    }
    if(G[x].size() == 0) {
        return 0;
    }
    sort(G[x].begin(), G[x].end());
    for(auto y : G[x]) {
        if(make_metal(y) == 0) {
            return 0;
        }
    }
    return 1;
}

int main() {
    cin >> n;
    for(int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    cin >> k;
    while(k--) {
        int L, M;
        cin >> L >> M;
        for(int i = 1; i <= M; ++i) {
            int x;
            cin >> x;
            G[L].push_back(x);
        }
    }
    while(make_metal(n)) {
        ans += 1;
    }
    cout << ans << endl;
    return 0;
}