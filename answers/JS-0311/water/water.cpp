#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;
int n, m, tot;
#define maxn 2000007
int head[maxn], nxt[maxn], to[maxn];
int d[maxn], in[maxn];
#define ll long long
ll f[maxn], g[maxn];
void add (int x, int y)
{
	to[++tot] = y;
	nxt[tot] = head[x];
	head[x] = tot;
}
ll gcd (ll x, ll y)
{
	return y ? gcd (y, x % y) : x;
}
queue <int> q;
void topo()
{
	for (int i = 1; i <= n; i++)
		if (!in[i]) q.push(i);
	while (!q.empty())
	{
		int x = q.front();
		q.pop();
		for (int i = head[x]; i; i = nxt[i])
		{
			int y = to[i];
			ll t = gcd (g[x] * d[x], g[y]);
			in[y]--;
			f[y] = f[x] * g[y] / t + f[y] * g[x] * d[x] / t;
			g[y] = g[y] / t * d[x] * g[x];
			if (!in[y]) q.push(y);
		}
	}
}
int main()
{
	freopen ("water.in", "r", stdin);
	freopen ("water.out", "w", stdout);
	scanf ("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
	{
		g[i] = 1;
		scanf ("%d", &d[i]);
		int x;
		for (int j = 1; j <= d[i]; j++)
		{
			scanf ("%d", &x);
			add (i, x);
			in[x]++;
		}
	}
	for (int i = 1; i <= m; i++)
	f[i] = 1;
	topo();
	for (int i = 1; i <= n; i++)
	{
		if (!d[i])
		{
			int x = gcd (f[i], g[i]);
			printf ("%lld %lld\n", f[i] / x, g[i] / x);
		}
	}
	return 0;
}
