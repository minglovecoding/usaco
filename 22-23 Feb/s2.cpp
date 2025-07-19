#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>
#define int long long 
#define tiii tuple<int,int,int>

using namespace std;


bool cmp(tiii t1,tiii t2){
    return get<2>(t1)<get<2>(t2);
}

void solve(){
    int n,m;
    cin >> n >> m;
    vector<tiii> x(n);
    for(int i=0;i<n;i++){
        cin>>get<0>(x[i])>>get<1>(x[i])>>get<2>(x[i]);
    }
    sort(x.begin(),x.end(),cmp);
    for(int i=1;i<n;i++){
        int dx = get<0>(x[i])-get<0>(x[i-1]);
        int dy = get<1>(x[i])-get<1>(x[i-1]);
        int dt = get<2>(x[i])-get<2>(x[i-1]);
        if(dx*dx+dy*dy>dt*dt){
            cout<<m;
            return ;
        }
    }
    int cnt=0;
    while(m--){
        int xx,y,t;
        cin>>xx>>y>>t;
        int i = upper_bound(x.begin(),x.end(),tiii(xx,y,t),cmp) - x.begin();
        bool flag = false;
        if(i<n){
            int dx = get<0>(x[i])-xx;
            int dy = get<1>(x[i])-y;
            int dt = get<2>(x[i])-t;
            if(dx*dx+dy*dy>dt*dt){
                flag = true;
            }
        }
        if(i>0){
            int dx = get<0>(x[i-1])-xx;
            int dy = get<1>(x[i-1])-y;
            int dt = get<2>(x[i-1])-t;
            if(dx*dx+dy*dy>dt*dt){
                flag = true;
            }
        }
        cnt+=flag;
    }
    cout<<cnt<<endl;
}

signed main()
{
    int T=1;
    while(T--){
        solve();
    }
    return 0;
}

