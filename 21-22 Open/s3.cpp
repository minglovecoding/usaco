#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<cmath>
#define ll long long
#define maxn 200020
using namespace std;
inline int getint(){
    char c=getchar();int x=0;bool p=0;
    while((c>'9'||c<'0')&&c!='-')c=getchar();
    if(c=='-')p=1,c=getchar();
    while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();
    if(p)x=-x;return x;
}
char s[maxn],cnt[maxn][3];
int idx(char c){
	if(c=='C')return 0;
	if(c=='O')return 1;
	return 2;
}
string ans;
int main(){
	scanf("%s",s+1);
	int n=strlen(s+1);
	cnt[0][0]=cnt[0][1]=cnt[0][2]=0;
	for(int i=1;i<=n;++i){
		cnt[i][0]=cnt[i-1][0];
		cnt[i][1]=cnt[i-1][1];
		cnt[i][2]=cnt[i-1][2];
		++cnt[i][idx(s[i])];
	}
	int q=getint();
	for(int i=1;i<=q;++i){
		int l=getint(),r=getint();
		int t0=(cnt[r][0]-cnt[l-1][0])&1,t1=(cnt[r][1]-cnt[l-1][1])&1,t2=(cnt[r][2]-cnt[l-1][2])&1;
		if(t0==1&&t1==0&&t2==0||t0==0&&t1==1&&t2==1)ans+="Y";
		else ans+="N";
	}
	cout<<ans<<endl;
	return 0;
}
