#include<bits/stdc++.h>
using namespace std;
int n,m;
int g[10005][10];
long long a[10005][5];
long long a3,b3;
void zhi()
{
	int k=2;
	while(1)
	{
		if(k>a3||k>b3)  return;
		if(a3%k==0&&b3%k==0)
		{
			a3/=k;
			b3/=k;
		}
		else
		{
			k++;
		}
	}
	return;
}
void plu(long long a1,long long b1,long long a2,long long b2)
{
	a3=a1*b2+a2*b1;
	b3=b1*b2;
	if(a3>=200000||b3>=200000)
	{
		zhi();
	}
	return;
}
void dfs(int point,int left)//剩余污水：1/left 
{
	if(g[point][0]==-1)
	{
		plu(a[point][1],a[point][2],1,left);
		a[point][1]=a3;
		a[point][2]=b3;
	}
	else
	{
		left*=g[point][0];
		for(int i=1;i<=g[point][0];i++)
		{
			dfs(g[point][i],left);
			
		}
	}
	return;
}
int main()
{
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	std::ios::sync_with_stdio(false);
	cin>>n>>m;
	memset(g,0,sizeof(g));
	for(int i=1;i<=n;i++)
	{
		int k;
		cin>>k;
		if(k==0)
		{
			g[i][0]=-1;//g[i][0]表示排水管数目,g[i][x]=1 i->x;
			a[i][2]=1;
			a[i][1]=0; 
			continue;
		}
		g[i][0]=k;
		for(int j=1;j<=k;j++)
		{
			int x;
			cin>>x;
			g[i][j]=x;////
		}
		
	}
	
	for(int i=1;i<=m;i++)
	{
		dfs(i,1);
	}
	
	for(int i=1;i<=n;i++)
	{
		if(g[i][0]==-1)
		{
			a3=a[i][1];
			b3=a[i][2];
			zhi();
			cout<<a3<<" "<<b3<<"\n";
		}
	}
	return 0;
}
