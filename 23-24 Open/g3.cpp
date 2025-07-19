#include<bits/stdc++.h>
#define N 509
using namespace std;
typedef long long ll;
const int mod=1e9+7;
int dp[N][N],n,a[N],b[N];
ll sum1[N],sum2[N];
int sm[N][N];
inline void MOD(int &x){x=x>=mod?x-mod:x;}
struct nd{
	ll x,y;
	inline bool operator <(const nd &b)const {
		return x*b.y<y*b.x;
	}
	inline bool operator <=(const nd &b)const {
		return x*b.y<=y*b.x;
	}
};
vector<nd>ve1[N],ve2[N];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;++i)cin>>a[i],sum1[i]=sum1[i-1]+a[i];
	for(int i=1;i<=n;++i)cin>>b[i],sum2[i]=sum2[i-1]+b[i];
	dp[0][0]=1;
	for(int i=1;i<=n;++i) {
		for(int j=0;j<i;++j)ve1[i].push_back(nd{sum1[i]-sum1[j],i-j});
		sort(ve1[i].begin(),ve1[i].end());
	}
	for(int i=1;i<=n;++i) {
		for(int j=0;j<i;++j)ve2[i].push_back(nd{sum2[i]-sum2[j],i-j});
		sort(ve2[i].begin(),ve2[i].end());
	}
	for(int i=1;i<=n;++i) {
		for(int j=0;j<=n;++j) {
			for(int k=0;k<i;++k) {
				sm[j][k]=dp[i-ve1[i][k].y][j];
				if(k)MOD(sm[j][k]+=sm[j][k-1]);
			}
		}
		for(int j=1;j<=n;++j) {
			int k=-1;
			for(auto x:ve2[j]) {
				while(k+1<ve1[i].size()&&ve1[i][k+1]<=x)k++;
				if(k>=0)MOD(dp[i][j]+=sm[j-x.y][k]);
			}	
		}
	
	}
	cout<<dp[n][n];
	
    return 0;
}

