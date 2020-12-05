#include <bits/stdc++.h>
#define N 100005
#define LL long long
using namespace std;

int n, m, last[N], tot;
LL a[N], b[N];
vector < int > e[N];

inline void dfs(int u, LL x, LL y)
{
	if (!e[u].size())
	{
		a[u] = a[u] * y + x * b[u];
		b[u] *= y;
		LL g = __gcd(a[u], b[u]);
		a[u] /= g, b[u] /= g;
		return;
	}
	for (int i = 0; i < e[u].size(); ++i)
	{
		int v = e[u][i];
		LL xx = x, yy = y;
		yy *= e[u].size();
		LL g = __gcd(xx, yy);
		dfs(v, xx / g, yy / g);
	}
}

int main()
{
	freopen("water.in", "r", stdin);
	freopen("water.out", "w", stdout);
	scanf("%d %d", &n, &m);
	for (int u = 1; u <= n; ++u)
	{
		a[u] = 0, b[u] = 1;
		int x;
		scanf("%d", &x);
		if (!x) last[++tot] = u;
		for (int j = 1; j <= x; ++j)
		{
			int v;
			scanf("%d", &v);
			e[u].push_back(v);
		}
	}
	for (int i = 1; i <= m; ++i)
		dfs(i, 1ll, 1ll);
	for (int i = 1; i <= tot; ++i)
		printf("%lld %lld\n", a[last[i]], b[last[i]]);
	return 0;
}

