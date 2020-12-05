#include <bits/stdc++.h>
#define N 500005
#define LL long long
#define mod 1000000007
using namespace std;

LL n, m, w[15], a[15], b[15], c[N], d[N], aff[15], ans;
bool p;

inline void solve()
{
	for (LL i = 1; i <= m; ++i) b[i] = a[i];
	for (LL i = 1; i <= n; ++i)
	{
		b[c[i]] += d[i];
		if (b[c[i]] < 1 || b[c[i]] > w[c[i]])
		{
			ans = (ans + i) % mod;
			return;
		}
	}
	if (!p)
	{
		puts("-1");
		exit(0);
	}
	ans = (ans + n) % mod;
	for (LL i = 1, cnt = 0; ; ++i)
	{
		if (i > n) i = 1, ++cnt;
		b[c[i]] += d[i];
		if (b[c[i]] < 1 || b[c[i]] > w[c[i]])
		{
			ans = (ans + i + cnt * n % mod) % mod;
			return;
		}
	}
}

inline void build(LL now)
{
	if (now > m)
	{
		solve();
		return;
	}
	for (LL i = 1; i <= w[now]; ++i)
		a[now] = i, build(now + 1);
}

int main()
{
	freopen("walk.in", "r", stdin);
	freopen("walk.out", "w", stdout);
	scanf("%lld %lld", &n, &m);
	for (LL i = 1; i <= m; ++i)
		scanf("%lld", &w[i]);
	for (LL i = 1; i <= n; ++i)
		scanf("%lld %lld", &c[i], &d[i]), aff[c[i]] += d[i];
	for (LL i = 1; i <= m; ++i)
		if (aff[i]) p = 1;
	build(1);
	printf("%lld\n", ans);
	return 0;
}

