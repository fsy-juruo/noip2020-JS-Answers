#include<bits/stdc++.h>
using namespace std;
const int N = 55;
const int M = 405;
const int T = 820005;
int n,m;
int sta[N][M],top[N],cnt[N][M];
int sta2[N][M],top2[N],cnt2[N][M];
int xi[T],yi[T];
int lasx,lasy;
inline bool check()
{
	for(int i=1;i<=n;++i) if(cnt[i][sta[i][top[i]]]!=m) return 0;
	return 1;
}
int main()
{
	freopen("ball.in","r",stdin);
	freopen("ball.out","w",stdout);
	srand(time(0));
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=m;++j) scanf("%d",&sta[i][j]),++cnt[i][sta[i][j]];
		top[i]=m;
	}
	memcpy(sta2,sta,sizeof(sta2)),memcpy(top2,top,sizeof(top)),memcpy(cnt2,cnt,sizeof(cnt2));
	for(int k=0;k<=820000;++k)
	{
		if(check())
		{
			printf("%d\n",k);
			for(int i=1;i<=k;++i) printf("%d %d\n",xi[i],yi[i]);
			fclose(stdin);
			fclose(stdout);
			return 0;
		}
		int x=rand()%(n+1)+1,y=rand()%(n+1)+1;
		while(x==y||cnt[x][sta2[x][top2[x]]]==m||!top2[x]||top2[y]==m||(x==lasy&&y==lasx)) x=rand()%(n+1)+1,y=rand()%(n+1)+1;
		++top2[y],++cnt2[y][sta2[x][top2[x]]],sta2[y][top2[y]]=sta2[x][top2[x]],--cnt2[x][sta2[x][top2[x]]],--top2[x];
		xi[k+1]=x,yi[k+1]=y;
		lasx=x,lasy=y;
	}
	memcpy(sta2,sta,sizeof(sta2)),memcpy(top2,top,sizeof(top)),memcpy(cnt2,cnt,sizeof(cnt2));
	for(int k=0;k<=820000;++k)
	{
		if(check())
		{
			printf("%d\n",k);
			for(int i=1;i<=k;++i) printf("%d %d\n",xi[i],yi[i]);
			fclose(stdin);
			fclose(stdout);
			return 0;
		}
		int x=rand()%(n+1)+1,y=rand()%(n+1)+1;
		while(x==y||cnt[x][sta2[x][top2[x]]]==m||!top2[x]||top2[y]==m||(x==lasy&&y==lasx)) x=rand()%(n+1)+1,y=rand()%(n+1)+1;
		++top2[y],++cnt2[y][sta2[x][top2[x]]],sta2[y][top2[y]]=sta2[x][top2[x]],--cnt2[x][sta2[x][top2[x]]],--top2[x];
		xi[k+1]=x,yi[k+1]=y;
		lasx=x,lasy=y;
	}
	memcpy(sta2,sta,sizeof(sta2)),memcpy(top2,top,sizeof(top)),memcpy(cnt2,cnt,sizeof(cnt2));
	for(int k=0;k<=820000;++k)
	{
		if(check())
		{
			printf("%d\n",k);
			for(int i=1;i<=k;++i) printf("%d %d\n",xi[i],yi[i]);
			fclose(stdin);
			fclose(stdout);
			return 0;
		}
		int x=rand()%(n+1)+1,y=rand()%(n+1)+1;
		while(x==y||cnt[x][sta2[x][top2[x]]]==m||!top2[x]||top2[y]==m||(x==lasy&&y==lasx)) x=rand()%(n+1)+1,y=rand()%(n+1)+1;
		++top2[y],++cnt2[y][sta2[x][top2[x]]],sta2[y][top2[y]]=sta2[x][top2[x]],--cnt2[x][sta2[x][top2[x]]],--top2[x];
		xi[k+1]=x,yi[k+1]=y;
		lasx=x,lasy=y;
	}
	memcpy(sta2,sta,sizeof(sta2)),memcpy(top2,top,sizeof(top)),memcpy(cnt2,cnt,sizeof(cnt2));
	for(int k=0;k<=820000;++k)
	{
		if(check())
		{
			printf("%d\n",k);
			for(int i=1;i<=k;++i) printf("%d %d\n",xi[i],yi[i]);
			fclose(stdin);
			fclose(stdout);
			return 0;
		}
		int x=rand()%(n+1)+1,y=rand()%(n+1)+1;
		while(x==y||cnt[x][sta2[x][top2[x]]]==m||!top2[x]||top2[y]==m||(x==lasy&&y==lasx)) x=rand()%(n+1)+1,y=rand()%(n+1)+1;
		++top2[y],++cnt2[y][sta2[x][top2[x]]],sta2[y][top2[y]]=sta2[x][top2[x]],--cnt2[x][sta2[x][top2[x]]],--top2[x];
		xi[k+1]=x,yi[k+1]=y;
		lasx=x,lasy=y;
	}
	return 0;
}
