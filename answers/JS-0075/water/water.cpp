#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

struct divd
{
	ll p, q;
} ans[100010];

vector < ll > vIn[100010], vOut[100010];
ll n, m, d, x;
bool vis[100010];

inline void add(ll from, ll to)
{
	vOut[from].push_back(to);
	vIn[to].push_back(from);
}

inline divd divWater(divd u, ll x)
{
	divd tmp;
	ll pi = u.p;
	ll qi = u.q;
	ll g = __gcd(pi, x);
	x /= g, pi /= g;
	qi = (ll) x * qi;
	tmp.p = pi;
	tmp.q = qi;
	return tmp;
}

inline divd plsWater(divd x, divd y)
{
	if (x.p == 0) return y;
	if (y.p == 0) return x;
	divd tmp;
	ll px = x.p, py = y.p;
	ll qx = x.q, qy = y.q;
	ll g = __gcd(qx, qy);
	ll l = (ll) qx / g * qy;
	ll pi = (ll) (l / qx) * px + (l / qy) * py;
	ll qi = l;
	ll gg = __gcd(pi, qi);
	tmp.p = pi / gg;
	tmp.q = qi / gg;
	return tmp;
}

inline void dfs(ll pos)
{
	if (pos > n) return;
	ll sze = vIn[pos].size();
	for (int i = 0; i < sze; i++)
		if (!vis[vIn[pos][i]])
			dfs(vIn[pos][i]);
	vis[pos] = true;
	sze = vOut[pos].size();
	if (sze > 0)
		ans[pos] = divWater(ans[pos], sze);
	for (int i = 0; i < sze; i++)
	{
		ll npos = vOut[pos][i];
		ans[npos] = plsWater(ans[npos], ans[pos]);
	}
	dfs(pos + 1);
}

int main()
{
	freopen("water.in", "r", stdin);
	freopen("water.out", "w", stdout);
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &d);
		for (int j = 1; j <= d; j++)
		{
			scanf("%d", &x);
			add(i, x);
		}
		ans[i].p = 0, ans[i].q = 1;
		if (i <= m) 
			ans[i].p = 1;
	}
	dfs(1);
	for (int i = 1; i <= n; i++)
		if (vOut[i].size() == 0)
			printf("%lld %lld\n", ans[i].p, ans[i].q);
	return 0;
}
