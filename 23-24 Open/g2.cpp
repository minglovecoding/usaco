#include<bits/stdc++.h>
#define N 500009
using namespace std;
typedef long long ll;
int b[N],tot,n,ans[N];
inline ll rd(){
	ll x=0;char c=getchar();bool f=0;
	while(!isdigit(c)){if(c=='-')f=1;c=getchar();}
	while(isdigit(c)){x=(x<<1)+(x<<3)+(c^48);c=getchar();}
	return f?-x:x;
}
struct node{
	int l,r,k,id;
	inline bool operator <(const node &b)const {
		return r-l>b.r-b.l;
	}
}a[N],c[N];
inline bool cmp1(node x,node y) {
	return x.k>y.k;
}
struct BIT{
	int tr[N];
	inline void add(int x,int y){
		while(x<=tot)tr[x]+=y,x+=x&-x;
	}
	int query(int x) {
		int ans=0;
		while(x)ans+=tr[x],x-=x&-x;
		return ans;
	}
}T1,T2;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;++i) {
		cin>>a[i].l>>a[i].r>>a[i].k;a[i].id=i;
		b[++tot]=a[i].l;
		b[++tot]=a[i].r;		
		c[i]=a[i];
	}
	sort(b+1,b+tot+1);
	sort(c+1,c+n+1,cmp1);
	sort(a+1,a+n+1); 
	tot=unique(b+1,b+tot+1)-b-1;
	int p=1;
	for(int i=1;i<=n;++i) {
		while(p<=n&&c[p].k>a[i].r-a[i].l) {
			int x=lower_bound(b+1,b+tot+1,c[p].l+c[p].k)-b;
			int y=upper_bound(b+1,b+tot+1,c[p].r-c[p].k)-b;
			ans[c[p].id]+=T2.query(y-1)-T1.query(x-1);
			p++;
		}	
		a[i].l=lower_bound(b+1,b+tot+1,a[i].l)-b;
		a[i].r=lower_bound(b+1,b+tot+1,a[i].r)-b;
		T1.add(a[i].r,1);T2.add(a[i].l,1);
	}
	while(p<=n){
		int x=lower_bound(b+1,b+tot+1,c[p].l+c[p].k)-b;
		int y=upper_bound(b+1,b+tot+1,c[p].r-c[p].k)-b;
		ans[c[p].id]+=T2.query(y-1)-T1.query(x-1);
		p++;
	}
	for(int i=1;i<=n;++i)cout<<ans[i]-1<<endl;
    return 0;
}

