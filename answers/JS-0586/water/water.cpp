#include <iostream>
#include <cstdio>
#include <vector>
using std::vector;
typedef long long ll;

ll n, m, dl[100009];
bool v[100009];
vector<ll> g[100009];

struct Node
{
	ll p, q;
}w[100009];

inline ll read()
{
	char ch = getchar();
	ll figure = 0;
	while (ch < '0'||ch > '9')
	{
		ch = getchar();
	}
	while (ch >= '0'&&ch <= '9')
	{
		figure = (figure<<3) + (figure<<1) + ch - '0';
		ch = getchar();
	}
	return figure;
}

ll gcd(ll m1, ll m2)
{
	ll re;
	if(m1 < m2)
	{
		re = m1;
		m1 = m2;
		m2 = re;
	}
	while(m2 != 0)
	{
		re = m2;
		m2 = m1 % m2;
		m1 = re;
	}
	return re;
}

void plus(ll np, ll nq, ll da)
{
	ll lp = np * w[da].q + nq * w[da].p, lq = nq * w[da].q;
	ll ddlc = gcd(lp, lq);
	w[da].p = lp / ddlc;
	w[da].q = lq / ddlc;
	return;
}

void dfs(ll at)
{
	int l = g[at].size();
	if(l == 0)
	{
		w[at].p = 1;
		return;
	}
	for (register ll k = 0; k < l; ++k)
	{
		if(w[g[at][k]].p == 0)
		{
			dfs(g[at][k]);
		}
		int cd = gcd(w[g[at][k]].p, dl[g[at][k]]);
		plus(w[g[at][k]].p / cd, w[g[at][k]].q * dl[g[at][k]] / cd, at);
	}
}

int main()
{
	freopen("water.in", "r", stdin);
	freopen("water.out", "w", stdout);
	n = read();
	m = read();
	for (register ll i = 1; i <= n; ++i)
	{
		dl[i] = read();
		w[i].p = 0;
		w[i].q = 1;
		for (register ll j = 1; j <= dl[i]; ++j)
		{
			ll a;
			a = read();
			g[a].push_back(i);
		}
	}
	for (register ll i = 1; i <= n; ++i)
	{
		if(dl[i] == 0)
			dfs(i);//Hope Cirno can help me.
	}
	for (register ll i = 1; i <= n; ++i)
	{
		if (dl[i] == 0)
		{
			printf("%lld %lld\n", w[i].p, w[i].q);
		}
	}
	return 0;
}

