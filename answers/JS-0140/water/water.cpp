#include <bits/stdc++.h>

#define ll long long
#define N (int) (1e5+10)

using namespace std;
ll input () {
	ll x = 0, f = 0;
	char c = getchar ();
	while (c < '0' || c > '9') f = c == '-', c = getchar ();
	while (c >= '0' && c <= '9') x = (x << 1ll) + (x << 3ll) + (c ^ 48), c = getchar ();
	return f ? - x : x;
}

ll n, m;

struct Edge {
	ll v, nxt;
} edge[N];
ll fst[N], ecnt;
void add_edge (ll u, ll v) {
	edge[ecnt].v = v, edge[ecnt].nxt = fst[u], fst[u] = ecnt ++;
}
void init_e () {
	ecnt = 0;
	memset (fst, -1, sizeof (fst));
}

vector <ll> ed;

ll gcd (ll x, ll y) {
	if (! y) return x;
	return gcd (y, x%y);
}

struct Frac {
	ll x, y;
	
	
	void simp () {
		ll g = gcd (x, y);
		x /= g, y /=g;
	}
	
	friend Frac operator * (const Frac & x, const Frac & y) {
		Frac ret = x;
		ret.x *= y.x;
		ret.y *= y.y;
		ret.simp ();
		return ret;
	}
	
	friend Frac operator + (const Frac & x, Frac & y) {
		Frac ret = x;
		ll g = gcd (ret.y, y.y);
		ll tmp = ret.y;
		ret.y *= y.y/g, ret.x *= y.y/g, y.y *= tmp/g, y.x *= tmp/g;
		ret.x += y.x;
		ret.simp ();
		return ret; 
	}
	
	Frac () {
		x = 0, y = 1;
	}
	Frac (ll _x, ll _y) {
		x = _x, y = _y;
	}
} a[N];

ll d[N];
ll deg[N];
void tuopu () {
	queue <ll> q;
	
	for (int i = 1; i <= m; i ++) {
		a[i] = Frac (1, 1);
		q.push (i);
	}
	
	while (! q.empty ()) {
		int u = q.front ();
		q.pop ();
		
		Frac tmp = a[u] * Frac (1, d[u]);
		for (int e = fst[u]; e != -1; e = edge[e].nxt) {
			int v = edge[e].v;
			a[v] = a[v] + tmp;
			deg[v] --;
			if (! deg[v]) q.push (v);
		}
	}
}

int main () {
	freopen ("water.in", "r", stdin);
	freopen ("water.out", "w", stdout);

	init_e ();
	n = input (), m = input ();
	for (int i = 1; i <= n; i ++) {
		d[i] = input ();
		for (int j = 1; j <= d[i]; j ++) {
			int v = input ();
			add_edge (i, v);
			deg[v] ++;
		}
		if (! d[i]) ed.push_back (i);
	}
	
	tuopu ();
	
	for (int i = 0; i < ed.size (); i ++) printf ("%lld %lld\n", a[ed[i]].x, a[ed[i]].y);
	
	return 0;
}
