#include<bits/stdc++.h>

using namespace std;

#define endl "\n"

void solve(){
    int n,q;
    cin>>n>>q;
    vector<int>c(n),t(n);
    for(int&x:c) cin>>x;
    for(int&x:t) cin>>x;
    vector<int> a;
    for(int i = 0;i<n;i++){
        if(t[i] >= c[i] - 1) continue;
        a.push_back(c[i] - t[i]);
    }
    sort(a.begin(),a.end());
    while(q--){
        int v,s;cin>>v>>s;
        int l = -1, r = a.size();
        while(l+1!=r){
            int m = l+r>>1;
            if(a[m]<=s) l = m;
            else r = m;
        }
        int g = a.size() - 1 - l;
        if(g>=v) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }

}

int main(){
    cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
    solve();
}