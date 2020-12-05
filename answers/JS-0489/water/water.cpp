#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn=1e4+5;

int last[maxn],t[maxn][maxn],d[maxn];

struct edge{
	int p;
	int q;
}ans[maxn];

int main()
{
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	int n,m,a=0;
	cin>>n>>m;
	
	memset(ans,0,sizeof(ans));
	
	for(int i=1;i<=n;i++)
	{
		cin>>d[i];
		for(int j=1;j<=d[i];j++)
		{
			cin>>t[i][j];
		}
	}
	
	ll dd=1;
	for(int i=1;i<=n;i++)
	{
		if(d[i]!=0)
			dd*=d[i];
	//		cout<<dd<<" ";
	}
	for(int i=1;i<=n;i++)
	{
		ans[i].p=dd;
	}
	ans[1].q=(dd*m);
	
//	cout<<" "<<dd<<" "<<endl;
	
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(d[i]==0)	continue;
			ans[t[i][j]].q+=ans[i].q/d[i];
		}
		if(d[i]!=0)
			ans[i].q=0;
	}
	
	for(int i=1;i<=n;i++)
	{
		if(ans[i].q)
		{
			int x=2;
			while(x<=max(ans[i].p,ans[i].q))
			{
				if(ans[i].p%x==0 && ans[i].q%x==0)
				{
					ans[i].p/=x;
					ans[i].q/=x;
				}
				else
				{
					x++;
				}
			}
			cout<<ans[i].q<<" "<<ans[i].p<<endl;
		}
	}
	
	return 0;
}
/*
5 1
3 2 3 5
2 4 5
2 5 4
0
0
*/
