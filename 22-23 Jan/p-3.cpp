#include<bits/stdc++.h>
#define ll long long
#define gmax(x,y) x=max(x,y)
#define gmin(x,y) x=min(x,y)
#define F first
#define S second
#define P pair
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define rep(i,a,b) for(int i=a;i<b;i++)
#define V vector
#define RE return
#define ALL(a) a.begin(),a.end()
#define MP make_pair
#define PB emplace_back
#define PF push_front
#define FILL(a,b) memset(a,b,sizeof(a))
#define lwb lower_bound
#define upb upper_bound
#define lc (x<<1)
#define rc ((x<<1)|1)
#define sz(x) ((int)x.size())
#define pc putchar
using namespace std;
int siz[200005];
int n,p[200005],dp[200005][2];
V<int> v[200005];
int ans=0,f[3],to[3];
void dfs(int x){
	siz[x]=1;
	int mx=0;
	for(auto u:v[x]){
		dfs(u);
		siz[x]+=siz[u];
		gmax(mx,siz[u]);
	}
	f[0]=0;
	f[1]=f[2]=1e9;
	for(auto u:v[x]){
		to[0]=to[1]=to[2]=1e9;
		rep(i,0,3){
			rep(j,0,min(2,3-i)){
				gmin(to[i+j],f[i]+dp[u][j]);
			}
		}
		rep(i,0,3)f[i]=to[i];
	}
	dp[x][1]=min(f[0],f[1]);
	dp[x][0]=min({f[0],f[1],f[2]})+siz[x];
	gmin(dp[x][0],f[0]+siz[x]-mx);
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	FOR(i,2,n)cin>>p[i],v[p[i]].PB(i);
	dfs(1);
	cout<<dp[1][0]*2;
	RE 0;
}



