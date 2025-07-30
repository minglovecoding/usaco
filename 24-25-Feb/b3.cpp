#include<bits/stdc++.h>
using namespace std;
const int maxn=100+10;
const int maxk=10;
int t,n,k,a[maxn];
bool f[maxk][maxn][maxn];
bool repeat(int st,int mid,int ed){
    int d=mid-st+1;
    if((ed-st+1)%d!=0) return false;
    for(int i=st;i<=ed;i++){
        int j=i+d;
        if(j>ed) break;
        if(a[i]!=a[j]) return false;
    }
    return true;
}
int main(){
    cin>>t;
    while(t--){
        cin>>n>>k;
        memset(f,false,sizeof(f));
        for(int i=1;i<=n;i++) cin>>a[i];
        for(int i=1;i<=n;i++){
            for(int j=1;j<=k;j++) f[j][i][i]=true;
            for(int j=i+1;j<=n;j++){
                f[1][i][j]=f[1][i][j-1]&&a[j]==a[j-1];
            }
        }
        for(int i=2;i<=k;i++){
            for(int st=1;st<=n;st++){
                for(int ed=st+1;ed<=n;ed++){
                    //case1 ()()
                    for(int mid=st+1;mid<=ed;mid++){
                        for(int kk=1;kk<i;kk++){
                            f[i][st][ed]=f[i][st][ed] || f[i-kk][st][mid-1] && f[kk][mid][ed];
                        }
                    }
                    //case2 ()()()()
                    for(int mid=st;mid<ed;mid++){
                        if(repeat(st,mid,ed)){
                            f[i][st][ed]=f[i][st][ed]||f[i][st][mid];
                        }
                    }
                }
            }
        }
        if(f[k][1][n]) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}