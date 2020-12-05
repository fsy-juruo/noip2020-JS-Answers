#include <bits/stdc++.h>
using namespace std;
int n,m;
long long a[100005][6];
bool b[100005];
long long c[100005];
long long d[100005];
long long ans[100005];
long long e[100005];
long long gcdd(long long x,long long y)
{
	if(x==0) return y;
	if(y==0) return x;
	return gcdd(y%x,x);
}
long long maxx(long long x,long long y)
{
	if(x>y) return x;
	return y;
}
int main()
{
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	int t,x;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		c[i]=1;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&t);
		c[i]*=t;
		e[i]=t;
		if(t==0)
		{
			b[i]=true;
			continue;
		}
		else
		{
			for(int j=1;j<=t;j++)
			{
				scanf("%d",&x);
				a[x][++d[x]]=i;
				long long yh=gcdd(c[x],c[i]);
				c[x]=yh*c[x]/yh*c[i]/yh;
			}
		}
	}
	long long op=-1;
	for(int i=1;i<=n;i++)
		op=maxx(op,c[i]);
	long long akioi=op;
	ans[1]=op;
	for(int i=1;i<=n;i++)
	{
		if(b[i]==true)
		{
			long long ans1=0;
			for(int j=1;j<=d[i];j++)
				ans1+=ans[a[i][j]]/e[a[i][j]];
			long long ty=gcdd(ans1,akioi);
			cout<<ans1/ty<<" "<<akioi/ty<<endl;
		}
		else
		{
			for(int j=1;j<=d[i];j++)
				ans[i]=ans[i]+ans[a[i][j]]/e[a[i][j]];
		}
	}
	return 0;
}
