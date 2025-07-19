#include<bits/stdc++.h>
#define int long long
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
#define sz(x) ((int)x.size())
#define pc putchar
using namespace std;
const int INF=3e18;
int n,m,d[20];
P<int,int> dp[1<<18][20];
int s[1<<18],dis[20][20];
int get(P<int,int> x,int y){
	RE x.F*y+x.S;
}
int root[20],cnt;
P<int,int> p[10000005];
int lc[10000005],rc[10000005];
void update(int &x,int l,int r,P<int,int> tp){
	if(l>r)RE;
	if(!x){
		x=++cnt;
		p[x]=tp;RE;
	}
	int mid=(l+r)>>1;
	if(get(tp,mid)>get(p[x],mid))swap(p[x],tp);
	if(l==r)RE;
	if(tp.F>p[x].F)update(rc[x],mid+1,r,tp);
	else update(lc[x],l,mid-1,tp);
}
int get(int x,int l,int r,int id){
	if(!x)RE -INF;
	int re=get(p[x],id);
	int mid=(l+r)>>1;
	if(mid>=id)gmax(re,get(lc[x],l,mid-1,id));
	else gmax(re,get(rc[x],mid+1,r,id));
	RE re;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	rep(i,0,n)rep(j,0,n)dis[i][j]=INF;
	rep(i,0,n)cin>>d[i];
	rep(i,0,n){
		rep(mask,0,1<<n)if(mask&(1<<i)){
			s[mask]+=d[i];
		}
	}
	FOR(i,1,m){
		int s,t,val;
		cin>>s>>t>>val;
		gmin(dis[s-1][t-1],val);
	}
	rep(i,0,n)dis[i][i]=0;
	rep(k,0,n)rep(i,0,n)if(dis[i][k]!=INF)rep(j,0,n)gmin(dis[i][j],dis[i][k]+dis[k][j]);
	rep(mask,0,1<<n)rep(i,0,n)dp[mask][i]=MP(INF,INF);
	rep(i,0,n)dp[1<<i][i]=MP(0,0);
	rep(mask,1,1<<n){
		rep(i,0,n)if(dp[mask][i].F!=INF){
			rep(to,0,n)if(!(mask&(1<<to))){
				if(dis[i][to]==INF||dp[mask][i].S+dis[i][to]>1000000000)continue;
				gmin(dp[mask^(1<<to)][to],MP(dp[mask][i].F+dis[i][to]*s[mask],dp[mask][i].S+dis[i][to]));
			}
		}
	}
	rep(i,0,n){
		rep(mask,0,1<<n)if(mask&(1<<i)){
			if(dp[mask][i].F!=INF&&dp[mask][i].S<=1000000000){
				update(root[i],1,1e9,MP(s[mask],-dp[mask][i].F));
			}
		}
	}
	int Q;cin>>Q;
	FOR(_,1,Q){
		int s,e;
		cin>>s>>e;e--;
		cout<<get(root[e],1,1e9,s)<<'\n';
	}
	RE 0;
}



