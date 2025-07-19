#include <bits/stdc++.h>
using namespace std;
vector<string>ve[5];
int main()
{
//	freopen("1.out","w",stdout); 
	int T;
	cin>>T;
	while (T--)
	{
		int n,a,b;
		cin>>n>>a>>b;
		for (int i=1;i<=4;i++) ve[i].clear();
		for (int i=1;i<=n;i++)
		{
			string s1,s2;
			cin>>s1>>s2;
			if (s2[0]=='n') ve[1].push_back(s1);
			if (s2[0]=='i') ve[2].push_back(s1);
			if (s2[0]=='t') ve[3].push_back(s1);
			if (s2[0]=='c') ve[4].push_back(s1);
		}
		int n1=ve[1].size(),n2=ve[2].size(),n3=ve[3].size(),n4=ve[4].size();
		n4=min(n4,b);
		int mx=n4*2+b-n4;
		int anss=-1;
		int i1=0,j1=0,o1=0;
		for (int i=0;i<=n3;i++) //3
		if (2*i<=n1)
		{
			int j=min({n1-2*i,n2,mx-i}); //2
			int o=min(n1-j-2*i,a);
			if (i==0) o=0;
			if (j>=0&&i+j+2*i+j+o>anss)
			{
				i1=i,j1=j,o1=o;
				anss=i+j+2*i+j+o;
			}
		}
		int now=ve[1].size(); now--;
		vector<string> ans;
		if (j1+i1*2+o1>now+1) while (1);
		for (int i=1;i<=j1;i++)
		{
			string ss=ve[1][now]; now--; 
			ss=ss+" "+ve[2][i-1];
			ans.push_back(ss);
		}
		for (int i=1;i<=i1;i++)
		{
			string s;
			string ss=ve[1][now]; now--; 
			s=ss+" "+ve[3][i-1];
			ss=ve[1][now]; now--;
			s=s+" "+ss;
			if (i==i1)
			{
				while (o1)
				{
					string ss=ve[1][now]; now--; o1--;
					s=s+", "+ss;
				}
		    }
		    ans.push_back(s);
		}
		int t=min(n4,(int)(ans.size())/2);
		cout<<anss+t<<endl;
		string ss;
		for (int i=0;i<=t-1;i++)
		{
			ss+=ans[i*2];
			ss+=" ";
			ss+=ve[4][i];
			ss+=" ";
			ss+=ans[i*2+1]+". ";
//			cout<<ans[i*2]<<" "<<ve[4][i]<<" "<<ans[i*2+1]<<". ";
		}
		for (int i=t*2;i<ans.size();i++)
		{
			ss+=ans[i]+". ";
//		  cout<<ans[i]<<". ";
		}
		int nn=max(0,(int)(ss.length())-1);
		for (int i=0;i<=nn-1;i++)
		  cout<<ss[i];
		cout<<endl;
	}
	return 0;
}
/*
1
10 5 4
bessie noun
taught transitive-verb
flew intransitive-verb
elsie noun
farmer noun
john noun
and conjunction
and conjunction
nhoj noun
mooed intransitive-verb
*/
