// Powered		by RA
// Programmed	by Dg
#define task	"walk"
//#undef LOCAL
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define st first
#define nd second
#define R register
#define rep(i, a, b) for (R int i = (a); i <= (b); ++ i)
#ifndef LOCAL
char buf[1 << 21], *p1 = buf, *p2 = buf;
#define getchar() (p1 == p2 && (p2 = (p1 = buf) +\
		fread(buf, 1, 1 << 21, stdin), p1 == p2) ? EOF : *p1 ++)
#endif
const int MAXN	= 5e5 + 10;
const int P		= 1e9 + 7;
const int AC	= 15e4;
const int MAXK	= 15;

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

int n, k, ans, res, w[MAXK], d[MAXN][3];
pair<int, bool> dir[MAXN];

void dfs(int dep, int pos[]) {
	if (dep > n) dep = 1;
	rep (i, 1, k) if (pos[i] < 1 || pos[i] > w[i]) return;
	while (dep == 1) {
		bool flg = true;
		rep (i, 1, k)
			if (pos[i] + d[i][1] < 1 || pos[i] + d[i][2] > w[i]) {
				flg = false; break;
			}
		if (flg) {
			bool kill = true;
			rep (i, 1, k) {
				if (d[i][0] != 0) kill = false;
				pos[i] += d[i][0];
			}
			if (kill) { wtl(-1); exit(0); }
			else { ans += n; ans %= P; }
		} else break;
	}
	pos[dir[dep].st] += (dir[dep].nd - 0.5) * 2;
	++ ans; ans %= P;
	dfs(dep + 1, pos);
	pos[dir[dep].st] -= (dir[dep].nd - 0.5) * 2;
}
void init(int *p, int depth) {
	if (depth > k) {
		int *tmp = new int[k + 5];
		memcpy(tmp, p, sizeof(int) * (k + 1));
		delete tmp;
		dfs(1, tmp);
		return;
	}
	rep (i, 1, w[depth]) { p[depth] = i; init(p, depth + 1); }
}

signed main() {
#ifndef LOCAL
	File();
#endif
	n = rd<int>(); k = rd<int>();
	
	if (n >= AC) {
		wtl(-1); return 0;
	}
	
	rep (i, 1, k) w[i] = rd<int>();
	rep (i, 1, n) { d[i][1] = INT_MAX; d[i][2] = INT_MIN; }
	rep (i, 1, n) {
		dir[i].st = rd<int>();
		int x = rd<int>();
		d[dir[i].st][0] += x;
		d[dir[i].st][1] = min(d[dir[i].st][1], d[dir[i].st][0]);
		d[dir[i].st][2] = max(d[dir[i].st][2], d[dir[i].st][0]);
		dir[i].nd = x == 1 ? 1 : 0;
	}
	
	int *p = new int[k + 5];
	memset(p, 0, sizeof(int) * (k + 1));
	init(p, 1);
	delete p;
	
	wtl(ans);
	return 0;
}

