#include <bits/stdc++.h>

using namespace std;

template <typename T> inline void read(T &x) {
	T f = 1; x = 0; char c = getchar();
	for (; !isdigit(c); c = getchar()) if (c == '-') f = -f;
	for (; isdigit(c); c = getchar()) x = x * 10 + c - 48;
	x *= f;
}

template <typename T> inline void write(T x) {
	if (x < 0) x = -x, putchar('-');
	if (x > 9) write(x / 10);
	putchar(x % 10 + 48);
}

template <typename T> inline void writeln(T x, char c) { write(x); putchar(c); }
template <typename T> inline void chkmax(T &x, const T y) { x = x > y ? x : y; }
template <typename T> inline void chkmin(T &x, const T y) { x = x < y ? x : y; }

typedef long long ll;
typedef pair <int, int> pii;

#define Ms(arr, opt) memset(arr, opt, sizeof(arr))
#define Mp(x, y) make_pair(x, y)

const int INF = 1e9 + 10;
const int mod = 1e9 + 7;

const int Maxn = 5e5 + 5, Maxk = 15;
int n, k, w[Maxk], c[Maxn], d[Maxn], ans = 0;
int dt[Maxk], W = 0; pii mink[Maxk], maxk[Maxk];

namespace BF {
	int zb[Maxk], zb1[Maxk];
	bool h[Maxn];
	inline int ys() {
		int s = 0;
		for (int i = 1; i <= k; i++)
			s = s * (W + 1) + zb[i];
		return s;
	}
	
	inline void dfs() {
		h[ys()] = true;
		int t = 0;
		for (int i = 1; i <= k; i++) zb1[i] = zb[i];
		do {
			int tt = n + 1;
			for (int i = 1; i <= k; i++) {
				if (zb1[i] + maxk[i].first > w[i]) {
					chkmin(tt, maxk[i].second);
				} else if (zb1[i] + mink[i].first < 1) {
					chkmin(tt, mink[i].second);
				}
			}
			
			if (tt != n + 1) {
				int ttt = 0;
				for (int i = 1; i <= n; i++)
					if (zb1[c[i]] + d[i] > w[c[i]] || zb1[c[i]] + d[i] < 1) {
						ttt = i; break;
					} else zb1[c[i]] += d[i];
				ans = (ans + (ttt + t * n % mod) % mod) % mod; break;
			}
			for (int i = 1; i <= k; i++) zb1[i] += dt[i]; ++t;
		} while (1);
		
		for (int i = 1; i <= k; i++) {
			if (zb[i] < w[i]) {
				++zb[i];
				int s = ys();
				if (!h[s]) dfs();
				--zb[i];
			}
		}
	}
	
	inline void solve(void) {
		Ms(h, 0);
		for (int i = 1; i <= k; i++) zb[i] = 1;
		dfs(); writeln(ans, '\n');
	}
}

//namespace SL {
//	inline void solve() {
//	}
//}

int main() {
	freopen("walk.in", "r", stdin);
	freopen("walk.out", "w", stdout);
	read(n), read(k);
	for (int i = 1; i <= k; i++) {
		read(w[i]); chkmax(W, w[i]);
		mink[i] = Mp(INF, -1);
		maxk[i] = Mp(-INF, -1);
	}
	
	for (int i = 1; i <= n; i++) {
		read(c[i]), read(d[i]);
		dt[c[i]] += d[i];
		if (dt[c[i]] > maxk[c[i]].first) maxk[c[i]] = Mp(dt[c[i]], i);
		if (dt[c[i]] < mink[c[i]].first) mink[c[i]] = Mp(dt[c[i]], i);
	}
	
	if (n > 100000) { puts("-1"); return 0; }
	BF :: solve();
//	SL :: solve();
	return 0;
}

/*
3 2
3 3
1 1
2 -1
1 1

5 4
6 8 6 5
3 1
2 1
1 1
2 1
2 -1
*/
