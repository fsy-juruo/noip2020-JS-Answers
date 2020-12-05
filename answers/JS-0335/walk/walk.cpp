#include<cstdio>
#include<cstring>
#include<algorithm>
#define INF 0x3f3f3f3f
#define MaxN 1010

typedef long long LL;

const int mod = 1e9 + 7;

int n, k, mx[MaxN], mn[MaxN], now[MaxN], w[MaxN], c[MaxN], d[MaxN], sum[MaxN], _now[MaxN];
LL ans;

int main() {
	freopen("walk.in", "r", stdin);
	freopen("walk.out", "w", stdout);
	scanf("%d %d", &n, &k);
	if (n >= 1e5) {puts("-1"); return 0;}
	for (int i = 1; i <= k; ++i) mx[i] = -INF, mn[i] = INF, now[i] = 1;
	for (int i = 1; i <= k; ++i) scanf("%d", &w[i]);
	for (int i = 1; i <= n; ++i) {
		scanf("%d %d", &c[i], &d[i]);
		sum[c[i]] += d[i];
		if (sum[c[i]] > mx[c[i]]) mx[c[i]] = sum[c[i]];
		if (sum[c[i]] < mn[c[i]]) mn[c[i]] = sum[c[i]];
	}
	bool flag = 1;
	for (int i = 1; i <= k; ++i)
		if (sum[i] != 0) flag = 0;
	if (flag) {
		for (int i = 1; i <= k; ++i)
			if (mx[i] - mn[i] > w[i]) {flag = 0; break;}
	}
	if (flag) {
		puts("-1");
		return 0;
	}
	for (int i = 1; i <= k; ++i) {
		if (mx[i] == -INF) mx[i] = 0;
		if (mn[i] == INF) mn[i] = 0;
	}
	while (1) {
		int steps = INF, cnt = 1;
		if (now[0]) break;
		for (int i = 1; i <= k; ++i) _now[i] = now[i];
		while (1) { 
			bool flag = 0;
			for (int i = 1; i <= k; ++i)
				if (_now[i] > w[i] || _now[i] < 1) {flag = 1; break;}
			if (flag) break;
			_now[c[cnt]] += d[cnt];
			cnt = (cnt == n) ? 1 : cnt + 1;
			++ans; ans %= mod;
		}
		flag = 0; ++now[k];
		for (int i = k; i; --i)
			if (now[i] > w[i]) now[i] = 1, ++now[i - 1];
			else break;
	}
	printf("%d\n", ans);
	return 0;
}
