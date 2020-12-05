#include<bits/stdc++.h>
using namespace std;
int n,m,tot=0,a[50][500]={0},k[820000][2]={0},ans=0;
bool p=0;
void dfs(int x)
{
	if(p==1)
	return ;
	bool ppp=0;
	for(int i=1;i<=n+1;i++)
	{
		if(ppp==1)
		{
			break;
		}
		for(int j=2;j<=m;j++)
		{
			if(a[i][j]!=a[i][j-1])
			{
				ppp=1;
				break;
			}
			else if(i==n&&j==m)
			{
				p=1;
				ans=x;
				return ;
			}
		}
	}
	for(int i=1;i<=n+1;i++)
	{
		for(int j=1;j<=n+1;j++)
		{
			if(a[j][0]<m&&a[i][0]>0&&i!=j)
			{
				k[x][0]=i;
				k[x][1]=j;
				a[j][++a[j][0]]=a[i][a[i][0]];
				a[i][a[i][0]]=0;
				a[i][0]--;
				dfs(x+1);
				if(p==1)
	            return ;
	            a[i][++a[i][0]]=a[j][a[j][0]];
				a[j][a[j][0]]=0;
				a[j][0]--;
			}
		}
	}
	return ;
}
int main()
{
	freopen("ball.in","r",stdin);
	freopen("ball.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	for(int j=1;j<=m;j++)
	{
		cin>>a[i][j];
	}
	for(int i=1;i<=n;i++)
	a[i][0]=m;
	dfs(0);
	cout<<ans<<endl;
	for(int i=1;i<=ans;i++)
	{
		cout<<k[i][0]<<" "<<k[i][1]<<endl;
	}
	return 0;
}
