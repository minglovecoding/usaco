#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int inf=0x3f3f3f3f;
const int mod=1e9+7;
int h[110],dp[110][1100],s[110][1100];
int main(){
    int n;
    scanf("%d",&n);
    int maxh=0,minh=inf; 
    for(int i=1;i<=n;i++){
        scanf("%d",&h[i]);
        maxh=max(maxh,h[i]);
        minh=min(minh,h[i]);
    }
    if(n%2==0){
        for(int i=0;i<=h[1];i++){
            dp[1][i]=1;
            s[1][i]=i+1;
        }
        for(int i=h[1]+1;i<=maxh;i++){
            s[1][i]=s[1][h[1]];
        } 
        for(int i=2;i<=n-1;i++){
            for(int j=0;j<=h[i];j++){
                dp[i][j]=s[i-1][h[i]-j];
            }
            s[i][0]=dp[i][0];
            for(int j=1;j<=maxh;j++){
                s[i][j]=(s[i][j-1]+dp[i][j])%mod;
            }
        }
        printf("%d",s[n-1][h[n]]);
        return 0;
    }
    int sum=0;
    for(int k=0;k<=minh;k++){
        if(k!=0){
            for(int i=1;i<=n;i++){
                h[i]--;
            }
        }
        for(int i=0;i<=h[1];i++){
            dp[1][i]=1;
            s[1][i]=i+1;
        }
        for(int i=h[1]+1;i<=maxh;i++){
            s[1][i]=s[1][h[1]];
        } 
        for(int i=2;i<=n-1;i++){
            for(int j=0;j<=h[i];j++){
                dp[i][j]=s[i-1][h[i]-j];
            }
            s[i][0]=dp[i][0];
            for(int j=1;j<=h[i];j++){
                s[i][j]=(s[i][j-1]+dp[i][j])%mod;
            }
            for(int j=h[i]+1;j<=maxh;j++){
                s[i][j]=s[i][h[i]];
            }
        }
        sum=(sum+s[n-1][h[n]])%mod;
    }
    printf("%d",sum);
    return 0;
}