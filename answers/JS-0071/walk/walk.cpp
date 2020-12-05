#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for(int i = 0; i < (int)(n); i ++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i ++)
#define MP make_pair
typedef long long LL;
typedef pair<int, int> PII;
const int MOD = 1e9 + 7;

int n, k, w[15], c[500005], d[500005];
int pos[1000005][15], minp[1000005][15], maxp[1000005][15];

int dim[15], dif[15];
int inv[15], coef[15], pc[15], sc[15], eval[15];

int ans;
void calc0()
{
	rep1(i, k) if(dim[i] <= 0) return;
	
	int ca = 1;
	rep1(i, k) ca = 1LL * ca * dim[i] % MOD;
	ans = (ans + ca) % MOD;
}

void calc1()
{
	
	rep1(i, k) if(dim[i] <= 0) return;
	bool hv = false;
	rep1(i, k) if(dif[i] != 0) hv = true;
	if(!hv) ans = -1;
	if(ans == -1) return;
	
	int lb = MOD;
	rep1(i, k) if(dif[i] != 0) lb = min(lb, (dim[i] - 1) / dif[i] + 1);
	
	eval[0] = 0;
	rep(i, min(k + 2, lb)) {
		int ca = 1;
		rep1(j, k) ca = 1LL * ca * (dim[j] - dif[j] * i) % MOD;
		eval[i + 1] = (eval[i] + ca) % MOD;
	}
	if(lb <= k + 2) {
		ans = (ans + eval[lb]) % MOD; return;
	}
	
	pc[0] = 1;
	rep(i, k + 1) pc[i + 1] = 1LL * pc[i] * (lb - i) % MOD;
	sc[k + 1] = 1;
	for(int i = k + 1; i >= 1; i --) sc[i - 1] = 1LL * sc[i] * (lb - i) % MOD;
	rep(i, k + 2) ans = (ans + 1LL * pc[i] * sc[i] % MOD * coef[i] % MOD * eval[i]) % MOD;
}

int main()
{
	freopen("walk.in", "r", stdin);
	freopen("walk.out", "w", stdout);
	
	scanf("%d%d", &n, &k);
	rep1(i, k) scanf("%d", &w[i]);
	rep1(i, n) scanf("%d%d", &c[i], &d[i]);
	
	rep1(i, 2 * n) {
		rep1(j, k) {
			pos[i][j] = pos[i - 1][j];
			minp[i][j] = minp[i - 1][j];
			maxp[i][j] = maxp[i - 1][j];
		}
		int cur = c[i > n ? i - n : i];
		pos[i][cur] += d[i > n ? i - n : i];
		minp[i][cur] = min(minp[i][cur], pos[i][cur]);
		maxp[i][cur] = max(maxp[i][cur], pos[i][cur]);
	}
	
	rep(i, n) {
		rep1(j, k) dim[j] = w[j] - maxp[i][j] + minp[i][j];
		calc0();
	}
	
	rep1(i, k + 2) inv[i] = i == 1 ? 1 : MOD - 1LL * inv[MOD % i] * (MOD / i) % MOD;
	rep(i, k + 2) {
		coef[i] = 1;
		rep1(j, i) coef[i] = 1LL * coef[i] * inv[j] % MOD;
		rep1(j, k + 1 - i) coef[i] = 1LL * coef[i] * (MOD - inv[j]) % MOD;
	}
	
	rep1(j, k) dif[j] = pos[n][j] < 0 ? -pos[n][j] : pos[n][j];
	rep(i, n) {
		rep1(j, k) dim[j] = w[j] - maxp[i + n][j] + minp[i + n][j];
		calc1();
	}
	
	printf("%d\n", ans);
	return 0;
}
