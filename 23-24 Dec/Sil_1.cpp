#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e6;
struct re{
  int a,b;
};
bool cmp(re x,re y){
  return x.a<y.a;
}
re a[N];
signed main(){
    ios::sync_with_stdio(false);
    int n,m,k;
    cin>>n>>k>>m;
    for (int i=1;i<=n;i++) cin>>a[i].a>>a[i].b;
    sort(a+1,a+n+1,cmp);
    vector<re> ve;
    ve.push_back((re){(int)(-1e9),k});
    int now=0;
    int ans=0;
    for (int i=1;i<=n;i++){
      int num=0;
      for (int j=now;j<ve.size();j++)
        if (a[i].a-m>=ve[j].a){
          if (a[i].b>=ve[j].b) num+=ve[j].b,a[i].b-=ve[j].b,now++;
          else{
            ve[j].b-=a[i].b;
            num+=a[i].b;
            break;
          }
        } else break;
      ans+=num;
      ve.push_back((re){a[i].a,num});
    }
    cout<<ans<<endl;
    return 0;
}