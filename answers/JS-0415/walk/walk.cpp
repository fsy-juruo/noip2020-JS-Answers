#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const int MAXN = 1000005, MOD = 1e9 + 7;
int n, K, w[20], lim[MAXN], rim[MAXN], sum[20];
LL inv[MAXN];
struct Data { int a, b; };
vector<Data> dx[20];
struct Val {
	LL a; int b;
	bool operator<(const Val &v) const { return a < v.a; }
} val[MAXN * 10];

int main() {
	freopen("walk.in", "r", stdin);
	freopen("walk.out", "w", stdout);
	scanf("%d%d", &n, &K);
	for (int i = 1; i <= K; i++) scanf("%d", w + i);
	for (int i = 1; i <= n; i++) {
		int a, b; scanf("%d%d", &a, &b);
		dx[a].push_back((Data) { i, b });
	}
	int cnt = 0;
	bool nag = 1;
	for (int i = 1; i <= K; i++) {
		int m = dx[i].size(), s = 0, mx = 0, mn = 0;
		memset(lim, 0, sizeof(lim));
		memset(rim, 0, sizeof(rim));
		for (int j = 0; j < m; j++) {
			s += dx[i][j].b;
			mx = max(mx, s);
			mn = min(mn, s);
			if (!lim[-mn]) lim[-mn] = dx[i][j].a;
			if (!rim[mx]) rim[mx] = dx[i][j].a;
		}
		if (s != 0 || mx - mn + 1 > w[i]) nag = 0;
		int st = cnt;
		for (int j = 1; j <= w[i]; j++) {
			if (s == 0) {
				LL l = lim[j], r = rim[w[i] - j + 1];
				if (l == 0) l = 1e18;
				if (r == 0) r = 1e18;
				val[++cnt] = (Val) { min(l, r), i };
			} else if (s > 0) {
				LL l = lim[j], r;
				if (l == 0) l = 1e18;
				if (w[i] - j + 1 > mx) {
					int t = (w[i] - j - mx + s) / s;
					int rem = w[i] - j + 1 - t * s;
					assert(rem <= mx && rem > 0);
					r = (LL)n * t + rim[rem];
				} else r = rim[w[i] - j + 1];
				val[++cnt] = (Val) { min(l, r), i };
			} else {
				LL l, r = rim[w[i] - j + 1];
				if (r == 0) r = 1e18;
				if (j > -mn) {
					int t = (j + mn - s - 1) / (-s);
					int rem = j - t * (-s);
					assert(rem <= -mn && rem > 0);
					l = (LL)n * t + lim[rem];
				} else l = lim[j];
				val[++cnt] = (Val) { min(l, r), i };
			}
		}
		mx = 0;
		for (int i = st + 1; i <= cnt; i++)
			if (!mx || val[i].a > val[mx].a) mx = i;
//		for (int i = st + 1; i < mx; i++) assert(val[i].a <= val[i + 1].a);
//		for (int i = mx; i < cnt; i++) assert(val[i].a >= val[i + 1].a);
		reverse(val + mx + 1, val + 1 + cnt);
		inplace_merge(val + st + 1, val + mx + 1, val + cnt + 1);
		inplace_merge(val + 1, val + st + 1, val + cnt + 1);
	}
	if (nag) puts("-1");
//	sort(val + 1, val + 1 + cnt);
//	for (int i = 1; i <= cnt; i++)
//		printf("%lld %d\n", val[i].a, val[i].b);
	inv[1] = 1;
	for (int i = 2; i <= 1000000; i++)
		inv[i] = MOD - (LL)(MOD / i) * inv[MOD % i] % MOD;
	LL ans = 0, mul = 1;
	int c0 = K;
	for (int i = cnt; i > 0; i--) {
		int b = val[i].b; LL cur = 0;
		if (c0 == 1 && sum[b] == 0) cur = mul;
		else if (c0 == 0) cur = mul * inv[sum[b]] % MOD;
		ans = (ans + cur * val[i].a) % MOD;
		if (!sum[b]) --c0;
		else mul = mul * inv[sum[b]] % MOD * (sum[b] + 1) % MOD;
		++sum[b];
	}
	printf("%lld\n", ans % MOD);
	return 0;
}
