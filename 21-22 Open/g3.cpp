#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5+10;
const int INF = 2e9+10;
vector<int> g[maxn];
int l[maxn], r[maxn], zl[maxn], zr[maxn], val[maxn];
bool intersect(int al, int ar, int bl, int br){
    return max(al, bl) <= min(ar, br);
}
void dfs(int u, int w){
    zl[u] = l[u] - w;
    zr[u] = r[u] + w;
    for (int v : g[u]) {
        dfs(v, w);
        zl[u] = max(zl[u], zl[v]);
        zr[u] = min(zr[u], zr[v]);
    }
}
void dfs2(int u, int left, int right, int w) {
    int vl = max(max(left, zl[u]), l[u]);
    int vr = min(min(right, zr[u]), r[u]);
    assert(vl <= vr);
    val[u] = vl;
    for (int v : g[u]) dfs2(v, max(left, val[u] - w), min(right, val[u] + w), w);
}
int B = 0;
void solve(){
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) g[i].clear();
    for (int i = 2; i <= n; i++) {
        int p;
        cin >> p;
        g[p].push_back(i);
    }
    for (int i = 1; i <= n; i++) cin >> l[i] >> r[i];
    int wl = 0, wr = 1e9;
    while (wl < wr){
        int mid = wl + wr >> 1;
        dfs(1, mid);
        bool flag = 1;
        for (int i = 1; i <= n; i++) if (zl[i] > zr[i] || !intersect(zl[i], zr[i], l[i], r[i])) flag = 0;
        if (flag) wr = mid; else wl = mid + 1;
    }
    cout << wl << endl;
    if (B) {
        dfs(1, wl);
        dfs2(1, -INF, INF, wl);
        for (int i = 1; i <= n; i++) cout << val[i] << " \n"[i == n];
    }
}
int main(){
    ios::sync_with_stdio(false);
    int T;
    cin >> T >> B;
    while (T--) solve();
}