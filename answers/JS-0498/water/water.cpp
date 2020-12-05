/* by Hyperhydrochloric Acid */
#include <bits/stdc++.h>
using namespace std;
#define SZ(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define loop(i, a) for(int i = 0; i < (a); ++i)
#define cont(i, a) for(int i = 1; i <= (a); ++i)
#define circ(i, a, b) for(int i = (a); i <= (b); ++i)
#define range(i, a, b, c) for(int i = (a); (c) > 0 ? (i <= (b)) : (i >= (b)); i += c)
#define foreach(it, x) for(__typeof((x).begin()) it = (x).begin(); it != (x).end(); ++it)
#define pub push_back
#define pob pop_back
#define mak make_pair
typedef long long ll;
typedef long double lf;
const int Inf = 0x3f3f3f3f;
const ll INF = 0x3f3f3f3f3f3f3f3fll;
/* Source code starts here */

ll inline gcd(ll a, ll b) {
	return b ? gcd(b, a % b) : a;
}

struct Frac {
	ll a, b;
	Frac(ll a = 0, ll b = 1): a(a), b(b) {}
	friend Frac inline operator+(const Frac &a, const Frac &b) {
		Frac c(a.a * b.b + a.b * b.a, a.b * b.b);
		ll gg = gcd(c.a, c.b);
		c.a /= gg; c.b /= gg;
		return c;
	}
	friend Frac inline operator/(const Frac &a, int b) {
		Frac c(a.a, a.b * b);
		ll gg = gcd(c.a, c.b);
		c.a /= gg; c.b /= gg;
		return c;
	}
};

const int qwq = 1 << 17;
int n, m;
vector<int> nei[qwq];
Frac dp[qwq];
int deg[qwq];

void dfs(int now) {
	int sz = SZ(nei[now]);
	if(!sz) return;
	Frac dn = dp[now] / sz;
	loop(i, SZ(nei[now])) {
		int to = nei[now][i];
		--deg[to]; dp[to] = dp[to] + dn;
		if(!deg[to]) dfs(to);
	}
}

int main() {
	#ifndef HCl10
	freopen("water.in", "r", stdin);
	freopen("water.out", "w", stdout);
	#endif
	scanf("%d%d", &n, &m);
	cont(i, n) {
		int cnt; scanf("%d", &cnt);
		while(cnt--) {
			int to; scanf("%d", &to);
			nei[i].pub(to); ++deg[to];
		}
	}
	cont(i, m) dp[i] = 1;
	cont(i, m) dfs(i);
	cont(i, n) if(!SZ(nei[i])) printf("%lld %lld\n", dp[i].a, dp[i].b);
	return 0;
}
