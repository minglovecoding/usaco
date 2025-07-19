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
int n,m;
int val[105];
int l[25],r[25],c[25];
int tl[25],tr[25],tc[25],cost[25];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	FOR(i,1,n)cin>>l[i]>>r[i]>>c[i];
	rep(i,0,m){
		cin>>tl[i]>>tr[i]>>tc[i]>>cost[i];
	}
	int ans=1e9;
	rep(mask,0,1<<m){
		FILL(val,0);
		int s=0;
		rep(i,0,m)if(mask&(1<<i)){
			FOR(j,tl[i],tr[i])val[j]+=tc[i];
			s+=cost[i];
		}
		bool f=1;
		FOR(i,1,n){
			FOR(j,l[i],r[i])if(val[j]<c[i]){
				f=0;break;
			}
			if(!f)break;
		}
		if(f)gmin(ans,s);
	}
	cout<<ans;
	RE 0;
}

