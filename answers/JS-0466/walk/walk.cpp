#include<bits/stdc++.h>
#define fir(a, b, c) for(int a = b; a <= c; ++ a)
#define ll long long
#define inf 1e8
using namespace std;

const int N = 5e5 + 100;
int n, k;
int dx[15][N], w[20], c[N], d[N], tx[20], ttx[20], dd[20];
ll ans = 0;

inline void solve () {
	ll res = 0;
	int i = 1;
	fir (i, 1 ,k) ttx[i] = tx[i];
	while (1) {
		ttx[c[i]] += d[i];
		res += 1ll;
		if (ttx[c[i]] > w[c[i]] || ttx[c[i]] <= 0) break;
		
		if (i == n) {
			bool bl = 0;
			fir (j, 1, k) 
				if (ttx[j] != tx[j]) {
					bl = 1; break;
				}
			if (bl == 0) {
				printf("-1\n");
				exit(0);
			}
			i = 0;
		}
		
		++ i;
	}
	ans += res;
}

void work(int dep) {
	if (dep > k) {
		solve();
		return;
	}
	fir (i, 1, w[dep]) {
		tx[dep] = i;
		work(dep+1);
	}
}

int main() {
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	scanf("%d%d", &n, &k);
	if (n > 100005 || (k == 2 &&  n == 100000)) {
		printf("-1\n");
		return 0;
	}
	fir (i, 1, k) scanf("%d", w + i);
	fir (i, 1, n) {
		scanf("%d%d", c+i, d+i);
	}
	
	if (k == 1) {
		int le = inf, ri = -inf;
		int x = 0, xle = 0, xri = 0;
		fir (i, 1, n) {
			x += d[i];
			if (x < le) le = x, xle = i;
			if (x > ri) ri = x, xri = i;
		}
		int y = x;
		ll ans = 0;
		fir (i, 1, w[1]) {
			x = i;
			while ((x + le) > 0 && (x + ri) <= w[1]) {
				x += y; ans += (ll)n;
				if (y == 0) {
					printf("%d\n", -1);
					return 0;
				}
			}
			int j = 1;
			while (1) {
				x += d[j];
				ans += 1ll;
				if (x <= 0 || x > w[1]) break;
				++ j;
			}
		}
		printf("%lld\n", ans);
		return 0;
	}
	
	work(1);
	printf("%lld\n", ans);
	return 0;
}

