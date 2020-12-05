#include <bits/stdc++.h>
using namespace std;
const int N = 1000005;
const int mod = 1000000007;
struct Node {
	int d, id;
};
int n, m, w[15], inv[N], tot, ps[65536];
long long A[11][N];
pair<long long, int> al[N * 10], bl[N * 10];
vector<Node> buck[15];
int main() {
	inv[1] = 1;
	for (int i = 2; i < N; i++) inv[i] = 1ll * (mod - mod / i) * inv[mod % i] % mod;
	freopen("walk.in", "r", stdin);
	freopen("walk.out", "w", stdout);
	scanf("%d%d", &n, &m);
	int mxw = 0;
	for (int i = 1; i <= m; i++) scanf("%d", &w[i]), mxw = max(mxw, w[i]);
	if (mxw <= 1000000) {
		for (int i = 1; i <= n; i++) {
			int c, d;
			scanf("%d%d", &c, &d);
			Node tmp;
			tmp.d = d;
			tmp.id = i;
			buck[c].push_back(tmp);
		}
		int bad = 1;
		tot = 0;
		for (int i = 1; i <= m; i++) {
			int cur = 0, dl = 0, dr = 0;
			for (int j = 1; j <= w[i]; j++) A[i][j] = -1;
			for (int j = 0; j < (int)buck[i].size(); j++) {
				cur += buck[i][j].d;
				if (cur < dl) {
					dl = cur;
					if (A[i][-dl] == -1) A[i][-dl] = buck[i][j].id;
				} else if (cur > dr) {
					dr = cur;
					if (A[i][w[i] - dr + 1] == -1) A[i][w[i] - dr + 1] = buck[i][j].id;
				}
			}
			if (dr - dl < w[i]) {
				if (cur) {
					bad = 0;
					for (int j = 1; j <= w[i]; j++) if (A[i][j] == -1) {
						int c = (cur > 0 ? (w[i] - dr - j) / cur + 1 : (j + dl - 1) / (-cur) + 1);
						A[i][j] = 1ll * c * n + A[i][j + c * cur];
					}
				}
			} else {
				bad = 0;
			}
			for (int j = 1; j <= w[i]; j++) if (A[i][j] != -1) al[++tot] = make_pair(A[i][j], i);
		}
		if (bad) {
			puts("-1");
			return 0;
		}
		if (tot > 1e5) {
			memset(ps, 0, sizeof(ps));
			for (int i = 1; i <= tot; i++) ps[al[i].first & 65535]++;
			for (int i = 1; i < 65536; i++) ps[i] += ps[i - 1];
			for (int i = tot; i >= 1; i--) bl[ps[al[i].first & 65535]--] = al[i];
			memset(ps, 0, sizeof(ps));
			for (int i = 1; i <= tot; i++) ps[bl[i].first >> 16 & 65535]++;
			for (int i = 1; i < 65536; i++) ps[i] += ps[i - 1];
			for (int i = tot; i >= 1; i--) al[ps[bl[i].first >> 16 & 65535]--] = bl[i];
			memset(ps, 0, sizeof(ps));
			for (int i = 1; i <= tot; i++) ps[al[i].first >> 32 & 65535]++;
			for (int i = 1; i < 65536; i++) ps[i] += ps[i - 1];
			for (int i = tot; i >= 1; i--) bl[ps[al[i].first >> 32 & 65535]--] = al[i];
		} else {
			sort(al + 1, al + 1 + tot);
			for (int i = 1; i <= tot; i++) bl[i] = al[i];
		} 
		int prd = 1;
		for (int i = 1; i <= m; i++) prd = 1ll * prd * w[i] % mod;
		bl[0].first = 0;
		int ans = 0;
		for (int i = 1; i <= tot; i++) {
			ans = (ans + (bl[i].first - bl[i - 1].first) * prd) % mod;
			int pos = bl[i].second;
			prd = 1ll * prd * inv[w[pos]] % mod * (w[pos] - 1) % mod;
			w[pos]--;
			if (!prd) break;
		}
		printf("%d\n", ans);
		return 0;
	} else puts("-1");
	return 0;
}
