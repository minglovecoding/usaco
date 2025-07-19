#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<cmath>
#define ll long long
#define maxc 18
#define maxn 100010
using namespace std;
inline int getint(){
    char c=getchar();int x=0;bool p=0;
    while((c>'9'||c<'0')&&c!='-')c=getchar();
    if(c=='-')p=1,c=getchar();
    while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();
    if(p)x=-x;return x;
}
string ans;
bool ok[maxc][maxc];
char s[maxn],t[maxn];
int main(){
	memset(ok,0,sizeof(ok));
	scanf("%s",s+1);
	scanf("%s",t+1);
	int ns=strlen(s+1),nt=strlen(t+1);
	for(int i=0;i<maxc;++i)
	for(int j=i;j<maxc;++j){
		int l=1;
		bool p=1;
		for(int k=1;k<=ns;++k)
		if(s[k]==i+'a'||s[k]==j+'a'){
			while(l<=nt&&t[l]!=i+'a'&&t[l]!=j+'a')++l;
			if(l>nt){p=0;break;}
			if(s[k]!=t[l]){p=0;break;}
			++l;
		}
		while(l<=nt){
			if(t[l]==i+'a'||t[l]==j+'a'){p=0;break;}
			++l;
		}
		ok[i][j]=p;
	}
	int q=getint();
	for(int i=1;i<=q;++i){
		bool p=1;
		char tmp[maxc];
		scanf("%s",tmp);
		int len=strlen(tmp);
		for(int j=0;j<len;++j)
		for(int k=j;k<len;++k)
		if(!ok[tmp[j]-'a'][tmp[k]-'a'])p=0;
		if(p)ans+="Y";
		else ans+="N";
	}
	cout<<ans<<endl;
	return 0;
}
