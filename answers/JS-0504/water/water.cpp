// Powered		by RA
// Programmed	by Dg
#define task	"water"
//#undef LOCAL
#include <bits/stdc++.h>
using namespace std;

#define int unsigned long long
#define R register
#define rep(i, a, b) for (R int i = (a); i <= (b); ++ i)
#ifndef LOCAL
char buf[1 << 21], *p1 = buf, *p2 = buf;
#define getchar() (p1 == p2 && (p2 = (p1 = buf) +\
		fread(buf, 1, 1 << 21, stdin), p1 == p2) ? EOF : *p1 ++)
#endif
const int MAXN	= 1e5 + 10;

inline void File() {
	freopen(task ".in",  "r", stdin);
	freopen(task ".out", "w", stdout);
}
template <typename T>
inline T rd() {
	R T p = 0; R bool sgn = false; R char ch = getchar();
	for (; !isdigit(ch); ch = getchar()) if (ch == '-') sgn ^= 1;
	for (;  isdigit(ch); ch = getchar()) p = (p << 1) + (p << 3) + (ch ^ 48);
	return sgn ? ~p + 1 : p;
}
template <typename T>
void wt(T p) {
	if (p > 9) wt(p / 10);
	putchar(p % 10 ^ 48);
}
template <typename T>
inline void wts(T p, char sp = ' ') { wt(p); putchar(sp); }
template <typename T>
inline void wtl(T p) { wt(p); puts(""); }

int n, m, val[MAXN][2], edge[MAXN][10], cnt[MAXN];

int gcd(int x, int y) { return y == 0 ? x : gcd(y, x % y); }
inline void work(int &x, int &y) { int g = gcd(x, y); x /= g; y /= g; }
inline void extend(int &x, int &y, int pow) { x *= pow; y *= pow; }
inline void add(int x, int y) {
	int tmp1 = val[x][0], tmp2 = val[x][1] * edge[x][0];
	work(tmp1, tmp2);
	int l = tmp2 * val[y][1] / gcd(tmp2, val[y][1]);
	extend(tmp1, tmp2, l / tmp2);
	extend(val[y][0], val[y][1], l / val[y][1]);
	val[y][0] += tmp1;
	work(val[y][0], val[y][1]);
}
inline void solve() {
	queue<int> q;
	rep (i, 1, m) { val[i][0] = 1; q.push(i); }
	while (!q.empty()) {
		int x = q.front(); q.pop();
		rep (i, 1, edge[x][0]) {
			add(x, edge[x][i]);
			if (!(-- cnt[edge[x][i]])) q.push(edge[x][i]);
		}
	}
}
signed main() {
#ifndef LOCAL
	File();
#endif
	n = rd<int>(); m = rd<int>();
	rep (i, 1, n) {
		edge[i][0] = rd<int>(); val[i][1] = 1;
		rep (j, 1, edge[i][0]) {
			edge[i][j] = rd<int>();
			++ cnt[edge[i][j]];
		}
	}
	
	solve();

	rep (i, m + 1, n) if (!edge[i][0]) {
		wts(val[i][0]); wtl(val[i][1]);
	}
	return 0;
}
