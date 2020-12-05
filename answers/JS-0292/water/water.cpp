#include<bits/stdc++.h>
using namespace std;
int read()
{
	int x = 0, f = 1;
	char c = getchar();
	while (!isdigit(c))
	{
		if(c == '-')
		{
			f = -1;
		}
		c = getchar();
	}
	while (isdigit(c))
	{
		x = x * 10 + c - 48;
		c = getchar();
	}
	return x * f;
}
const int maxn = 1e5 + 10;
int tot, head[maxn], ver[maxn], nxt[maxn];
void add(int u, int v)
{
	ver[++tot] = v;
	nxt[tot] = head[u];
	head[u] = tot;
}
queue<int>q;
int deg[maxn], out[maxn];
struct node
{
	long long p, q;
	node(const long long &_p = 0, const long long &_q = 1)
	{
		p = _p, q = _q;
	}
	void print()
	{
		printf("%lld %lld\n", p, q);
	}
}f[maxn];
long long gcd(long long a, long long b)
{
	return !b ? a : gcd(b, a % b);
}
node operator+(const node&A, const node&B)
{
	long long a = A.q * B.q,  b = A.p * B.q + A.q * B.p;
	long long d = gcd(a, b);
	return node(b / d, a / d);
}
node operator/(const node&A, const long long&B)
{
	long long d = gcd(A.p, A.q * B);
	return node(A.p / d, A.q * B / d);
}
int main()
{
	freopen("water.in", "r", stdin);
	freopen("water.out", "w", stdout);
	int n = read(), m = read();
	for (int i = 1; i <= n; ++i)
	{
		out[i] = read();
		for (int j = 1; j <= out[i]; ++j)
		{
			int x = read();
			add(i, x);deg[x]++;
		}
	}
	for (int i = 1; i <= n; ++i)
	{
		if(!deg[i])
		{
			q.push(i);
			f[i] = node(1, 1);
		}
	}
	while (!q.empty())
	{
		int x = q.front();
		q.pop();
		for (int i = head[x]; i; i = nxt[i])
		{
			int y = ver[i];
			f[y] = f[y] + f[x] / out[x];
			if(--deg[y] == 0)
			{
				q.push(y);
			}
		}
	}
	for (int i = 1; i <= n; ++i)
	{
		if(!out[i])
		{
			f[i].print();
		}
	}
	return 0;
}

