#include<bits/stdc++.h>
using namespace std;
int n,a[100005][10],m,p[100005],q[100005],d;
int inline read()
{
    int s=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9')s=s*10+ch-'0',ch=getchar();
	return s*f;
}
int gx(int z,int m)
{
	int y;
	y=m%z;
	while(y!=0)
	{
		m=z;
		z=y;
		y=m%z;
	}
	return z;
}
int main()
{
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	n=read();
	m=read();
	for(int i=1;i<=n;i++)
	p[i]=1,q[i]=1;
	for(int i=1;i<=n;i++)
	{
		d=read();
		for(int j=1;j<=d;j++)
		a[i][j]=read();
		a[i][0]=d;
	}
	int j;
	for(int i=1;i<=m;i++)
	{
		j=1;
		while(a[i][j])
		{
		    a[a[i][j]][0]*=a[i][0];
			q[a[i][j]]=a[i][0];
			j++;
		}
	}
	for(int i=m+1;i<=n;i++)
	{
		j=1;
		while(a[i][j])
		{
			a[a[i][j]][0]*=a[i][0];
		    q[a[i][j]]=a[i][0];
			j++;
		}
	}
	for(int i=1;i<=n;i++)
	{
		j=1;
		while(a[i][j])
		{
			if(a[a[i][j]][0]==0)
			{
				p[a[i][j]]+=(q[n]/a[i][0]);
			}
			j++;
		}
		if(a[i][1]==0)
		{
			int j=gx(p[i]-1,q[i]);
		    p[i]/=j;
		    q[i]/=j;
			cout<<p[i]<<" "<<q[i]<<endl;
		}
	}
	return 0;
}
