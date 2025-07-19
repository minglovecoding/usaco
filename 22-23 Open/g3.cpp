#include <bits/stdc++.h>
using namespace std;
const int N=5000;
vector<int> ve[N],ve2[N];
int f1[N],f2[N],h[N],dep[N],t[N],n,m,rt,h2[N],g[N],fa[N];
vector<pair<int,int>> A;
int find(int x)
{
	return fa[x]==x?x:fa[x]=find(fa[x]);
}
void merge(int x,int y)
{
	if (x>y) swap(x,y);
	A.push_back({x,y});
	t[x]=1;
	int f1=find(x),f2=find(y);
	if (f1>f2) swap(f1,f2);
	fa[f1]=f2;
}
void dfs(int x)
{
	if (h[x])
	{
		int n1=x,n2=x;
    	while (n1!=rt)
    	{
    		n1=f1[n1],n2=f2[n2];
    		if (n1==n2) break;
			merge(n1,n2);
    	}
	}
	for (auto v:ve[x])
	{
	  dep[v]=dep[x]+1;
	  dfs(v);
	  h[x]|=h[v];
    }
}
vector<int> o;
int path[10000];
bool fin=0;
void dfs3(int x,int y)
{
	if (fin) return;
	if (y==o.size())
	{
		for(int i=0;i<y;i++)
		  merge(o[i],path[i]); 
		fin=1;
		return;
	}
	for (auto v:ve2[x])
	  if (v>=o[y])
	  {
	  	path[y]=v;
	  	dfs3(v,y+1);
	  }
}
vector<int> P[N];
void dfs4(int x)
{
	P[dep[x]].push_back(x);
	for (auto v:ve[x])
	  dfs4(v);
}
void dfs2(int x)
{
	for (auto v:ve[x])
	{
	  dfs2(v); 
	  if (h[x]==1&&!h[v])
	  {
	  	  for (int i=0;i<=n;i++)  P[i].clear();
	  	  dfs4(v);
	  	  o.clear();
	  	  for (int i=dep[v];i<=n;i++)
	  	  {
	  	  	int lst=0,ans=0;
	  	  	for (auto v:P[i])
	  	  	{
	  	  		ans=max(ans,v);
	  	  		if (lst) merge(lst,v);
	  	  		lst=max(lst,v);
			}
			if (ans) o.push_back(ans);
	  	  }
	  	  fin=0;
	  	  dfs3(find(x),0);
		  fin=1; 
	  }
    }
}
bool cmp(pair<int,int> x,pair<int,int> y)
{
	return dep[x.first]<dep[y.first];
}
int main()
{
	ios::sync_with_stdio(false);
	int T;
	cin>>T;
	while (T--)
	{
		cin>>n;
		for (int i=1;i<=n;i++) fa[i]=i,ve[i].clear(),ve2[i].clear(),g[i]=t[i]=0;
		for (int i=1;i<n;i++)
		{
			int x,y;
			cin>>x>>y;
			g[x]=1;
			ve[y].push_back(x);
			f1[x]=y;
		}
		rt=0;
		for (int i=1;i<=n;i++)
		  if (!g[i]) rt=i;
		dep[rt]=0;
		cin>>m;
		for (int i=1;i<=n;i++) h[i]=h2[i]=0;
		for (int i=1;i<m;i++)
		{
			int x,y;
			cin>>x>>y;
			ve2[y].push_back(x);
			f2[x]=y;
			h[x]=1; h[y]=1;
			h2[x]=1; h2[y]=1;
		}
		A.clear();
		dfs(rt);
		dfs2(rt);
		for (int i=0;i<A.size();i++)
		  A[i].second=find(A[i].first);
		sort(A.begin(),A.end());
		A.erase(unique(A.begin(),A.end()),A.end());
		sort(A.begin(),A.end(),cmp); 
		cout<<A.size()<<endl;
		for (auto v:A)
		{
			cout<<v.first<<" "<<v.second<<endl;
	    }
	}
	return 0;
}
/*
1
7
4 3
2 3
5 4
1 4
6 2
7 2
4
4 3
5 4
7 4
*/ 
