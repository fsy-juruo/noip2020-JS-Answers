#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

inline ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }

const int N = 1e5 + 10;

struct frac {
	ll p, q; // p / q
	
	frac(ll x = 0) { p = x, q = 1; }
	
	frac(ll a, ll b) {
		p = a, q = b;
		int d = gcd(a, b);
		p /= d, q /= d;
	}
	
	frac operator+(const frac &o) const {
		ll k = q * o.q / gcd(q,o.q);
		ll p1 = k / q * p, p2 = k / o.q * o.p;
		ll np = p1 + p2;
		return frac(np, k);
	}
	
	frac operator-(const frac &o) const {
		ll k = q * o.q / gcd(q,o.q);
		ll p1 = k / q * p, p2 = k / o.q * o.p;
		ll np = p1 - p2;
		return frac(np, k);
	}
	
	frac operator*(const frac &o) const {
		return frac(p * o.p, q * o.q);
	}
	
	frac operator/(const frac &o) const {
		return frac(p * o.q, q * o.p);
	}
};

int n, mm;
struct edge { int to, nxt; } e[N * 10];
int fst[N], cnt = 0, ind[N], outd[N];
inline void ade(int u, int v) { ++outd[u], ++ind[v]; e[++cnt].to = v, e[cnt].nxt = fst[u]; fst[u] = cnt; }

frac dp[N];
int topo[N], sz;
void topo_sort() {
	queue<int> q;
	for (int i = 1; i <= mm; ++i) {
		q.push(i);
		dp[i] = 1;
	}
	while (q.size()) {
		int u = q.front();
		q.pop();
		topo[++sz] = u;
		for (int i = fst[u]; i; i = e[i].nxt) {
			int v = e[i].to;
			if (--ind[v] == 0) q.push(v);	
		}
	}
//	assert(sz == n);
}
void solve() {
	for (int i = 1; i <= sz; ++i) {
		int u = topo[i];
		frac k = dp[u] / outd[u];
		for (int j = fst[u]; j; j = e[j].nxt) {
			int v = e[j].to;
			dp[v] = dp[v] + k;
		}		
	}
}

int main() {
	freopen("water.in", "r", stdin);
	freopen("water.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> mm;
	for (int i = 1; i <= n; ++i) {
		int d; cin >> d;
		for (int it = 0; it < d; ++it) {
			int j; cin >> j;
			ade(i, j);
		}
	}
	topo_sort(), solve();
	for (int i = 1; i <= n; ++i) if (outd[i] == 0) cout << dp[i].p << " " << dp[i].q << '\n';
	return 0;
}
