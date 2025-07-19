#include<bits/stdc++.h>
#define fors(i,a,b) for(int i = a; i < b; ++i)
#define ll long long
#define mid ((l+r)>>1)
#define lson rt<<1, l, mid
#define rson rt<<1|1, mid+1, r
#define all(x) x.begin(),x.end()
#define pb push_back
using namespace std;
const int maxn = 1e5+5;
#define P pair<int,int>
int k;
ll sol_mx(vector<P> a){
    ll tot = 0;for(auto p:a) tot += p.second;
    if(a.size()%2 == 0) return tot;
    ll ans = 0;
    for(int i = 0; i < a.size(); i += 2) ans = max(ans, tot-a[i].second);
    for(int i = 1; i < a.size(); i += 2){
        if(a[i+1].first-a[i-1].first <= k) ans = max(ans, tot-a[i].second);
    }
    return ans;
}
ll s[maxn], dp[maxn][2];
const ll inf = 0x3f3f3f3f3f3f3f3f;
ll sol_mi(vector<P> a){
    s[0] = a[0].second;
    fors(i,1,a.size()) s[i] = s[i-1]+a[i].second;

    dp[0][0] = 0; dp[0][1] = inf;
    dp[1][0] = inf; dp[1][1] = a[0].second+a[1].second;
    for(int i = 2; i < a.size(); ++i){
        //0
        int p = lower_bound(all(a), P(a[i].first-k, 0))-a.begin();
        if(p == 0){
            if(i%2 == 1) dp[i][0] = inf;
            else dp[i][0] = s[i-1];
        }else{//[p,i-1]
            if((i-p)%2 == 0) dp[i][0] = min(dp[p-1][0], dp[p-1][1]) + s[i-1]-s[p-1];
            else dp[i][0] = dp[p][1] + s[i-1] - s[p];
        }
        dp[i][0] = min(dp[i][0], inf);

        //1
        dp[i][1] = min(dp[i-2][0], dp[i-2][1]) + a[i-1].second + a[i].second;
        if(a[i].first-a[i-2].first <= k) {
            int p = lower_bound(all(a), P(a[i-1].first-k, 0))-a.begin();
            if(p == 0){
                if(i%2 == 0) dp[i][1] = min(dp[i][1], s[i]-a[i-1].second);
            }else{
                //[p, i]
                if((i-p)%2 == 0) dp[i][1] = min(dp[i][1], min(dp[p-1][0], dp[p-1][1])+s[i]-s[p-1]-a[i-1].second );
                else dp[i][1] = min(dp[i][1], dp[p][1] + s[i]-s[p]-a[i-1].second);
            }
            dp[i][1] = min(dp[i][1], dp[i-2][0]+a[i].second+a[i-2].second);
        }
        dp[i][1] = min(dp[i][1], inf);
    }
    int len = a.size();
    ll ans = min(dp[len-1][0], dp[len-1][1]);
    return ans;
}
int main(){
    int T, n;
    cin>>T>>n>>k;
    ll tot = 0;
    vector<P> a;
    fors(i,0,n){
        int x, y; scanf("%d%d", &x, &y);
        a.push_back(P(x, y)); tot += y;
    }
    sort(all(a));
    for(int i = 0; i < a.size(); ++i){
        int j = i;
        while(j+1<a.size() && a[j+1].first-a[j].first <= k) j++;
        vector<P> b; fors(o,i,j+1) b.pb(a[o]);
        if(T == 1){
            tot -= sol_mx(b);
        }else{
            tot -= sol_mi(b);
        }
        i = j;
    }
    cout<<tot<<endl;
    return 0;
}
/*
2
6 2
1 10
3 1
4 3
5 2
6 2
7 1
*/