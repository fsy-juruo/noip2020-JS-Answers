#include<iostream>
#include<cstdio>

using namespace std;
int n,k;
int w[15];
int c[100005],d[100005];
long long dis[100005];
bool flag;
long long mod=1e9+7;

void dfs(int t)
{
	if(dis[t]) return;
	int x[15];
	int p=t;
	for(int i=1;i<=k;++i)
	{
		x[i]=p%10;
		p/=10;
	}
	for(int i=1;i<=n;++i)
	{
		x[c[i]]+=d[i];
		if(x[c[i]]>w[c[i]] || x[c[i]]<1)
		{
			dis[t]=i;
			return;
		}
	}
	dis[t]=n;
	p=0;
	for(int i=k;i>=1;--i)
	{
		p*=10;
		p+=x[i];
	}
	if(p==t)
	{
		flag=true;
		return;
	}
	dfs(p);
	dis[t]+=dis[p];
}
int main()
{
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=k;++i)
	{
		scanf("%d",&w[i]);
	}
	long long ans=0;
	if(n<=100)
	{
		
		for(int i=1;i<=n;++i)
		{
			scanf("%d%d",&c[i],&d[i]);
		}
		int t=1;
		for(int i=1;i<=k;++i) t*=10;
		for(int i=1;i<t;++i)
		{
			int l[15];
			int p=i;
			for(int j=1;j<=k;++j)
			{
				l[j]=p%10;
				p/=10;
			}
			bool mark=false;
			for(int j=1;j<=k;++j)
			{
				if(l[j]>w[j]||l[j]<1) mark=true;
			}
			if(!mark)
			{
				dfs(i);
				ans+=dis[i];
				ans%=mod;
			}
		}
		if(flag) printf("-1\n");
		else printf("%lld\n",ans);
	}
	else if(k==1)
	{
			
	}
	return 0;
}
