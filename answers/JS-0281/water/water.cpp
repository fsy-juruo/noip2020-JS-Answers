#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<vector>
using namespace std;

int n,m,d[100010],depth;
vector<int>g[100010],ot;
pair<long long,long long>ans[100010];

long long gcd(long long x,long long y)
{
	if(x==0)
		return y;
	else 
		return gcd(y%x,x);
}

void dfs(int cur,long long x,long long y)
{
	ans[cur].first=ans[cur].first*y+ans[cur].second*x;
	ans[cur].second=ans[cur].second*y;
	long long ggcd=gcd(ans[cur].first,ans[cur].second);
	ans[cur].first=ans[cur].first/ggcd;
	ans[cur].second=ans[cur].second/ggcd;
	int ss=g[cur].size();
	if(ss==0)
		return;	
	long long xx=ans[cur].first,yy=ans[cur].second*ss;
	ans[cur]=make_pair(0,1);
	for(int i=0;i<ss;i++)
		dfs(g[cur][i],xx,yy);
}

int main()
{
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&d[i]);
		if(d[i]==0)
			ot.push_back(i);
		for(int j=0;j<d[i];j++)
		{
			int x;
			scanf("%d",&x);
			g[i].push_back(x);
		}
	}
	for(int i=0;i<100010;i++)
		ans[i]=make_pair(0,1);
	for(int i=1;i<=m;i++)
		ans[i]=make_pair(1,1);
	for(int i=1;i<=n;i++)
		if(ans[i].first!=0 && d[i]!=0)
			dfs(i,0,1);
	for(int i=0;i<ot.size();i++)
	{
		long long x=ans[ot[i]].first,y=ans[ot[i]].second;
		long long ggcd=gcd(x,y);
		cout<<x*1ll/ggcd<<' '<<y*1ll/ggcd<<endl;
	}
	return 0;
}
