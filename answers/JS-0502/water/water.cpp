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

const int N = 1e5 + 5;
const int M = 5e5 + 5;

int head[N], ver[M], Next[M], tot;
inline void addedge(int x, int y)
{
	ver[++tot] = y;
	Next[tot] = head[x];
	head[x] = tot;
}

int n, m, s[N], deg[N];

queue <int> q;
int seq[N], cnt;

inline void topsort()
{
	for (int i = 1; i <= n; i++) if (!deg[i]) q.push(i);
	
	int x;
	while (!q.empty())
	{
		x = q.front(); q.pop(); seq[++cnt] = x;
		
		for (int i = head[x]; i; i = Next[i])
		{
			int y = ver[i];
			if (--deg[y] == 0) q.push(y);
		}
	}
}

inline LL gcd(LL x, LL y) { return y == 0 ? x : gcd(y, x % y); }

bool isleaf[N];

struct info
{
	LL p, q;
	inline void calc()
	{
		LL d = gcd(p, q);
		p /= d; q /= d;
	}
	
} ans[N], cur;

int main()
{
	freopen ("water.in", "r", stdin);
	freopen ("water.out", "w", stdout);
	read(n); read(m);
	for (int x = 1, y; x <= n; x++)
	{
		read(s[x]);
		
		if (!s[x]) isleaf[x] = 1;
		
		for (int j = 1; j <= s[x]; j++)
		{
			read(y);
			addedge(x, y);
			deg[y]++;
		}
	}
	
	topsort();
	
	for (int i = 1; i <= n; i++)
	{
		ans[i].q = 1;
		if (i <= m) ans[i].p = 1;
	}
	
	for (int i = 1; i <= n; i++)
	{
		int x = seq[i];
		if (isleaf[x]) continue;
		
		ans[x].q *= s[x]; ans[x].calc();
		
		for (int j = head[x]; j; j = Next[j])
		{
			int y = ver[j];
			cur.p = (LL) ans[x].p * ans[y].q + ans[y].p * ans[x].q;
			cur.q = (LL) ans[x].q * ans[y].q;
			cur.calc();
			ans[y] = cur;
		}
	}
	
	for (int i = 1; i <= n; i++)
	if (isleaf[i]) printf ("%lld %lld\n", ans[i].p, ans[i].q);
	
	return 0;
}
