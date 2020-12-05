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

const int Maxn = 1e5 + 5, Maxm = 1e6 + 5;
int n, m, cnt = 0, head[Maxn], ver[Maxm], nxt[Maxm];
inline void AddEdge(int u, int v) {
	ver[++cnt] = v, nxt[cnt] = head[u], head[u] = cnt;
}

inline ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b); }

struct FS {
	ll fz, fm;
	FS(ll FZ = 0, ll FM = 1) : fz(FZ), fm(FM) {}
	inline FS operator + (const FS&rhs) const {
		ll FM = fm * rhs.fm;
		ll FZ = fz * rhs.fm + fm * rhs.fz;
		ll D = gcd(FZ, FM);
		return FS(FZ / D, FM / D);
	}
} fs[Maxn];

int deg[Maxn], num[Maxn]; queue <int> q;

int main() {
	freopen("water.in", "r", stdin);
	freopen("water.out", "w", stdout);
	read(n), read(m);
	for (int u = 1; u <= n; u++) {
		int t; read(t); num[u] = t;
		while (t--) {
			int v; read(v);
			AddEdge(u, v);
			++deg[v];
		}
	}
	
	for (int i = 1; i <= m; i++) q.push(i), fs[i] = FS(1, 1);
	while (!q.empty()) {
		int u = q.front(); q.pop();
		FS w = fs[u]; w.fm = 1ll * w.fm * num[u];
		for (int i = head[u]; i; i = nxt[i]) {
			fs[ver[i]] = fs[ver[i]] + w;
			--deg[ver[i]];
			if (deg[ver[i]] == 0) q.push(ver[i]);
		}
	}
	
	for (int i = 1; i <= n; i++) {
		if (num[i] > 0) continue;
		writeln(fs[i].fz, ' ');
		writeln(fs[i].fm, '\n');
	}
	return 0;
}

/*
5 1
3 2 3 5
2 4 5
2 5 4
0
0
*/
