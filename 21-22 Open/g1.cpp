#include<bits/stdc++.h>
#define sight(c) ('0'<=c&&c<='9')
#define swap(a,b) a^=b,b^=a,a^=b
#define LL long long
#define debug(a) cout<<#a<<" is "<<a<<"\n"
#define dput(a) puts("a")
#define eho(x) for(int i=head[x];i;i=net[i])
#define fi first
#define se second
inline char nc(){
static char buf[1000000],*p1=buf,*p2=buf;
return p1==p2&&(p2=(p1=buf)+fread(buf,1,1000000,stdin),p1==p2)?EOF:*p1++;}
template <class T>
inline void read(T &x){
    static char c;
    for (c=getchar();!sight(c);c=getchar());
    for (x=0;sight(c);c=getchar())x=x*10+c-48;
}
template <class T> void write(T x){if (x<10) {putchar('0'+x); return;} write(x/10); putchar('0'+x%10);}
template <class T> inline void writeln(T x){ if (x<0) putchar('-'),x*=-1; write(x); putchar('\n'); }
template <class T> inline void writel(T x){ if (x<0) putchar('-'),x*=-1; write(x); putchar(' '); }
using namespace std;
#define N 4000007
struct Node{
	int op,t,x,n,X,Y;
	bool operator <(const Node & A)const{
		return X==A.X?Y<A.Y:X<A.X;
	}
}p[N];
map<int,int> S;
int n,ans,dla;
signed main() {
	read(n); 
	for (int i=1;i<=n;i++) {
		read(p[i].op);
		read(p[i].t);
		read(p[i].x);
		read(p[i].n);
		p[i].X=p[i].t+p[i].x;
		p[i].Y=p[i].t-p[i].x; 
	} 
	sort(p+1,p+n+1);
	for (int i=1;i<=n;i++) {
		int Y=p[i].Y;
		if (p[i].op==1) {
			if (S.count(Y)) {
				S[Y]+=p[i].n;
			}
			else {
				S[Y]=p[i].n;
			}
		} else {
			int Node=p[i].n;
			while (Node>0) {
				auto it=S.upper_bound(Y);
				if (it==S.begin()) break;
				it--;
				dla=min(Node,it->second);
				it->second-=dla;
				ans+=dla;
				Node-=dla;
				if (it->second==0) S.erase(it);
			}
		}
	}
	printf("%d\n",ans);
    return 0;
}
