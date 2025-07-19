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
char c[100005];
int l[100005],r[100005];
P<int,int> p[100005];
int n;
int l1,r1,l2,r2;
bool check(int x,int y){
	if(p[x].F<=l1&&p[x].S>=r1||(p[x].F<=y&&p[x].S>=y)){
		
	}else RE 0;
	if(p[y].F<=l2&&p[y].S>=r2||(p[y].F<=x&&p[y].S>=x)){
		
	}else RE 0;
	RE 1;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	l1=n+1,r1=0,l2=n+1,r2=0;
	FOR(i,1,n){
		cin>>c[i];
		if(c[i]=='H'){
			gmin(l1,i);gmax(r1,i);
		}else{
			gmin(l2,i);gmax(r2,i);
		}
	}
	FOR(i,1,n)cin>>p[i].S,p[i].F=i;
	int ans=0;
	int it=-1;
	FOR(i,1,n)if(c[i]=='H'){
		it=i;
		FOR(j,1,n)if(c[j]=='G'){
			if(check(i,j))ans++;
		}
		break;
	}
	FOR(j,1,n)if(c[j]=='G'){
		FOR(i,it+1,n)if(c[i]=='H'){
			if(check(i,j))ans++;
		}
		break;
	}
	cout<<ans<<'\n';
	RE 0;
}
