#include<bits/stdc++.h>
#define pb push_back
using namespace std;
int T,n,res,f[100],vis[100],d[100];
char input[100010],output[100010];
vector<int>e[100];
int id(char c){return c<='Z'?c-'A'+27:c-'a'+1;}
int dfs(int u)
{
	int res=1;
	vis[u]=1;
	for(auto v:e[u])
		if(!vis[v])if(!dfs(v))res=0;
	if((!d[u])||f[u]==u)res=0;
	return res;
}
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		for(int i=1;i<=52;i++)
			f[i]=vis[i]=0;
		scanf("%s%s",input+1,output+1);
		n=strlen(input+1),res=0;
		for(int i=1;i<=n;i++)
		{
			int x=id(input[i]),y=id(output[i]);
			if(f[x]&&f[x]!=y){res=-1;break;}
			f[x]=y;
		}
		//һ����ĸֻ��ת�Ƴ�һ����ĸ�������޽� 
		if(res!=-1)
		{
			bool MID=false;
			//��û�п�����Ϊ��ת��Ŀհ���ĸ 
			//����û����Ȼ��߳���Ϊ0�ĵ� 
			for(int i=1;i<=52;i++)
				e[i].clear(),d[i]=0;
			for(int i=1;i<=52;i++)
				if(f[i])
					e[i].pb(f[i]),
					e[f[i]].pb(i),
					d[f[i]]++;
				else MID=true;
			for(int i=1;i<=52;i++)
				if(!d[i])
					MID=true;
			for(int i=1;i<=52;i++)
				if(!vis[i])
					res+=dfs(i);
			//dfs�Ҵ�����ÿ��ֻ�л��ĵ㼯��Ҫ��ת�Ƶ�Ͷ���һ�β������� 
			if(res==0||MID)
			{
				for(int i=1;i<=52;i++)
					if(f[i]!=0&&f[i]!=i)
						res++;
				//ÿ��������ı���Ҫһ�β������� 
			}
			else res=-1;
		}
		printf("%d\n",res);
	}
	return 0;
}
