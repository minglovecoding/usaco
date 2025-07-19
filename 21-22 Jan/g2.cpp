#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(),(x).end()
const int N=1e5+2,M=2e5+2;
struct Q
{
    int u,v,w;
    Q(){}
    Q(int a,int b,int c):u(a),v(b),w(c){}
    bool operator<(const Q &o) const {return w>o.w;}
};
struct P
{
    int v,w;
    P(){}
    P(int a,int b):v(a),w(b){}
};
vector<P> e[N];
int E[M][2],T[M],ed[N],f[N],at[M],ans[N];
int getf(int u) {return f[u]==u?u:f[u]=getf(f[u]);}
void dfs(int u,int x)
{
    ed[u]=1;ans[u]=x;
    for (auto [v,w]:e[u]) if (!ed[v]) dfs(v,min(x,w));
}
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    int i,n,m,id=0;
    char c;
    vector<Q> eg;
    cin>>n>>m;
    iota(f,f+n+1,0);
    for (i=1;i<=m;i++)
    {
        int x;
        cin>>c>>x;
        if (c=='D') ed[x]=1,eg.emplace_back(0,x,i-1); else if (c=='R') eg.emplace_back(E[x][0],E[x][1],i-1),T[x]=0; else
        {
            int y;
            cin>>y;
            T[++id]=i;
            E[id][0]=x;
            E[id][1]=y;
        }
    }
    for (i=1;i<=id;i++) if (T[i]) eg.emplace_back(E[i][0],E[i][1],m);
    for (i=1;i<=n;i++) if (!ed[i]) eg.emplace_back(0,i,m);
    reverse(all(eg));
    for (auto [u,v,t]:eg)
    {
        int fu=getf(u),fv=getf(v);
        if (fu==fv) continue;
        e[u].emplace_back(v,t);
        e[v].emplace_back(u,t);
        f[fu]=fv;
    }
    fill_n(ed,n+1,0);
    dfs(0,m);
    for (i=1;i<=n;i++) cout<<ans[i]<<'\n';
}