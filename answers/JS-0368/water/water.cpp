#include<bits/stdc++.h>
using namespace std;
int m,n;
bool bo[1002][1002];
int nu[1005];
int a[1005],head=1,tail=1;
long c[1005][2];
int gcd(int a,int b)
{
	if(b==0)
	{
		return a;
	}else
	return gcd(b,a%b);
	
}
void add(int i,int j)
{
	long ai=c[i][1]*nu[i];
	long aj=c[j][1];
	long y=gcd(ai,aj);
	y=ai*aj/y;
	c[j][0]*=y/aj;c[j][1]=y;
	c[j][0]+=c[i][0]*y/ai;
	
	y=gcd(c[j][0],c[j][1]);
	c[j][0]/=y;
	c[j][1]/=y;
}
int main()
{
	
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	cin>>n>>m;int x;
	for(int i=1;i<=n;i++)
	{
		c[i][1]=1;	
	}
	for(int i=1;i<=m;i++)
	{
		c[i][0]=1;
		c[i][1]=1;	
	}
	
	for(int i=1;i<=n;i++)	
	{
		cin>>nu[i];
		for(int j=1;j<=nu[i];j++)
		{
			cin>>x;
			bo[i][x]=1;
			
		}
	}
	for(int i=1;i<=m;i++)
	{
		head=1;tail=1;
		a[1]=i;
		int h;
		while(head<=tail)
		{
			h=a[head];head++;
			if(nu[h]!=0)
			{
				for(int j=1;j<=n;j++)
				{
				if(bo[h][j])
				{
					a[++tail]=j;
					add(h,j);
				}
				}
				c[h][0]=0;c[h][1]=1;
			}
			
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(nu[i]==0)
		{
			cout<<c[i][0]<<" "<<c[i][1]<<endl;
		}
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
