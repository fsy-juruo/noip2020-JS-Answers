#include <bits/stdc++.h>
#define mp make_pair
#define ll long long
using namespace std;
typedef pair<ll ,ll > fs;
const int maxn=1e5+5;

struct edge
{
	int to,nxt;
}e[maxn];
int head[maxn],cnt=0;

void addedge (int u,int v)
{
	e[cnt].to=v;
	e[cnt].nxt=head[u];
	head[u]=cnt++;
}

ll gcd (ll a,ll b)
{
	if (a%b==0) return b;
	return gcd(b,a%b);
}

fs hj (ll a,ll b)
{
	if (a!=0&&b!=0)
	{
		ll g=gcd (a,b);
		a/=g,b/=g;
	}
	else if (a==0)
		b=1;
	return mp (a,b);
}

fs add (fs a,fs b)
{
	a=hj (a.first,a.second),b=hj (b.first,b.second);
	int m1=a.second,z1=a.first,m2=b.second,z2=b.first;
	return hj(z1*m2+z2*m1,m1*m2);
}

int n,m,v;
ll d[maxn];
fs wat[maxn];
queue <int > q;

void dfs (int st)
{
	q.push (st);
	while (!q.empty())
	{
		int p=q.front();
		q.pop();
		fs w=hj (wat[p].first,wat[p].second*d[p]);
		wat[p]=mp(0,1);
		for (int u=head[p];u!=-1;u=e[u].nxt)
		{
			wat[e[u].to]=add (wat[e[u].to],w);
			if (d[e[u].to]!=0) q.push (e[u].to);
		}
	}
	return;
}

int main ()
{
	freopen ("water.in","r",stdin);
	freopen ("water.out","w",stdout);
	scanf ("%d%d",&n,&m);
	for (int i=1;i<=n;i++) 
	{
		head[i]=-1,wat[i].second=1;
		scanf ("%lld",&d[i]);
		for (ll j=1;j<=d[i];j++)
		{
			scanf ("%d",&v);
			addedge (i,v);
		}
	}
	for (int p=1;p<=m;p++)
		wat[p].first=1;		
	for (int p=1;p<=m;p++)	
		dfs(p);
	for (int i=1;i<=n;i++)
	{
		if (d[i]==0)
			printf ("%lld %lld\n",wat[i].first,wat[i].second);
	}
	return 0;
}
