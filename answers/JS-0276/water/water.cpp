#include<bits/stdc++.h>
using namespace std;
int n,m,t,x,d[100005];
long long p[100005],q[100005];
vector<int> v[100005],g,s[100005];
long long gcd(long long x,long long y)
{
	long long z=x%y;
	while(z>0)
	{
		x=y;y=z;z=x%y;
	}
	return y;
}
void dfs(int x)
{
	long long y=0,z=0;
	if(p[x]) return;
	for(int i=0;i<s[x].size();i++)
	{
		dfs(s[x][i]);
		y=gcd(q[s[x][i]]*d[s[x][i]],q[x]);
		z=q[s[x][i]]*d[s[x][i]]*q[x]/y;
		p[x]=p[s[x][i]]*z/(q[s[x][i]]*d[s[x][i]])+p[x]*z/q[x];
		q[x]=z;
		y=gcd(p[x],q[x]);
		p[x]/=y;
		q[x]/=y;
	}
}
int main()
{
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&d[i]);
		for(int j=1;j<=d[i];j++)
		{
			scanf("%d",&x);
			v[i].push_back(x);
			s[x].push_back(i);
		}
		if(d[i]==0) g.push_back(i);
	}
	for(int i=1;i<=n;i++)
	{
		q[i]=1;
		if(s[i].size()==0) p[i]=1;
	}
	for(int i=0;i<g.size();i++)
	{
		dfs(g[i]);
		printf("%lld %lld\n",p[g[i]],q[g[i]]);
	}
	return 0;
}
