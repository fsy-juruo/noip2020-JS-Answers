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

const int N = 55, M = 405;
int a[N][M], n, m, col, tot = 0; bool vis[N];
pair <int, int> pls[820005]; int ss = 0, idx = -1;
inline void solve() {
	idx = -1;
//	for (int i = 1; i <= n + 1; i++)
//	for (int j = 1; j <= a[i][0]; j++) writeln(a[i][j], " \n"[j == a[i][0]]);
	while (a[n + 1][0] > 0) {
		for (int i = 1; i <= n; i++) {
			if (vis[i] || a[i][0] == m) continue;
			while (a[i][0] < m) pls[++ss] = Mp(n + 1, i), a[i][++a[i][0]] = a[n + 1][a[n + 1][0]], a[n + 1][0]--;
		}
	}
	
	for (int i = 1; i <= n + 1; i++) {
		if (vis[i]) continue;
		col = a[i][1]; idx = i; break;
	}
	
	while (a[idx][0] > 1) pls[++ss] = Mp(idx, n + 1), a[n + 1][++a[n + 1][0]] = a[idx][a[idx][0]], a[idx][0]--;
	
	for (int i = 1; i <= n; i++) {
		if (i == idx) continue; int f = 0;
		for (int j = 1; j <= a[i][0]; j++) if (a[i][j] == col) f++;
		if (f == 0) continue; gggg : ;
		while (f > 0) {
			if (a[i][a[i][0]] == col) { f--; pls[++ss] = Mp(i, idx), a[idx][++a[idx][0]] = a[i][a[i][0]]; a[i][0]--; continue; }
			bool ff = false;
			for (int j = 1; j <= n + 1; j++) {
				if (j == i || j == idx || a[j][0] == m) continue;
				pls[++ss] = Mp(i, j), a[j][++a[j][0]] = a[i][a[i][0]--]; ff = true; break;
			}
			
			if (!ff) {
				int tmp = a[idx][0];
				pls[++ss] = Mp(n + 1, idx);
				a[idx][++a[idx][0]] = a[n + 1][a[n + 1][0]--];
				while (a[i][a[i][0]] != col) {
					pls[++ss] = Mp(i, idx);
					a[idx][++a[idx][0]] = a[i][a[i][0]--];
				}
				pls[++ss] = Mp(i, n + 1);
				a[n + 1][++a[n + 1][0]] = a[i][a[i][0]--];
				while (a[idx][0] != tmp) {
					pls[++ss] = Mp(idx, i);
					a[i][++a[i][0]] = a[idx][a[idx][0]--];
				}
				pls[++ss] = Mp(n + 1, idx);
				a[idx][++a[idx][0]] = a[n + 1][a[n + 1][0]--];
				f--;
			}
		}
		bool ggg = 0;
		while (a[i][0] < m && a[n + 1][a[n + 1][0]] != col) {
			if (a[n + 1][a[n + 1][0]] == col) ggg = true;
			pls[++ss] = Mp(n + 1, i);
			a[i][++a[i][0]] = a[n + 1][a[n + 1][0]--];
		} if (ggg) goto gggg;
	}
	
	int gg = 0;
	for (int i = 1; i <= a[n + 1][0]; i++)
		if (a[n + 1][i] == col) gg++;
	
	for (int i = 1; i <= n; i++) {
		if (i == idx) continue;
		while (gg > 0) {
			if (a[n + 1][a[n + 1][0]] == col) { gg--; pls[++ss] = Mp(n + 1, idx), a[idx][++a[idx][0]] = a[n + 1][a[n + 1][0]--]; continue; }
			int tmp = a[idx][0];
			pls[++ss] = Mp(i, idx);
			a[idx][++a[idx][0]] = a[i][a[i][0]--];
			while (a[n + 1][a[n + 1][0]] != col) {
				pls[++ss] = Mp(n + 1, idx);
				a[idx][++a[idx][0]] = a[n + 1][a[n + 1][0]--];
			}
			pls[++ss] = Mp(n + 1, i);
			a[i][++a[i][0]] = a[n + 1][a[n + 1][0]--];
			while (a[idx][0] != tmp) {
				pls[++ss] = Mp(idx, n + 1);
				a[n + 1][++a[n + 1][0]] = a[idx][a[idx][0]--];
			}
			pls[++ss] = Mp(i, idx);
			a[idx][++a[idx][0]] = a[i][a[i][0]--];
			gg--;
		}
		while (a[n + 1][0] > 0) {
			pls[++ss] = Mp(n + 1, i);
			a[i][++a[i][0]] = a[n + 1][a[n + 1][0]--];
		}
	}
	++tot; vis[idx] = 1;
}

int main() {
	freopen("ball.in", "r", stdin);
	freopen("ball.out", "w", stdout);
	read(n), read(m);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) read(a[i][j]);
		a[i][0] = m;
	}
	
	while (tot != n) solve(); writeln(ss, '\n');
	for (int i = 1; i <= ss; i++) writeln(pls[i].first, ' '), writeln(pls[i].second, '\n');
	return 0;
}

/*
2 3
1 1 2
2 1 2
*/
