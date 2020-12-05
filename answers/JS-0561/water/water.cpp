#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
long long gcd(long long x, long long y) {
	return y ? gcd(y, x % y) : x;
}
struct Frac {
	long long x, y;
	inline Frac(long long _x = 0, long long _y = 1) {
		x = _x, y = _y;
		long long g = gcd(x, y);
		x /= g, y /= g;
	}
	inline Frac operator + (const Frac &oth) const {
		long long g = gcd(y, oth.y);
		return Frac(oth.y / g * x + y / g * oth.x, y / g * oth.y);
	}
} a[N];
int n, m, deg[N], que[N];
vector<int> G[N];
int main() {
	freopen("water.in", "r", stdin);
	freopen("water.out", "w", stdout);
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		int tmp;
		scanf("%d", &tmp);
		G[i].resize(tmp);
		for (int j = 0; j < (int)G[i].size(); j++) {
			scanf("%d", &G[i][j]);
			deg[G[i][j]]++;
		}
	}
	for (int i = 1; i <= m; i++) a[i] = Frac(1, 1);
	int ql = 1, qr = 0;
	for (int i = 1; i <= n; i++) if (!deg[i]) que[++qr] = i;
	while (ql <= qr) {
		int u = que[ql++];
		Frac cur(a[u].x, a[u].y * G[u].size());
		for (int j = 0; j < (int)G[u].size(); j++) {
			int v = G[u][j];
			a[v] = a[v] + cur;
			deg[v]--;
			if (!deg[v]) que[++qr] = v;
		}
	}
	for (int i = 1; i <= n; i++) if (G[i].empty()) printf("%lld %lld\n", a[i].x, a[i].y);
	return 0;
}
