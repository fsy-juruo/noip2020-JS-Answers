#include<bits/stdc++.h>
#define MAX 1000000
using namespace std;
typedef long long ll;
int n,m,cnt,head[MAX+5],ru[MAX+5],chu[MAX+5],cnt2;
struct T
{
	int nxt,to;
}e[MAX+5];
struct node
{
	ll x,y;
}dp[MAX+5];
bool ori(int from)
{
	return dp[from].x==0;
}
void add(int u,int v)
{
	e[++cnt].to=v;
	e[cnt].nxt=head[u];
	head[u]=cnt;
}
ll gcd(ll a,ll b)
{
	if(!b) return a;
	else return gcd(b,a%b);
}
void plu(int from,int to)
{
	ll up,down; 
    if(!chu[from])
    {
	up=dp[from].x*dp[to].y+dp[to].x*dp[from].y;
	down=dp[from].y*dp[to].y;
    }
    else 
    {
    	up=dp[from].x*dp[to].y*ll(chu[from])+dp[to].x*dp[from].y;
    	down=dp[from].y*dp[to].y*chu[from];
	}
	ll GCD=gcd(up,down);
	dp[from].x=up/GCD,dp[from].y=down/GCD;
}
void dfs(int from)
{
	if(!ori(from)) return ;
	for(int i=head[from]; i; i=e[i].nxt)
	{
		int to=e[i].to;
		dfs(to);
		plu(from,to);
	}
}
int main()
{
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1; i<=n; i++)
	{
		int d,u; scanf("%d",&d);
		u=i;
		for(int j=1; j<=d; j++)
		{
			int v; scanf("%d",&v);
			add(v,u);
			ru[v]++,chu[u]++;
		}
	}
	for(int i=1; i<=n; i++) 
    {
	if(!ru[i]) dp[i].x=1,dp[i].y=chu[i];
	else dp[i].x=0,dp[i].y=1;
    } 
	for(int i=1; i<=n; i++) 
	if(!chu[i]) { dfs(i);  printf("%lld %lld\n",dp[i].x,dp[i].y); }
	return 0;
}
