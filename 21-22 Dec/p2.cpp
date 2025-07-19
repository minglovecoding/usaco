
#include <iostream>
#include <cstdio>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <deque>
#include <vector>
#include <queue>
#include <string>
#include <cstring>
#include <map>
#include <stack>
#include <set>

using namespace std;

const int N=5055;
const int U=1e5+1;
int n = 0, k = 0;
int nU = 0, nD = 0;
int xU[N], yU[N];
int xD[N], yD[N];
int sum = 0;


#define clr(a, x) memset(a, x, sizeof(a))
#define rep(i,a,n) for(ll i=a;i<=n;i++)
#define pre(i,a,n) for(int i=a;i>=n;i--)
#define ll long long
#define max3(a,b,c) fmax(a,fmax(b,c))
#define ios ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
const double eps = 1e-6;
const int INF = 0x3f3f3f3f;
const int inf = 1e5+10;
const int mod = 1e9 + 7;
const int MAXN = 1e6+100;
int have[MAXN],now[MAXN];
int m,q,que,haved;
int a[MAXN];

int mn[MAXN];

void PushUp(int rt)
{
    mn[rt] = min(mn[rt<<1],mn[rt<<1|1]);   
}

void Build(int l,int r,int rt)
{
    if(l == r)
    {
        mn[rt] = a[l];
        return ;
    }
    int mid = (l+r)>>1;
    Build(l,mid,rt<<1);
    Build(mid+1,r,rt<<1|1);
    PushUp(rt);
}

void Add(int L,int C,int l,int r,int rt)
{
    if(l == r)
    {
        mn[rt] += C;
        return ;
    }
    int mid = (l+r) >> 1;
    if(L <= mid)
        Add(L,C,l,mid,rt<<1);
    else 
        Add(L,C,mid+1,r,rt<<1|1);
    PushUp(rt);
}

int Query(int L,int R,int l,int r,int rt)
{
    if(L <= l && r <= R)
    {
        return mn[rt];
    }
    int mid = (l+r)>>1;
    int MIN = INF;
    if(L <= mid)
    {
        MIN = min(Query(L,R,l,mid,rt<<1),MIN);
    }
    if(R > mid)
    {
        MIN = min(Query(L,R,mid+1,r,rt<<1|1),MIN);
    }
    return MIN;
}

int Find()
{
    int l = 1,r = n;
    while(l < r)
    {
        int mid = (l+r)/2;
        int tmp = Query(l,mid,1,n,1);
        if(tmp <= haved)
        {
            r = mid;
        }
        else 
        {
            l = mid+1;
        }
    }
    return l;
}

namespace sub1
{
  int dp[5055][5055];
  void solve()
  {
	  for(int d=1;d<=nD;++d)
    {
      int u = 1;
  

	    while(u<=nU)
      {
		    dp[d][u]=dp[d-1][u];
        if(dp[d][u] < dp[d][u-1])
        {
           dp[d][u] = dp[d][u-1];
        }
        bool bo = abs(xD[d]-xU[u])<=k;
		    if(bo)
        {
          int tmp = dp[d-1][u-1]+yD[d]+yU[u];
          bool blb = dp[d][u] < tmp;
          if(blb)
          {
            dp[d][u] = tmp;
          }
			    
	      }
        ++u;
      }
      int tmp = sum;
      tmp -= dp[nD][nU];
      if(tmp)
      {
        cout << tmp << endl;
      }
      else
      {
        cout << 0 << endl;
      }
    }
  }
}

namespace sub2
{
  

  int dp[N][N][3], mx[N][N], la_d[N];

  void solve()
  {
    bool pr = 0;
	  for(int d=1;!pr && d<=nD;++d)
    {
      int u = 1;
      while(pr || u <= nU)
      {
        bool tmp = abs(xD[d]-xU[u])>k;
	      if(!pr && tmp)
        {
          mx[d][u]=0;
        }
	      else 
        {
  

          mx[d][u]=mx[d-1][u-1]+1;
        }
        ++u;
      }
    }
	  for(int d=0;!pr && d<=nD;++d)
    {
      int u = 0;
		  while(!pr && u<=nU)
      {
        int i = 1;
			  while(pr || i<=2)
        {
          dp[d][u][i]=-2e9;
          i++;
        }
        u++;
      }
    }

  

	  for(int d=1;!pr && d<=nD;++d)
    {
      dp[d][0][0]=dp[d-1][0][0]+yD[d];
    }
	  for(int u=1;!pr && u<=nU;++u)
    {
      dp[0][u][0]=dp[0][u-1][0]+yU[u];
    }
  

	  for(int d=1;!pr && d<=nD;++d)
    {
		  int la_u=0;
		  for(int u=1;!pr && u<=nU;++u)
      {
			  if(xD[d]-xU[u]>k)
        {
				  la_u=u;
				  dp[d][u][0]=dp[d-1][u][0]+yD[d];
				  dp[d][u][2]=dp[d-1][u][2]+yD[d];
			  }
        else if(xD[d]-xU[u]<-k)
        {
				  la_d[u]=d;
				  dp[d][u][0]=dp[d][u-1][0]+yU[u];
				  dp[d][u][1]=dp[d][u-1][1]+yU[u];
			  }
        else
        {
          dp[d][u][2] = dp[d-1][u][2]+yD[d];
  

          if(dp[d][u][2] < dp[d-1][u-1][2])
          {
            dp[d][u][2] = dp[d-1][u-1][2];
          }
          bool tr = false;
          int t1 = u-mx[d-1][u];
          int t2 = la_u;
				  if(t1 <= t2)
          {
            tr = true;
          }
				  if(tr)
          {
  

            int tmp = dp[d-1-(u-la_u)][la_u][0]+yD[d];
            if(dp[d][u][2] < tmp)
            {
              dp[d][u][2] = tmp;
            }
          }
          int tmp = dp[d][u-1][1];
          tmp += yU[u];
          dp[d][u][1] = tmp;
          bool tp = dp[d][u][1] < dp[d-1][u-1][1];
          int tpp = dp[d-1][u-1][1];
  

          if(tp)
          {
            dp[d][u][1] = tpp;
          }
				  if(d-mx[d][u-1]<=la_d[u])
          {
            int tm = dp[la_d[u]][u-1-(d-la_d[u])][0]+yU[u];
            if(dp[d][u][1] < tm)
            {
  

              int tni = dp[la_d[u]][u-1-(d-la_d[u])][0]+yU[u];
              dp[d][u][1] = tni;
            }
          }
          tmp = dp[d][u][2];
  

          if(dp[d][u][1] > dp[d][u][2])
          {
            tmp = dp[d][u][1];
          }

          dp[d][u][0] = tmp;
          tmp = dp[d-1][u-1][0];
  

          if(dp[d][u][0] > dp[d-1][u-1][0])
          {
            tmp = dp[d][u][0];
          }

          dp[d][u][0] = tmp;
			}
		}
	}
  
  int tdp = dp[nD][nU][0];
  if(!tdp)
  {
    cout << 0 << endl;
  }
  else
  {
    cout << tdp << endl;
  }
	
  }
}

