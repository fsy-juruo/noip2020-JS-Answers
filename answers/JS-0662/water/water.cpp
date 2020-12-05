#include<bits/stdc++.h>
using namespace std;
unsigned long long d;
unsigned long long gcd(unsigned long long a,unsigned long long b)
{
	if (!b) return a;
	return gcd(b,a%b);
}
unsigned long long lcm(unsigned long long a,unsigned long long b)
{
	if (!a || !b) return a^b;
	return a/gcd(a,b)*b;
}
struct frac
{
	unsigned long long x,y;
	frac operator + (const frac &u) const
	{
		frac res;
		res.y=lcm(y,u.y);
		res.x=(res.y/y*x+res.y/u.y*u.x);
		d=gcd(res.y,res.x);
		res.y/=d;res.x/=d;
		return res;
	}
}dp[111111];
int n,m,k,x,y,dg[111111],ord[111111],cnt,deg[111111];
vector<int> g[111111];
void topo()
{
	queue<int> q;
	for (int i=1;i<=n;i++)
	{
		if (!deg[i]) 
		{
			q.push(i);
		}
	}
	while(!q.empty())
	{
		int x=q.front();q.pop();ord[++cnt]=x;
		for (int i=0;i<g[x].size();i++)
		{
			int to=g[x][i];
			if (!--deg[to]) q.push(to);
		}
	}
}
int main()
{
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&x);dg[i]=x;
		for (int j=1;j<=x;j++)
		{
			scanf("%d",&y);
			g[i].push_back(y);
			deg[y]++;
		}
	}
	topo();
	for (int i=1;i<=m;i++) dp[i]=(frac){1ull,1ull};
	for (int i=m+1;i<=n;i++) dp[i]=(frac){0ull,1ull};
	for (int i=1;i<=n;i++)
	{
		x=ord[i];
		if (dg[x])
		{
			d=gcd(dp[x].x,(unsigned long long)dg[x]);
			dp[x].x/=d;dp[x].y*=((unsigned long long)dg[x]/d);
		}
		for (int j=0;j<g[x].size();j++)
		{
			int to=g[x][j];
			dp[to]=dp[to]+dp[x];
		}
	}
	for (int i=1;i<=n;i++)
	{
		if (!dg[i]) 
		{
			printf("%llu %llu\n",dp[i].x,dp[i].y);
		}
	}
	return 0;
}
