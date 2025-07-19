#include<bits/stdc++.h>
#define N 300009
using namespace std;
typedef long long ll;
int c[N],s[N],f[N];
int head[N],tot,tag[N],vis[N],p[N];
int n,m;
queue<int>q; 
vector<int>vec[N];
inline ll rd(){
	ll x=0;char c=getchar();bool f=0;
	while(!isdigit(c)){if(c=='-')f=1;c=getchar();}
	while(isdigit(c)){x=(x<<1)+(x<<3)+(c^48);c=getchar();}
	return f?-x:x;
}
struct edge{
	int n,to;
}e[N<<1];
inline void add(int u,int v){
	e[++tot].n=head[u];
	e[tot].to=v;
	head[u]=tot;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int T;cin>>T;
		while(T--){
		cin>>n>>m;
		for(int i=1;i<=n;++i)cin>>c[i];
		for(int i=1;i<=n;++i)cin>>s[i];
		for(int i=1;i<=n;++i)cin>>f[i];
		int u,v;
		for(int i=1;i<=m;++i){
			cin>>u>>v;
			add(u,v);
			add(v,u);
		}
		tag[s[1]]=1;vis[1]=1;
		int g=0;
		q.push(1);
		while(!q.empty()){
			int u=q.front();q.pop();
			//cout<<u<<"??"endl;
			tag[s[u]]=1;
			for(auto x:vec[s[u]]){
				if(vis[x])continue;
				q.push(x);
				vis[x]=1;
			}
			vec[s[u]].clear();
			for(int i=head[u];i;i=e[i].n){
				int v=e[i].to;
				if(vis[v])continue;
				if(tag[c[v]]){
					vis[v]=1;q.push(v);
				}
				else vec[c[v]].push_back(v);
			}
		}
		for(int i=1;i<=n;++i){
			if(!vis[i]&&f[i]!=s[i])g=1;
			if(vis[i])p[i]=1;
		}
		for(int i=1;i<=n;++i){
			vis[i]=0;tag[i]=0;vec[i].clear();
		}
		tag[f[1]]=1;vis[1]=1;
		q.push(1);
		while(!q.empty()){
			int u=q.front();q.pop();
			//cout<<u<<"??"endl;
			tag[f[u]]=1;
			for(auto x:vec[f[u]]){
				if(vis[x])continue;
				q.push(x);
				vis[x]=1;
			}
			vec[f[u]].clear();
			for(int i=head[u];i;i=e[i].n){
				int v=e[i].to;
				if(p[v]==0)continue;
				if(vis[v])continue;
				if(tag[c[v]]||f[v]==c[v]){
					vis[v]=1;q.push(v);
				}
				else vec[c[v]].push_back(v);
			}
		}
		for(int i=1;i<=n;++i){
			if(!vis[i]&&f[i]!=s[i])g=1;
		}
		if(g)cout<<"NO\n";else cout<<"YES\n";
		for(int i=1;i<=n;++i){
			head[i]=vis[i]=tag[i]=p[i]=0;
			vec[i].clear();
		}
		tot=0;
    }
    return 0;
}

