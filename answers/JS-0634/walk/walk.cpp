#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;
int n,k,w[11],d[11][500001],a[11],ans,l[200001];
void dfs(int x)
{
	if(x>k)
	{
		int b[11];
		for(int i=1;i<=k;i++)
		b[i]=a[i];
		int flag=0,oo;
		while(1)
		{
			for(int p=1;p<=n;p++)
			{
				for(int i=1;i<=k;i++)
				if(b[i]+d[i][p]>w[i]||b[i]+d[i][p]<=0)
				{
					flag=1;ans+=p;
					break;
				}
				if(flag)break;
			}
			if(flag)break;
			ans+=n;
			for(int i=1;i<=k;i++)
			b[i]+=d[i][n],oo+=d[i][n];
			if(!oo)
			{
				cout<<"-1";
				k=-99;
				return;
			}
		}
	}
	for(int i=1;i<=w[x];i++)
	{
		a[x]=i;
		dfs(x+1);
	}
}
int main()
{
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=k;i++)
	cin>>w[i];
	for(int i=1;i<=n;i++)
	{
		int x,y;
		cin>>x>>y;
		for(int j=1;j<=k;j++)
		d[j][i]=d[j][i-1];
		d[x][i]+=y;
	}
	dfs(1);
	if(k)cout<<ans<<endl;
	return 0;
}
