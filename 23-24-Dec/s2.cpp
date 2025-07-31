#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e6;
int a[N],b[N],pos1[N],pos2[N],f[N],n,m;
signed main(){
    ios::sync_with_stdio(false);
    cin>>n>>m;
    for (int i=1;i<=m;i++) {
      cin>>a[i];
      pos1[a[i]]=i;
    }
    for (int i=1;i<=m;i++) {
      cin>>b[i];
      pos2[b[i]]=i;
    }
    for (int i=1;i<=n;i++)
      if (pos1[i]&&pos2[i])
        f[(pos1[i]-pos2[i]+m)%m]++;
    int ans=0;
    for (int i=0;i<=n;i++) ans=max(ans,f[i]);
    memset(f,0,sizeof(f));
    memset(pos1,0,sizeof(pos1));
    memset(pos2,0,sizeof(pos2));
    reverse(b+1,b+m+1);
    for (int i=1;i<=m;i++) {
      pos1[a[i]]=i;
    }
    for (int i=1;i<=m;i++) {
      pos2[b[i]]=i;
    }
    for (int i=1;i<=n;i++)
      if (pos1[i]&&pos2[i])
        f[(pos1[i]-pos2[i]+m)%m]++;
    for (int i=0;i<=n;i++) ans=max(ans,f[i]);
    int ans2=0;
    for (int i=1;i<=n;i++)
      if (pos1[i]>0&&!pos2[i]) ans2++;
    cout<<n-(m-ans)-ans2;
    return 0;
}
/*
5 5
1 2 3 4 5
1 5 4 3 2
*/