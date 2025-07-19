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
int n,Q,tol[200005][20],tor[200005][20],tl[200005],tr[200005];
int l[200005],r[200005],sl[200005],sr[200005],s[200005];
int getr(int x,int y){
	rep(i,0,20)if(y&(1<<i))x=tor[x][i];
	RE x;
}
int getl(int x,int y){
	rep(i,0,20)if(y&(1<<i))x=tol[x][i];
	RE x;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>Q;
	int cnt1=0,cnt2=0;
	FOR(i,1,2*n){
		char c;
		cin>>c;
		if(c=='L'){
			l[++cnt1]=i;
		}else r[++cnt2]=i;
	}
	FOR(i,1,n){
		char c;cin>>c;
		s[i]=c-'0';
		s[i]+=s[i-1];
	}
	int it=1;
	FOR(i,1,n){
		while(it<n&&l[it+1]<r[i])it++;
		tr[i]=tor[i][0]=it;
	}
	it=n;
	for(int i=n;i>=1;i--){
		while(it>1&&r[it-1]>l[i])it--;
		tl[i]=tol[i][0]=it;
	}
	rep(i,1,20){
		FOR(j,1,n){
			tol[j][i]=tol[tol[j][i-1]][i-1];
			tor[j][i]=tor[tor[j][i-1]][i-1];
		}
	}
	for(int i=n;i>=1;i--)sl[i]=sl[tr[i]]+s[i];
	FOR(i,1,n)sr[i]=sr[tl[i]]+s[i-1];
	FOR(_,1,Q){
		int a,b;
		cin>>a>>b;
		int now=a,ans=0;
		for(int i=19;i>=0;i--)if(tor[now][i]<b){
			now=tor[now][i];
			ans+=(1<<i);
		}
		ans++;
		int sum=sl[tr[a]]-sl[getr(a,ans)];
		sum-=sr[tl[b]]-sr[getl(b,ans)];
		cout<<ans<<' '<<sum+s[a]+s[b]-s[a-1]-s[b-1]<<'\n';
	}
	RE 0;
}



