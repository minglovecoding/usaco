#include<bits/stdc++.h>
using namespace std;
int n,p,s,a[100010];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]),s+=a[i];
	while(1)
	{
		if(s==0&&p==0)break;
		while(p<n&&a[p+1])
			a[++p]--,s--,putchar('R'),s-=a[p];
		while(p>0&&a[p])
		{
			if(a[p]==1&&s)break;
			a[p--]--,putchar('L'),s+=a[p+1];
		}
	}
	return 0;
}

