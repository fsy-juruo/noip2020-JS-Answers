#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN = 5e5 + 10, MAXK = 15, MOD = 1e9 + 7;
int n, k, w[MAXK], c[MAXN], d[MAXN], ans[MAXN];

int main()
{
    freopen("walk.in", "r", stdin);
    freopen("walk.out", "w", stdout);
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= k; i++) scanf("%d", w + i);
    for (int i = 1; i <= n; i++) scanf("%d%d", c + i, d + i);
    if (k == 1) {
	int now = 0, res = 0;
	for (int i = 1; i <= n; i++) {
	    now += d[i];
	    if (now > 0) {
		for (int j = w[1] - now + 1; j <= w[1]; j++) if (j > 0) if (!ans[j]) ans[j] = i % MOD;
	    } else if (now < 0) {
		int t = -now;
		for (int j = 1; j <= t; j++) if (!ans[j]) ans[j] = i % MOD;
	    }
	}
	for (int i = 1; i <= w[i]; i++) {
	    if (!ans[i]) {
		cout << -1 << endl;
		return 0;
	    }
	    res = (res + ans[i]) % MOD;
	}
	printf("%d\n", res);
    }
    cout << -1 << endl;
    return 0;
}
