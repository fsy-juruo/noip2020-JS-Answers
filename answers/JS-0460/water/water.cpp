#include <bits/stdc++.h>
using namespace std;
const long long maxn = 1e5 + 10;
long long n, m, rudu[maxn], p[maxn], q[maxn];
vector <int> e[maxn];
queue <int> Q;
long long rd() {
	long long x = 0, f = 1;
	char ch = getchar();
	for (; !isdigit(ch); ch = getchar()) {
		if (ch == '-') {
			f = -f;
		}
	}
	for (; isdigit(ch); ch = getchar()) {
		x = (x << 1) + (x << 3) + (ch ^ 48);
	}
	return x * f;
}
long long GCD(long long a, long long b) {
	if (b == 0) {
		return a;
	}
	return GCD(b, a % b);
}
void add(long long u, long long x, long long y) {
	long long a = p[u] * y + q[u] * x, b = q[u] * y;
	long long d = GCD(a, b);
	p[u] = a / d;
	q[u] = b / d;
}
int main() {
	freopen("water.in", "r", stdin);
	freopen("water.out", "w", stdout);
	n = rd();
	m = rd();
	for (long long i = 1; i <= n; i++) {
		long long t = rd();
		for (long long j = 1; j <= t; j++) {
			long long x = rd();
			e[i].push_back(x);
			rudu[x]++;
		}
	}
	for (long long i = 1; i <= n; i++) {
		q[i] = 1;
	}
	for (long long i = 1; i <= n; i++) {
		if (rudu[i] == 0) {
			p[i] = 1;
			Q.push(i);
		}
	}
	while (!Q.empty()) {
		long long u = Q.front();
		Q.pop();
		long long tot = e[u].size();
		for (long long i = 0; i < tot; i++) {
			long long v = e[u][i];
			add(v, p[u], q[u] * tot);
			rudu[v]--;
			if (rudu[v] == 0) {
				Q.push(v);
			}
		}
	}
	for (long long i = 1; i <= n; i++) {
		if (e[i].size() == 0) {
			cout << p[i] << " " << q[i] << endl;
		}
	}
	return 0;
}

