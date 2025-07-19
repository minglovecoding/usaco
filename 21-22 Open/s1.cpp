#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 100010
#define ll long long 
using namespace std;
int f[maxn],c[maxn],vis[maxn];
int main(){
	int n;scanf("%d",&n);
	ll ans=0;
	for(int i=1;i<=n;++i)scanf("%d%d",&f[i],&c[i]),ans+=c[i];
	memset(vis,0,sizeof(vis));
	for(int i=1;i<=n;++i)
	if(!vis[i]){
		int p=i;
		do{
			vis[p]=i;
			p=f[p];
		}while(!vis[p]);
		if(vis[p]!=i)continue;
		int mn=1e9+1,ed=p;
		do{
			mn=min(mn,c[p]);
			p=f[p];
		}while(p!=ed);
		ans-=mn;
	}
	printf("%lld\n",ans);
	return 0;
}
