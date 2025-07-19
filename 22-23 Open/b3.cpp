#include <bits/stdc++.h>
using namespace std;
const int N=3e5;
int n,k,t;
int a[N],f[N],p2[N];
int main()
{
	cin>>n>>k>>t;
	for (int i=1;i<=k;i++) cin>>a[i]; a[k+1]=a[1]+n;
	for (int i=1;i<=k;i++) f[a[i]]=a[i+1]-a[i]; 
	int lst=0;
	for (int i=0;i<n;i++)
	{
		if (f[i]) lst=i;
		int t1=t-(i-lst);
		int k=ceil(1.0*t1/f[lst]);
		p2[(i+k*f[lst])%n]=i;
	}
	for (int i=0;i<n;i++)
	{
	 cout<<p2[i];
	 if (i!=n-1) cout<<" ";
	} 
	return 0;
}
