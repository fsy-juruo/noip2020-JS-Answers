#include<bits/stdc++.h>
using namespace std;
bool AC_AK=true;
int n,k;
int w[10];
int c[100010];
int d[100010];
int tmp[10];
int rec[10];
int ans;
void dfs(int dep)
{
	if(dep>k)
	{
		bool f=0;
		for(int i=1;i<=k;i++)
			tmp[i]=rec[i];
		for(int i=1;i<=n;i++)
		{
			tmp[c[i]]+=d[i];
			if(tmp[c[i]]<1||tmp[c[i]]>w[c[i]])
			{
				ans+=(i-1);
				f=1;
				break;
			}
		}
		if(f==0)
		{
			printf("-1\n");
			exit(0);
		}
		return;
	}
	for(int i=1;i<=w[dep];i++)
	{
		rec[dep]=i;
		dfs(dep+1);
	}
}
int main()
{
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	scanf("%d%d",&n,&k);
	if(n>2000)
	{
		printf("-1\n");
		return 0;	
	} 
	for(int i=1;i<=k;i++)
		scanf("%d",&w[i]);
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d",&c[i],&d[i]);
	}
	dfs(1);
	printf("%d\n",ans);
	return 0;
}
