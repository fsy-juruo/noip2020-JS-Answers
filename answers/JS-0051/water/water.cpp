#include<bits/stdc++.h>
#define N 100005
#define E 1000005

using namespace std;

template <class T>
inline void read(T &n)
{
	n = 0;
	char ch = getchar();
	while (!isdigit(ch))
		ch = getchar();
	while (isdigit(ch))
		n = n * 10 + (ch ^ '0'), ch = getchar();
}

int n, m, e, num[N], waterp[N], waterq[N], in[N], ver[E], head[N], Next[E];
stack <int> s;

inline int gcd(int a, int b)
{
	return b ? gcd(b, a % b) : a;
}

pair<int, int> ad(int a, int b, int c, int d)
{
	if (c == d && d == 0)
		return make_pair(a, b);
	if (b == d)
		return make_pair(a + c, b);
	int Gcd = gcd(b, d);
	return make_pair(d / Gcd * a + b / Gcd * c, b / Gcd * d);
}

void add(int x, int y)
{
	ver[++e] = y;
	Next[e] = head[x];
	head[x] = e;
}

void topsort()
{
	while (!s.empty())
	{
		int x = s.top(); s.pop();
		if (num[x])
			waterq[x] *= num[x];
		for (int i = head[x], y = ver[i]; i; i = Next[i], y = ver[i])
		{
			--in[y];
			if (!in[y])
				s.push(y);
			pair<int, int> ans = ad(waterp[x], waterq[x], waterp[y], waterq[y]);
			int Gcd = gcd(ans.first, ans.second);
			waterp[y] = ans.first / Gcd, waterq[y] = ans.second / Gcd;
		}
	}
}

int main(int argc, char *argv[])
{
	freopen ("water.in", "r", stdin);
	freopen ("water.out", "w", stdout);
	read(n), read(m);
	for (int i = 1; i <= n; ++i)
	{
		read(num[i]);
		for (int j = 1; j <= num[i]; ++j)
		{
			int x;
			read(x);
			add(i, x);
			++in[x];
		}
	}
	for (int i = 1; i <= m; ++i)
		waterp[i] = waterq[i] = 1, s.push(i);
	topsort();
	for (int i = 1; i <= n; ++i)
		if (!num[i])
			printf ("%d %d\n", waterp[i], waterq[i]);
	return 0;
}
