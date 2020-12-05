#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for(int i = 0; i < (int)(n); i ++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i ++)
#define MP make_pair
typedef long long LL;
typedef pair<int, int> PII;

int n;
char S[1048585];
int zf[1048585];

int ccl[30], ccr[30], ctl, ctr, gtr, sumc, sumg;
int cnt[30];

void solve()
{
	scanf("%s", S);
	n = strlen(S);
	
	int mp = 0;
	zf[0] = 0;
	for(int i = 1; i < n; i ++) {
		if(zf[i - mp] < mp + zf[mp] - i) zf[i] = zf[i - mp];
		else {
			zf[i] = max(mp + zf[mp] - i, 0);
			while(i + zf[i] < n && S[i + zf[i]] == S[zf[i]]) zf[i] ++;
			mp = i;
		}
	}
	rep(i, n) S[i] -= 'a';
	
	ctl = ctr = 0;
	rep(i, 26) ccl[i] = ccr[i] = 0;
	rep(i, n) {
		ctr -= ccr[S[i]]; ccr[S[i]] ^= 1; ctr += ccr[S[i]];
	}
	gtr = ctr;
	rep(i, 27) cnt[i] = 0;
	sumc = sumg = 0;
	
	LL ans = 0;
	rep(i, n) {
		if(i >= 2) {
			int maxc = min(zf[i], n - 1 - i) / i + 1;
			ans += 1LL * (maxc / 2) * sumg + 1LL * ((maxc + 1) / 2) * sumc;
		}
		if(i >= 1) {
			cnt[ctl] ++;
			if(ctl <= ctr) sumc ++;
			if(ctl <= gtr) sumg ++;
		}
		ctl -= ccl[S[i]]; ccl[S[i]] ^= 1; ctl += ccl[S[i]];
		if(ccr[S[i]]) sumc -= cnt[ctr];
		ctr -= ccr[S[i]]; ccr[S[i]] ^= 1; ctr += ccr[S[i]];
		if(ccr[S[i]]) sumc += cnt[ctr];
	}
	
	printf("%lld\n", ans);
}

int main()
{
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	
	int T;
	scanf("%d", &T);
	while(T --) solve();
	return 0;
}
