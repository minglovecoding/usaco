#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e6;
string s;
signed main(){
    int n;
    cin>>n;
    cin>>s;
    int ans1=1e9,ans2=0;
    for (int i=0;i<s.length();i++)
      if (s[i]=='1'){
        int j;
        for (j=i;j<s.length();j++)
          if (s[j]=='0') break;
        int len=j-i;
        if (i==0||j==s.length()) ans1=min(ans1,len-1);
        else ans1=min(ans1,(len-1)/2);
        i=j-1;
      }
    for (int i=0;i<s.length();i++)
      if (s[i]=='1'){
        int j;
        for (j=i;j<s.length();j++)
          if (s[j]=='0') break;
        int len=j-i;
        ans2+=ceil(1.0*len/(2*ans1+1));
        i=j-1;
      }
    cout<<ans2<<endl;
    return 0;
}