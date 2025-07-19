#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;typedef double db;
typedef pair<int, int> pii;typedef pair<ll, ll> pll;
typedef pair<int,ll> pil;typedef pair<ll,int> pli;
#define Fi first
#define Se second
#define _Out(a)	cerr<<#a<<" = "<<(a)<<endl
const int INF = 0x3f3f3f3f, MAXN = 2e5 + 5;
const ll LINF = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7;
const db Pi = acos(-1), EPS = 1e-6;
void test(){cerr << "\n";}template<typename T,typename...Args>void test(T x,Args...args){cerr<<x<<" ";test(args...);}
inline ll qpow(ll a, ll b){return b?((b&1)?a*qpow(a*a%MOD,b>>1)%MOD:qpow(a*a%MOD,b>>1))%MOD:1;}
inline ll qpow(ll a, ll b,ll c){return b?((b&1)?a*qpow(a*a%c,b>>1,c)%c:qpow(a*a%c,b>>1,c)) %c:1;}
inline ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
inline ll cede(ll a,ll b){if(b<0)return cede(-a,-b);if(a<0)return a/b;return (a+b-1)/b;}
inline ll flde(ll a,ll b){if(b<0)return flde(-a,-b);if(a<0)return (a-b+1)/b;return a/b;}
inline int sign(db x){return x<-EPS ? -1:x>EPS;}
inline int dbcmp(db l,db r){return sign(l - r);}
namespace Fast_IO{ //orz laofu
    const int MAXL((1 << 18) + 1);int iof, iotp;
    char ioif[MAXL], *ioiS, *ioiT, ioof[MAXL],*iooS=ioof,*iooT=ioof+MAXL-1,ioc,iost[55];
    char Getchar(){
        if (ioiS == ioiT){
            ioiS=ioif;ioiT=ioiS+fread(ioif,1,MAXL,stdin);return (ioiS == ioiT ? EOF : *ioiS++);
        }else return (*ioiS++);
    }
    void Write(){fwrite(ioof,1,iooS-ioof,stdout);iooS=ioof;}
    void Putchar(char x){*iooS++ = x;if (iooS == iooT)Write();}
    inline int read(){
        int x=0;for(iof=1,ioc=Getchar();(ioc<'0'||ioc>'9')&&ioc!=EOF;)iof=ioc=='-'?-1:1,ioc=Getchar();
        if(ioc==EOF)Write(),exit(0);
        for(x=0;ioc<='9'&&ioc>='0';ioc=Getchar())x=(x<<3)+(x<<1)+(ioc^48);return x*iof;
    }
    inline long long read_ll(){
        long long x=0;for(iof=1,ioc=Getchar();(ioc<'0'||ioc>'9')&&ioc!=EOF;)iof=ioc=='-'?-1:1,ioc=Getchar();
        if(ioc==EOF)Write(),exit(0);
        for(x=0;ioc<='9'&&ioc>='0';ioc=Getchar())x=(x<<3)+(x<<1)+(ioc^48);return x*iof;
    }
    void Getstr(char *s, int &l){// isgraph || isalnum || iscntrl || isblank
        for(ioc=Getchar();ioc!=EOF&&!isgraph(ioc);)ioc=Getchar();
        if(ioc==EOF)Write(),exit(0);
        for(l=0;isgraph(ioc);ioc=Getchar())s[l++]=ioc;s[l] = 0;
    }
    template <class Int>void Print(Int x, char ch = '\0'){
        if(!x)Putchar('0');if(x<0)Putchar('-'),x=-x;while(x)iost[++iotp]=x%10+'0',x/=10;
        while(iotp)Putchar(iost[iotp--]);if (ch)Putchar(ch);
    }
    void Putstr(const char *s){for(int i=0;s[i];++i)Putchar(s[i]);}
} // namespace Fast_IO
using namespace Fast_IO;

