// Powered		by RA
// Programmed	by Dg
#define task	"ball"
//#undef LOCAL
#include <bits/stdc++.h>
using namespace std;

#define st first
#define nd second
#define R register
#define rep(i, a, b) for (R int i = (a); i <= (b); ++ i)
#ifndef LOCAL
char buf[1 << 21], *p1 = buf, *p2 = buf;
#define getchar() (p1 == p2 && (p2 = (p1 = buf) +\
		fread(buf, 1, 1 << 21, stdin), p1 == p2) ? EOF : *p1 ++)
#endif
const int MAXN	= 50 + 10;
const int MAXM	= 400 + 10;

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
	if (p < 0) putchar('-'), p = ~p + 1;
	if (p > 9) wt(p / 10);
	putchar(p % 10 ^ 48);
}
template <typename T>
inline void wts(T p, char sp = ' ') { wt(p); putchar(sp); }
template <typename T>
inline void wtl(T p) { wt(p); puts(""); }

int n, m, a[MAXN][MAXM], b[MAXN][MAXM];
bool flg, stat[MAXN];
vector< pair<int, int> > opt;

inline void update(int x) {
	stat[x] = true;
	rep (i, 2, a[x][0])
		if (a[x][i] != a[x][i - 1]) { stat[x] = false; return; }
}

void dfs(int dep, int lmt) {
	if (dep > lmt) {
		rep (i, 1, n + 1)
			if (!stat[i]) return;
//		rep (i, 1, n + 1) {
//			cout << stat[i] << ' ';
//			rep (j, 1, a[i][0]) cout << a[i][j] << ' ';
//			cout << endl;
//		}
		flg = true;
		return;
	}
//	cout << dep << ' ' << lmt << endl;
//	rep (i, 1, n + 1) {
//		cout << stat[i] << ' ';
//		rep (j, 1, a[i][0]) cout << a[i][j] << ' ';
//		cout << endl;
//	} 
//	cout << endl;
	rep (i, 1, n + 1) {
		rep (j, 1, n + 1) {
			if (i == j) continue;
			if (a[i][0] >= 1 && a[j][0] <= m - 1) {
				++ a[j][0]; -- a[i][0];
				a[j][a[j][0]] = a[i][a[i][0] + 1];
				update(i); update(j);
				opt.push_back(make_pair(i, j));
				dfs(dep + 1, lmt);
				if (flg) return;
				-- a[j][0]; ++ a[i][0];
				a[i][a[i][0]] = a[j][a[j][0] + 1];
				update(i); update(j);
				opt.pop_back();
			}
		}
	}
}

signed main() {
#ifndef LOCAL
	File();
#endif
	n = rd<int>(); m = rd<int>();
	rep (i, 1, n) {
		a[i][0] = m;
		rep (j, 1, m) a[i][j] = rd<int>();
		update(i);
	}
	
	memcpy(b, a, sizeof(a));
	rep (i, 1, 820000) {
		dfs(0, i);
		if (flg) {
			wtl(i);
			rep (j, 0, (int)opt.size() - 1)
				wts(opt[j].st), wtl(opt[j].nd);
			return 0;
		} else {
			memcpy(a, b, sizeof(b));
			opt.clear();
			memset(stat, 0, sizeof(stat));
		}
	}
	return 0;
}

