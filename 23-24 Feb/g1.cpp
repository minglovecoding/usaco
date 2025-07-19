#include <cstdio>
#include <queue>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
using namespace std;

#define N 100005
#define M 200005


struct node{
    int st,dis,meta_st;
    bool operator<(const node &t)const{
        return dis>t.dis;
    }
};

priority_queue<node>pq;

int n,m,s,u,v,w,cnt,dis;
int c, r, k;
typedef pair<int, int> pii;
unordered_map<int, unordered_map<int, int> >G;
unordered_map<int, vector<pii> >true_G;
unordered_map<int, unordered_map<int, int>>vis_map;
int times[N];


void ins(int u,int v,int w){
    if(!G[u].count(v)) {
        G[u][v] = w;
    }
    else {
        G[u][v] = min(G[u][v], w);
    }
}
void construct_true_G() {
    for(int i = 1; i <= n; ++i) {
        for(auto o: G[i]) {
            true_G[i].push_back({o.second, o.first});
        }
        sort(true_G[i].begin(), true_G[i].end());
    }
}

int main(){
    cin >> n >> m >> c >> r >> k;
    for(int i=1;i<=m;++i){
        cin >> u >> v >> w;
        ins(u,v,w);
        ins(v,u,w);
    }
    vector<int>ans;
    construct_true_G();
    for(int i = 1; i <= c; ++i) {
        pq.push({i, 0, i});
    }
    while(!pq.empty()){
        node tmp=pq.top();  pq.pop();
        u=tmp.st;    dis=tmp.dis;
        int meta_st = tmp.meta_st;
        if(times[u] < k && !vis_map[meta_st][u]) {
            vis_map[meta_st][u] = 1;
            ++times[u];
        }
        else {
            continue;
        }
        for(pii o: true_G[u]) {
            int v = o.second; int w = o.first;
            if(times[v] < k && w + dis <= r && !vis_map[meta_st][v]) {
                pq.push((node){v, w + dis, meta_st});
            }
        }
     }
    for(int i = c + 1; i <= n; ++i) {
        if(times[i] >= k) {
            ans.push_back(i);
        }
    }
    
    
    sort(ans.begin(), ans.end());
    cout << ans.size() << '\n';
    for(int o: ans) {
        cout << o << '\n';
    }
    

    return 0;
}
