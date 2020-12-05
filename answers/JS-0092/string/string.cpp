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

#define lim fuckyoulim
#define mask fuckyoumask
#define init fuckyouinit

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
	Reader& operator >> (char* s) {
		char c = getchar();
		while (c == ' ' || c == '\n') {
			c = getchar();
		}
		while (c != ' ' && c != '\n') {
			*s = c;
			++s;
			c = getchar();
		}
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

const int MAXN = (1 << 20);
const ull BASE = 13131;

char s[5][MAXN + 5];
int _n[5];
vector<int> d[MAXN + 5];
void init(int n) {
	for (int i = 2; i <= n; ++i) {
		for (int j = i; j <= n; j += i) {
			d[j].push_back(i);
		}
	}
}

int mask[MAXN + 5];
int bitcnt_suf[MAXN + 5];
ull hs[MAXN + 5], pw[MAXN + 5];
int lim[MAXN + 5];
int sum[MAXN + 5][27];
void solve_case(const char* s, const int n) {
	int bitcnt_pre = 0;
	for (int i = 1; i <= n; ++i) {
		mask[i] = (mask[i - 1] ^ (1 << (s[i] - 'a')));
		hs[i] = hs[i - 1] * BASE + (s[i] - 'a');
		
		if ((mask[i] >> (s[i] - 'a')) & 1) {
			bitcnt_pre++;
		} else {
			bitcnt_pre--;
		}
		
		for (int j = 0; j <= 26; ++j) {
			sum[i][j] = sum[i - 1][j];
		}
		for (int j = bitcnt_pre; j <= 26; ++j) {
			sum[i][j]++;
		}
	}
	
	mask[n + 1] = 0;
	bitcnt_suf[n + 1] = 0;
	for (int i = n; i >= 1; --i) {
		mask[i] = (mask[i + 1] ^ (1 << (s[i] - 'a')));
		bitcnt_suf[i] = bitcnt_suf[i + 1];
		if ((mask[i] >> (s[i] - 'a')) & 1) {
			bitcnt_suf[i]++;
		} else {
			bitcnt_suf[i]--;
		}
	}
	
	for (int i = 2; i <= n - 1; ++i) {
		lim[i] = i;
		for (int j = i + i; j <= n; j += i) {
			//bool _s = 1;
			//for (int k = 1; k <= i; ++k) if (s[i - k + 1] != s[j - k + 1]) { _s = 0; break; }
			if (hs[j] - hs[j - i] * pw[i] == hs[i]) {
				lim[i] = j;
			} else {
				break;
			}
		}
	}
	ll ans = 0;
	for (int i = n; i >= 3; --i) {
		int x = i - 1;
		for (int j = 0; j < SZ(d[x]); ++j) {
			int ABlen = d[x][j];
			if (lim[ABlen] < x)
				continue;
			ans += sum[ABlen - 1][bitcnt_suf[i]];
		}
	}
	cout << ans << endl;
}
int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	int T; cin >> T;
	int maxn = 0;
	for (int t = 0; t < T; ++t) {
		cin >> (s[t] + 1);
		_n[t] = strlen(s[t] + 1);
		// cerr << _n[t] << endl;
		maxn = max(maxn, _n[t]);
	}
	init(maxn);
	pw[0] = 1;
	for (int i = 1; i <= maxn; ++i) {
		pw[i] = pw[i - 1] * BASE;
	}
	
	for (int t = 0; t < T; ++t) {
		solve_case(s[t], _n[t]);
	}
	return 0;
}
