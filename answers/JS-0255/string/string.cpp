#include <bits/stdc++.h>

using namespace std;

template <typename T> inline void read(T &x) {
	T f = 1; x = 0; char c = getchar();
	for (; !isdigit(c); c = getchar()) if (c == '-') f = -f;
	for (; isdigit(c); c = getchar()) x = x * 10 + c - 48;
	x *= f;
}

template <typename T> inline void write(T x) {
	if (x < 0) x = -x, putchar('-');
	if (x > 9) write(x / 10);
	putchar(x % 10 + 48);
}

template <typename T> inline void writeln(T x, char c) { write(x); putchar(c); }
template <typename T> inline void chkmax(T &x, const T y) { x = x > y ? x : y; }
template <typename T> inline void chkmin(T &x, const T y) { x = x < y ? x : y; }

typedef long long ll;
typedef pair <int, int> pii;

#define Ms(arr, opt) memset(arr, opt, sizeof(arr))
#define Mp(x, y) make_pair(x, y)

const int Maxm = (1 << 20) + 5;
int T, n; char s[Maxm];
int pre[Maxm][27]; int h[27];
unsigned long long p0[Maxm], f0[Maxm];
int b[Maxm];

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	for (read(T); T; T--) {
		scanf("%s", s + 1); Ms(h, 0);
		n = strlen(s + 1); int tt = 0;
		if (n < 3) { writeln(0, ' '); continue; }
		p0[0] = 1;
		for (int i = 1; i <= n; i++) {
			p0[i] = p0[i - 1] * 13331ull;
			f0[i] = f0[i - 1] * 13331ull + (unsigned long long) (s[i] - 'a' + 1);
			h[s[i] - 'a'] ^= 1;
			if (h[s[i] - 'a'] == 1) ++tt;
			if (h[s[i] - 'a'] == 0) --tt;
			for (int j = 0; j <= 26; j++)
				pre[i][j] = pre[i - 1][j] + (j >= tt);
		}
		
		Ms(h, 0); tt = 0; ll ans = 0;
		for (int i = n; i >= 3; i--) {
			b[i] = 0;
			h[s[i] - 'a'] ^= 1;
			if (h[s[i] - 'a'] == 1) ++tt;
			if (h[s[i] - 'a'] == 0) --tt;
			b[i] = tt;
		}
		
		for (int i = 2; i <= n; i++) {
			for (int j = i; j <= n; j += i) {
				if (f0[j] - p0[i] * f0[j - i] != f0[i]) {
					break;
				} else {
					if (j != n) ans += pre[i - 1][b[j + 1]];
				}
			}
		}
		
		writeln(ans, '\n');
	}
	return 0;
}

/*
3
nnrnnr
zzzaab
mmlmmlo

5
kkkkkkkkkkkkkkkkkkkk
lllllllllllllrrlllrr
cccccccccccccxcxxxcc
ccccccccccccccaababa
ggggggggggggggbaabab
*/
