#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll mod=1e9+7;
typedef struct node
{
    int x, y;
}point;
point po[10005];
point xl(point a, point b)
{
    point c;
    c.x = b.x - a.x;
    c.y = b.y - a.y;
    return c;
}
double cal(point a, point b)
{
    return abs(1.0*a.x * b.y - 1.0*a.y * b.x);
}
bool judge(point a,point b,point c,point p)
{
    int flag = 1;

    point pa = xl(p, a), pb = xl(p, b), pc = xl(p, c);
    point ab = xl(a, b), ac = xl(a, c), bc = xl(b, c);
    double s = cal(ab, ac);
    double s1 = cal(pa, ab), s2 = cal(pb, bc), s3 = cal(pc, ac);
    if (s1 == 0 || s2 == 0 || s3 == 0)//点不在三角形边界的判断
        flag = 0;
    if (s == s1 + s2 + s3 && flag == 1)
        return true;
    else
        return false;

}
ll ans[50][50][50],in[50][50][50][50],dp[50][50][50][50],n;
ll min3(ll a,ll b,ll c)
{
    return min(min(a,b),c);
}
ll max3(ll a,ll b,ll c)
{
    return max(max(a,b),c);
}
ll mid(ll a,ll b,ll c)
{
    return (a+b+c-min3(a,b,c)-max3(a,b,c));
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d%d",&po[i].x,&po[i].y);
    for(int j=1;j<=n;j++)
    for(int g=j+1;g<=n;g++)
    for(int k=g+1;k<=n;k++)
    for(int l=1;l<=n;l++)
    {
        if(l==j||l==g||l==k)continue;
        if(judge(po[j],po[g],po[k],po[l]))
        {
            in[j][g][k][l]=1;
            ans[j][g][k]++;
//            printf("%d %d %d %d\n",j,g,k,l);
        }
    }
    for(int j=1;j<=n;j++)
    for(int g=j+1;g<=n;g++)
    for(int k=g+1;k<=n;k++)dp[j][g][k][3]=6;

    for(int i=4;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        for(int g=j+1;g<=n;g++)
        for(int k=g+1;k<=n;k++)
        {
            if(i>ans[j][g][k]+3)continue;
            for(int l=1;l<=n;l++)
            {
                if(l==j||l==g||l==k)continue;
                if(in[j][g][k][l])
                {
                    dp[j][g][k][i]=(dp[j][g][k][i]+
                    dp[min3(j,g,l)][mid(j,g,l)][max3(j,g,l)][i-1]+
                    dp[min3(j,k,l)][mid(j,k,l)][max3(j,k,l)][i-1]+
                    dp[min3(k,g,l)][mid(k,g,l)][max3(k,g,l)][i-1])%mod;
                }
            }
            dp[j][g][k][i]=(dp[j][g][k][i]+(ans[j][g][k]+3-i+1)*dp[j][g][k][i-1])%mod;
//            printf("%lld %lld %lld %lld %lld\n",j,g,k,i,dp[j][g][k][i]);
        }
    }
    ll an=0;
    for(int j=1;j<=n;j++)
    for(int g=j+1;g<=n;g++)
    for(int k=g+1;k<=n;k++)an=(an+dp[j][g][k][n])%mod;
    printf("%lld\n",an);

}
/**
4
0 0
0 4
4 0
1 1
5
0 0
0 4
4 0
1 1
1 2
*/