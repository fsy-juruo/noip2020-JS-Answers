#include <bits/stdc++.h>
using namespace std;
typedef long long lint;
typedef vector<int> vii;
typedef vector<lint> vll;
typedef unsigned int uint;
typedef pair<int, int> pii;
typedef pair<lint, lint> pll;
typedef unsigned long long ulint;
#define pb push_back
#define mp make_pair
#define SZ(x) ((int) (x).size())
#define all(x) (x).begin(), (x).end()
#define rep(it, ff, ee) for (int it = (ff); it <= (ee); ++it)
#define per(it, ff, ee) for (int it = (ff); it >= (ee); --it)
const int MAXN = (1 << 20) + 5;
char s[MAXN];
int lcs[MAXN], suf[MAXN], per[MAXN];
inline void exKMP(int n) {
	lcs[1] = n;
	int mid = 0, maxr = 0;
	rep (i, 2, n) {
		lcs[i] = 0;
		if (i <= maxr) {
			lcs[i] = min(maxr - i + 1, lcs[i - mid + 1]);
		}
		while (s[1 + lcs[i]] == s[i + lcs[i]]) ++lcs[i];
		if (i + lcs[i] - 1 > maxr) {
			mid = i, maxr = i + lcs[i] - 1;
		}
	}
}
int cnt[30], cnt2[MAXN][27];
inline void solve() {
	scanf("%s", s + 1);
	int n = strlen(s + 1);
	if (n < 3) {
		printf("0\n");
		return;
	}
	s[n + 1] = '$';
	memset(cnt, 0, sizeof(cnt));
	memset(per, 0, sizeof(per));
	rep (i, 1, n) {
		cnt[s[i] - 'a'] ^= 1, per[i] = per[i - 1];
		cnt[s[i] - 'a'] ? ++per[i] : --per[i];
		memcpy(cnt2[i], cnt2[i - 1], sizeof(cnt2[i]));
		++cnt2[i][per[i]];
	}
	int N_1 = n + 1;
	for (int i = 1; i != N_1; ++i)
		for (int j = 0; j != 26; ++j) {
		cnt2[i][j + 1] += cnt2[i][j];
	}
	memset(cnt, 0, sizeof(cnt));
	memset(suf, 0, sizeof(suf));
	per (i, n, 1) {
		cnt[s[i] - 'a'] ^= 1, suf[i] = suf[i + 1];
		cnt[s[i] - 'a'] ? ++suf[i] : --suf[i];
	}
	exKMP(n);
	ulint ans = 0;
	rep (i, 3, n) {
		int ed = lcs[i] + i - 1;
		ed = min(ed, n - 1);
		int i_1 = i - 1, i_2 = i - 2, res = 0;
		for (int j = i_1; j <= ed; j += i_1) {
			res += cnt2[i_2][suf[j + 1]];
		}
		ans += res;
	}
	cout << ans << '\n';
}
int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	int T;
	scanf("%d", &T);
	while (T--) solve();
	return 0;
}
