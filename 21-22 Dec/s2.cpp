#include<bits/stdc++.h>
using namespace std;
#define ll long long 

int t;
int n,m;
int fa[100050];
int cnt=0;
ll s[100050];
ll dp[100050][2];
ll ans=0;
int find(int x){
	if(x==fa[x])return x;
	return fa[x]=find(fa[x]);
}
int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++)fa[i]=i,dp[i][0]=dp[i][1]=1e18;
		cnt=0;
		for(int i=1;i<=m;i++){
			int a,b;
			scanf("%d%d",&a,&b);
			a=find(a);b=find(b);
			if(a!=b){
				fa[a]=b;
			}
		}
		for(int i=1;i<=n;i++){
			if(find(i)==find(1)){
				cnt++;
				s[cnt]=i;
				dp[i][0]=0;
			}
		}
		for(int i=1;i<=n;i++){
			if(find(i)!=find(1)){
				int pos=lower_bound(s+1,s+1+cnt,i)-s;
				int id=find(i);
				if(pos==cnt+1){
					pos--;
					dp[id][0]=min(dp[id][0],(s[pos]-i)*(s[pos]-i));
				}else if(pos==1){
					dp[id][0]=min(dp[id][0],(s[pos]-i)*(s[pos]-i));
				}else{
					dp[id][0]=min(dp[id][0],(s[pos]-i)*(s[pos]-i));
					pos--;
					dp[id][0]=min(dp[id][0],(s[pos]-i)*(s[pos]-i));
				}
			}
		}
		cnt=0;
		for(int i=1;i<=n;i++){
			if(find(i)==find(n)){
				cnt++;
				s[cnt]=i;
				dp[i][1]=0;
			}
		}
		for(int i=1;i<=n;i++){
			if(find(i)!=find(n)){
				int pos=lower_bound(s+1,s+1+cnt,i)-s;
				int id=find(i);
				if(pos==cnt+1){
					pos--;
					dp[id][1]=min(dp[id][1],(s[pos]-i)*(s[pos]-i));
				}else if(pos==1){
					dp[id][1]=min(dp[id][1],(s[pos]-i)*(s[pos]-i));
				}else{
					dp[id][1]=min(dp[id][1],(s[pos]-i)*(s[pos]-i));
					pos--;
					dp[id][1]=min(dp[id][1],(s[pos]-i)*(s[pos]-i));
				}
			}
		}
		ans=1e18;
		for(int i=1;i<=n;i++)
			ans=min(ans,dp[i][0]+dp[i][1]);
		printf("%lld\n",ans);
	}
	return 0;
}

