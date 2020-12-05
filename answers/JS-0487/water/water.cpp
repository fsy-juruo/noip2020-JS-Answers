#include<bits/stdc++.h>
using namespace std;
int n,m;
int d[100005],g[100005][6];
long long p[100005],q[100005];
long long gcd(long long a,long long b)
{
	if(a%b==0) return b;
	return gcd(b,a%b);
}
void xj(int x,int y)
{
	p[y]=p[y]*q[x]+p[x]*q[y];
	q[y]*=q[x];
	long long a2=gcd(p[y],q[y]);
	p[y]/=a2;
	q[y]/=a2;
}
int main()
{
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&d[i]);
		for(int j=1;j<=d[i];j++)
		{
			scanf("%d",&g[i][j]);
		}
		if(i<=m) p[i]=1;
		q[i]=1;
	}
	
	for(int i=1;i<=n;i++)
	{
		if(d[i]==0) 
		{
			printf("%lld %lld\n",p[i],q[i]);
			continue;
		}
		q[i]*=d[i];
		for(int j=1;j<=d[i];j++)
		{
			xj(i,g[i][j]);
		}
	}
	return 0;
}


