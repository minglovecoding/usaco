#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define inf 0x3f3f3f3f
vector<int>v[100005];
map<int,int>mp1,mp2;
int a[200005],b[200005],c[200005],ans[100005],k[100005];
void dfs(int x,int pre){
    for(auto to:v[x])if(to!=pre){
        if(ans[to]==inf)ans[to]=ans[x];
        else break;
        dfs(to,x);
    }
    return ;
}
int main(){
    int n,q;
    scanf("%d%d",&n,&q);
    int cnt=0;
    for(int i=1;i<=n;i++)k[i]=inf,c[i]=inf,ans[i]=inf;
    for(int i=1;i<=q;i++){
    	char op;
    	scanf(" %c",&op);
    	if(op=='D'){
    		int x;
    		scanf("%d",&x);
            k[x]=i;
            mp1[i]=x;
		}else if(op=='A'){
            cnt++;
			scanf("%d%d",&a[cnt],&b[cnt]);
		}else{
			int x;
			scanf("%d",&x);
            c[x]=i;
            mp2[i]=x;
		}
	}
    for(int i=1;i<=cnt;i++)if(c[i]==inf){
        v[a[i]].push_back(b[i]);
        v[b[i]].push_back(a[i]);
    }
    for(int i=1;i<=n;i++)if(k[i]==inf){
        ans[i]=q;
        dfs(i,0);
    }
    for(int i=q;i>0;i--){
        if(mp1[i]){
            if(ans[mp1[i]]==inf){
                ans[mp1[i]]=i-1;
                dfs(mp1[i],0);
            }
        }else if(mp2[i]){
            v[a[mp2[i]]].push_back(b[mp2[i]]);
            v[b[mp2[i]]].push_back(a[mp2[i]]);
            if(ans[a[mp2[i]]]!=inf&&ans[b[mp2[i]]]==inf){
                ans[b[mp2[i]]]=i-1;
                dfs(b[mp2[i]],0);
            }else if(ans[b[mp2[i]]]!=inf&&ans[a[mp2[i]]]==inf){
                ans[a[mp2[i]]]=i-1;
                dfs(a[mp2[i]],0);
            }
        }
    }
    for(int i=1;i<=n;i++)printf("%d\n",min(ans[i],q));
    return 0;
}