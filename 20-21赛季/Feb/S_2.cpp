#include <cstdio>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
using namespace std;
#define pii pair<int,int>
#define mp(x,y) make_pair(x,y)
const int N=1e5+5;
int n,k;
int p[N];
int line[N]; int line_num;


void read(){
    scanf("%d %d",&n,&k);
    --k;
    for(int i=2;i<=n+1;++i){
        scanf("%d", p+i);
    }
}
int f1(int x){
    if(x%12!=0){
        x=((x/12)+1)*12;
    }
    return x;
}
int f2(int x){
    if(x%12!=0){
        x=x/12*12;
    }
    return x;
}
void make_line(){
    n=n+1;
    sort(p+1,p+1+n);
//    for(int i=1;i<=n;++i){
//        printf("%d\n",p[i]);
//    }
    for(int i=1;i<n;++i){
        int p1=p[i];
        int p2=p[i+1];
        int y1=f1(p1); int y2=f2(p2);
        if(y2-y1>0){
            line[++line_num]=y2-y1;
        }
    }
    sort(line+1,line+1+line_num);
}

int cal(){
    if(k>=line_num){
        int tot=0;
        for(int i=1;i<=line_num;++i) tot+=line[i];
        return tot;
    }
    else{
        int tot=0;
        for(int i=1;i<=k;++i){
            tot+=line[line_num-i+1];
        }
        return tot;
    }
    
}

int main(){
    read();
    make_line();
    //printf("%d\n",f1(p[n]));
    printf("%d\n",f1(p[n])-cal());
    return 0;
}