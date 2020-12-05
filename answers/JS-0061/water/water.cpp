#include<bits/stdc++.h>
using namespace std;
int n,m,d[100001],a[100001][6],ans[100001][3];
int gy(int x,int y)
{
	int z,x1,y1;
	x1=x;
	y1=y;
	while(z!=0)
	{
		z=x1%y1;
		x1=y1;
		y1=z;
	}
	x=x/x1;
	y=y/x1;
	cout<<x<<" "<<y;
}
int main()
{
 	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(register int i=1;i<=n;++i)
	{
		scanf("%d",&d[i]);
		if (d[i]!=0)
			for(register int j=1;j<=d[i];++j)
				scanf("%d",&a[i][j]);
	}
	for(int i=1;i<=m;i++)
	{
		ans[m][1]=1;
		ans[m][2]=1;
	}
	for(register int i=1;i<=n;++i)
		if (d[i]!=0)
		{
			ans[i][2]=ans[i][2]*d[i];
			for(register int j=1;j<=d[i];++j)
			{
				if (ans[a[i][j]][1]==0)
				{
					ans[a[i][j]][1]=1;
					ans[a[i][j]][2]=ans[i][2];
				}
				else
				{
					ans[a[i][j]][1]=ans[i][1]*ans[a[i][j]][2]+ans[a[i][j]][1]*ans[i][2];
					ans[a[i][j]][2]=ans[i][2]*ans[a[i][j]][2];	
				}
			}			
		}
	for(register int i=1;i<=n;++i)
		if (d[i]==0)
		{
			gy(ans[i][1],ans[i][2]);	
			cout<<endl;		
		}
	return 0;
}

