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
const int INF=1e9;
char c[100005];
void solve(){
	string s;
	cin>>s;
	int n=sz(s);
	rep(i,0,n)c[i+1]=s[i];
	int ans=INF;
	FOR(l,1,n-2){
		if(c[l+1]=='O'){
			int s=0;
			s+=(c[l]=='O');
			s+=(c[l+2]=='M');
			gmin(ans,n-3+s);
		}
	}
	if(ans==INF)cout<<-1<<'\n';
	else cout<<ans<<'\n';
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--)solve();
	RE 0;
}

