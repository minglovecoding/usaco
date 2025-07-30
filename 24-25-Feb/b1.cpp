#include<iostream>
using namespace std;
const int maxn=2025;
char map[maxn][maxn];
int n,m,ans;
int check(int x,int y){
    int cnt=0;
    cnt+=(map[x][y]=='#')+(map[x][n-1-y]=='#')+(map[n-1-x][y]=='#')+(map[n-1-x][n-1-y]=='#');
    return min(cnt,4-cnt);
}

int main(){
    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>map[i][j];
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            ans+=check(i,j);
        }
    }
    ans/=4;
    cout<<ans<<endl;
    while(m--){
        int x,y;
        cin>>x>>y;
        x--;
        y--;
        int before=check(x,y);
        if(map[x][y]=='#'){
            map[x][y]='.';
        }else{
            map[x][y]='#';
        }
        int after=check(x,y);
        ans+=after-before;
        cout<<ans<<endl;
    }
    return 0;
}