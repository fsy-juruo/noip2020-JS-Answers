#include <bits/stdc++.h>
#define re register
#define SIZE 500005
#define LL long long
#define MOD 1000000007
#define INF 0x3f3f3f3f
#define mp make_pair
#define F first
#define S second
using namespace std;
template <typename T>
inline void read(T &x)
{
	int f;char c;
	x=0;f=0;c=getchar();
	while(c<'0' || '9'<c)	f|=(c=='-'),c=getchar();
	while('0'<=c && c<='9')	x=(x<<3)+(x<<1)+c-48,c=getchar();
	x=f?-x:x;
}
int n,k;
int w[15];
int c[SIZE],d[SIZE];
int move[SIZE];
int s[SIZE],now[SIZE];
int ans=0;
int Left[5][SIZE<<1],Right[5][SIZE<<1];
int lmax[5],rmax[5];
int Key[SIZE<<1],ANS[SIZE<<1];
inline bool isok()
{
	for(re int i=1;i<=k;++i)
		if(move[i])
			return true;
	return false;
}
inline bool isin(int de,int t)
{
	if(t<=0 || t>w[de])
		return false;
	return true;
}
inline void dfs()
{
	while(1)
		for(re int i=1;i<=n;++i)
		{
			now[c[i]]+=d[i];
			++ans;
			if(!isin(c[i],now[c[i]]))
				return;
		}
}
inline void dfs_start(int de)
{
	if(de>k)
	{
		for(re int i=1;i<de;++i)
			now[i]=s[i];
		dfs();
	}
	for(re int i=1;i<=w[de];++i)
		s[de]=i,dfs_start(de+1);
}
inline void DFS(int now)
{
	if(!Key[now])
		return;
	DFS(Key[now]);
	ANS[now]=(ANS[Key[now]]+n)%MOD;
	Key[now]=0;
}
int main()
{
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	read(n);read(k);
	for(re int i=1;i<=k;++i)
		read(w[i]);
	for(re int i=1;i<=n;++i)
		read(c[i]),read(d[i]),move[c[i]]+=d[i];
	if(!isok())
	{
		printf("-1\n");
		return 0;
	}
	if(k<=1)
	{
		int now=0;
		lmax[1]=rmax[1]=0;
		memset(Left,INF,sizeof(Left));
		memset(Right,INF,sizeof(Right));
		Left[1][0]=Right[1][0]=0;
		for(re int i=1;i<=n;++i)
		{
			now+=d[i];
			if(now<lmax[1])
				Left[1][-now]=i,lmax[1]=now;
			if(now>rmax[1])
				Right[1][now]=i,rmax[1]=now;
		}
		for(re int i=1;i<=w[1];++i)
		{
			int L=i-1+1,R=w[1]-i+1;
			int lim=min(Left[1][L],Right[1][R]);
			if(lim==INF)
				Key[i]=i+move[1];
			else
				ANS[i]=lim%MOD;
		}
		for(re int i=1;i<=w[1];++i)
			if(Key[i]!=0)
				DFS(i);
		for(re int i=1;i<=w[1];++i)
			ans=(ans+ANS[i])%MOD;
		printf("%d\n",ans);
		return 0;
	}
	dfs_start(1);
	printf("%d\n",ans%MOD);
	return 0;
}
