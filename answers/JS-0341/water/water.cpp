#include <bits/stdc++.h>
using namespace std;
#define cin fin
#define cout fout
ifstream fin("water.in");
ofstream fout("water.out");
typedef long long lint;
typedef vector<int> vii;
typedef vector<lint> vll;
typedef unsigned int uint;
typedef pair<int, int> pii;
typedef pair<lint, lint> pll;
typedef unsigned long long ulint;
#define pb push_back
#define mp make_pair
#define SZ(x) ((int) (x).size())
#define all(x) (x).begin(), (x).end()
#define rep(it, ff, ee) for (int it = (ff); it <= (ee); ++it)
#define per(it, ff, ee) for (int it = (ff); it >= (ee); --it)
const int MAXN = 1e5 + 20;
struct myFact {
	ulint a, b;
	myFact () {
		a = 0, b = 1;
	}
	inline void init1() { a = b = 1; }
	inline ulint gcd(ulint x, ulint y) {
		return x == 0 ? y : gcd(y % x, x);
	}
	inline void smly() {
		ulint dv = gcd(a, b);
		a /= dv, b /= dv;
	}
	inline void add(const myFact & q) {
		ulint mul = b / gcd(b, q.b) * q.b;
		a = mul / b * a + mul / q.b * q.a;
		b = mul, smly();
	}
	inline void divc(const int & q) {
		b *= q, smly();
	}
}	dp[MAXN];
int deg[MAXN];
vii edge[MAXN];
queue<int> que;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	int n, m;
	cin >> n >> m;
	rep (u, 1, n) {
		int d, v;
		cin >> d;
		rep (j, 1, d) {
			cin >> v;
			edge[u].pb(v);
			++deg[v];
		}
	}
	rep (i, 1, m) {
		que.push(i);
		dp[i].init1();
	}
	while (SZ(que)) {
		int u = que.front();
		que.pop();
		if (SZ(edge[u])) dp[u].divc(SZ(edge[u]));
		rep (i, 0, SZ(edge[u]) - 1) {
			int v = edge[u][i];
			if ((--deg[v]) == 0) que.push(v);
			dp[v].add(dp[u]);
		}
	}
	rep (i, 1, n) if (SZ(edge[i]) == 0) {
		cout << dp[i].a << ' ' << dp[i].b << endl;
	}
	return 0;
}
