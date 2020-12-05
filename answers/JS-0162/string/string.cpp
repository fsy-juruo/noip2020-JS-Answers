#include <bits/stdc++.h>
using namespace std;
const long long N = 1050000, M = 30, K = 15669730, FI = 19260817, SE = 998244353;
vector <long long> v[N];
char s[N];
long long T, aa, n, b[N], st[N], hav[26], sums[N][M];
long long cnt, to[K], head[K], nxt[K], pw[N];
void add_edge (long long x, long long y) {
	nxt[++ cnt] = head[x];
	head[x] = cnt;
	to[cnt] = y;
	return ;
}
long long ksm (long long x, long long y) {
	long long ret = 1;
	while (y) {
		if (y & 1)
			ret = 1ll * ret * x % SE;
		x = 1ll * x * x % SE;
		y >>= 1;
	}
	return ret;
}
int main () {
	freopen ("string.in", "r", stdin);
	freopen ("string.out", "w", stdout);
	scanf ("%lld", &T);
	pw[0] = 1;
	for (int i = 1; i <= 1048576; i ++)
		pw[i] = 1ll * pw[i - 1] * FI % SE;
	while (T --) {
		n = 0;
		char ch = getchar ();
		while (ch < 'a' || ch > 'z')
			ch = getchar ();
		while (ch >= 'a' && ch <= 'z') {
			n ++;
			s[n] = ch;
			st[n] = ((long long)(ch - 'a' + 1) + 1ll * st[n - 1] * FI % SE) % SE;
			ch = getchar ();
		}
		cnt = 0;
		memset (head, 0, sizeof (head));
		for (long long i = 1; i <= n; i ++)
			for (long long j = 1; i * j <= n; j ++) {
				int l = st[i], r = st[j * i];
				r = r - (1ll * st[(j - 1) * i] * pw[i] % SE);
				while (r < 0)
					r += SE;
				if (l != r)
					break ;
				add_edge (j * i, i);
			}
		long long sum = 0;
		memset (hav, 0, sizeof (hav));
		for (long long i = 1; i <= n; i ++) {
			hav[(long long)(s[i] - 'a')] ^= 1;
			if (hav[(long long)(s[i] - 'a')] == 0)
				sum --;
			else
				sum ++;
			for (long long j = 0; j <= 26; j ++)
				sums[i][j] = sums[i - 1][j];
			sums[i][sum] ++;
		}
		memset (hav, 0, sizeof (hav));
		sum = 0;
		for (long long i = n; i >= 1; i --) {
			hav[(long long)(s[i] - 'a')] ^= 1;
			if (hav[(long long)(s[i] - 'a')] == 0)
				sum --;
			else
				sum ++;
			b[i] = sum;
		}
		long long ans = 0;
		for (long long i = 2; i < n; i ++) {//C = s[i + 1] ~ s[n]
			for (long long j = head[i]; j; j = nxt[j]) {
				long long x = to[j];//x = |AB|
				for (long long k = 0; k <= b[i + 1]; k ++)
					ans += (long long)(sums[x - 1][k]);
			}
		}
		printf ("%lld\n", ans);
	}
	return 0;
}

