#include <cstdio>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <cstring>
using namespace std;
#define pii pair<int,int>
#define mp(x,y) make_pair(x,y)
const int N=500+5;

int n;
int mat[N][N];
int num[N][N];
int arr[N];
pii seg_arr[N];
int seg_num;

void read(){
    scanf("%d",&n);
    for(int i=1;i<=n;++i){
        for(int j=1;j<=n;++j){
            scanf("%d",&mat[i][j]);
        }
    }
}
int C2(int x){
    return (x+1)*x/2;
}
int cal(int *arr){
    int ret=0;
    seg_num=0;
    int l=1;
    arr[n+1]=-1;
    for(int i=1;i<=n+1;++i){
        if(arr[i]<100){
            seg_arr[++seg_num]=mp(l,i-1);
            l=i+1;
        }
    }
//    for(int i=1;i<=n;++i){
//        printf("%d ",arr[i]);
//    }
//    printf(": \n");
    
    for(int i=1;i<=seg_num;++i){
        int l=seg_arr[i].first;
        int r=seg_arr[i].second;
        //printf("%d %d\n",l,r);
        if(l>r) continue;
        int n = r-l+1;
        int tot=C2(n);
        
        int memo=arr[r+1];
        arr[r+1]=100;
        int ll=l-1;
        for(int j=l;j<=r+1;++j){
            if(arr[j]==100){
                tot-=C2(j-ll-1);
                ll=j;
            }
        }
        arr[r+1]=memo;
        ret+=tot;
    }
    return ret;
}

void solve(){
    for(int up=1;up<=n;++up){
        memset(arr,0x3f,sizeof(arr));
        for(int down=up;down<=n;++down){
            for(int i=1;i<=n;++i) arr[i]=min(arr[i],mat[down][i]);
            num[up][down]=cal(arr);
        }
    }
}

long long fun(){
    long long ret =0LL;
    for(int up=1;up<=n;++up){
        for(int down=up;down<=n;++down){
            ret+=num[up][down];
        }
    }
    return ret;
}

int main(){
    read();
    solve();
    printf("%lld\n",fun());
    return 0;
}