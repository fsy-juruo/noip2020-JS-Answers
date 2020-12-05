#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

inline ll in() {
	ll x = 0; bool f = 0; char c = getchar();
	while (!isdigit(c)) {
		f |= (c == '-');
		c = getchar();
	} while (isdigit(c)) {
		x = (x << 3) + (x << 1) + (c ^ 48);
		c = getchar();
	}
	return f ? -x : x;
}

const int N = 100010, M = 500010;
int h[N], e[M], ne[M], idx, n, m;
int rd[N], d[N], cd[N];
int solve[N], cnt;

inline ll gcd(ll a, ll b) {
	return b ? gcd(b, a % b) : a;
}

struct frac {
	ll a, b;
	inline void print() {
		printf("%lld %lld\n", a, b);
	}
	inline void good() {
		int g = gcd(a, b);
		a /= g, b /= g;
	}
} w[N];


frac operator + (const frac &A, const frac &B) {
	frac ret = {A.a * B.b + B.a * A.b, A.b * B.b};
	ret.good(); return ret;
}

frac operator / (const frac &A, const ll &b) {
	frac ret = {A.a, A.b * b};
	ret.good(); return ret;
}

inline void add(int x, int y) {
	e[++idx] = y, ne[idx] = h[x], h[x] = idx;
}

int main() {
	freopen("water.in", "r", stdin);
	freopen("water.out", "w", stdout);
	
	n = in(), m = in();
	for (int i = 1; i <= n; i++) {
		d[i] = in();
		if (!d[i]) solve[++cnt] = i;
		else for (int j = 1; j <= d[i]; j++) {
			int x;
			cin >> x;
			add(i, x);
			rd[x]++;
		}
	}
	queue<int> q;
	for (int i = 1; i <= n; i++) {
		w[i].b = 1;
		if (!rd[i]) {
			w[i].a = 1;
			q.push(i);
		}
	}
	while (!q.empty()) {
		int x = q.front(); q.pop();
		if (!d[x]) continue;
		for (int i = h[x]; i; i = ne[i]) {
			int y = e[i];
			w[y] = w[y] + w[x] / d[x];
			if (!(--rd[y])) q.push(y);
		}
	}
	for (int i = 1; i <= cnt; i++)
		w[solve[i]].print();
	
	return 0;
}

