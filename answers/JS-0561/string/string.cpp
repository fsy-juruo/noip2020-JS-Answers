#include <bits/stdc++.h>
using namespace std;
// Fast IO start
namespace io {
	const int BUFSIZE = 1 << 20;
	char ibuf[BUFSIZE + 1], *is = ibuf, *it = ibuf;
	inline char read_char() {
		if (is == it) {
			it = (is = ibuf) + fread(ibuf, 1, BUFSIZE, stdin);
			if (is == it) return 0;
		}
		return *is++;
	}
	template<class T>
	inline void read_int(T &x) {
		T f = 1;
		char c = read_char();
		while (!isdigit(c)) {
			if (c == '-') f = -1;
			c = read_char();
		}
		x = 0;
		while (isdigit(c)) {
			x = x * 10 + (c - '0');
			c = read_char();
		}
		x *= f;
	}
	inline void read_str(char *s) {
		char c = read_char();
		while (c <= ' ') c = read_char();
		while (c > ' ') *s++ = c, c = read_char();
		*s = 0;
	}
}
using io::read_char;
using io::read_int;
using io::read_str;
// Fast IO end
const int N = 1050000;
int n, nxt[N], cyc[N], f[N], g[N], cnt[27];
char S[N];
int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	int T;
	read_int(T);
	while (T--) {
		read_str(S + 1);
		n = strlen(S + 1);
		memset(cnt, 0, sizeof(cnt));
		for (int i = 1, cur = 0; i <= n; i++) {
			int cc = S[i] - 'a';
			cnt[cc]++;
			if (cnt[cc] & 1) cur++;
			else cur--;
			f[i] = cur;
		}
		memset(cnt, 0, sizeof(cnt));
		for (int i = n, cur = 0; i >= 1; i--) {
			int cc = S[i] - 'a';
			cnt[cc]++;
			if (cnt[cc] & 1) cur++;
			else cur--;
			g[i] = cur;
		}
		nxt[1] = 0;
		for (int i = 2, j = 0; i <= n; i++) {
			while (j && S[i] != S[j + 1]) j = nxt[j];
			if (S[i] == S[j + 1]) nxt[i] = ++j;
			else nxt[i] = 0;
		}
		for (int i = 1; i <= n; i++) {
			cyc[i] = ((i % (i - nxt[i]) == 0) ? (i - nxt[i]) : i);
		}
		memset(cnt, 0, sizeof(cnt));
		long long ans = 0;
		for (int x = 2; x < n; x++) {
			for (int j = f[x - 1]; j <= 26; j++) cnt[j]++;
			for (int y = x; y < n; y += x) {
				if (x % cyc[y] == 0) {
					ans += cnt[g[y + 1]];
				}
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
}
