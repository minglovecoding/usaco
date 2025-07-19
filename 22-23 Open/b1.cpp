#include <bits/stdc++.h>
using namespace std;
const int N=3e5;
char s[N];
bool f[N];
int pd(char c)
{
	if (c=='B') return 0;
	if (c=='E') return 1;
	return 2; 
}
int main()
{
	int n;
	cin>>n;
	cin>>(s+1);
	int ss=0;
	for (int i=1;i<=n;i++)
	  if (s[i]=='F') ss++;
	if (ss==n)
	{
		cout<<n<<endl;
		for (int i=0;i<=n-1;i++)
		  cout<<i<<endl;
		return 0;
	}
	int now=0;
	int cnt=0;
	int sum=0,sum2=0;
	for (int i=1;i<=n;i++)
	{
	  if (i!=1&&s[i]==s[i-1]&&s[i]!='F') cnt++;
	  if (s[i]=='F') now++;
	  else
  	  if (now!=0)
  	  {
  		if (i-now-1!=0)
		{
		  if (s[i]==s[i-now-1]) now=now+1;
		  if (now%2==1) cnt++;
		  sum+=now/2;
	    } else
	    {
	    	sum2+=now;
	    }
	    now=0;
  	  }
    }
    if (now) sum2+=now;
    for (int i=0;i<=sum;i++)
      for (int j=0;j<=sum2;j++)
	    f[i*2+j+cnt]=1;
	int numm=0;
	for (int i=0;i<=n+1;i++)
	  if (f[i]) numm++;
	cout<<numm<<endl;
	for (int i=0;i<=n+1;i++)
	  if (f[i]) cout<<i<<endl; 
	return 0;
}
