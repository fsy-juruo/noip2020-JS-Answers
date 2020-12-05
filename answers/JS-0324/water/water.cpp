#include<bits/stdc++.h>
using namespace std;
int n,m;
long long d[100001][6],wx[100001],wy[100001];
bool flag[100001];
long long gcd(long long x,long long y)
{
	if(!y)return x;
	return gcd(y,x%y);
}
void update(long long &x_1,long long &y_1,long long &x_2,long long &y_2,long long xx,long long yy)
{
	long long p;
	if(y_1!=y_2||y_1!=yy)
	{
		if(!y_2)y_2=y_1;
		else
		{
			p=y_1*y_2/gcd(y_1,y_2);
			p=yy*p/gcd(yy,p);
			x_1*=p/y_1;
			x_2*=p/y_2;
			xx*=p/yy;
			y_1=y_2=yy=p;
		}
	}
	x_1-=xx;
	x_2+=xx;
}
int main()
{
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(register int i=1;i<=m;i++)wx[i]=1;
	for(register int i=1;i<=n;++i)
	{
		scanf("%lld",&d[i][0]);
		if(!d[i][0])flag[i]=true;
		wy[i]=1;
		for(register int j=1;j<=d[i][0];++j)scanf("%lld",&d[i][j]);
	}
	for(register int i=1;i<=n;++i)
	{
		if(flag[i])continue;
		int fx=wx[i],fy=d[i][0]*wy[i];
		for(register int j=1,v;j<=d[i][0];++j)
		{
			v=d[i][j];
			update(wx[i],wy[i],wx[v],wy[v],fx,fy);
		}
	}
	for(register int i=1;i<=n;++i)
	{
		if(flag[i])
		{
			int p=gcd(wx[i],wy[i]);
			printf("%lld %lld\n",wx[i]/p,wy[i]/p);
		}
	}
	return 0;
}
