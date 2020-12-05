#include<bits/stdc++.h>
using namespace std;
const int N=5000005,mod=1e9+7;
int n,k,w[N],a[N],b[N],c[N],d[N],ans; 
void sol()
{
	for(int i=1;i<=k;i++)
		a[i]=b[i];
	while(1)
	{
		for(int i=1;i<=n;i++)
		{
			a[c[i]]+=d[i];
			ans++;
			if(a[c[i]]<=0||a[c[i]]>w[c[i]])
				return;
		}
	}
}
void dfs(int p)
{
	if(p==k+1)
	{
		sol();
		return;
	}
	for(int i=1;i<=w[p];i++)
	{
		b[p]=i;
		dfs(p+1);
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
	printf("%d\n",ans);
	return 0;
}

