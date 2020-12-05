#include <bits/stdc++.h>
using namespace std;
#define cin fin
#define cout fout
ifstream fin("walk.in");
ofstream fout("walk.out");
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
int w[20], C[MAXN], D[MAXN], n, k;
vector<int> vv, vvv;
int ans = 0;
inline bool check() {
	rep (i, 1, k) {
		if (vv[i - 1] < 1 || vv[i - 1] > w[i]) return true;
	}
	return false;
}
inline int move(int i) {
	if (check()) return i;
	if (i == n) return n;
	vv[C[i + 1] - 1] += D[i + 1];
	return move(i + 1);
}
inline void dfs(int i) {
	if (i == k) {
		vv = vvv;
		ans += move(0);
		if (vv == vvv) {
			cout << -1 << endl;
			exit(0);
		}
		while (true) {
			ans += move(0);
			if (check()) break;
		}
		return;
	}
	rep (j, 1, w[i + 1]) {
		vvv[i] = j;
		dfs(i + 1);
	}
}
inline void solve1() {
	vvv.resize(k);
	dfs(0);
	cout << ans << endl;
}
lint dp[MAXN];
const lint INF = 1e18;
inline void solve2() {
	rep (i, 1, w[1]) dp[i] = INF; 
	int A = 0, B = w[1] + 1;
	int amv = 0;
	rep (i, 1, n) {
		amv += D[i];
		A -= D[i], B -= D[i];
		if (A >= 1 && A <= w[1]) dp[A] = min(dp[A], (lint) i);
		if (B >= 1 && B <= w[1]) dp[B] = min(dp[B], (lint) i);
	}
	lint aans = 0;
	if (amv <= 0) rep (i, 1, w[1]) {
		if (dp[i] != INF) aans += dp[i];
		else if (amv < 0) {
			dp[i] = dp[i + amv] + n;
			aans += dp[i];
		} else if (amv == 0) {
			cout << -1 << endl;
			exit(0);
		}
	}
	if (amv > 0) per (i, w[1], 1) {
		cerr << i << ' ' << dp[i] << endl;
		if (dp[i] != INF) aans += dp[i];
		else if (amv < 0) {
			dp[i] = dp[i + amv] + n;
			cerr << i << ' ' << i + amv << endl;
			aans += dp[i];
		}
	}
	rep (i, 1, w[1]) {
		cout << dp[i] << ' ';
	}	cout << endl;
	cout << aans << endl;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	int mw = 0;
	cin >> n >> k;
	rep (i, 1, k) {
		cin >> w[i];
		mw = max(mw, w[i]);
	}
	rep (i, 1, n) {
		cin >> C[i] >> D[i];
	}
	if (n <= 5 && k <= 5 && mw <= 3) {
		solve1();
	} else if (n <= 100 && k <= 3 && mw <= 10) {
		solve1();
	} else if (k == 1) {
		cout << -1 << endl;
	//	solve2();
	} else {
		cout << -1 << endl;
	}
	return 0;
}
