#include<iostream>
#include<cstdio>

#define N 55
#define M 405

using namespace std;
int n,m;
int a[N][M];
int b[M];

int opr[1500005][2];
int cnt;

int main()
{
	freopen("ball.in","r",stdin);
	freopen("ball.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=m;++j)
		{
			scanf("%d",&a[i][j]);
		}
	}
	for(int i=1;i<n;++i)
	{
		int t=0;
		int cb=m+1;
		for(int j=m;j>=1;--j)
		{
			if(a[i][j]==i) ++t;
			else b[--cb]=a[i][j];
		}
		for(int j=1;j<=t;++j)
		{
			++cnt;
			opr[cnt][0]=i+1,opr[cnt][1]=n+1;
		}
		for(int j=m;j>=1;--j)
		{
			++cnt;
			if(a[i][j]==i) opr[cnt][0]=i,opr[cnt][1]=i+1;
			else opr[cnt][0]=i,opr[cnt][1]=n+1;
		}
		for(int j=1;j<=t;++j)
		{
			b[--cb]=i;
			++cnt;
			opr[cnt][0]=i+1,opr[cnt][1]=i;
		}
		for(int j=1;j<=m-t;++j)
		{
			++cnt;
			opr[cnt][0]=n+1,opr[cnt][1]=i;
		}
		for(int j=1;j<=t;++j)
		{
			++cnt;
			opr[cnt][0]=n+1,opr[cnt][1]=i+1;
		}
		for(int j=1;j<=m;++j) a[i][j]=b[j];
		/*************/
		for(int j=i+1;j<=n;++j)
		{
			int c=0;
			int cb=0;
			for(int k=1;k<=m;++k)
			{
				if(a[j][k]==i) ++c;
				else b[++cb]=a[j][k];
			}
			for(int k=1;k<=c;++k)
			{
				++cnt;
				opr[cnt][0]=1,opr[cnt][1]=n+1;
			}
			for(int k=m;k>=1;--k)
			{
				++cnt;
				if(a[j][k]==i) opr[cnt][0]=j,opr[cnt][1]=1;
				else opr[cnt][0]=j,opr[cnt][1]=n+1;
			}
			for(int k=1;k<=m-c;++k)
			{
				++cnt;
				opr[cnt][0]=n+1,opr[cnt][1]=j;
			}
			for(int k=1;k<=c;++k)
			{
				b[++cb]=i;
				++cnt;
				opr[cnt][0]=1,opr[cnt][1]=j;
			}
			for(int k=1;k<=c;++k)
			{
				++cnt;
				opr[cnt][0]=n+1,opr[cnt][1]=1;
			}
			for(int k=1;k<=m;++k) a[j][k]=b[k];
		}
		/*************/
		for(int j=1;j<=m-t;++j)
		{
			++cnt;
			opr[cnt][0]=i,opr[cnt][1]=n+1;
		}
		int cur=t+1;
		/***/
		for(int j=i+1;j<=n;++j)
		{
			int c=0;
			for(int k=m;k>=1;--k)
			{
				if(a[j][k]!=i) break;
				++c;
			}
			for(int k=1;k<=c;++k)
			{
				++cnt;
				opr[cnt][0]=j,opr[cnt][1]=i;
			}
			for(int k=1;k<=c;++k)
			{
				++cnt;
				opr[cnt][0]=n+1,opr[cnt][1]=j;
			}
			for(int k=m-c+1;k<=m;++k)
			{
				a[j][k]=a[i][cur];
				++cur;
			}
		}
		/***/
		for(int j=m-t+1;j<=m;++j) a[i][j]=i;
	}
	printf("%d\n",cnt);
	for(int i=1;i<=cnt;++i)
	{
		printf("%d %d\n",opr[i][0],opr[i][1]);
	}
	return 0;
}
