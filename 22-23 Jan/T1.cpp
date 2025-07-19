#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef long long LL;
const int inf =2e18;
const int maxn=210000;
int len[maxn],id[maxn];
vector<int> ve[maxn];
char c[maxn];
string s[maxn];
int l,r,n;
int Now[26];

int a[200005];
struct Tr
{
    int l,r;
    int mxa,lmxa,mxb,cnt;
    int mxadd,nmxadd,mxmx,nmxmx;
    LL sum;
}tr[400005];
void pushup(int p)
{
    tr[p].mxa=max(tr[p<<1].mxa,tr[p<<1|1].mxa);
    tr[p].mxb=max(tr[p<<1].mxb,tr[p<<1|1].mxb);
    tr[p].sum=tr[p<<1].sum+tr[p<<1|1].sum;
    if(tr[p<<1].mxa==tr[p<<1|1].mxa)
        tr[p].lmxa=max(tr[p<<1].lmxa,tr[p<<1|1].lmxa),
        tr[p].cnt=tr[p<<1].cnt+tr[p<<1|1].cnt;
    else if(tr[p<<1].mxa>tr[p<<1|1].mxa)
        tr[p].lmxa=max(tr[p<<1].lmxa,tr[p<<1|1].mxa),
        tr[p].cnt=tr[p<<1].cnt;
    else
        tr[p].lmxa=max(tr[p<<1|1].lmxa,tr[p<<1].mxa),
        tr[p].cnt=tr[p<<1|1].cnt;
}
void change(int k1,int k2,int k3,int k4,int p)
{
    tr[p].sum+=1ll*k1*tr[p].cnt+1ll*k2*(tr[p].r-tr[p].l+1-tr[p].cnt);
    tr[p].mxb=max(tr[p].mxb,tr[p].mxa+k3);
    tr[p].mxa+=k1;
    if(tr[p].lmxa!=-inf)tr[p].lmxa+=k2;
    tr[p].mxmx=max(tr[p].mxmx,tr[p].mxadd+k3);
    tr[p].nmxmx=max(tr[p].nmxmx,tr[p].nmxadd+k4);
    tr[p].mxadd+=k1;
    tr[p].nmxadd+=k2;
}
void pushdown(int p)
{
    int mx=max(tr[p<<1].mxa,tr[p<<1|1].mxa);
    if(mx==tr[p<<1].mxa)
        change(tr[p].mxadd,tr[p].nmxadd,tr[p].mxmx,tr[p].nmxmx,p<<1);
    else
        change(tr[p].nmxadd,tr[p].nmxadd,tr[p].nmxmx,tr[p].nmxmx,p<<1);
    if(mx==tr[p<<1|1].mxa)
        change(tr[p].mxadd,tr[p].nmxadd,tr[p].mxmx,tr[p].nmxmx,p<<1|1);
    else
        change(tr[p].nmxadd,tr[p].nmxadd,tr[p].nmxmx,tr[p].nmxmx,p<<1|1);
    tr[p].mxadd=tr[p].nmxadd=tr[p].mxmx=tr[p].nmxmx=0;
}
void build(int p,int l,int r)
{
    tr[p]={l,r};
    if(l==r)
    {
        tr[p].sum=tr[p].mxa=tr[p].mxb=a[l];
        tr[p].cnt=1;
        tr[p].lmxa=-inf;
        return ;
    }
    int mid=l+r>>1;
    build(p<<1,l,mid),build(p<<1|1,mid+1,r);
    pushup(p);
}
void modify_add(int p,int l,int r,int k)
{
    if(l<=tr[p].l&&tr[p].r<=r)
    {
        tr[p].sum+=1ll*k*(tr[p].r-tr[p].l+1);
        tr[p].mxa+=k;
        tr[p].mxb=max(tr[p].mxb,tr[p].mxa);
        if(tr[p].lmxa!=-inf)tr[p].lmxa+=k;
        tr[p].mxadd+=k;
        tr[p].nmxadd+=k;
        tr[p].mxmx=max(tr[p].mxmx,tr[p].mxadd);
        tr[p].nmxmx=max(tr[p].nmxmx,tr[p].nmxadd);
        return ;
    }
    pushdown(p);
    int mid=tr[p].l+tr[p].r>>1;
    if(l<=mid)
        modify_add(p<<1,l,r,k);
    if(r>mid)
        modify_add(p<<1|1,l,r,k);
    pushup(p);
}
void modify_min(int p,int l,int r,int v)
{
    if(tr[p].mxa<=v)return ;
    if(l<=tr[p].l&&tr[p].r<=r&&tr[p].lmxa<v)
    {
        int t=v-tr[p].mxa;
        tr[p].sum+=1ll*t*tr[p].cnt;
        tr[p].mxadd+=t;
        tr[p].mxa=v;    
        return ;
    }
    pushdown(p);
    int mid=tr[p].l+tr[p].r>>1;
    if(l<=mid)
        modify_min(p<<1,l,r,v);
    if(r>mid)
        modify_min(p<<1|1,l,r,v);
    pushup(p);
}
LL ask_sum(int p,int l,int r)
{
    if(l<=tr[p].l&&tr[p].r<=r)return tr[p].sum;
    LL res=0;
    int mid=tr[p].l+tr[p].r>>1;
    pushdown(p);
    if(l<=mid)res+=ask_sum(p<<1,l,r);
    if(r>mid)res+=ask_sum(p<<1|1,l,r);
    return res;
}
int ask_maxa(int p,int l,int r)
{
    if(l<=tr[p].l&&tr[p].r<=r)return tr[p].mxa;
    int res=-inf;
    int mid=tr[p].l+tr[p].r>>1;
    pushdown(p);
    if(l<=mid)res=max(res,ask_maxa(p<<1,l,r));
    if(r>mid)res=max(res,ask_maxa(p<<1|1,l,r));
    return res;
}
int ask_maxb(int p,int l,int r)
{
    if(l<=tr[p].l&&tr[p].r<=r)return tr[p].mxb;
    int res=-inf;
    int mid=tr[p].l+tr[p].r>>1;
    pushdown(p);
    if(l<=mid)res=max(res,ask_maxb(p<<1,l,r));
    if(r>mid)res=max(res,ask_maxb(p<<1|1,l,r));
    return res;
}
int re=0;
void dfs(int x,int &now){
    if(ve[x].size()==0){
        cout<<c[x];
        now++;
        re+=now;
        if(now==r)exit(0);
        return;
    }
    for(auto &it:ve[x]){
        if(now+len[it]<l){
            now+=len[it];
            continue;
        }
        dfs(it,now);
    }
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    build(1,1,20000);
    cin>>l>>r>>n;
    re=0;
    for(int i=1;i<=n;i++){
        cin>>c[i]>>s[i];
        if(i<=15000){
            re+=ask_sum(1,1,i+2);
        }
        id[i]=i;
    }
    for(int i=1;i<=26;i++){
        s[n+i].push_back((char)('a'+i-1));
        len[n+i]=1;
        Now[i-1]=n+i;
        if(i<=13000){
            re+=ask_sum(1,1,i+3);
        }
        c[n+i]=(char)('a'+i-1);
        id[i+n]=i+n;
    }
    for(int i=n;i>=1;i--){
        if(i<=13000){
            re+=ask_sum(1,1,i+3);
        }
        for(auto &it:s[i]){
            ve[i].push_back(id[Now[it-'a']]);
            len[i]+=len[id[Now[it-'a']]];
            if(len[i]>inf)len[i]=inf;
        }
        if(s[i].length()==1){
            id[i]=id[Now[s[i][0]-'a']];
        }
        Now[c[i]-'a']=i;
        re+=i;
    }
    ve[0].push_back(id[Now[0]]);
    int now=0;
    dfs(0,now);
    return 0;
}
