#include<iostream>
using namespace std;
const int maxn=2e5+10;
int n,a[maxn],cnt[maxn],empt[maxn];
int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        cnt[a[i]]++;
    }
    empt[0]=int(cnt[0]==0);
    for(int i=0;i<=n;i++){
        empt[i]=empt[i-1]+int(cnt[i]==0);
    }
    cout<<cnt[0]<<endl;
    for(int i=1;i<=n;i++){
        cout<<max(empt[i-1],cnt[i])<<endl;
    }
}
