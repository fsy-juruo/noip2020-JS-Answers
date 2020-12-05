#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const int MAXN=50+5,MAXM=400+10;
int ball[MAXN][MAXM*MAXN],step[MAXN*MAXN*MAXM][2],cnt[MAXN],ans,n,m;
void output()
{
	printf("%d\n",ans);
	for(int i=1;i<=ans;i++)
		printf("%d %d\n",step[i][0],step[i][1]);
	exit(0);
}
void dfs()
{
	int flag=1;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
			if(ball[i][j]!=i)
				flag=0;
	}
	if(flag)
		output();
	for(int now=1;now<=n;now++)
	{
		int cntcol[MAXN],pos=1;
		memset(cntcol,0,sizeof(cntcol));
		while(ball[now][pos]==now)
			pos++;
		for(int i=pos;i<=m;i++)
			cntcol[ball[now][i]]++;
		for(int i=1;i<=n;i++)
		{
			if(i!=now)
			{
				for(int j=0;j<cntcol[i];j++)
				{
					int col=ball[i][cnt[i]];
					step[++ans][0]=i,step[ans][1]=n+1;
					ball[i][cnt[i]--]=0,ball[n+1][++cnt[n+1]]=col;
				}
			}
		}
		for(int i=cnt[now];i>=pos;i--)
		{
			int col=ball[now][cnt[now]];
			if(col!=now)
			{
				step[++ans][0]=now,step[ans][1]=col;
				ball[col][++cnt[col]]=col,ball[now][cnt[now]--]=0;
			}
			else
			{
				step[++ans][0]=now,step[ans][1]=n+1;
				ball[now][cnt[now]--]=0,ball[n+1][++cnt[n+1]]=col;
			}
		}
		for(int i=cnt[n+1];i>=1;i--)
		{
			int col=ball[n+1][cnt[n+1]];
			step[++ans][0]=n+1,step[ans][1]=now;
			ball[n+1][cnt[n+1]--]=0,ball[now][++cnt[now]]=col;
		}
	}
	dfs();
}
int main()
{
	freopen("ball.in","r",stdin);
	freopen("ball.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			scanf("%d",&ball[i][j]);
	for(int i=1;i<=n;i++)
		cnt[i]=m;
	dfs();
	return 0;
}
