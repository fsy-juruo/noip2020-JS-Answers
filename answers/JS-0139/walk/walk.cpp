#include <bits/stdc++.h>
using namespace std;

const int B = 1000000;
const int mod = 1000000007;
const int INF = 0x3f3f3f3f;

int n, k;
int W[20];
int step[10][2000010];
int ans[10][2000010];

struct State {
	int a[10], minj[10], maxj[10];
	void init() {memset(a, 0, sizeof(a)), memset(minj, 0, sizeof(minj)), memset(maxj, 0, sizeof(maxj));}
	void modify(int x, int v, int cnt) {
		a[x] += v, minj[x] = min(minj[x], a[x]), maxj[x] = max(maxj[x], a[x]);
		if (step[x][a[x] + B] == INF) step[x][a[x] + B] = cnt;
	}
	State operator + (const State &A) const {
		State res;
		for (int i = 0; i < k; i++) {
			res.a[i] = a[i] + A.a[i];
			res.minj[i] = min(minj[i], a[i] + A.minj[i]);
			res.maxj[i] = max(maxj[i], a[i] + A.maxj[i]);
		}
		return res;
	}
};

int a[20];
int A[20];
int C[500010], D[500010];

const int mx_step = 1000000;

int calc() {
	for (int i = 0; i < k; i++) {
		A[i] = a[i];
	}
	int cur = 0, step = 0;
	while (step < mx_step) {
		A[C[cur]] += D[cur], step++;
		if (A[C[cur]] < 1 || A[C[cur]] > W[C[cur]]) break;
		cur++;
		if (cur == n) cur = 0;
	}
	if (step == mx_step) {
		printf("-1\n");
		exit(0);
	}
	return step;
}

int dfs(int now) {
	if (now == k) return calc();
	int res = 0;
	for (int i = 1; i <= W[now]; i++) {
		a[now] = i;
		res += dfs(now + 1);
	}
	return res;
}

void solve() {
	for (int i = 0; i < n; i++) {
		scanf("%d%d", &C[i], &D[i]);
		C[i]--;
	}
	printf("%d\n", dfs(0));
}

void solve1() {
	memset(step, 0x3f, sizeof(step));
	for (int i = 0; i < k; i++) {
		step[i][0 + B] = 0;
	}
	State cur; cur.init();
	for (int i = 0; i < n; i++) {
		int c, d; scanf("%d%d", &c, &d);
		c--;
		cur.modify(c, d, i + 1);
	}
	long long ans = 0;
	for (int i = 1; i <= W[0]; i++) {
		int L = i + cur.minj[0], R = i + cur.maxj[0];
		int pos = i;
		int need;
		if (L < 1 || R > W[0]) need = 0;
		else {
			if (cur.a[0] == 0) {
				printf("-1\n");
				return ;
			}
			int len = abs(cur.a[0]);
			if (cur.a[0] < 0) need = (L + len - 1) / len;
			else need = (W[0] - R + 1 + len - 1) / len;
		}
		L += need * cur.a[0], R += need * cur.a[0];
		pos += need * cur.a[0];
		ans = (ans + 1ll * need * n) % mod;
		ans = (ans + min(step[0][-pos + B], step[0][W[0] - pos + 1 + B])) % mod;
	}
	printf("%lld\n", ans);
}

void solve2() {
	memset(step, 0x3f, sizeof(step));
	for (int i = 0; i < k; i++) {
		step[i][0 + B] = 0;
	}
	State cur; cur.init();
	for (int i = 0; i < n; i++) {
		int c, d; scanf("%d%d", &c, &d);
		c--;
		cur.modify(c, d, i + 1);
	}
	for (int it = 0; it < k; it++) {
		for (int i = 1; i <= W[it]; i++) {
			int L = i + cur.minj[it], R = i + cur.maxj[it];
			int pos = i;
			int need;
			if (L < 1 || R > W[it]) need = 0;
			else {
				if (cur.a[it] == 0) {
					printf("-1\n");
					return ;
				}
				int len = abs(cur.a[it]);
				if (cur.a[it] < 0) need = (L + len - 1) / len;
				else need = (W[it] - R + 1 + len - 1) / len;
			}
			L += need * cur.a[it], R += need * cur.a[it];
			pos += need * cur.a[it];
			ans[it][i] = (1ll * need * n + min(step[it][-pos + B], step[it][W[it] - pos + 1 + B])) % mod;
		}
	}
	for (int it = 0; it < k; it++) {
		sort(ans[it] + 1, ans[it] + W[it] + 1);
	}
	long long res = 0;
	for (int it = 0; it < k; it++) {
		int pos[10] = {};
		for (int i = 0; i < k; i++) {
			pos[i] = W[i];
		}
		for (int i = W[it]; i >= 1; i--) {
			long long mul = 1;
			for (int j = 0; j < it; j++) {
				while (pos[j] >= 1 && ans[j][pos[j]] > ans[it][i]) pos[j]--;
				mul = mul * (W[j] - pos[j]) % mod;
			}
			for (int j = it + 1; j < k; j++) {
				while (pos[j] >= 1 && ans[j][pos[j]] >= ans[it][i]) pos[j]--;
				mul = mul * (W[j] - pos[j]) % mod;
			}
			res = (res + mul * ans[it][i]) % mod;
		}
	}
	printf("%lld\n", res);
}

int main() {
	freopen("walk.in", "r", stdin);
	freopen("walk.out", "w", stdout);
	scanf("%d%d", &n, &k);
	for (int i = 0; i < k; i++) {
		scanf("%d", &W[i]);
	}
	if (n <= 100) {
		solve();
		return 0;
	}
	if (k == 1) {
		solve1();
		return 0;
	}
	solve2();
	return 0;
}
/*
3 2
3 3
1 1
2 -1
1 1

5 4
6 8 6 5
3 1
2 1
1 1
2 1
2 -1


*/
