#include <bits/stdc++.h>
#define LL long long
using namespace std;

template <class T>
void read(T& x)
{
	x = 0;
	char ch = getchar();
	while (!isdigit(ch)) ch = getchar();
	while (isdigit(ch)) x = x * 10 + (ch ^ 48), ch = getchar();
}

const LL N = 1e5 + 5;

LL gcd(LL x, LL y)
{
	return y ? gcd(y, x % y) : x;
}

struct Res
{
	LL p, q;
	void add(LL p2, LL q2, LL k)
	{
		q2 = q2 * k;
		LL fz = p * q2 + p2 * q;
		LL fm = q * q2;
		LL gys = gcd(fz, fm);
		p = fz / gys;
		q = fm / gys;
	}
}a[N];

vector <LL> G[N];
queue <LL> q;
LL n, m, S[N];

void TopSort()
{
	for (LL i = 1; i <= n; ++i)
	{
		a[i].q = 1;
		if (!S[i])
		{
			q.push(i);
			a[i].p = 1;	
		}
	}
	
	while (!q.empty())
	{
		LL node = q.front();
		q.pop();
		for (vector <LL> :: iterator it = G[node].begin(); it != G[node].end(); ++it)
		{
			--S[*it];
			a[*it].add(a[node].p, a[node].q, G[node].size());
			if (!S[*it]) q.push(*it);
		}
	}
}

int main()
{
	freopen("water.in", "r", stdin);
	freopen("water.out", "w", stdout);
	read(n); read(m);
	for (LL i = 1; i <= n; ++i)
	{
		LL d; read(d);
		for (LL j = 1; j <= d; ++j)
		{
			LL x; read(x);
			G[i].push_back(x);
			++S[x];
		}
	}
	TopSort();
	for (LL i = 1; i <= n; ++i)
		if (G[i].empty()) printf("%lld %lld\n", a[i].p, a[i].q);
	return 0;
}

