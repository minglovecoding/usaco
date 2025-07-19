#include<bits/stdc++.h>
using namespace std;
int n,q,ans,a[1510],b[1510],tr[1510][1510];
char c[1510][1510];
int upd(int x,int y,int k)
{
	if(x==n+1)
		return k*b[y];
	if(y==n+1)
		return k*a[x];
	if(c[x][y]=='R')
	{
		tr[x][y+1]+=k;
		return upd(x,y+1,k);
	}
	else
	{
		tr[x+1][y]+=k;
		return upd(x+1,y,k);
	}
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%s%d",c[i]+1,&a[i]);
	for(int i=1;i<=n;i++)
		scanf("%d",&b[i]);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
		{
			tr[i][j]++;
			if(c[i][j]=='R')
				tr[i][j+1]+=tr[i][j];
			else tr[i+1][j]+=tr[i][j];
		}
	for(int i=1;i<=n;i++)
	{
		ans+=tr[i][n+1]*a[i];
		ans+=tr[n+1][i]*b[i];
	}
	printf("%d\n",ans);
	scanf("%d",&q);
	while(q--)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		ans+=upd(x,y,-tr[x][y]);
		c[x][y]='R'-c[x][y]+'D';
		ans+=upd(x,y,tr[x][y]);
		printf("%d\n",ans);
	}
	return 0;
}
