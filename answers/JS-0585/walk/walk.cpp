#include<bits/stdc++.h>
using namespace std;
int n,m,w[100005],b[100005],ans=0,d[100005],f[100005],ff[100005],tt;
void dfs(int x)
{
	if(x==m+1)
	{
		for(int i=1;i<=m;i++)ff[i]=f[i];
		int i=1;
		while(1)
		{
			tt++;
			if(tt>10000000)
			{
				cout<<-1;
				return 0;
			}
			ff[b[i]]+=d[i];ans++;
			if(ff[b[i]]<1||ff[b[i]]>w[b[i]])
			{
				return;
			}
			i=i+1;
			if(i==n+1)i=1;
		}
		
	}
	for(int i=1;i<=w[x];i++)
	{
		f[x]=i;
		dfs(x+1);
	}
}
int main()
{
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++)
	{
		int k,x;
		cin>>b[i]>>d[i];
	}
	dfs(1);
	cout<<ans;
	return 0;
}
