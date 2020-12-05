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

const int qwq = 1 << 20;
int cnt[26], cc;
char s[qwq];
int n;
int fail[qwq];
int pos[qwq];
int cn[qwq][27];
short in[qwq][120];
int len[qwq];

void solve() {
	scanf("%s", s + 1); n = strlen(s + 1);
	cont(i, n) fail[i] = 0;
	int now = 1;
	circ(i, 2, n) {
		while(now && s[i] != s[now]) now = fail[now];
		fail[i] = now++;
	}
	cont(i, n) {
		int len = i - fail[i];
		if(i % len == 0 && (!pos[i - len] || len % pos[i - len] == 0)) pos[i] = len;
		else pos[i] = i;
	}
	memset(cnt, 0, sizeof(cnt)); cc = 0;
	cont(i, n) {
		++cnt[s[i] - 'a'];
		if(cnt[s[i] - 'a'] & 1) ++cc;
		else --cc;
		loop(j, 27) cn[i][j] = (j >= cc) + cn[i - 1][j];
	}
	memset(cnt, 0, sizeof(cnt)); cc = 0;
	ll ans = 0;
	range(i, n, 2, -1) {
		++cnt[s[i] - 'a'];
		if(cnt[s[i] - 'a'] & 1) ++cc;
		else --cc;
		if(pos[i - 1] == Inf) continue;
		int ch = (i - 1) / pos[i - 1];
		loop(j, len[ch]) {
			int nin = in[ch][j] * pos[i - 1], nnin = nin;
			ans += cn[nin - 1][cc];
			nin = ch / in[ch][j] * pos[i - 1];
			if(nin != nnin) {
				ans += cn[nin - 1][cc];
			}
		}
	}
	printf("%lld\n", ans);
}

// Duo ce bu qing kong
// Bao 0 liang hang lei
int main() {
	#ifndef HCl10
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	#endif
	cont(i, 1 << 10) range(j, i * i, qwq - 1, i) in[j][len[j]++] = i;
	int T; scanf("%d", &T);
	while(T--) solve();
	return 0;
}
