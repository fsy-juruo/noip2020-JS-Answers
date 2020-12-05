#include <bits/stdc++.h>
#define mp make_pair
using namespace std;

typedef long long ll;
typedef pair<ll,ll> pii;
const int N = 1e5 + 5;
template <typename T> inline void rd(T &x)
{
	x = 0; int f = 1; char ch = 0;
	for(;!isdigit(ch); ch = getchar()) if(ch == '-') f = -f;
	for(; isdigit(ch); ch = getchar()) x = (x << 1) + (x << 3) + ch - 48;
	x *= f;
}
template <typename T> inline void wrote(T x)
{
	if(x < 0) {putchar('-'); wrote(-x); return;}
	if(x < 10){putchar(x + 48); return;}
	wrote(x / 10); putchar(x % 10 + 48);
}
template <typename T> inline void writeln(T x)
{
	wrote(x); puts("");
}

vector <int> g[N];
int n,m,ind[N],outd[N];
pii val[N];
queue <int> q;

ll GcD(ll x, ll y)
{
	if(y == 0) return x;
	return GcD(y, x % y);
}

pii pls(pii a, pii b)
{
	ll tmp = GcD(a.first, a.second);
	ll aup = a.first / tmp; ll adown = a.second / tmp;
	tmp = GcD(b.first, b.second);
	ll bup = b.first / tmp; ll bdown = b.second / tmp;
	ll ansup = aup * bdown + adown * bup; ll ansdown = adown * bdown;
	tmp = GcD(ansup, ansdown);
	return mp(ansup / tmp, ansdown / tmp);
}

void topsort()
{
	while(!q.empty())
	{
		int u = q.front();
		q.pop();
		for(int i = 0; i < outd[u]; ++i)
		{
			int v = g[u][i];
			val[v] = pls(val[v], mp(val[u].first, 1ll * val[u].second * outd[u]));
			if(--ind[v] == 0) q.push(v);
		}
	}
}

int main()
{
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	rd(n); rd(m);
	for(int i = 1; i <= n; ++i)
	{
		val[i] = mp(0ll, 1ll);
		rd(outd[i]);
		for(int j = 1; j <= outd[i]; ++j)
		{
			int x; rd(x); ++ind[x];
			g[i].push_back(x);
		}
	}
	for(int i = 1; i <= m; ++i)
	{
		val[i] = mp(1ll, 1ll);
		q.push(i);
	}
	topsort();
	for(int i = 1; i <= n; ++i)
	{
		if(outd[i] == 0)
		{
			wrote(val[i].first); putchar(' ');
			writeln(val[i].second);
		}
	}
	return 0;
}
