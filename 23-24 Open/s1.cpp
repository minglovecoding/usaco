#include<bits/stdc++.h>
#define mm make_pair
#define N 500009
using namespace std;
typedef long long ll;
int t[N],n,k,f[N],vis[N],ans[N],head[N],tot;
set<pair<ll,int> >s;
set<pair<ll,int> >::iterator it;
struct edge{
	int n,to;
}e[N*5];
queue<int>q;
inline void add(int u,int v){
	e[++tot].n=head[u];
	e[tot].to=v;
	head[u]=tot;
}
void ins(pair<ll,int> P) {
	s.insert(P);
	int x=P.second;
	it=s.find(P);
	if(it!=s.begin()) {
		--it;
		if(it->first==P.first){
			int y=it->second;
			add(x,y);
			add(y,x);
		}
		++it;
	}
	++it;
	if(it!=s.end()) {
		if(it->first==P.first){
			int y=it->second;
			add(x,y);
			add(y,x);
		}
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;++i){
		cin>>t[i];
	}
	for(int i=1;i<=k;++i) {
		f[i]=i;
		ins(mm(t[i],i));
	}
	int now=k;
	for(int i=k+1;i<=n;++i){
		pair<ll,int>P=*s.begin();
		++now;
		f[now]=f[P.second];
		add(now,P.second);
		s.erase(s.begin());
		P.first+=t[i];
		P.second=now;
		ins(P);
	}
	int x=s.begin()->second;
	cout<<s.begin()->first<<endl;
	q.push(x);vis[x]=1;ans[f[x]]=1;
	while(!q.empty()){
		int u=q.front();q.pop();
		for(int i=head[u];i;i=e[i].n) {
			int v=e[i].to;if(vis[v])continue;
			vis[v]=1;ans[f[v]]=1; 
			q.push(v);
		}
	}
	for(int i=1;i<=k;++i)cout<<ans[i];
    return 0;
}

