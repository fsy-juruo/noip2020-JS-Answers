#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
const int N=1e5+10;
int n,m,d[N],a[N][6];
ll p[N],q[N];
ll gcd(ll x,ll y)
{
	if(x==0) return y;
	return gcd(y%x,x);
}
void dfs(int x,ll dq)
{
	if(!d[x])
	{
		if(!q[x])
		{
			p[x]=1;
			q[x]=dq;
		}
		else
		{
			p[x]=dq*p[x]+q[x];
			q[x]*=dq;
			ll g=gcd(p[x],q[x]);
			p[x]/=g;q[x]/=g;
		}
		return;
	}
	for(int i=1;i<=d[x];i++)
	{
		dfs(a[x][i],dq*d[x]);
	}
}
int main()
{
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&d[i]);
		for(int j=1;j<=d[i];j++) scanf("%d",&a[i][j]);
	}
	for(int i=1;i<=m;i++)
	{
		dfs(i,1);
	}
	for(int i=m+1;i<=n;i++)
	{
		if(!d[i])
		{
			printf("%llu %llu\n",p[i],q[i]);
		}
	}
	return 0;
}
