#include<stdio.h>
#define N 51
#define M 401
int n,m;
int a[N][M],tail[N],ans[2][10000],cnt;
bool finish()
{
	for(int i=0;i<n;++i)
	{
		if(tail[i]!=m)
			return false;
		int tmp=a[i][0];
		for(int j=1;j<tail[i];++j)
			if(a[i][j]!=tmp)
				return false;	
	}
	return true;
}
void dfs()
{
	if(cnt>=10)
		return;
	if(finish())
	{
		for(int i=0;i<cnt;++i)
			printf("%d %d\n",ans[0][i],ans[1][i]);
		cnt=1000000;
	}
	else
	{
		for(int i=0;i<=n;++i)
		{
			if(!tail[i])
				continue;
			for(int j=0;j<=n;++j)
			{
				if(i==j||tail[j]==m)
					continue;
				ans[cnt][0]=i,ans[cnt][1]=j;
				cnt++;
				tail[i]--;
				a[j][tail[j]++]=a[i][tail[i]];
				dfs();
			}
		}
	}
}
int main()
{
	freopen("ball.in","r",stdin);
	freopen("ball.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;++i)
	{
		for(int j=0;j<m;++j)
			scanf("%d",a[i]+j);
		tail[i]=m;
	}
	dfs();
	return 0;
}
