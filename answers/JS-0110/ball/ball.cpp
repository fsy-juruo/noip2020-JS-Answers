#include<bits/stdc++.h>
using namespace std;
int n,m,a[55][405],b[900001][2],top[52],r=1;
int e(int x,int nn)
{
	for(int i=x;i>=1;i--)
	{
		if(a[nn][i]==a[3][top[3]])
		{
			return i;
		}
	}
	return 0;
}
int pan()
{
	for(int i=1;i<=n+1;i++)
	{
		if(top[i]==m)
		{
			int z=a[i][1];
			for(int j=2;j<=m;j++)
			{
				if(a[i][j]!=z) return 0;
			}
		}
	}
	return 1;
}
void huan2()
{
	if(a[1][top[1]]==a[2][top[2]-1]&&a[1][top[1]]==a[2][top[2]])
	{
		a[3][top[3]]=a[2][top[2]];
		b[r][0]=2;
		b[r][1]=3;
		r++;
		top[2]--;
		top[3]++;
	}
	else
	{
		a[3][top[3]]=a[1][top[1]];
		b[r][0]=1;
		b[r][1]=3;
		r++;
		top[1]--;
		top[3]++;
	}
	while(pan()==0)
	{
		if(a[1][top[1]]==a[3][top[3]])
		{
			a[3][top[3]+1]=a[1][top[1]];
			a[1][top[1]]=0;
			top[1]--;
			top[3]++;
			b[r][0]=1;
			b[r][1]=3;
			r++;
		}
		if(a[2][top[2]]==a[3][top[3]])
		{
			a[3][top[3]+1]=a[2][top[2]];
			a[2][top[2]]=0;
			top[2]--;
			top[3]++;
			b[r][0]=2;
			b[r][1]=3;
			r++;
		}
		if(a[1][top[1]]!=a[3][top[3]]&&a[2][top[2]]!=a[3][top[3]])
		{
			if(top[1]-e(top[1],1)<top[2]-e(top[2],2)&&top[1]!=0)
			{
				int d=e(top[1],1);
				for(int i=top[1];i>d;i--)
				{
				//	if(a[1][top[1]]==a[3][top[3]])
				//	{
						a[2][top[2]+1]=a[1][top[1]];
						a[1][top[1]]=0;
						top[1]--;
						top[2]++;
						b[r][0]=1;
						b[r][1]=2;
						r++;
				//	}
				}
			}
			else if(top[1]-e(top[1],1)>top[2]-e(top[2],2)&&top[2]!=0)
			{
				int d=e(top[2],2);
				for(int i=top[2];i>d;i--)
				{
				//	if(a[1][top[1]]==a[3][top[3]])
				//	{
						a[1][top[1]+1]=a[2][top[2]];
						a[2][top[2]]=0;
						top[2]--;
						top[1]++;
						b[r][0]=2;
						b[r][1]=1;
						r++;
				//	}
				}
			}
			else if(e(top[1],1)==0&&e(top[2],2)==0)
			{
				int d=e(top[2],2);
				for(int i=top[2];i>d;i--)
				{
				//	if(a[1][top[1]]==a[3][top[3]])
				//	{
						a[1][top[1]+1]=a[2][top[2]];
						a[2][top[2]]=0;
						top[2]--;
						top[1]++;
						b[r][0]=2;
						b[r][1]=1;
						r++;
				//	}
				}
			}
		}
	}
}
int main()
{
	freopen("ball.in","r",stdin);
	freopen("ball.in","w",stdout);
	scanf("%d%d",&n,&m);
	memset(a,0,sizeof(a));
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			scanf("%d",&a[i][j]);
		}
	}
	for(int i=1;i<=n;i++)
	{
		top[i]=m;
	}
	top[n+1]=0;
	huan2();
	printf("%d\n",r-1);
	for(int i=1;i<r;i++)
	{
		printf("%d %d\n",b[i][0],b[i][1]);
	}
	return 0;
}
