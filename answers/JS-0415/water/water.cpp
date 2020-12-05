#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const int MAXN = 100005;
int que[MAXN], deg[MAXN], n, m;
vector<int> out[MAXN];
LL gcd(LL x, LL y) {
	return y == 0 ? x : gcd(y, x % y);
}

struct Frac {
	LL x, y;
	Frac() { x = 0, y = 1; }
	Frac(LL a, LL b) { x = a, y = b; }
	
	Frac operator+=(const Frac &f) {
		x = x * f.y + y * f.x;
		y *= f.y;
		LL g = gcd(x, y);
		x /= g, y /= g;
		return *this;
	}
} f[MAXN];

int main() {
	freopen("water.in", "r", stdin);
	freopen("water.out", "w", stdout);
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		int d; scanf("%d", &d);
		for (int j = 1; j <= d; j++) {
			int c; scanf("%d", &c);
			out[i].push_back(c);
			++deg[c];
		}
	}
	int he = 1, ta = 0;
	for (int i = 1; i <= n; i++) if (!deg[i])
		que[++ta] = i, f[i] = Frac(1, 1);
	while (he <= ta) {
		int u = que[he++];
		for (int i = 0; i < (int)out[u].size(); i++) {
			int v = out[u][i];
			if (!--deg[v]) que[++ta] = v;
		}
	}
	for (int i = 1; i <= n; i++) {
		int u = que[i], d = out[u].size();
		if (!d) {
			LL g = gcd(f[u].x, f[u].y);
			f[u].x /= g, f[u].y /= g;
		}
		Frac t = f[u]; t.y *= d;
		for (int j = 0; j < (int)out[u].size(); j++) {
			int v = out[u][j];
			f[v] += t;
		}
	}
	for (int i = 1; i <= n; i++) if (out[i].empty())
		printf("%lld %lld\n", f[i].x, f[i].y);
	return 0;
}
