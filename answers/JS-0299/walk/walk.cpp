#include<bits/stdc++.h>
using namespace std;
int n,k,a[15],c[500005],d[500005],mx[15],r[15],mn[15],p[15],tmp[15],sdfasdsgfd=2147483647;
const int mod=1000000007;
long long ans=0;
void dfs(int u)
{
	if(u==k+1)
	{
		for(int i=1;i<=k;++i)
			tmp[i]=p[i];
		sdfasdsgfd=2147483647;
		for(int i=1;i<=k;++i)
			if(r[i]>0)
				sdfasdsgfd=min(sdfasdsgfd,max((a[i]-p[i]-mx[i])/r[i],0));
			else
				if(r[i]<0)
					sdfasdsgfd=min(sdfasdsgfd,max(-(p[i]+mn[i])/r[i],0));
		if(sdfasdsgfd==2147483647)
		{
			puts("-1");
			exit(0);
		}
		ans+=(long long)n*sdfasdsgfd;
		ans%=mod;
		for(int i=1;i<=k;++i)
			p[i]+=sdfasdsgfd*r[i];
		for(int i=1;i<=n*2;++i)
		{
			p[c[(i-1)%n+1]]+=d[(i-1)%n+1];
			++ans;
			if(p[c[(i-1)%n+1]]<=0||p[c[(i-1)%n+1]]>a[c[(i-1)%n+1]])
			{
				for(int j=1;j<=k;++j)
					p[j]=tmp[j];
				return;
			}
		}
		return;
	}
	for(int i=1;i<=a[u];++i)
	{
		p[u]=i;
		dfs(u+1);
		p[u]=0;
	}
}
int main()
{
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=k;++i)
		scanf("%d",&a[i]);
	for(int i=1;i<=n;++i)
	{
		scanf("%d%d",&c[i],&d[i]);
		r[c[i]]+=d[i];
		mx[c[i]]=max(mx[c[i]],r[c[i]]),mn[c[i]]=min(mn[c[i]],r[c[i]]);
	}
	dfs(1);
	printf("%lld\n",ans%mod);
	return 0;
}
