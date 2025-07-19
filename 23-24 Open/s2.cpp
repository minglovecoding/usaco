#include <bits/stdc++.h>
using namespace std;
#define int long long
#define mp make_pair
const int N=2e6+10;
int a[N],b[N],aa[N],bb[N],sum[N],c[N],c2[N],f[N];
map<int,int> M;
set<pair<pair<int,int>,int> > S[N],S2[N];
vector<pair<int,int> > Q1[N],Q2[N];
vector<int> ve[N];
bool vis[N];
pair<int,int> dis(int x,int y){
	if (M[x]!=0){
		auto it=S[M[x]].lower_bound({{y,1e9+10},1e9+10});
		if (it!=S[M[x]].begin()){
			it--;
			int k=it->second;
			if (y>=it->first.first&&y<=it->first.second) return mp(sum[k-1]+abs(y-b[k]),k);
		}
	}
	if (M[y]!=0){
		auto it=S2[M[y]].lower_bound({{x,1e9+10},1e9+10});
		if (it!=S2[M[y]].begin()){
			it--;
			int k=it->second;
			if (x>=it->first.first&&x<=it->first.second) return mp(sum[k-1]+abs(x-a[k]),k);
	    }
	}
}
int s[N];
int cnt=0;
void dfs(int x){
	s[++cnt]=x;
	vis[x]=1;
	for (auto v:ve[x])
	  if (!vis[v]){
	    dfs(v);
	    return;
	  }
}
signed main(){
	ios::sync_with_stdio(false);
	int n,m;
	cin>>n>>m;
	int cnt=0;
	for (int i=1;i<=m;i++){
		cin>>a[i]>>b[i];
		aa[i]=a[i]; bb[i]=b[i];
		M[a[i]]=++cnt;
		M[b[i]]=++cnt;
	}
	
	for (int i=1;i<=m;i++){
		Q1[M[a[i]]].push_back({b[i],i});
		Q2[M[b[i]]].push_back({a[i],i});
	}
	for (int i=1;i<=cnt;i++){
		sort(Q1[i].begin(),Q1[i].end());
		sort(Q2[i].begin(),Q2[i].end());
		for (int j=0;j<Q1[i].size();j+=2){
			ve[Q1[i][j].second].push_back(Q1[i][j+1].second);
			ve[Q1[i][j+1].second].push_back(Q1[i][j].second);
	    }
		for (int j=0;j<Q2[i].size();j+=2){
			ve[Q2[i][j].second].push_back(Q2[i][j+1].second);
			ve[Q2[i][j+1].second].push_back(Q2[i][j].second);
	    }
	}
	
	dfs(1);
	for (int i=1;i<=m;i++) a[i]=aa[s[i]],b[i]=bb[s[i]];
	a[m+1]=a[1],b[m+1]=b[1];
	
	for (int i=1;i<=m;i++) assert(a[i]==a[i+1]||b[i]==b[i+1]);
	for (int i=1;i<=m;i++){
		if (a[i]==a[i+1]) 
		  S[M[a[i]]].insert(mp(mp(min(b[i],b[i+1]),max(b[i],b[i+1])),i));
		else 
		  S2[M[b[i]]].insert(mp(mp(min(a[i],a[i+1]),max(a[i],a[i+1])),i));
		sum[i]=abs(a[i]-a[i+1])+abs(b[i]-b[i+1]);
		sum[i]+=sum[i-1]; 
	}
	for (int i=1;i<=n;i++){
		int X1,Y1,X2,Y2;
		cin>>X1>>Y1>>X2>>Y2;
		bool tt=0;
		auto k1=dis(X1,Y1);
		auto k2=dis(X2,Y2); 
		if (k1.first>k2.first){
			swap(k1,k2);
			swap(X1,X2);
			swap(Y1,Y2);
		}
		int x=abs(k1.first-k2.first);
		if (x<sum[m]-x){
			c[k1.second]++; c[k2.second+2]--;
			if (!(a[k1.second]==X1&&b[k1.second]==Y1)) f[k1.second]--;
			if (!(a[k2.second+1]==X2&&b[k2.second+1]==Y2)) f[k2.second+1]--;
		} else {
			c[1]++; c[k1.second+2]--;
			c[k2.second]++; c[m+1]--;
			if (!(a[k1.second+1]==X1&&b[k1.second+1]==Y1)) f[k1.second+1]--;
			if (!(a[k2.second]==X2&&b[k2.second]==Y2)) f[k2.second]--;	
		}
	}
	for (int i=1;i<=m+1;i++) c[i]+=c[i-1];
	for (int i=1;i<=m+1;i++) c[i]+=f[i];
	c[1]+=c[m+1];
	for (int i=1;i<=m;i++) c2[s[i]]=c[i];
	for (int i=1;i<=m;i++) cout<<c2[i]<<endl;
	return 0;
}
