#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <set>
#include <cstring>
#include <assert.h>
#include <unordered_map>
using namespace std;
typedef long long ll;

const int N = 1e6 + 100;


int n;
int a[N];
int ok[N];
int leaf_num[N];
int nongyao_num[N];
vector<int>G[N];
int ans;

void dfs1(int u, int f) {
    int is_leaf = 1;
    for(int v: G[u]) {
        if(v == f) {
            continue;
        }
        is_leaf = 0;
        dfs1(v, u);
        leaf_num[u] += leaf_num[v];
    }
    if(is_leaf) {
        leaf_num[u] = 1;
    }
}
void dfs2(int u, int f) {
    leaf_num[u] = 0;
    int is_leaf = 1;
    for(int v: G[u]) {
        if(v == f) {
            continue;
        }
        is_leaf = 0;
        dfs2(v, u);
        
        leaf_num[u] += leaf_num[v];

    }
    
    if(is_leaf) {
        leaf_num[u] = 1;
    }
    if(leaf_num[u]) {
        int temp = min(leaf_num[u], ok[u]);
        leaf_num[u] -= temp;;
        ans += temp;
    }
    

}

int main() {
    cin >> n;
    for(int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    for(int i = 1; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    dfs1(1, -1);
    for(int i = 1; i <= n; ++i) {
        assert(leaf_num[i] > 0);
    }
    for(int i = 1; i <= leaf_num[1]; ++i) {
        ok[a[i]]++;
    }
    dfs2(1, -1);
    cout << ans << endl;
    
    
    
    return 0;
}