typedef int TP;
struct SegTree
{
#define nd snode[now]
#define lson (now<<1)
#define rson (now<<1|1)
#define lc snode[lson]
#define rc snode[rson]
#define mid (nd.l+nd.r>>1)
#define MAXS 800005
    struct SegNode
    {
        int l,r;
        TP minv,maxv,sum,add,cov,mul;
        int len(){return r-l+1;}
    }snode[MAXS];
    void Build(int n){build(1,1,n);}
    void Build(int n,TP *A){build(1,1,n,A);}
    void pushup(int now){
        nd.minv=min(lc.minv,rc.minv);
        nd.maxv=max(lc.maxv,rc.maxv);
        nd.sum=lc.sum+rc.sum;
    }
    void pushflg(int now,TP cov,TP mul,TP add){
        if(cov!=-1)
        {
            nd.cov=cov;
            nd.mul=1;nd.add=0;
            nd.minv=nd.maxv=cov;
            nd.sum=cov*nd.len();
        }
        if(mul!=1)
        {
            nd.mul=nd.mul*mul;
            nd.add=nd.add*mul;
            nd.minv=nd.minv*mul;
            nd.maxv=nd.maxv*mul;
            nd.sum=nd.sum*mul;
        }
        if(add)
        {
            nd.add=(nd.add+add);
            nd.minv=(nd.minv+add);
            nd.maxv=(nd.maxv+add);
            nd.sum=nd.sum+add*nd.len();
        }
    }
    void pushdown(int now){
        pushflg(lson,nd.cov,nd.mul,nd.add);
        pushflg(rson,nd.cov,nd.mul,nd.add);
        nd.cov=-1;nd.mul=1;nd.add=0;
    }
    void build(int now,int l,int r){
        nd.l=l;nd.r=r;nd.add=0;nd.mul=1;nd.cov=-1;
        if(l==r)
        {
            nd.minv=nd.maxv=nd.sum=1;
            return;
        }
        build(lson,l,mid);build(rson,mid+1,r);
        pushup(now);
    }
    void build(int now,int l,int r,TP *A){
        nd.l=l;nd.r=r;nd.add=0;nd.mul=1;nd.cov=-1;
        if(l==r)
        {
            nd.minv=nd.maxv=nd.sum=A[l];
            return;
        }
        build(lson,l,mid,A);build(rson,mid+1,r,A);
        pushup(now);
    }
    void Add_update(int L,int R,TP val){
   // printf("ADD %d %d %d\n",L,R,val);
    add_update(1,L,R,val);}
    void add_update(int now,int L,int R,TP val){
        if(L<=nd.l&&nd.r<=R)
        {
            pushflg(now,-1,1,val);
            return ;
        }
        pushdown(now);
        if(L<=mid)add_update(lson,L,R,val);
        if(R>mid)add_update(rson,L,R,val);
        pushup(now);
    }
    void Mul_update(int L,int R,TP val){mul_update(1,L,R,val);}
    void mul_update(int now,int L,int R,TP val){
        if(L<=nd.l&&nd.r<=R)
        {
            pushflg(now,-1,val,0);
            return;
        }
        pushdown(now);
        if(L<=mid)mul_update(lson,L,R,val);
        if(R>mid)mul_update(rson,L,R,val);
        pushup(now);
    }
    void Cov_update(int L,int R,TP val){cov_update(1,L,R,val);}
    void cov_update(int now,int L,int R,TP val){
        if(L<=nd.l&&nd.r<=R)
        {
            pushflg(now,val,1,0);
            return ;
        }
        pushdown(now);
        if(L<=mid)cov_update(lson,L,R,val);
        if(R>mid)cov_update(rson,L,R,val);
        pushup(now);
    }
    TP Min_query(int L,int R){return min_query(1,L,R);}
    TP min_query(int now,int L,int R){
        if(L<=nd.l&&nd.r<=R)return nd.minv;pushdown(now);
        if(R<=mid)return min_query(lson,L,R);
        else if(L>mid) return min_query(rson,L,R);
        else return min(min_query(lson,L,R),min_query(rson,L,R));
    }
    TP Max_query(int L,int R){return max_query(1,L,R);}
    TP max_query(int now,int L,int R){
        if(L<=nd.l&&nd.r<=R)return nd.maxv;pushdown(now);
        if(R<=mid)return max_query(lson,L,R);
        else if(L>mid) return max_query(rson,L,R);
        else return max(max_query(lson,L,R),max_query(rson,L,R));
    }
    TP Sum_query(int L,int R){return sum_query(1,L,R);}
    TP sum_query(int now,int L,int R){
        if(L>R)return 0;
        if(L<=nd.l&&nd.r<=R)return nd.sum;pushdown(now);
        if(R<=mid)return sum_query(lson,L,R);
        else if(L>mid) return sum_query(rson,L,R);
        else return sum_query(lson,L,R)+sum_query(rson,L,R);
    }
}ST;



int a[MAXN];
vector<int>ve[MAXN];
int lst[MAXN],nxt[MAXN];
void work()
{
    int n=read();
    for(int i=1;i<=n;i++)a[i]=read();
    memset(lst,-1,sizeof lst);
    for(int i=1;i<=n;i++)
    {
        nxt[i]=lst[a[i]];
        if(lst[a[i]]!=-1)ve[i].push_back(lst[a[i]]);
        lst[a[i]]=i;
    }
    ST.build(1,1,n);
    ll ans=0;
    for(int i=1;i<=n;i++)
    {
        for(auto v:ve[i])ST.Add_update(v,v,-1);
        ans+=ST.Sum_query(max(0,nxt[i])+1,i-1);
        //printf("%d ",nxt[i]);
       // printf("%lld\n",ans);
    }
    printf("%lld\n",ans);
    

}
int main()
{
   // init();
    //std::ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  //  int T=read();for(int cas=1;cas<=T;cas++)
    //int T;scanf("%d",&T);for(int i=1;i<=T;i++)
    work();
    // Write();
}
