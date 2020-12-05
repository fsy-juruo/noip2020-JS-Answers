#include<bits/stdc++.h>
using namespace std;
const int N=100005;

int n,m,d[N],a[N][10],lf[N],cnt=0;
long long p[N],q[N];

long long gcd(long long x,long long y)
{
	if(x<y)swap(x,y);
	if(y==0)return x;
	return gcd(y,x%y);
}

void dfs(int x)
{
	if(d[x]==0)return;
	long long pp,qq;
	for(int i=1;i<=d[x];i++)
	{
		int u=a[x][i];
		pp=p[x];
		qq=q[x]*d[x];
		if(d[u]!=0)
		{
			p[u]=p[x];
			q[u]=q[x]*d[x];
		}
		else
		{
			p[u]=pp*q[u]+p[u]*qq;
			q[u]=qq*q[u];
		}
		long long g=gcd(p[u],q[u]);
		p[u]=p[u]/g;
		q[u]=q[u]/g;
		
		dfs(u);
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
		if(d[i]==0)
		{
			lf[++cnt]=i;
			continue;
		}
		for(int j=1;j<=d[i];j++)scanf("%d",&a[i][j]);	
	}
	memset(p,0,sizeof(p));
	for(int i=1;i<=m;i++)p[i]=1;
	for(int i=1;i<=n;i++)q[i]=1;
	
	for(int i=1;i<=m;i++)dfs(i);
	for(int i=1;i<=cnt;i++)printf("%lld %lld\n",p[lf[i]],q[lf[i]]);
	return 0;
}
