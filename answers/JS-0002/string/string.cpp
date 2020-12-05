#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const int MN = 1048577 , maxn = 1048576 , LOG = 20;
const int ALP = 27;
const int bas1 = 131 , mod1 = 998244353;
const int bas2 = 137 , mod2 = 19260817;

int N , tot , occ[MN] , pre[MN] , suf[MN] , cnt[MN][ALP] , rm[MN] , head[MN] , val[MN * LOG] , nxt[MN * LOG];
int pw1[MN] , pw2[MN] , hsh1[MN] , hsh2[MN];
char s[MN];

inline pair < int , int > get(int l , int r) {
	int f = (hsh1[r] - 1ll * pw1[r - l + 1] * hsh1[l - 1] % mod1 + mod1) % mod1;
	int s = (hsh2[r] - 1ll * pw2[r - l + 1] * hsh2[l - 1] % mod2 + mod2) % mod2;
	return make_pair(f , s);
}
inline void AddEdge(int u , int v) {
	nxt[++tot] = head[u]; val[tot] = v; head[u] = tot;
}

int main() {
	
	#ifndef evenbao
	freopen("string.in" , "r" , stdin);
	freopen("string.out" , "w" , stdout);
	#endif
	
	int T; scanf("%d" , &T);
	for (int i = 2; i <= maxn; ++i)
	for (int j = i + i; j <= maxn; j += i)
		AddEdge(j , i);
	pw1[0] = pw2[0] = 1;
	for (int i = 1; i <= maxn; ++i) {
		pw1[i] = 1ll * pw1[i - 1] * bas1 % mod1;
		pw2[i] = 1ll * pw2[i - 1] * bas2 % mod2;
	}
	while (T--) {
		scanf("%s" , s + 1); N = strlen(s + 1);
		for (int i = 1; i <= N + 1; ++i) pre[i] = suf[i] = 0;
		for (int i = 0; i <= 26; ++i) occ[i] = 0;
		for (int i = 0; i <= N; ++i) for (int j = 0; j <= 26; ++j) cnt[i][j] = 0;
		for (int i = N; i >= 1; --i) {
			++occ[s[i] - 'a']; suf[i] = suf[i + 1];
			if (occ[s[i] - 'a'] & 1) ++suf[i];
			else --suf[i];
		} 
		for (int i = 0; i < 26; ++i) occ[i] = 0;
		for (int i = 1; i <= N; ++i) {
			++occ[s[i] - 'a']; pre[i] = pre[i - 1];
			if (occ[s[i] - 'a'] & 1) ++pre[i];
			else --pre[i];
		}
		for (int i = 1; i <= N; ++i) {
			hsh1[i] = (1ll * hsh1[i - 1] * bas1 % mod1 + s[i] - 'a') % mod1;
			hsh2[i] = (1ll * hsh2[i - 1] * bas2 % mod2 + s[i] - 'a') % mod2;
		}
		for (int i = 2; i <= N; ++i) {
			rm[i] = 0;
			for (int j = i + 1; j + i - 1 <= N; j += i)
				if (get(j , j + i - 1) != make_pair(hsh1[i] , hsh2[i])) break;
				else rm[i] = j + i - 1;
		} 
		LL ans = 0;
		for (int i = 1; i < N; ++i) {
			for (int j = 0; j <= 26; ++j) cnt[i][j] += cnt[i - 1][j];
			for (int j = pre[i]; j <= 26; ++j) ++cnt[i + 1][j];
		}
		for (int i = 2; i < N; ++i) {
			ans += cnt[i][suf[i + 1]];
			for (int j = head[i]; j; j = nxt[j]) {
				int x = val[j];
				if (rm[x] >= i) ans += (LL) cnt[x][suf[i + 1]];
			}
		}
		printf("%lld\n" , ans);
	}
	return 0; 
}

