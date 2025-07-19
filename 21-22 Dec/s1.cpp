#include<bits/stdc++.h>
using namespace std;
#define ll long long 

int n,m,k;
struct nod{
	int pos,w;
}z[200050];
ll pos1[200040],w[200050],pos2[200050];
int cnt=0;
ll dp[200050][2];
struct node{
	ll w,id,op;
	bool operator <  (const node &ths)const{
		return w<ths.w;
	} 
};
priority_queue<node>q;
bool cmp(nod a,nod b){
	return a.pos<b.pos;
} 
int main(){
	scanf("%d%d%d",&k,&m,&n);
	for(int i=1;i<=k;i++){
		scanf("%lld%lld",&pos1[i],&w[i]);
		z[i].pos=pos1[i];
		z[i].w=w[i];
	}
	sort(z+1,z+1+k,cmp);
	for(int i=1;i<=k;i++){
		pos1[i]=z[i].pos;
		w[i]=z[i].w;
	}
	for(int i=1;i<=m;i++)scanf("%lld",&pos2[i]);
	sort(pos2+1,pos2+1+m);
	int id=1;
	cnt=1; 
	for(int i=1;i<=m;i++){
		if(i==1){
			int f=0;
			while(id<=k&&pos1[id]<pos2[i]){
				dp[cnt][0]+=w[id];
				dp[cnt][1]+=w[id];
				id++;
				f=1;
			} 
			if(f)cnt++;
		}else{
			int f=0;
			while(id<=k&&pos1[id]<pos2[i]){
				dp[cnt][1]+=w[id];
				if(pos1[id]-pos2[i-1]<=pos2[i]-pos1[id]){
					dp[cnt][0]+=w[id];
				} 
				id++;
				f=1;
			}
			if(f)dp[cnt][0]=max(dp[cnt][0],dp[cnt][1]-dp[cnt][0]),cnt++;
		}
	}
	int f=0;
	while(id<=k){
		f=1;
		dp[cnt][1]+=w[id];
		dp[cnt][0]+=w[id];
		id++;
	}
	if(f)cnt++;
	for(int i=1;i<cnt;i++){
		dp[i][1]-=dp[i][0];
		q.push({dp[i][0],i,1});
	} 
	int num=0;
	ll ans=0; 
	while(num<n&&!q.empty()){
		node x=q.top();q.pop();
		ans+=x.w;
		if(x.op==1){
			q.push({dp[x.id][1],x.id,2});
		}
		num++;
	}
	printf("%lld\n",ans);
	return 0;
}

