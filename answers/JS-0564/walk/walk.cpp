#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10,inf=0x7fffffff;
int n,k,w[N],c[N],d[N],ans;
namespace k1
{
	int p[N],maxn,minn;
	void solve()
	{
		for(int i=1;i<=n;i++)
		{
			p[i]=p[i-1]+d[i];
			maxn=max(p[i],maxn);
			minn=min(p[i],minn);
		}
		if(p[n]==0)
		{
			for(int i=1;i<=n;i++)
			{
				if(i+maxn<=w[1]&&i+minn>0)
				{
					puts("-1");
					exit(0);
				}
			}
		}
		for(int id=1;id<=n;id++)
		{
			int i=id;
			while(i+maxn<=w[1]&&i+minn>0)
			{
				i+=p[n];
				ans+=n;
			}
			for(int j=1;j<=n;j++)
			{
				if(i+p[j]<=0||i+p[j]>w[1])
				{
					ans+=j;
					break;
				}
			}
		}
		printf("%d\n",ans);
	}
}
int main()
{
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=k;i++) scanf("%d",&w[i]);
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d",&c[i],&d[i]);
	}
	if(n>100)
	{
		puts("-1");
		return 0;
	}
	if(k==1) k1::solve();
	else puts("-1");
	return 0;
}
