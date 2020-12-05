#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

#define N (1048580)
#define MOD (10000007)
#define MUL1 (144)
#define MUL2 (131)

int TT;
int n;
char s[N];
int app[26][N];
int cnt[N];
int plt[30][N];
int hsh1[N], hsh2[N];
int pw1[N], pw2[N];
int cval[N];

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	scanf("%d", &TT);
	pw1[0] = pw2[0] = 1;
	for (int i = 1; i < N - 1; i++) {
		pw1[i] = pw1[i - 1] * MUL1 % MOD;
		pw2[i] = pw2[i - 1] * MUL2 % MOD;
	}
	while (TT--) {
		memset(s, 0, sizeof(s));
		memset(app, 0, sizeof(app));
		memset(cnt, 0, sizeof(cnt));
		memset(plt, 0, sizeof(plt));
		memset(hsh1, 0, sizeof(hsh1));
		memset(hsh2, 0, sizeof(hsh2));
		memset(cval, 0, sizeof(cval));
		scanf("%s", s + 1);
		n = strlen(s + 1);
		pw1[0] = pw2[0] = 1;
		for (int i = 1; i <= n; i++) {
			for (int j = 0; j < 26; j++) {
				if (j == (int)(s[i] - 'a')) {
					app[j][i] = app[j][i - 1] + 1;
				}
				else {
					app[j][i] = app[j][i - 1];
				}
				if (app[j][i] % 2 == 1) {
					cnt[i]++;
				}
			}
			for (int j = 0; j <= 26; j++) {
				if (cnt[i] <= j) {
					plt[j][i] = plt[j][i - 1] + 1;
				}
				else {
					plt[j][i] = plt[j][i - 1];
				}
			}
			hsh1[i] = (hsh1[i - 1] * MUL1 + s[i] - 'a') % MOD;
			hsh2[i] = (hsh2[i - 1] * MUL2 + s[i] - 'a') % MOD;
		}
		for (int i = 0; i <= n; i++) {
			int tmpcnt = 0;
			for (int j = 0; j < 26; j++) {
				if ((app[j][n] - app[j][i]) % 2 == 1) {
					tmpcnt++;
				}
			}
			cval[i] = tmpcnt;
		}
		long long Ans = 0LL;
		for (int k = 2; k < n; k++) {
			int r = 1;
			while (true) {
				r++;
				int curpos = r * k;
				if (curpos >= n) {
					r--;
					break;
				}
				int bok = 1;
				int chkhs1 = hsh1[curpos] - hsh1[curpos - k];
				int chkrm1 = (int)(((long long)(hsh1[k]) * (long long)(pw1[curpos - k])) % (long long)(MOD));
				if (chkhs1 < 0) {
					chkhs1 += MOD;
				}
				if (chkhs1 != chkrm1) {
					bok = 0;
				}
				int chkhs2 = hsh2[curpos] - hsh2[curpos - k];
				int chkrm2 = (int)(((long long)(hsh2[k]) * (long long)(pw2[curpos - k])) % (long long)(MOD));
				if (chkhs2 < 0) {
					chkhs2 += MOD;
				}
				if (chkhs2 != chkrm2) {
					bok = 0;
				}
				if (!bok) {
					r--;
					break;
				}
			}
			int curval = cval[r * k];
			int caddval = cval[r * k - k];
			Ans += ((long long)(r) + 1LL) / 2LL * (long long)(plt[curval][k - 1]);
			Ans += (long long)(r) / 2LL * (long long)(plt[caddval][k - 1]);
		}
		printf("%lld\n", Ans);
	}
	return 0;
}

