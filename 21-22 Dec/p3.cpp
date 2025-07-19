#pragma GCC optimize(2,3,"Ofast")
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define rep(i,l,r) for(int i=(l);i<=(r);i++)
#define per(i,l,r) for(int i=(l);i>=(r);i--)
#define pb push_back
#define fir first
#define sec second
#define SZ(x) (int(x.size()))
const int N=5005;
const int mod=1e9+7;

inline void add(int &x,int y){
    x+=y;if(x>=mod)x-=mod;
}
inline int qpow(int a,int b=mod-2){
    int res=1;
    while(b>0){
        if(b&1)res=1ll*res*a%mod;
        a=1ll*a*a%mod;b>>=1;
    }
    return res;
}
int fac[N],ifac[N];
inline void init(int n){
    fac[0]=1;rep(i,1,n)fac[i]=1ll*fac[i-1]*i%mod;
    ifac[n]=qpow(fac[n]);per(i,n,1)ifac[i-1]=1ll*ifac[i]*i%mod;
}
inline int C(int n,int m){
    if(n<m||m<0)return 0;
    else return 1ll*fac[n]*ifac[n-m]%mod*ifac[m]%mod;
}
int f[N][3],g[N][3];
int n,x,ans;
int d1[N],d2[N];
struct flow
{
	static const int N=200005,inf=1000000000;
	int n,m,s,t,h[N],to[N],f[N],nx[N],q[N],bg,ed,d[N],c[N];
	void init()
	{
		m=1;
		for(int i=1;i<=n;i++)
			h[i]=0;
	}
	void addedge(int u,int v,int w)
	{
		m++;
		f[m]=w,to[m]=v;
		nx[m]=h[u];
		h[u]=m;
	}
	void add(int u,int v,int w)
	{
		addedge(u,v,w);
		addedge(v,u,0);
	}
	int bfs()
	{
		bg=ed=0;
		for(int i=1;i<=n;i++)
			d[i]=inf,c[i]=h[i];
		d[s]=0;
		q[ed++]=s;
		while(bg<ed)
		{
			int u=q[bg++];
			for(int i=h[u];i;i=nx[i])
			{
				int v=to[i],w=f[i];
				if(w&&d[v]>d[u]+1)
				{
					d[v]=d[u]+1;
					q[ed++]=v;
				}
			}
		}
		return d[t]<inf;
	}
	int dfs(int u,int l)
	{
		if(u==t)
			return l;
		int t=0;
		for(int &i=c[u];i;i=nx[i])
		{
			int v=to[i],w=f[i];
			if(d[v]!=d[u]+1)
				continue;
			int r=dfs(v,min(l,w));
			t+=r,l-=r;
			f[i]-=r,f[i^1]+=r;
			if(!l)
				break;
		}
		return t;
	}
	int mf()
	{
		int t=0;
		while(bfs())
			t+=dfs(s,inf);
		return t;
	}
}z;
int main(){
    cin>>n>>x;
    init(n);
    d1[0]=d2[0]=1;
    rep(i,1,x)d1[i]=1ll*d1[i-1]*(x+1-i)%mod;
    rep(i,1,n-x)d2[i]=1ll*d2[i-1]*((n-x)+1-i)%mod; 
    f[0][0]=1;
    for(int ij=0;ij<n;ij++)
    {
        for(int i=0;i<=n;i++)
        {
            g[i][0]=f[i][0];f[i][0]=0;
            g[i][1]=f[i][1];f[i][1]=0;
            g[i][2]=f[i][2];f[i][2]=0;
        }
        if(ij==0)
        {
            f[0][1]=1;
            f[1][0]=1;
            continue;
        }
        for(int i=0;i<=x;i++)
        {
            int j=ij-i;
            if(j>n-x)
                continue;
            add(f[i+1][1],1ll*i*g[i][1]%mod);
            add(f[i][0],1ll*j*g[i][0]%mod);
            add(f[i+1][0],1ll*i*g[i][0]%mod);
            if(n>114514)
            {
                while(1)
                {
                    puts("sbjt!");
                }
                int y=(n+x)^(n-x);
                z.init();
                while(rand()>2333)
                {
                    z.add(123,456,rand()%789+y);
                    puts("!!???!!!");
                    if(z.m+(y<<(rand()%3))==1919810)
                        break;
                }
            }
            add(f[i][1],1ll*j*g[i][1]%mod);
            add(f[i+1][0],g[i][0]);
            add(f[i][1],g[i][0]);
            add(f[i+1][0],g[i][1]);
            if(i<x)add(ans,1ll*g[i][1]*d1[x-(i+1)]%mod*d2[(n-x)-j]%mod*C(n-(i+1)-j,x-(i+1))%mod);
            add(f[i][1],g[i][1]);
        }    
    }   
    cout<<ans<<'\n';
    return 0;
}