int main()
{
	  int T;
    scanf("%d %d %d",&T,&n,&k);
	  for(int i=1;i<=n;i++)
    {
		  char ty[5];
		  scanf("%s",ty);
		  if(ty[0]=='H')
      {
			  nU++;
			  scanf("%d %d",xU+nU,yU+nU);
			  sum+=yU[nU];
		  }
      else
      {
			  nD++;
			  scanf("%d %d",xD+nD,yD+nD);
			  sum+=yD[nD];
		  }
	  }
    switch (T)
    {
      case 1:
        sub1::solve();
        break;
    
      default:
        sub2::solve();
        break;
    }

  return 0;
}


int pre[N];   
bool vis[N];
int last[N]; 
int nxt[N];   
int ans[N];

struct node
{
    int l,r,id;
    bool operator < (const node &b) const   
    {
        return this->l < b.l;
    }
}query[N];

int bit[N];
int lowbit(int x)
{
    return x&(-x);
}

void update(int x,int y)
{
    while(x < N)
        bit[x] += y,x += lowbit(x);
}

int Query(int x)
{
    int ret = 0;
    while(x)
        ret += bit[x],x -= lowbit(x);
    return ret;
}

int Query(int l,int r)
{
    return Query(r)-Query(l-1);
}



char vir[N][55];
struct nod
{
    int son[27];
    int fail;
    int count;
    int number;
}ac[100*N];
int tot = 0;
void init()
{
    clr(a,0);
    for(int i = 0;i < 50000;i++)
    {
        memset(ac[i].son,0,sizeof ac[i].son);
        ac[i].count = 0;
        ac[i].fail = 0;
        ac[i].number = 0;
    }
}

void Insert(char *s,int num)
{
    int len = strlen(s);
    int now = 0;
    int tmp;
    for(int i = 0;i < len;i++)
    {
        tmp = s[i]-'A';
        if(ac[now].son[tmp] == 0)
            ac[now].son[tmp] = ++tot;
        now = ac[now].son[tmp];
    }
    ac[now].count++;
    ac[now].number = num;
}

void Insert1(char *s,int id)
{
    int len = strlen(s);
    int now = 0;
    int tmp;
    for(int i = 0;i < len;i++)
    {
        tmp = s[i]-'A';
        if(ac[now].son[tmp] == 0)
            ac[now].son[tmp] = ++tot;
        now = ac[now].son[tmp];
    }
    ac[now].count++;
    ac[now].number = id;
}

void MakeFail()
{
    queue<int> q;
    for(int i = 0;i < 26;i++)
    {
        if(ac[0].son[i] != 0)
        {
            ac[ac[0].son[i]].fail = 0;
            q.push(ac[0].son[i]);
        }
    }
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        for(int i = 0;i < 26;i++)
        {
            if(ac[u].son[i] != 0)
            {
                ac[ac[u].son[i]].fail = ac[ac[u].fail].son[i];
                q.push(ac[u].son[i]);
            }
            else 
                ac[u].son[i] = ac[ac[u].fail].son[i];
        }
    }
}

void query2(char *s)
{
    int len = strlen(s);
    int now = 0,tmp;
    for(int i = 0;i < len;i++)
    {
        tmp = s[i]-'A';
        if(tmp < 0 || tmp > 25)
            tmp = 26;
        now = ac[now].son[tmp];
        for(int t = now;t && ac[t].count != -1;t = ac[t].fail)
        {
            if(ac[t].number > 0)
            {
                a[ac[t].number]++;
            }
            // ans += ac[t].count;
            // ac[t].count = -1;
        }
    }
}

