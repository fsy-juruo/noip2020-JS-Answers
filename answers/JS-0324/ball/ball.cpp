#include<bits/stdc++.h>
using namespace std;
int n,m,cnt,vis[55],ans[500005][2];
vector<int>vec[55];
int main()
{
	freopen("ball.in","r",stdin);
	freopen("ball.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		for(int j=1,x;j<=m;j++)
		{
			scanf("%d",&x);
			vec[i].push_back(x);
		}
	}
	for(int i=1;i<=n;i++)
	{
		while(vec[i].size()>1)
		{
			vec[n+1].push_back(vec[i].back());
			vec[i].pop_back();
			cnt++;
			ans[cnt][0]=i;
			ans[cnt][1]=n+1;
		}
	}
	for(int i=1;i<=n;i++)
	{
		int x=vec[i].back();
		if(!vis[x])vis[x]=i;
	}
	while(vec[n+1].size())
	{
		int x=vec[n+1].back();
		cnt++;
		ans[cnt][0]=n+1;
		ans[cnt][1]=vis[vec[n+1].back()];
		vec[n+1].pop_back();
	}
	printf("%d\n",cnt);
	for(int i=1;i<=cnt;i++)printf("%d %d\n",ans[i][0],ans[i][1]);
	return 0;
}
