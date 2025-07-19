#include<bits/stdc++.h>
#define ll long long
#define mid ((l+r)>>1)
#define lson rt<<1, l, mid
#define rson rt<<1|1, mid+1, r
using namespace std;
const int maxn = 2e5+5;
namespace HL{
    int p1[maxn<<2], p2[maxn<<2];
    ll ans[maxn<<2];
    void up(int rt){
        ans[rt] = ans[rt<<1] + ans[rt<<1|1] + (p2[rt<<1] == 0 && p1[rt<<1|1] == 1);
        p1[rt] = p1[rt<<1]==-1?p1[rt<<1|1]:p1[rt<<1];
        p2[rt] = p2[rt<<1|1] == -1?p2[rt<<1]:p2[rt<<1|1];
        return;
    }
    void update(int rt, int l, int r, int pos, int x){
        if(l == r){
            if(x == 0) p1[rt] = p2[rt] = 0;
            else if(x == 1) p1[rt] = p2[rt] = 1;
            else p1[rt] = p2[rt] = -1;
            return;
        }
        if(pos <= mid) update(lson, pos, x);
        else update(rson, pos, x);
        up(rt);
    }
}
int p[maxn], pos[maxn];
int n;
ll ans[maxn];

int state[maxn];//-1, 0, 1 x, h, l
vector<int> g1[maxn], g2[maxn];

int main(){
    cin>>n;
    for(int i = 1; i <= n; ++i) scanf("%d", &p[i]), pos[p[i]] = i;
    
    int x = 0;
    ll last = n+1;
    set<int> s; s.insert(0); s.insert(n+1);

    for(int i = 1; i <= n; ++i){
        auto it = s.lower_bound(p[i]);
        int r = *it;
        int l = *prev(it);
        if(l > 0) g1[l].push_back(i);
        if(r <= n) g2[r].push_back(i);
        s.insert(p[i]);

        assert(last != p[i]);
        if(last < p[i]) state[i] = -1;
        else state[i] = 0, last = p[i];

        if(state[i] == 0) HL::update(1, 1, n, i, 0);
        else HL::update(1, 1, n, i, -1);
    }
    ans[0] = HL::ans[1];
    for(int x = 1; x <= n; ++x){
        // cout<<"x:"<<x<<endl;
        assert(state[pos[x]] == 0);
        //x H->L
        state[pos[x]] = 1; HL::update(1, 1, n, pos[x], 1);
        //g1 -1 -> H
        for(int k:g1[x]) {
            assert(state[k] == -1); state[k] = 0; HL::update(1, 1, n, k, 0);
        }
        //g2 L-> no
        for(int k:g2[x]){
            assert(state[k] == 1); state[k] = -1; HL::update(1, 1, n, k, -1);
        }
        ans[x] = HL::ans[1];
        
    }
    for(int i = 0; i <= n; ++i) cout<<ans[i]<<endl;
    return 0;
}
/*
5
5 1 3 2 4
*/