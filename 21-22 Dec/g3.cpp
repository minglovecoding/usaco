#include<bits/stdc++.h>
using namespace std;
int ALL;
int n, m;
struct tree{
    set<int> son[55];
    vector<int> g[55];
    bool init(vector<int> a){
        for(int i = 1; i <= n; ++i) son[i].clear();
        stack<int> st; st.push(0);
        for(int x:a){
            if(st.top() == x) st.pop(), son[st.top()].insert(x), g[st.top()].push_back(x);
            else st.push(x);
        }
        if(st.size() != 1) ALL = 0;
        return st.size() == 1;
    }
};
int state[55];//0 no, 1 keep, 2 over
void clr(tree &a, int u){
    assert(state[u] != 0);
    state[u] = 2;
    for(int v:a.son[u]) clr(a, v);
}
void add(tree &a, int u){
    if(state[u] != 0) {
        ALL = 0;
        return;
    }
    state[u] = 1;
    for(int v:a.son[u]) {
        add(a, v);
        if(!ALL) return;
    }
    return;
}
void dfs(tree &a, tree &b, int u){
    int j = 0;
    for(int i = 0; i < a.g[u].size(); ++i){
        int x = a.g[u][i];
        if(!b.son[u].count(x)) clr(a, x);
        else{
            while(j<b.g[u].size() && b.g[u][j] != x) {
                add(b, b.g[u][j]), j++;
                if(!ALL) return;
            }
            if(j < b.g[u].size()) dfs(a, b, x), j++;
            if(!ALL) return;
        }
    }
    while(j<b.g[u].size()) {
        add(b, b.g[u][j]), j++;
        if(!ALL) return;
    }
    return;
}
int main(){
    int T; cin>>T;
    while(T--){
        cin>>n>>m;
        for(int i = 0; i <= n; ++i) state[i] = 0;
        ALL = 1;
        tree cute;
        vector<int> nothing;
        cute.init(nothing);
        for(int i = 1; i <= m; ++i){
            vector<int> c;
            int t; cin>>t;
            while(t--){int x; cin>>x; c.push_back(x);}
            if(!ALL) continue;

            tree cur; 
            cur.init(c);
            dfs(cute, cur, 0);
            cute = cur;
        }
        if(!ALL){
            cout<<"NO"<<endl;
        }else{
            cout<<"YES"<<endl;
        }
    }
    return 0;
}