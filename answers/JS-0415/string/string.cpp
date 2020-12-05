#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const int MAXN = 1500005;
char S[MAXN];
int cnt[30], pre[MAXN], suf[MAXN], len[MAXN], n, T;

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	for (scanf("%d", &T); T--;) {
		scanf("%s", S + 1);
		n = strlen(S + 1);
		memset(cnt, 0, sizeof(cnt));
		memset(pre, 0, sizeof(pre));
		for (int i = 1; i <= n; i++) {
			int t = ++cnt[S[i] - 'a'];
			pre[i] = pre[i - 1];
			if (t & 1) ++pre[i];
			else --pre[i];
		}
		memset(suf, 0, sizeof(suf));
		memset(cnt, 0, sizeof(cnt));
		for (int i = n; i > 0; i--) {
			int t = ++cnt[S[i] - 'a'];
			suf[i] = suf[i + 1];
			if (t & 1) ++suf[i];
			else --suf[i];
		}
		memset(len, 0, sizeof(len));
		for (int i = 2, id = 0, r = 0; i <= n; i++) {
			if (r >= i) len[i] = min(r - i + 1, len[i - id + 1]);
			while (i + len[i] <= n && S[1 + len[i]] == S[i + len[i]]) ++len[i];
			if (i + len[i] - 1 > r) r = i + len[i] - 1, id = i;
		}
		memset(cnt, 0, sizeof(cnt));
		LL ans = 0;
		for (int i = 2; i < n; i++) {
			int r = i + len[i + 1];
			for (int j = pre[i - 1]; j <= 26; j++) ++cnt[j];
			for (int j = i; j <= r && j < n; j += i)
				ans += cnt[suf[j + 1]];
		}
		printf("%lld\n", ans);
	}
	return 0;
}
