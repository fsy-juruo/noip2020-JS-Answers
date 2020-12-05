#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

template <typename T> inline void read(T &x)
{
	int f = 1; x = 0; char c = getchar();
	for (; !isdigit(c); c = getchar()) if (c == '-') f = -1;
	for (; isdigit(c); c = getchar()) x = (x << 3) + (x << 1) + (c ^ 48);
	x *= f;
}

const int N = 5e5 + 5;
const int M = 15;
const int mod = 1e9 + 7;

int n, m, w[M], c[N], d[N];

namespace solver1
{
	LL ans;
	inline bool check()
	{
		for (int i = 1; i <= m; i++) if (w[i] > 10) return 0;
		return 1;
	}
	
	int p[M], tmp[M];
	
	inline void calc()
	{
		for (int i = 1; i <= m; i++) tmp[i] = p[i];
		
		int now = 0;
		bool flag = 0;
		for (int i = 1; ; i = i % n + 1)
		{
			if (i == 1 && flag)
			{
				bool Same = 1;
				for (int j = 1; j <= m; j++)
				if (tmp[i] != p[i])
				{
					Same = 0;
					break;
				}
				if (Same)
				{
					puts("-1");
					exit(0);
				}
			}
			
			tmp[c[i]] += d[i];
			now++;
			if (tmp[c[i]] < 1 || tmp[c[i]] > w[c[i]]) break;
			flag = 1;
		}
		ans = (ans + now) % mod;
	}
	
	inline void dfs(int dep)
	{
		if (dep > m)
		{
			calc();
			return;
		}
		for (int i = 1; i <= w[dep]; i++)
		{
			p[dep] = i;
			dfs(dep + 1);
		}
		p[dep] = 0;
	}
	
	inline void solve()
	{
		dfs(1);
		printf ("%lld\n", ans);
		exit(0);	
	}
}

int main()
{
	freopen ("walk.in", "r", stdin);
	freopen ("walk.out", "w", stdout);
	read(n); read(m);
	for (int i = 1; i <= m; i++) read(w[i]);
	for (int i = 1; i <= n; i++) { read(c[i]); read(d[i]); }
	
	if (solver1::check()) solver1::solve();
	puts("-1");
	return 0;
}
