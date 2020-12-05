#include <bits/stdc++.h>
#define MAXN 100000
#define MAXD 30
#define INF 0x7fffffff
#define MOD 1000000007
#define int long long
using namespace std;
int inline read(void)
{
	int x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}
	return x*f;
}
int head[MAXN]={0},num=0,son[MAXN]={0};
struct Edge
{
	int dis,to,next;
}edges[10000000];
int gcd(int p,int q)
{
	if(max(p,q)%min(p,q)==0)	return min(p,q);
	return gcd(max(p,q)%min(p,q),min(p,q));
}
struct Fenshu
{
	int p,q;
	void calc(void)
	{
		int x=gcd(p,q);
		p/=x;q/=x;
	}
	void clear(void)
	{
		p=0;q=1;
	}
}dp[MAXN];
void add(int x,int y)
{
	num++;
	edges[num].next=head[x];
	head[x]=num;
	edges[num].to=y;
}
void dfs(int u)
{
	int v;
	Fenshu f=dp[u],ans;f.q*=son[u];
	for(int i=head[u];i!=0;i=edges[i].next)
	{	
		v=edges[i].to;
		ans.p=f.p*dp[v].q+f.q*dp[v].p;
		ans.q=f.q*dp[v].q;
		ans.calc();
		dp[v]=ans;
		
		dfs(v);
	}
	if(son[u]!=0)
		dp[u].clear();
}
signed main()
{
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	int n,m;
	n=read(),m=read();
	int a,b;
	for(int i=1;i<=n;i++)
	{
		a=read();son[i]=a;dp[i].clear();
		for(int j=1;j<=a;j++)
		{
			b=read();
			add(i,b);
		}
	}
	for(int i=1;i<=m;i++)
	{
		dp[i].p=1;dp[i].q=1;
		dfs(i);	
	}	
	for(int i=1;i<=n;i++)
		if(son[i]==0)
			printf("%lld %lld\n",dp[i].p,dp[i].q);
	return 0;
}
