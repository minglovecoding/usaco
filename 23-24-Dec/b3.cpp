#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
const int N=2e6;
int h[N],a[N],t[N],f[N];
signed main(){

    int T;
    cin>>T;
    while (T--){
      int n;
      cin>>n;
      for (int i=1;i<=n;i++) cin>>h[i];
      for (int i=1;i<=n;i++) cin>>a[i];
      for (int i=1;i<=n;i++){ 
        cin>>t[i];
        f[t[i]]=i;
      }
      int ans=0;
      for (int i=1;i<n;i++){
        if (a[f[i-1]]>a[f[i]]&&h[f[i-1]]<=h[f[i]]){
          ans=max(ans,(ll)ceil(1.0*(h[f[i]]-h[f[i-1]]+1)/(a[f[i-1]]-a[f[i]])));
        }
      }
      for (int i=1;i<=n;i++) h[i]+=ans*a[i];
      bool tt=1;
      for (int i=1;i<n;i++)
        if (h[f[i-1]]<=h[f[i]]) tt=0;
      if (tt) cout<<ans<<endl;
      else cout<<-1<<endl;
    }
    return 0;
}