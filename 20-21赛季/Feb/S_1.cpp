#include <cstdio>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <unordered_map>
using namespace std;
#define pii pair<int,int>
#define mp(x,y) make_pair(x,y)
const int N=1e5+5;
int n;
int x[N], y[N];
int dx[]={-1, 1, 0, 0, 0};
int dy[]={0, 0, -1,1, 0};
unordered_map<int, unordered_map<int, int> >cows,vis,times;

inline int rea()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}

void read(){
    n=rea();
    for(int i=1;i<=n;++i){
        x[i]=rea();
        y[i]=rea();
    }
}


pii find_cow(pii cow){
    int x=cow.first;
    int y=cow.second;
    for(int i =0;i < 4;++i){
        int xx = x+dx[i];
        int yy=y+dy[i];
        if(vis[xx][yy]==0){
            return mp(xx,yy);
        }
    }
    return mp(-99999999,-99999999);
}

void Set(pii cow, int &cnt){
    queue<pii>q;
    int x=cow.first;
    int y=cow.second;
    vis[cow.first][cow.second]=1;
    if(times[cow.first][cow.second]==3){
        q.push(mp(x,y));
    }
    //cows.insert(cow);
    for(int i=0;i<4;++i){
        int xx= x+dx[i];
        int yy = y+dy[i];
        if(++times[xx][yy]==3){
            if(vis[xx][yy]==0) continue;
            q.push(mp(xx,yy));
        }
    }
    while(q.empty()==0){
        pii tmp=q.front();
        q.pop();
        tmp = find_cow(tmp);
        if(tmp.first==-99999999) continue;
        Set(tmp, cnt);
        ++cnt;
    }
}

void solve(){
    int cnt = 0;
    for(int i=1;i<=n;++i){
        if(vis[x[i]][y[i]]){
            --cnt;
        }
        else{
            Set(mp(x[i],y[i]), cnt);
        }
        printf("%d\n",cnt);
    }
}


int main(){
    read();
    solve();
    return 0;
}