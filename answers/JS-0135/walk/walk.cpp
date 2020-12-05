#include<bits/stdc++.h>

#define LL long long
#define ull unsigned long long
#define F(i,j,k) for(int i = j; i <= k; ++i)
#define DF(i,j,k) for(int i = j; i >= k; --i)

using namespace std;

template <typename T> inline void read(T &n) {
	T w = 1;
	n = 0;
	char ch = getchar();
	while (!isdigit(ch) && ch != EOF) {
		if(ch == '-') w = -1;
		ch = getchar();
	}
	while (isdigit(ch) && ch != EOF) {
		n = (n << 3) + (n << 1) + (ch & 15);
		ch = getchar();
	}
	n *= w;
}

template <typename T> inline void write(T x) {
	T l = 0;
	ull y = 0;
	if (x < 0) {
		putchar('-');
		x = -x;
	}
	if (!x) {
		putchar(48);
		return;
	}
	while(x) {
		y = y * 10 + x % 10;
		x /= 10;
		++l;
	}
	while(l) {
		putchar(y % 10 + 48);
		y /= 10;
		--l;
	}
}

template <typename T> inline void writes(T x) {
	write(x);
	putchar(' ');
}

template <typename T> inline void writeln(T x) {
	write(x);
	puts("");
}

template <typename T> inline void checkmax(T &a,T b) { a = a > b ? a : b; }

template <typename T> inline void checkmin(T &a,T b) { a = a < b ? a : b; }

const int N = 5e5 +100;

const LL INF = 1e15;

int n, k;

int w[11], col[N], del[N], h[11][11][11][11][11], f = 0, now[11];

LL ans, ff[N];

inline void solve1() {
	int delta = 0, l = 1, r = w[1], nl = 1, nr = w[1];
	ans = 0;
	F(i, 1, n) delta += del[i];
	F(i, 1, w[1] + 100000) ff[i] = INF;
	F(i, 1, n) {
		l += del[i];
		r += del[i];
		nl -= del[i];
		nr -= del[i];
		if (nl >= 0 && nl <= w[1]) checkmin(ff[nl - 1], (long long)i);
		if (nr >= 0 && nr <= w[1]) checkmin(ff[nr + 1], (long long)i);
		if (l <= 0) l++; 
		if (r > w[1]) r--; 
	}
	if (l <= r && delta == 0) { puts("-1"); return; }
	if (delta > 0) {
		DF(i, w[1], 1) {
			checkmin(ff[i], ff[i + delta] + n);
			ans += ff[i];
		}
	}
	else {
		F(i, 1, w[1]) {
			checkmin(ff[i], ff[i + delta] + n);
			ans += ff[i];
		}
	}
	writeln(ans);
}

inline void doit(int a,int b,int c,int d,int e) {
	now[1] = a;
	now[2] = b;
	now[3] = c;
	now[4] = d;
	now[5] = e;
	int pos = 0, s = 0;
	while (1) {
		++s;
		if (s > n && f == 0) { ans = -1; return; }
		pos = (pos + 1) % n;
		if (pos == 0) pos = n;
		now[col[pos]] += del[pos];
		if (now[col[pos]] <= 0 || now[col[pos]] > w[col[pos]]) break;
	}
	ans += s;
}
inline void dfs(int a,int b,int c,int d,int e) {
	if (h[a][b][c][d][e] || ans == -1) return;
	h[a][b][c][d][e] = 1;
	doit(a, b, c, d, e);
	if (ans == -1) return;
	if (a + 1 <= w[1]) dfs(a + 1, b, c, d, e);
	if (b + 1 <= w[2]) dfs(a, b + 1, c, d, e);
	if (c + 1 <= w[3]) dfs(a, b, c + 1, d, e);
	if (d + 1 <= w[4]) dfs(a, b, c, d + 1, e);
	if (e + 1 <= w[5]) dfs(a, b, c, d, e + 1);
}

inline void solve2() {
	dfs(1, 1, 1, 1, 1);
	writeln(ans);
}

int main() {
	freopen("walk.in", "r", stdin);
	freopen("walk.out", "w", stdout);
	read(n);
	read(k);
	F(i, 1, k) read(w[i]);
	F(i, 1, n) {
		read(col[i]);
		read(del[i]);
		now[col[i]] += del[i];
	}
	F(i, 1, k) if(now[i] != 0) f = 1;
	if (n <= 100)
		solve2();
	else 
		solve1();
	return 0;
}
