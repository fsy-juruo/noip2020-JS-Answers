#include<bits/stdc++.h>
using namespace std;
int n,m;
const int maxn=1e5+1;
struct edge
{
	int next,to;
} e[5*maxn];
int head[maxn];
int cnt;
int sum[maxn];
bool vis[maxn];
pair<long long,long long> ans[maxn];
void add_edge(int from,int to)
{
	e[++cnt].to=to;
	e[cnt].next=head[from];
	head[from]=cnt;
}
long long gcd(long long x,long long y)
{
	if(y==0)
	{
		return x;
	}
	gcd(y,x%y);
}
void clj(long long x,long long y ,int s)
{
	long long x2=ans[s].first;
	long long y2=ans[s].second;
	if(x2==0&&y2==0)
	{
		ans[s].first=x;
		ans[s].second=y;
		return ;
	}
	long long gys=gcd(y2,y);
	long long fm=y2*y/gys;
	long long fz=x*(y2/gys)+x2*(y/gys);
	gys=gcd(fm,fz);
	fm=fm/gys;
	fz=fz/gys;
	ans[s].first=fz;
	ans[s].second=fm;
}
void dfs(int s,long long x,long long y)
{
	if(head[s]==0)
	{
		clj(x,y,s);
		return ;
	}
	y*=sum[s];
	for(int i=head[s]; i; i=e[i].next)
	{
		int v=e[i].to;
		dfs(v,x,y);
	}
}
int main()
{
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1; i<=n; ++i)
	{
		scanf("%d",&sum[i]);
		for(int j=1; j<=sum[i]; ++j)
		{
			int x;
			scanf("%d",&x);
			vis[x]=1;
			add_edge(i,x);
		}
	}
	for(int i=1; i<=n; ++i)
	{
		if(!vis[i])
		{
			dfs(i,1,1);
		}
	}
	for(int i=1; i<=n; ++i)
	{
		if(ans[i].first)
		{
			printf("%lld %lld\n",ans[i].first,ans[i].second);
		}
	}
	return 0;
}
