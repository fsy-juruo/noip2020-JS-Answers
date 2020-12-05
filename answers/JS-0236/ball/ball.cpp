#include<bits/stdc++.h>
using namespace std;
int m,n,flag;
int ma[505][505];
int end[105];
int count[105];
int ans[105];

int main()
{
	freopen("ball.in","r",stdin);
	freopen("ball.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		int z;
		cin>>count[i];
		for(int j=0;j<count[i];j++)
		{
			cin>>z;
			ma[z][i]=1;
		}
	}
	for(int j=1;j<=n;j++)
	{
		for(int i=1;i<=n;i++)
		{
			if(ma[j][i]==1)
			break;
			if(i==n)
			flag=j;
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(ma[j][i]==1)
			break;
			if(j==n)
			end[j]=1;
		}
	}
	for(int p=0;p<n;p++)
	{
		
	}
	return 0;
}
