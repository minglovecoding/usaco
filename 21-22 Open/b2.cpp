#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
vector<ll>a1;
vector<ll>a2;
int n,tmp,ans=2000;
void read() {
    cin >> n;
    for(int i = 0; i < n; ++i) {
        string s;
        cin>>s;
        cin>>tmp;
        if(s[0]=='L')
        {
            a1.push_back(tmp);
        }
        else
        {
            a2.push_back(tmp);
        }
    }
}
int main() {
    read();
    sort(a1.begin(),a1.end());
    sort(a2.begin(),a2.end());
    for(int i = 0;i < a2.size(); i++) {
        int o = (int)(a2.size())-1-i;
        if(a1[a1.size()-1]>=a2[i]) {
            o += (lower_bound(a1.begin(),a1.end(),a2[i])-a1.begin());
        }
        else {
            o += a1.size();
        }
        ans = min(ans, o);
    }
    cout<<ans<<endl;
}