#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
const int N = 100005;
pll cows[N];
int n, father[N];
struct edge{
    int u, v;
    ll w;
    bool operator <(const edge & t) const {
        return w < t.w;
    }
};
vector<edge>book;
ll cal(ll X1, ll Y1, ll X2, ll Y2) {
    ll dx = (X1 - X2);
    ll dy = (Y1 - Y2);
    return dx * dx + dy * dy;
}
int find_father(int u) {
    if(u != father[u]) {
        father[u] = find_father(father[u]);
    }
    return father[u];
}

int main() {
    cin >> n;
    for(int i = 0; i < n; ++i) {
        cin >> cows[i].first >> cows[i].second;
        father[i] = i;
    }
    sort(cows, cows + n);
    for(int i = 0; i < n; ++i) {
        for(int j = i; j < min(n, i + 50); ++j) {
            book.push_back((edge){i, j, cal(cows[i].first, cows[i].second, cows[j].first, cows[j].second)});
        }
    }
    sort(book.begin(), book.end());
    ll ans = 0;
    for(int i = 0; i < book.size(); ++i) {
        int u = book[i].u;
        int v = book[i].v;
        u = find_father(u);
        v = find_father(v);
        ll w = book[i].w;
        if(u != v) {
            father[v] = u;
            ans += w;
        }
    }
    cout << ans << endl;
    return 0;
}