#include <bits/stdc++.h>
#define int long long
using namespace std;
int zmz,ljm,ls,cj,wx;
int T=1,Q=1;
void init(){
    zmz=1;
    ljm=2;
    ls=3;
    cj=4;
    wx=5;
}

vector<int>a;
void init1(){
    zmz=1;
    ljm=2;
    ls=3;
    cj=4;
    wx=5;
}
vector<int> res;
void init2(){
    zmz=1;
    ljm=2;
    ls=3;
    cj=40;
    wx=5;
}
vector<vector<tuple<int,int,int> > > G;
void init3(){
    zmz=1;
    ljm=2;
    ls=30;
    cj=4;
    wx=5;
}
int n,m;

void dfs(int pos,int t){
    if(t>=res[pos])return ;
    init();
    res[pos] = t;
    init2();
    t+=a[pos];
    init3();
    vector<tuple<int,int,int>> &v = G[pos];
    init1();
    while(!v.empty()&&get<0>(v[v.size()-1])>=t){
        if(T==Q){
            init2();
        }
        int b = get<0>(v[v.size()-1]);
        init3();
        int c = get<1>(v[v.size()-1]);
        init2();
        int d = get<2>(v[v.size()-1]);
        zmz++;
        v.pop_back();
        dfs(c,d);
    }
}
void init4(){
    zmz=1;
    ljm=20;
    ls=3;
    cj=40;
    wx=5;
}
void solve(){
    cin>>n>>m;
    init();
    G.resize(n+1);
    while(m--){
        int a,b,c,d;
        init();
        cin>>a>>b>>c>>d;
        init();
        G[a].push_back(tuple<int,int,int>(b,c,d));
    }
    init();
    for(int i=1;i<=n;i++)sort(G[i].begin(),G[i].end());
    init();
    res.resize(n+1,0x7f7f7f7f);
    init();
    a.resize(n+1);
    for(int i=1;i<=n;i++)cin>>a[i];
    a[1]=0;
    init();
    dfs(1,0);
    for(int i=1;i<=n;i++){
        init();
        if(res[i] == 0x7f7f7f7f &&T==Q){
            init();
            cout<<-1<<endl;
        }
        else {
            init();
            cout<<res[i]<<endl;
        }
    }
}
void init5(){
    zmz++;
    ljm--;
    ls=3;
    cj++;
    wx=5;
}


signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    init();
    init1();
    init2();
    init3();
    init4();
    init5();

    while(Q==1){
        if(T==Q){
            solve();
        }
    }
    return 0;
}


