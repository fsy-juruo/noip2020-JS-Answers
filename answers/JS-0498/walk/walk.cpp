/* by Hyperhydrochloric Acid */
#include <bits/stdc++.h>
using namespace std;
#define SZ(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define loop(i, a) for(int i = 0; i < (a); ++i)
#define cont(i, a) for(int i = 1; i <= (a); ++i)
#define circ(i, a, b) for(int i = (a); i <= (b); ++i)
#define range(i, a, b, c) for(int i = (a); (c) > 0 ? (i <= (b)) : (i >= (b)); i += c)
#define foreach(it, x) for(__typeof((x).begin()) it = (x).begin(); it != (x).end(); ++it)
#define pub push_back
#define pob pop_back
#define mak make_pair
typedef long long ll;
typedef long double lf;
const int Inf = 0x3f3f3f3f;
const ll INF = 0x3f3f3f3f3f3f3f3fll;
/* Source code starts here */

const int jt = 1000000007;
int mx[11], mn[11], sm[11];
int n, k;
int wd[11][1 << 20];
int w[11];
int L[11], rr[11];

bool comp(pair<int, int> a, pair<int, int> b) {
	if(wd[a.first][a.second] == wd[b.first][b.second]) return a < b;
	return wd[a.first][a.second] < wd[b.first][b.second];
}

int main() {
	#ifndef HCl10
	freopen("walk.in", "r", stdin);
	freopen("walk.out", "w", stdout);
	#endif
	scanf("%d%d", &n, &k);
	cont(i, k) scanf("%d", w + i);
	memset(wd, Inf, sizeof(wd));
	cont(i, n) {
		int c, d; scanf("%d%d", &c, &d);
		sm[c] += d;
		if(sm[c] < 0) wd[c][-sm[c]] = min(wd[c][-sm[c]], i);
		if(sm[c] > 0 && sm[c] <= w[c]) wd[c][w[c] + 1 - sm[c]] = min(wd[c][w[c] + 1 - sm[c]], i);
	}
	cont(i, k) range(j, w[i], 1, -1) {
		if(sm[i] < 0) continue;
		if(!sm[i]);
		else if(j <= w[i] - sm[i]) wd[i][j] = min(wd[i][j], wd[i][j + sm[i]] + n);
	}
	cont(i, k) cont(j, w[i]) {
		if(sm[i] > 0) continue;
		if(!sm[i]);
		else if(j > -sm[i]) wd[i][j] = min(wd[i][j], wd[i][j + sm[i]] + n);
	}
	cont(i, k) L[i] = 1, rr[i] = w[i];
	vector<pair<int, int> > vec;
	cont(i, k) cont(j, w[i]) vec.pub(mak(i, j));
	sort(all(vec), comp);
	int ans = 0;
	loop(i, SZ(vec)) {
		pair<int, int> now = vec[i];
		int x = now.first, y = now.second;
		if(wd[x][y] == Inf) return puts("-1"), 0;
		ll pro = 1;
		cont(j, k) if(x != j) pro = 1ll * pro * (rr[j] - L[j] + 1) % jt;
		ans = (ans + pro * wd[x][y]) % jt;
		if(L[x] == y) ++L[x];
		else --rr[x];
		if(L[x] > rr[x]) break;
	}
	printf("%d\n", ans);
	return 0;
}
