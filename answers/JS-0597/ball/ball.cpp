#include<bits/stdc++.h>
using namespace std;	
int n,m;
int x[100][100];
int k=0;
int num(int a,int b,int c)
{
	while(x[a][b]==0)
		b--;
	int w=n,e=m;
	while(x[a][b]!=c&&x[n-c+1][e]==0)
	{
		while(x[n-c+1][e]==0)
			e--;
		if(x[a][b]!=c&&e!=m)
		{
			x[n-c+1][e]=x[a][b];
			x[a][b]=0;
			e++;
			b--;
			cout<<c<<" "<<n-c+1<<endl;
		}
	}
	while(x[a][b]==c)
	{
		x[3][++k]=c;
		x[a][b]=0;
		b--;
		cout<<a<<" "<<3<<endl;
	}
	
}
int main()
{
	freopen("ball.in","r",stdin);
	freopen("ball.out","w",stdout);

	cin>>n>>m;
	
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			cin>>x[i][j];
	int sum=0;
	for(int i=1;i<=n;i++)
		for(int j=m/2-1;j<=m;j++)
			if(x[i][j]==1)
			sum++;
			
	if(sum>=m/2+1||(x[1][m]==1&&x[2][m])==1)
	{
		while(k!=m)
		{
			
			num(1,m,1);
			num(2,m,1);
		}
	}
	else
		while(k!=m)
		{
			num(1,m,2);
			num(2,m,2);
			
		}

		
	fclose(stdin);
	fclose(stdout);

	return 0;
}

