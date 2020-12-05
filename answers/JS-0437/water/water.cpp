#include <bits/stdc++.h>
using namespace std;

const long long maxn = 100010, maxm = 1000010;

inline long long fr()
{
	long long f = 1, x = 0;
	char c;
	for (c = getchar(); !isdigit(c); c = getchar()) if (c == '-') f = -f;
	for (; isdigit(c); c = getchar()) x = x * 10 + c - '0';
	return  f * x;
}

inline void fw(long long x)
{
	if (x < 0)
	{
		putchar('-');
		x = -x;
	}
	if (x >= 10)
	{
		fw(x / 10);
		x %= 10;
	}
	putchar(x + '0');
}

struct edge
{
	long long to, nxt;
}e[maxm];

struct frac
{
	long long x, y;
}w[maxn];

long long pre[maxn], nxt[maxn];
long long n, m, tot, head[maxn];
queue<long long> q;

long long gcd(long long x, long long y)
{
	long long r;
	while (y)
	{
		r = x % y;
		x = y;
		y = r;
	}
	return x;
}

long long lcm(long long x, long long y)
{
	return x / gcd(x, y) * y;
}

frac operator+(frac a, frac b)
{
	frac c;
	c.y = lcm(a.y, b.y);
	c.x = c.y / a.y * a.x + c.y / b.y * b.x;
	long long r = gcd(c.x, c.y);
	c.x /= r;
	c.y /= r;
	return c;
}

frac operator/(frac a, long long b)
{
	frac c;
	long long r = gcd(a.x, b);
	c.x = a.x / r;
	c.y = b / r * a.y;
	return c;
}

void add(long long x, long long y)
{
	e[++tot].to = y; e[tot].nxt = head[x]; head[x] = tot;
}

int main()
{
	// use long long
	freopen("water.in", "r", stdin);
	freopen("water.out", "w", stdout);
	
	n = fr(); m = fr();
	for (long long x = 1; x <= n; x++)
	{
		long long k, y;
		k = fr();
		for (long long j = 1; j <= k; j++)
		{
			y = fr();
			add(x, y);
			pre[y]++;
			nxt[x]++;
		}
	}
	for (long long i = 1; i <= n; i++)
		if (pre[i] == 0)
		{
			q.push(i);
			w[i].x = w[i].y = 1;
		}
	for (long long i = 1; i <= n; i++)
		w[i].y = 1;
	while (!q.empty())
	{
		long long x = q.front();
		q.pop();
		if (nxt[x] == 0) continue;
		frac addi = w[x] / nxt[x];
		for (long long i = head[x]; i; i = e[i].nxt)
		{
			long long y = e[i].to;
			w[y] = w[y] + addi;
			pre[y]--;
			if (!pre[y])
				q.push(y);
		}
	}
	for (long long i = 1; i <= n; i++)
		if (nxt[i] == 0)
		{
			fw(w[i].x); putchar(' ');
			fw(w[i].y); putchar('\n');
		}

	return 0;
}

