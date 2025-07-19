#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=5e5;
int a[N];
string ss="bessie";
ll dp[N][6],dp2[N][6];
//dp[i][j]代表考虑前i位，要匹配第j个位置 最小花费 
//dp2[i][j]代表考虑前i位，要匹配第j个位置 最大个数 
int main()
{
	string s;
	cin>>s;
	int n=s.length();
	for (int i=1;i<=n;i++)
	  cin>>a[i];
	for (int i=0;i<=N-1;i++)
	  for (int j=0;j<=5;j++)
	    dp[i][j]=1e18;
	dp[0][0]=0;
    for(int i=1;i<=n;i++)
      for (int j=0;j<=5;j++)
      if (dp[i-1][j]<1e18)
	  {
	  	if (s[i-1]==ss[j])
		{
		  int num=dp2[i-1][j];
		  if (j==5) num++;
		  if (num>dp2[i][(j+1)%6]||(num==dp2[i][(j+1)%6]&&dp[i-1][j]<dp[i][(j+1)%6]))
		  { 
		  	  dp2[i][(j+1)%6]=num;
		      dp[i][(j+1)%6]=dp[i-1][j];
		  }
		  //代表去掉当前位置的数 
	    }
	    int cost=0;
	    if (j!=0) cost=a[i];
	    if (dp2[i-1][j]>dp2[i][j]||(dp2[i-1][j]==dp2[i][j]&&dp[i-1][j]+cost<dp[i][j]))
	    {
	      dp2[i][j]=dp2[i-1][j];
	  	  dp[i][j]=dp[i-1][j]+cost;
	    }
	    //代表保留当前位置的数 如果匹配第0位花费为0 
	  }
	cout<<dp2[n][0]<<endl<<dp[n][0]<<endl;  
	return 0;
}
/*
bebesconsiete
6 5 2 3 6 5 7 9 8 1 4 5 1
*/ 