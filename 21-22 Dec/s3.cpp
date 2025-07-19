#include<bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
typedef pair<int,int>P;
typedef long long ll;
int n,m;
int A[200005];
int B[200005];
int a[5005];
int b[5005];
ll pre[10005];
const int N=5e3;
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++)
    {
        scanf("%d%d",&A[i],&B[i]);
        a[A[i]]++;
        b[B[i]]++;
    }
    for(int i=0;i<=N;i++)
    {
        for(int j=0;j<=N;j++)
        {
            pre[i+j]+=1ll*a[i]*a[j];
            pre[i+j+1]-=1ll*b[i]*b[j];
        }
    }
    ll res=0;
    for(int i=0;i<=2*m;i++)
    {
        res+=pre[i];
        printf("%lld\n",res);
    }
    return 0;
}
/*
2 5
1 3
2 5
*/

