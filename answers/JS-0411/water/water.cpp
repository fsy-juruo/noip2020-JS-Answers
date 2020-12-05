#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn=1e5+10;
LL p[maxn],q[maxn];
int to;
bool flg[maxn];
LL gcd(LL a,LL b)
{
	while(b!=0)
	{
		a=a%b;
		swap(a,b);
	}
	return a;
}
LL zd(LL a,LL b)
{
	return a*b/gcd(a,b);
}
int main()
{
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	int n,m,d,i;
	scanf("%d %d",&n,&m);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&d);
		if(d==0)
		flg[i]=true;
		else if(i<=m)
		{
			for(int j=1;j<=d;j++)
			{
				scanf("%d",&to);
				if(p[to]==0)
				{
					p[to]=1;
					q[to]=d;
				}
				else
				{
					LL yq=q[to];
					q[to]=zd(q[to],d);
					p[to]=q[to]/yq*p[to]+q[to]/d;
					LL gg=gcd(q[to],p[to]);
					q[to]/=gg; p[to]/=gg;
				}
			}
			q[i]=p[i]=0;
		}
		else
		{
			LL g1=gcd(p[i],d);
			p[i]/=g1;
			q[i]*=d/g1;
			for(int j=1;j<=d;j++)
			{
				scanf("%d",&to);
				if(p[to]==0 || q[to]==0)
				{
					p[to]=p[i];
					q[to]=q[i];
				}
				else
				{
					LL yq=q[to];
					q[to]=zd(q[to],q[i]);
					p[to]=q[to]/yq*p[to]+q[to]/q[i]*p[i];
					LL gg=gcd(q[to],p[to]);
					q[to]/=gg; p[to]/=gg;
				}
			}
			q[i]=p[i]=0;
		}
	}
	for(i=m+1;i<=n;i++)
	if(flg[i]==true)
	printf("%lld %lld\n",p[i],q[i]);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
