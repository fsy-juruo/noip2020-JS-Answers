#include <bits/stdc++.h>
using namespace std;
#define PROG "water"
#define FILEIO 1
#define DEBUG 0

typedef long long ll;

inline ll gcd(ll m, ll n)
{
	while (n != 0)
	{
		ll t = m % n;
		m = n;
		n = t;
	}
	return m;
}

struct fraction
{
	ll p, q;
	fraction() {}
	fraction(ll p, ll q) : p(p), q(q) {adjust();}
	inline void zero()
	{
		p=0; q=1;
	}
	inline void adjust()
	{
		ll g=gcd(p, q);
		p/=g; q/=g;
	}
	friend inline fraction operator+(fraction const& lhs, fraction const& rhs)
	{
		return fraction(lhs.p*rhs.q+lhs.q*rhs.p, lhs.q*rhs.q);
	}
	friend inline fraction operator/(fraction const& lhs, int rhs)
	{
		return fraction(lhs.p, lhs.q*rhs);
	}
	inline fraction& operator += (fraction const& o)
	{
		*this = *this + o;
		return *this;
	}
};

// optimize?
// long long?

const int N=1e5+1;
int n, m, ql, qr, q[N];
vector<int> g[N];
fraction w[N];

// my queue
inline void qclear()
{ ql=0; qr=0; }
inline void qpush(int x)
{ q[qr++]=x; }
inline void qpop()
{ ++ql; }
inline int qfront()
{ return q[ql]; }
inline int qback()
{ return q[qr-1]; }
inline int qsize()
{ return qr-ql; }

void init()
{
	int i, j, d, a;
	scanf("%d%d", &n, &m);
	for (i=1; i<=n; ++i)
	{
		scanf("%d", &d);
		for (j=1; j<=d; ++j)
		{
			scanf("%d", &a);
			g[i].push_back(a);
		}
	}
	for (i=1; i<=n; ++i)
	{
		w[i].zero();
	}
}

// todo: bfs
void flow(int s)
{
	qclear();
	qpush(s);
	while (qsize())
	{
		int x=qfront(); qpop();
		int siz=g[x].size();
		if (siz)
		{
			fraction sub=w[x]/siz;
			for (int i=0; i<siz; ++i)
			{
				int y=g[x][i];
				w[y]+=sub;
				qpush(y);
			}
			w[x].zero();
		}
	}
#if 0 // dfs wa
	int siz=g[s].size();
	if (siz)
	{
		fraction sub=w[s]/siz;
		for (int i=0; i<siz; ++i)
		{
			int t=g[s][i];
			w[t]+=sub;
			flow(t);
		}
		w[s].zero();
	}
#endif
}

void solve()
{
	init();
	for (int i=1; i<=m; ++i)
	{
		w[i].p=1;
		flow(i);
	}
	for (int i=1; i<=n; ++i)
	{
		if (w[i].p)
			printf("%lld %lld\n", w[i].p, w[i].q);
	}
}

int main()
{
#if FILEIO
	freopen(PROG ".in", "r", stdin);
	freopen(PROG ".out", "w", stdout);
#endif
	solve();
#if FILEIO
	fclose(stdin);
	fclose(stdout);
#endif
	return 0;
}

/*
5 1
3 2 3 5
2 4 5
2 5 4
0
0
---
10 1
5 2 3 4 5 6
2 7 8
2 8 10
2 9 7
1 9
3 7 8 9
1 10
0
1 10
0

*/
