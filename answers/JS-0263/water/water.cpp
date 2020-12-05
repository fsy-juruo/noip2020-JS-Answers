#include <bits/stdc++.h>
using namespace std;
template <typename T>
void readin(T &x) {
	x = 0;
	char ch = getchar();
	T fh = 1;
	for (; !isdigit(ch); ch = getchar()) if (ch == '-') fh = -1;
	for (; isdigit(ch); ch = getchar()) x = (x << 1) + (x << 3) + (ch ^ 48);
	x *= fh;
}
template <typename T>
void wt(T x) {
	if (x > 9) wt(x / 10);
	putchar(x % 10 + 48);
}
template <typename T>
void writeln(T x, char ch) {
	if (x < 0) {
		putchar('-');
		x = -x;
	}
	wt(x);
	putchar(ch);
}
const int N = 1e5 + 5;
vector <int> v[N];
struct info{
	long long mol, inv;
}b[10], a[N], res;
long long gcd(long long x, long long y) {
	if (!y) return x;
	return gcd(y, x % y);
}
void add(info &x, info y) {
	long long tmp = x.mol * y.inv + x.inv * y.mol, tnp = x.inv * y.inv;
	long long u = gcd(tmp, tnp);
	tmp /= u;
	tnp /= u;
	x = (info) {tmp, tnp};
	return;
}
void mul(info &x, info y) {
	long long tmp = x.mol * y.mol, tnp = x.inv * y.inv;
	long long u = gcd(tmp, tnp);
	tmp /= u;
	tnp /= u;
	x = (info) {tmp, tnp};
	return;
}
queue <int> q;
int r[N];
int main() {
	freopen("water.in", "r", stdin);
	freopen("water.out", "w", stdout);
	b[1] = (info) {1, 1};
	b[2] = (info) {1, 2};
	b[3] = (info) {1, 3};
	b[4] = (info) {1, 4};
	b[5] = (info) {1, 5};
	int kk, x, n, m;
	readin(n); readin(m);
	for (int i = 1; i <= n; i ++) {
		readin(kk);
		v[i].clear();
		for (int j = 1; j <= kk; j ++) {
			readin(x);
			r[x] ++;
			v[i].push_back(x);
		}
	}
	for (int i = 1; i <= m; i ++) {
		a[i] = (info) {1, 1};
		q.push(i);
	}
	for (int i = m + 1; i <= n; i ++) {
		a[i] = (info) {0, 1};
	}
	int d, u;
	while (!q.empty()) {
		d = q.front();
		q.pop();
		if (v[d].empty()) continue;
		res.mol = a[d].mol;
		res.inv = a[d].inv;
		mul(res, b[v[d].size()]);
		for (int i = 0; i < v[d].size(); i ++) {
			u = v[d][i];
			r[u] --;
			add(a[u], res);
			if (!r[u]) q.push(u);
		}
	}
	for (int i = 1; i <= n; i ++) {
		if (v[i].empty()) {
			writeln(a[i].mol, ' ');
			writeln(a[i].inv, '\n');
		}
	}
	return 0;
}

