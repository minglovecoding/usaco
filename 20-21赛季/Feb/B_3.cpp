#include<bits/stdc++.h>
using namespace std;

#define rep(i,a,n) for(int i=a;i<=n;i++)
const int mod = 1e9 + 7;
const int N = 120;

int t;
char a[1200];
int x[N],y[N];
int main()
{     
	cin >> t;
	while(t--)
	{
		cin >> a;
		int len = strlen(a)-1;
		int stx = 500, sty = 500;
		x[0] = stx;	y[0] = sty;
		for(int i = 1;i < len;i++)
		{
			if(a[i] == 'E')
			{
				x[i] = x[i-1]+1;
				y[i] = y[i-1];
			}
			if(a[i] == 'W')
			{
				x[i] = x[i-1]-1;
				y[i] = y[i-1];
			}
			if(a[i] == 'N')
			{
				x[i] = x[i-1];
				y[i] = y[i-1]+1;
			}
			if(a[i] == 'S')
			{	
				x[i] = x[i-1];
				y[i] = y[i-1]-1;
			}
		}
		double d = 0.0;
		for(int i = 0;i < len;i++)
		{
			d += x[i]*y[(i+1)%len]-x[(i+1)%len]*y[i];
		}
		if(d > 0)
			cout << "CCW" << endl;
		else
			cout << "CW" << endl;
	}
    
    return 0;
}     

