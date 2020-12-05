#include <bits/stdc++.h>

#define LL long long
#define rep(i,n) for(int i=0;i<n;i++)
#define repn(i,n) for(int i=1;i<=n;i++)
#define pii pair <LL,LL>
#define fi first
#define se second
#define pb push_back
#define mpr make_pair

using namespace std;

int n,m;
vector <int> g[100010],ord;
bool vis[100010];
pii dp[100010];

void dfs(int pos)
{
	vis[pos]=true;
	rep(i,g[pos].size())
	{
		if(vis[g[pos][i]]) continue;
		dfs(g[pos][i]);
	}
	ord.pb(pos);
}

LL gcd(LL a,LL b)
{
	if(a%b==0) return b;
	return gcd(b,a%b);
}

pii simp(pii ori)
{
	LL val=gcd(ori.fi,ori.se);
	ori.fi/=val;
	ori.se/=val;
	return ori;
}

pii Div(pii ori,LL val)
{
	ori.se*=val;
	ori=simp(ori);
	return ori;
}

pii add(pii a,pii b)
{
	a.fi=a.fi*b.se+b.fi*a.se;
	a.se*=b.se;
	a=simp(a);
	return a;
}

int main()
{
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	scanf("%d%d",&n,&m);
	int x,y;
	repn(i,n)
	{
		scanf("%d",&x);
		rep(j,x)
		{
			scanf("%d",&y);
			g[i].pb(y);
		}
	}
	repn(i,n)
	{
		if(vis[i]) continue;
		dfs(i);
	}
	repn(i,m) dp[i]=mpr(1,1);
	for(int i=m+1;i<=n;i++) dp[i]=mpr(0,1);
	for(int i=n-1;i>=0;i--)
	{
		if(g[ord[i]].size()==0) continue;
		int cur=ord[i];
		pii val=Div(dp[cur],(LL)g[cur].size());
		rep(j,g[cur].size()) dp[g[cur][j]]=add(dp[g[cur][j]],val);
	}
	repn(i,n) if(g[i].size()==0) printf("%lld %lld\n",dp[i].fi,dp[i].se);
	return 0;
}
/*
10 1
5 2 3 4 5 6
2 7 8
2 8 10
2 9 7
1 9
3 7 8 9
1 10
0
1 10
0

4 15
11 15


*/
