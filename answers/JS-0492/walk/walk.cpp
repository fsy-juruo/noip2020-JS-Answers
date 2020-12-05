#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const int MAXN=5e5+10,MAXK=12,MOD=1e9+7;
int n,k,w[MAXK],c[MAXN],d[MAXN],pos[MAXK],pos1[MAXK];
ll ans;
void dfs(int now)
{
	if(now==k+1)
	{
		int flag=1;
		ll cnt=0,maxstp=1;
		for(int i=1;i<=k;i++)
			pos1[i]=pos[i],maxstp*=w[i];
		while(flag)
		{
			for(int i=1;i<=n;i++)
			{
				pos1[c[i]]+=d[i],ans=(ans+1)%MOD,cnt++;
				if(cnt>maxstp)
				{
					printf("-1\n");
					exit(0);
				}
				if(pos1[c[i]]<=0 || pos1[c[i]]>w[c[i]])
				{
					flag=0;
					break;
				}
			}
		}
		return ;
	}
	for(int i=1;i<=w[now];i++)
	{
		pos[now]=i;
		dfs(now+1);
		pos[now]=0;
	}
}
int main()
{
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=k;i++)
		scanf("%d",&w[i]);
	for(int i=1;i<=n;i++)
		scanf("%d%d",&c[i],&d[i]);
	dfs(1);
	printf("%lld\n",ans);
	return 0;
}

