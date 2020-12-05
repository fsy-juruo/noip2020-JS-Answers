#include <bits/stdc++.h>
using namespace std;
const int maxn = 5;
const int mod = 1e9 + 7;
int w[maxn];
int now[maxn];
int c[105],d[105];
int ans = 0;
int b[maxn];
int vis[1500][105];
int n,k;
int check()
{
	for(int i = 1;i <= k; ++i)
	{
		b[i] = now[i];
//		printf("%d,",now[i]);
	}
//	printf("\n");
	int now = 0,ret = 0;
	memset(vis,0x00,sizeof(vis));
	while(1)
	{
		++now;
		if(now == n + 1)
		{
			now = 1;
		}
		b[c[now]] += d[now];
		ret++;
		if(b[c[now]] < 1 || b[c[now]] > w[c[now]])
		{
			return ret;
		}
//			for(int i = 1;i <= k; ++i)
//	{
////		b[i] = now[i];
//		printf("%d,",b[i]);
//	}
//	printf("\n");
	}
	return -1;
}
int fg = 1;
void dfs(int j)
{
	if(j == k + 1)
	{
		int p = check();
		(ans += p) %= mod;
		return;
	}
	for(int i = 1;i <= w[j]; ++i)
	{
		now[j] = i;
		dfs(j + 1);
	}
}
int main()
{
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i = 1;i <= k; ++i)
	{
		scanf("%d",&w[i]);
	}
	for(int i = 1;i <= n; ++i)
	{
		scanf("%d%d",&c[i],&d[i]);
	}
	if(n > 100)
	{
		printf("-1\n");
		return 0;
	}
	dfs(1);
	printf("%d\n",ans);
	
	return 0;
}
