#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll a[310][310];
ll ans[310];
bool check(int x,int y,int z){
    if(max(abs(ans[x]-ans[y]),max(abs(ans[x]-ans[z]),abs(ans[y]-ans[z])))==a[x][z]) return 1;
    return 0;
}
int main(){
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            scanf("%lld",&a[i][j]);
        }
    }
    ans[1]=0;
    int p=1,q=1;
    while(a[p][q]==0&&q<=n){
        q++;
        ans[q]=a[p][q];
    }
    for(int i=q+1;i<=n;i++){
        if(a[q][i]==0) ans[i]=ans[q];
        else{
            ans[i]=ans[q]+a[q][i];
            if(!check(p,q,i)) ans[i]=ans[q]-a[q][i]; 
            p=q;
            q=i;
        }
    }
    ll maxx=-1e15,minn=1e15;
    for(int i=1;i<=n;i++){
        if(maxx<ans[i]) maxx=ans[i];
        if(minn>ans[i]) minn=ans[i];
    }
    if(maxx>1e9){
        for(int i=1;i<=n;i++){
            ans[i]+=(1e9-maxx);
        }
    }
    if(minn<-1e9){
        for(int i=1;i<=n;i++){
            ans[i]+=(-1e9-minn);
        }
    }
    for(int i=1;i<=n;i++){
        printf("%lld",ans[i]);
        if(i!=n) printf(" ");
        else printf("\n");
    }
    return 0;
}
