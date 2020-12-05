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

const int MAXN = 1e5;

int n, m;
int indeg[MAXN + 5], outdeg[MAXN + 5];
int cur_indeg[MAXN + 5];
int a[MAXN + 5][6];

ll gcd(ll x, ll y) { return (!y) ? x : gcd(y, x % y); }
ll lcm(ll x, ll y) { return x / gcd(x, y) * y; }
struct Fenshu {
	ll fenzi, fenmu;
	Fenshu(ll _fenzi = 0, ll _fenmu = 1) {
		fenzi = _fenzi;
		fenmu = _fenmu;
	}
	Fenshu operator + (const Fenshu& rhs) const {
		ll newfenmu = lcm(fenmu, rhs.fenmu);
		ll newfenzi = newfenmu / fenmu * fenzi + newfenmu / rhs.fenmu * rhs.fenzi;
		ll g = gcd(newfenmu, newfenzi);
		newfenmu /= g;
		newfenzi /= g;
		return Fenshu(newfenzi, newfenmu);
	}
	Fenshu& operator += (const Fenshu& rhs) {
		*this = *this + rhs;
		return *this;
	}
	Fenshu operator / (const ll chushu) const {
		ll g = gcd(fenzi, chushu);
		ll newfenzi = fenzi / g;
		ll newchushu = chushu / g;
		return Fenshu(newfenzi, fenmu * newchushu);
	}
	Fenshu& operator /= (const ll chushu) {
		*this = *this / chushu;
		return *this;
	}
	void print() {
		cout << fenzi << " " << fenmu << endl;
	}
};

Fenshu f[MAXN + 5];

int main() {
	freopen("water.in", "r", stdin);
	freopen("water.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		cin >> outdeg[i];
		for (int j = 1; j <= outdeg[i]; ++j) {
			cin >> a[i][j];
			indeg[a[i][j]]++;
		}
	}
	for (int i = 1; i <= m; ++i) {
		f[i] = Fenshu(1, 1);
	}
	queue<int> q;
	for (int i = 1; i <= n; ++i) {
		cur_indeg[i] = indeg[i];
		if (!cur_indeg[i]) {
			q.push(i);
		}
	}
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		if (!outdeg[u])
			continue;
		Fenshu tmp = f[u] / outdeg[u];
		for (int i = 1; i <= outdeg[u]; ++i) {
			int v = a[u][i];
			f[v] += tmp;
			
			cur_indeg[v]--;
			if (!cur_indeg[v]) {
				q.push(v);
			}
		}
	}
	for (int i = 1; i <= n; ++i) {
		if (!outdeg[i]) {
			f[i].print();
		}
	}
	return 0;
}
