#include <bits/stdc++.h>
#define int long long
#define vi vector<int>
#define vvi vector<vi>
#define vb vector<bool>
#define gcd(a,b) __gcd(a,b)
#define fi first
#define se second
#define pb push_back

const int mod = 998244353;
const int inv2 = (mod+1)/2;
const int inv3 = (mod+1)/3;
int qpow(int,int);
int inv(int);

using namespace std;

void init(){

}

vector<int>a;
vector<int> res;
vector<vector<tuple<int,int,int> > > G;
int n,m;

void dfs(int pos,int t){
//    cout<<pos<<' '<<t<<' '<<endl;
    if(t>=res[pos])return ;
//    cout<<"aaa"<<' ';
    res[pos] = t;
    t+=a[pos];
//    cout<<t<<endl;
    vector<tuple<int,int,int>> &v = G[pos];
    while(!v.empty()&&get<0>(v[v.size()-1])>=t){
        int b = get<0>(v[v.size()-1]);
        int c = get<1>(v[v.size()-1]);
        int d = get<2>(v[v.size()-1]);
        v.pop_back();
        dfs(c,d);
    }
}

void solve(){
    cin>>n>>m;
    G.resize(n+1);
    while(m--){
        int a,b,c,d;
        cin>>a>>b>>c>>d;
        G[a].push_back(tuple<int,int,int>(b,c,d));
    }
    for(int i=1;i<=n;i++)sort(G[i].begin(),G[i].end());
    res.resize(n+1,0x7f7f7f7f);
    a.resize(n+1);
    for(int i=1;i<=n;i++)cin>>a[i];
    a[1]=0;
    dfs(1,0);
    for(int i=1;i<=n;i++){
        if(res[i] == 0x7f7f7f7f){
            cout<<-1<<endl;
        }
        else {
            cout<<res[i]<<endl;
        }
    }
}



signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    init();
    int T=1;
//    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}

int qpow(int a,int k){
    int res=1;
    while(k){
        if(k&1)res = res*a%mod;
        a = a*a%mod ;
        k>>=1;
    }
    return res;
}

int inv(int x){
    return qpow(x,mod-2);
}
