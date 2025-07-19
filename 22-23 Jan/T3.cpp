#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
const int P=1e9+7;
int inv[N],fact[N],inv_fact[N];
void init()
{
	inv[1]=1,fact[0]=1,fact[1]=1,inv_fact[0]=1,inv_fact[1]=1;
	for(int i=2;i<N;i++)
	{
		inv[i]=P-(long long)P/i*inv[P%i]%P;
		fact[i]=1ll*fact[i-1]*i%P;
		inv_fact[i]=1ll*inv_fact[i-1]*inv[i]%P;
	}
}
int n,ans=1,a[N];
int C(int x,int y){return 1ll*fact[x]*inv_fact[y]%P*inv_fact[x-y]%P;}
int solve(int x,int y){return x>=y?C(x,y):C(y-1,y-x);}
int main()
{
	init();
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<n;i++)
		ans=1ll*ans*solve(a[i]/2,a[i+1]/2)%P;
	printf("%d\n",ans);
	return 0;
}
