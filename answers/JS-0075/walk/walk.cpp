#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll P = 1e9 + 7;

struct walk
{
	ll a[15];
} pos, maxn, minn;

inline ll read()
{
	ll s = 0, f = 0;
	char ch = getchar();
	while (!isdigit(ch)) f |= (ch == '-'), ch = getchar();
	while (isdigit(ch)) s = (s << 1) + (s << 3) + (ch ^ 48), ch = getchar();
	return f ? -s : s;
}

inline void write(ll x)
{
	if (x < 0) putchar('-'), x = -x;
	if (x > 9) write(x / 10);
	putchar(x % 10 + 48);
}

ll n, k, w[15];
ll c[500010], d[500010];
ll ans;

inline ll work(walk u)
{
	bool flag;
	ll cnt = 0;
	walk u2 = u;
	while (!flag)
	{
		flag = false;
		for (int i = 1; i <= k; i++)
		{
			if (u.a[i] + maxn.a[i] > w[i] || u.a[i] + minn.a[i] <= 0)
			{
				flag = true;
				break;
			}
		}
		if (flag) break;
		cnt += n;
		for (int i = 1; i <= k; i++)
			u.a[i] += pos.a[i];
	}
	for (int i = 1; i <= n; i++)
	{
		u.a[c[i]] += d[i];
		cnt++;
		if (u.a[c[i]] <=  0 || u.a[c[i]] > w[c[i]]) return cnt;
	}
}

inline void dfs(ll dep, walk u)
{
	if (dep > k)
	{
		ans = (ans + work(u)) % P;
		return;
	}
	for (int i = 1; i <= w[dep]; i++)
	{
		u.a[dep] = i;
		dfs(dep + 1, u);
	}
}

int main()
{
	freopen("walk.in", "r", stdin);
	freopen("walk.out", "w", stdout);
	n = read(), k = read();
	for (int i = 1; i <= k; i++)
		w[i] = read();
	for (int i = 1; i <= n; i++)
	{
		c[i] = read(), d[i] = read();
		pos.a[c[i]] += d[i];
		maxn.a[c[i]] = max(maxn.a[c[i]], pos.a[c[i]]);
		minn.a[c[i]] = min(minn.a[c[i]], pos.a[c[i]]);
	}
	walk u;
	memset(u.a, 0, sizeof (u.a));
	dfs(1, u);
	write(ans), puts("");
	return 0;
}
