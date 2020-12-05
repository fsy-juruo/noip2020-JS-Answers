#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll rd() {
	ll s = 0, f = 1;
	char x = getchar();
	for (; !isdigit(x); x = getchar()) if (x == '-') f = -1;
	for (; isdigit(x); x = getchar()) s = s*10+x-48;
	return s*f;
}

const int N = 1e5+10;
int n, m;
int k[N], s[N], f[N], h[N], t[N][6];
ll p[N], q[N];

bool cmp(int a, int b) {
	return f[a] < f[b];
}

ll gcd(ll a, ll b) {
	if (a%b == 0)
		return b; else
		return gcd(b, a%b);
}

void add(int x, int y) {
	p[x] = p[x]*q[y]+p[y]*q[x];
	q[x] = q[x]*q[y];
	ll g = gcd(p[x], q[x]);
	p[x] /= g;
	q[x] /= g;
	return;
}

void cdt(int v) {
	if (f[v] != 0 || s[v] == 0 || h[v] == 1) return;
	h[v] = 1;
	q[v] *= s[v];
	for (int i = 1; i <= s[v]; i++) {
		add(t[v][i], v);
		f[t[v][i]]--;
		cdt(t[v][i]);
	}
	return;
}

int main() {
	freopen("water.in", "r", stdin);
	freopen("water.out", "w", stdout);
	n = rd();
	m = rd();
	for (int i = 1; i <= n; i++) {
		k[i] = i;
		s[i] = rd();
		q[i] = 1;
		for (int j = 1; j <= s[i]; j++) {
			t[i][j] = rd();
			f[t[i][j]]++;
		}
	}
	for (int i = 1; i <= n; i++) if (f[i] == 0) p[i] = 1;
	sort(k+1, k+n+1, cmp);
	for (int i = 1; i <= n; i++) cdt(i);
	for (int i = 1; i <= n; i++) if (s[i] == 0) cout << p[i] << ' ' << q[i] << endl;
	return 0;
}

