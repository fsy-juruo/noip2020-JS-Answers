#include <bits/stdc++.h>
using namespace std;

#define SZ(a) ((int)((a).size()))
#define fi first
#define se second
#define mk make_pair

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef pair<int, int> pii;

template<typename T> inline void ckmax(T& x, T y) { x = ((y > x) ? y : x); }
template<typename T> inline void ckmin(T& x, T y) { x = ((y < x) ? y : x); }

namespace Fread {
const int SIZE = (1 << 21);
char buf[SIZE], *S, *T;
inline char getchar() {
	if (S == T) {
		T = (S = buf) + fread(buf, 1, SIZE, stdin);
		if (S == T) return '\n';
	}
	return *S++;
}
} // namespace Fread
namespace Fwrite {
const int SIZE = (1 << 21);
char buf[SIZE], *S = buf, *T = buf + SIZE;
inline void flush() {
	fwrite(buf, 1, S - buf, stdout);
	S = buf;
}
inline void putchar(char c) {
	*S++ = c;
	if (S == T) flush();
}
struct NTR {
	~NTR() { flush(); }
} ztr;
} // namespace Fwrite
#define getchar Fread :: getchar
#define putchar Fwrite :: putchar
namespace Fastio {
struct Reader {
	template<typename T>
	Reader& operator >> (T& x) {
		char c = getchar();
		T f = 1;
		while (!isdigit(c)) {
			if (c == '-')
				f = -1;
			c = getchar();
		}
		x = 0;
		while (isdigit(c)) {
			x = (x * 10) + (c - '0');
			c = getchar();
		}
		x *= f;
		return *this;
	}
	Reader() {}
} cin;

const char endl = '\n';
struct Writer {
	template<typename T>
	Writer& operator << (T x) {
		if (x == 0) {
			putchar('0');
			return *this;
		}
		if (x < 0) {
			putchar('-');
			x = -x;
		}
		static int sta[100];
		int top = 0;
		while (x) {
			sta[++top] = x % 10;
			x /= 10;
		}
		while (top) {
			putchar(sta[top] + '0');
			--top;
		}
		return *this;
	}
	Writer& operator << (char c) {
		putchar(c);
		return *this;
	}
	Writer& operator << (char *s) {
		while (*s) {
			putchar(*s);
			s++;
		}
		return *this;
	}
	Writer& operator << (const char *s) {
		while (*s) {
			putchar(*s);
			s++;
		}
		return *this;
	}
	Writer() {}
} cout;
} // namespace Fastio

#define cin Fastio :: cin
#define cout Fastio :: cout
#define endl Fastio :: endl

const int MAXN = 5e5, MAXK = 10;

int n, K;
ll w[MAXK + 5];
int c[MAXN + 5], d[MAXN + 5];

ll movep[MAXK + 5];
ll maxmove[MAXN + 5][MAXK + 5], minmove[MAXN + 5][MAXK + 5];

ll curp[MAXK + 5];
ll ans;

ll p[MAXK + 5];
ll liml[MAXK + 5], limr[MAXK + 5];
bool nomove = 1;
void walk_one_round_out() {
	int l = 1, r = n + 1;
	while (l < r) {
		int mid = (l + r) >> 1;
		bool flag = 0;
		for (int i = 1; i <= K; ++i) {
			if (p[i] + maxmove[mid][i] > w[i] || p[i] + minmove[mid][i] < 1) {
				flag = 1;
				break;
			}
		}
		if (flag) {
			r = mid;
		} else {
			l = mid + 1;
		}
	}
	assert(l != n + 1);
	ans += l;
}
void work() {
	for (int i = 1; i <= K; ++i) {
		p[i] = curp[i];
	}
	for (int i = 1; i <= K; ++i) {
		limr[i] = w[i] - maxmove[n][i];
		liml[i] = 1 - minmove[n][i];
		if (liml[i] > limr[i] || p[i] < liml[i] || p[i] > limr[i]) {
			walk_one_round_out();
			return;
		}
	}
	if (nomove) {
		cout << -1 << endl;
		exit(0);
	}
	ll l = 1, r = 1e9 + 100;
	while (l < r) {
		ll mid = (l + r) >> 1;
		bool flag = 0;
		for (int i = 1; i <= K; ++i) {
			if (p[i] + mid * movep[i] < liml[i] || p[i] + mid * movep[i] > limr[i]) {
				flag = 1;
				break;
			}
		}
		if (flag) {
			r = mid;
		} else {
			l = mid + 1;
		}
	}
	ans += n * l;
	for (int i = 1; i <= K; ++i) {
		p[i] += l * movep[i];
	}
	walk_one_round_out();
}
void dfs_for_a_pos(int idx) {
	if (idx == K + 1) {
		work();
		return;
	}
	for (int i = 1; i <= w[idx]; ++i) {
		curp[idx] = i;
		dfs_for_a_pos(idx + 1);
	}
}
int main() {
	freopen("walk.in", "r", stdin);
	freopen("walk.out", "w", stdout);
	cin >> n >> K;
	for (int i = 1; i <= K; ++i) {
		cin >> w[i];
		if (K > 1 && w[i] > 100000) {
			cout << -1 << endl;
			return 0;
		}
	}
	for (int i = 1; i <= n; ++i) {
		cin >> c[i] >> d[i];
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= K; ++j) {
			maxmove[i][j] = maxmove[i - 1][j];
			minmove[i][j] = minmove[i - 1][j];
		}
		movep[c[i]] += d[i];
		ckmax(maxmove[i][c[i]], movep[c[i]]);
		ckmin(minmove[i][c[i]], movep[c[i]]);
	}
	nomove = 1;
	for (int i = 1; i <= K; ++i) {
		if (movep[i] != 0) {
			nomove = 0;
			break;
		}
	}
	dfs_for_a_pos(1);
	cout << ans << endl;
	return 0;
}
