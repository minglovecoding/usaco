#include <bits/stdc++.h>
using namespace std;
const int N=2e6;
bitset<100010> B,B1,B2,tmp,B1y1,B1y2,B1z1,B1z2;
int f[200010],n,m,a[200010];
int pref[N],prel[N],prer[N];
signed main(){
    ios::sync_with_stdio(false);
    int now=0;
    cin>>n>>m;
    for (int i=1;i<=n;i++){ 
      cin>>a[i];
    }
    string s;
    cin>>s;
    int pos=0;
    for (int i=0;i<s.size();i++){
      if (s[i]=='L') pos--;
      if (s[i]=='R') pos++;
      now=min(now,pos);
    }
    for (int i=0;i<s.size();i++){
      if (s[i]=='L') prel[i]=i;
      if (s[i]=='R') prer[i]=i;
      if (s[i]=='F') pref[i]=i;
      prel[i+1]=prel[i];
      prer[i+1]=prer[i];
      pref[i+1]=pref[i];
    }
    pos=0;
    now=-now+5;
    for (int i=1;i<=n;i++)
      if (a[i]+now>=0) B[a[i]+now]=1;
    for (int i=0;i<s.size();i++){
      if (s[i]=='L') pos--;
      if (s[i]=='R') pos++;
      if (s[i]=='F') {
        f[pos+now]++,B1[pos+now]=1;
        if (pos+now-1>=0) B1z1[pos+now-1]=1;
        if (pos+now-2>=0) B1z2[pos+now-2]=1;
        B1y1[pos+now+1]=1;
        B1y2[pos+now+2]=1;
      }
    }
    B1&=B;
    B1z1&=B;
    B1z2&=B;
    B1y1&=B;
    B1y2&=B;
    pos=0;
    int ans=(B1&B).count();
    for (int i=0;i<(int)s.size();i++){
      if (s[i]=='F') {
        f[pos+now]--;
        if (!f[pos+now]) {
            B1[pos+now]=0;
            if (pos+now-1>=0) B1z1[pos+now-1]=0;
            if (pos+now-2>=0) B1z2[pos+now-2]=0;
            B1y1[pos+now+1]=0;
            B1y2[pos+now+2]=0;
        }
      }
      if (s[i]=='L') {
        if (B2[pos+now]==0&&B[pos+now]==1){
            B2[pos+now]=1;
            ans=max(ans,(int)((B2|B1y1)).count());
            B2[pos+now]=0;
        }
        if (pref[i]>=prel[i-1]) ans=max(ans,(int)((B2|B1y2)).count());
      } else
      if (s[i]=='R') {
        if (B2[pos+now]==0&&B[pos+now]==1){
            B2[pos+now]=1;
            ans=max(ans,(int)((B2|B1z1)).count());
            B2[pos+now]=0;
        }
        if (pref[i]>=prer[i-1]) ans=max(ans,(int)((B2|B1z2)).count());
      } else {
        ans=max(ans,(int)((B2|(B1y1))).count());
        ans=max(ans,(int)((B2|(B1z1))).count());
      }
      if (s[i]=='L') pos--;
      if (s[i]=='R') pos++;
      if (s[i]=='F') {
        if (B[pos+now]==1) B2[pos+now]=1;
      }
    }
    cout<<ans<<endl;
    return 0;
}