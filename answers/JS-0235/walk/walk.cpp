#include<bits/stdc++.h>
using namespace std;
int w[11],n,sum=0,c[500001],d[500001],k;
int main()
{
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=k;i++)
		cin>>w[i];
	for(int i=1;i<=n;i++)
		cin>>c[i]>>d[i];
	if(k==1)
	{
		for(int i=1;i<=w[1];i++)
		{
			int nx=i,nn=1;
			while(nx>0&&nx<=w[1])
			{
				nx+=d[nn];
				nn==n?n=1:n++;
				sum++;
				if(n==1&&nx==i)
				{
					cout<<-1;
					fclose(stdin);
					fclose(stdout);
					return 0;
				}
			}
		}
		cout<<sum;
		fclose(stdin);
		fclose(stdout);
		return 0;
	}
	if(k==2)
	{
		for(int i=1;i<=w[1];i++)
			for(int j=1;j<=w[2];j++)
			{
				int nx=i,ny=j,nn=1;
				while(nx>0&&nx<=w[1]&&ny>0&&ny<=w[2])
				{
					if(c[nn]==1)nx+=d[nn];
					else ny+=d[nn];
					nn==n?nn=1:nn++;
					sum++;
					if(n==1&&nx==i&&ny==j)
					{
						cout<<-1;
						fclose(stdin);
						fclose(stdout);
						return 0;
					}
				}
			}
		cout<<sum;
		fclose(stdin);
		fclose(stdout);
		return 0;
	}
	if(k==3)
	{
		for(int i=1;i<=w[1];i++)
			for(int j=1;j<=w[2];j++)
				for(int l=1;l<=w[3];l++)
				{
					int nx=i,ny=j,nb=l,nn=1;
					while(nx>0&&nx<=w[1]&&ny>0&&ny<=w[2]&&nb>=0&&nb<=w[3])
					{
						if(c[nn]==1)nx+=d[nn];
						else if(c[nn]==2)ny+=d[nn];
						else nb+=d[nn];
						nn==n?nn=1:nn++;
						sum++;
						if(n==1&&nx==i&&ny==j&&nb==l)
						{
							cout<<-1;
							fclose(stdin);
							fclose(stdout);
							return 0;
						}
					}
				}
		cout<<sum;
		fclose(stdin);
		fclose(stdout);
		return 0;
	}
	if(k==4)
	{
		for(int i=1;i<=w[1];i++)
			for(int j=1;j<=w[2];j++)
				for(int l=1;l<=w[3];l++)
					for(int m=1;m<=w[4];m++)
					{
						int nx=i,ny=j,nz=l,na=m,nn=1;
						while(nx>0&&nx<=w[1]&&ny>0&&ny<=w[2]&&nz>0&&nz<=w[3]&&na>0&&na<=w[4])
						{
							if(c[nn]==1)nx+=d[nn];
							else if(c[nn]==2)ny+=d[nn];
							else if(c[nn]==3)nz+=d[nn];
							else na+=d[nn];
							nn==n?nn=1:nn++;
							sum++;
							if(n==1&&nx==i&&ny==j&&nz==l&&na==m)
							{
								cout<<-1;
								fclose(stdin);
								fclose(stdout);
								return 0;
							}
						}
					}
		cout<<sum;
		fclose(stdin);
		fclose(stdout);
		return 0;
	}
	if(k==5)
	{
		for(int i=1;i<=w[1];i++)
			for(int j=1;j<=w[2];j++)
				for(int l=1;l<=w[3];l++)
					for(int m=1;m<=w[4];m++)
						for(int o=1;o<=w[5];o++)
					{
						int nx=i,ny=j,nz=l,na=m,nb=o,nn=1;
						while(nx>0&&nx<=w[1]&&ny>0&&ny<=w[2]&&nz>0&&nz<=w[3]&&na>0&&na<=w[4]&&nb>0&&nb<=w[5])
						{
							if(c[nn]==1)nx+=d[nn];
							else if(c[nn]==2)ny+=d[nn];
							else if(c[nn]==3)nz+=d[nn];
							else if(c[nn]==4)na+=d[nn];
							else nb+=d[nn];
							nn==n?nn=1:nn++;
							sum++;
							if(n==1&&nx==i&&ny==j&&nz==l&&na==m&&nb==o)
							{
								cout<<-1;
								fclose(stdin);
								fclose(stdout);
								return 0;
							}
						}
					}
		cout<<sum;
		fclose(stdin);
		fclose(stdout);
		return 0;
	}
	cout<<-1;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

