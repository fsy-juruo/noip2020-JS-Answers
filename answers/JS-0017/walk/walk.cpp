#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define per(i, a, b) for (int i = a; i >= b; i--)

typedef long long ll;
using namespace std;
const ll mod = 1e9+7;
int n, k;
ll s[500010], up[500010], down[500010], w[500010], A[500010], b[500010], ans;
struct node {
	ll C, D;
} a[500010];
bool flg;

void search(int step) {
	if (step >= k) {
		rep(i, 1, step) b[i] = A[i];
//		puts("");
		for (ll I = 1; ; I++) {
			if (I > n && flg == 0) puts("-1"), exit(0);
			ll i = I%n;
			if (i == 0) i = n;
			b[a[i].C] += a[i].D;
//			printf("%d\n", b[a[i].C]);
			ans++; ans %= mod;
			if (b[a[i].C] > w[a[i].C] || b[a[i].C] < 1) {
//				printf("%lld %lld\n", b[a[i].C], w[a[i].C]);
				break;
			}
		}
		return ;
	}
	rep(i, 1, w[step+1]) {
		A[step+1] = i;
		search(step+1);
	}
}

int main() {
	freopen("walk.in", "r", stdin);
	freopen("walk.out", "w", stdout);
	scanf("%d%d", &n, &k);
	rep(i, 1, k) scanf("%lld", &w[i]);
	rep(i, 1, n) {
		scanf("%lld%lld", &a[i].C, &a[i].D);
		s[a[i].C] += a[i].D;
		up[a[i].C] = max(up[a[i].C], s[a[i].C]);
		down[a[i].C] = min(down[a[i].C], s[a[i].C]);
	}
	rep(i, 1, k) if (s[i] != 0) {flg = 1; break;}
//	if (flg == 0) return puts("-1"), 0;
//	if (k == 1) {
//		printf("%lld %lld %lld\n", s[1], up[1], down[1]);
//		ll S = 0, nk = 1;
//		if (s[1] > 0) {
//			for (ll i = 1; ; i += s[1]) {
//				S++;
//				nk = i;
//				if (i+up[1] > w[1] || i-down[1] < 1) break;
//			}
//		} else {
//			for (ll i = w[1]; ; i += s[1]) {
//				S++;
//				nk = i;
//				if (i+up[1] > w[1] || i-down[1] < 1) break;
//			}
//		}
//		printf("%lld\n", S);
//		ll ans = 0;
//		for (; S >= 1; S--) ans = (ans%mod)+((S%mod)*(s[1]%mod)%mod)%mod;
//		printf("%lld", ans);
//		return 0;
//	}
	if (n <= 100) {
		search(0);
		printf("%lld", ans%mod);
		return 0;
	}
	puts("-1");
	return 0;
}

