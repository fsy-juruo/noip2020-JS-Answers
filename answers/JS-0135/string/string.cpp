#include<bits/stdc++.h>

#define LL long long
#define ull unsigned long long
#define F(i,j,k) for(int i = j; i <= k; ++i)
#define DF(i,j,k) for(int i = j; i >= k; --i)

using namespace std;

template <typename T> inline void read(T &n) {
	T w = 1;
	n = 0;
	char ch = getchar();
	while (!isdigit(ch) && ch != EOF) {
		if(ch == '-') w = -1;
		ch = getchar();
	}
	while (isdigit(ch) && ch != EOF) {
		n = (n << 3) + (n << 1) + (ch & 15);
		ch = getchar();
	}
	n *= w;
}

template <typename T> inline void write(T x) {
	T l = 0;
	ull y = 0;
	if (x < 0) {
		putchar('-');
		x = -x;
	}
	if (!x) {
		putchar(48);
		return;
	}
	while(x) {
		y = y * 10 + x % 10;
		x /= 10;
		++l;
	}
	while(l) {
		putchar(y % 10 + 48);
		y /= 10;
		--l;
	}
}

template <typename T> inline void writes(T x) {
	write(x);
	putchar(' ');
}

template <typename T> inline void writeln(T x) {
	write(x);
	puts("");
}

template <typename T> inline void checkmax(T &a,T b) { a = a > b ? a : b; }

template <typename T> inline void checkmin(T &a,T b) { a = a < b ? a : b; }


const int N = (1 << 20) + 100;

const ull p = 37;

int a[N], sum[33], qz[N], hz[N], s[33];

ull cm[N], hsh[N];

inline void prepare() {
	cm[0] = 1;
	F(i, 1, 1 << 20) cm[i] = cm[i - 1] * p;
}

char ch;

inline void solve() {
	int n = 0;
	while ((ch = getchar()) !='\n') { ++n; a[n] = int(ch) - 96; }
	F(i, 1, 26) sum[i] = 0;
	qz[0] = 0;
	F(i, 1, n) {
		++sum[a[i]];
		if (sum[a[i]] & 1) qz[i] = qz[i - 1] + 1;
		else qz[i] = qz[i - 1] - 1;
	}
	F(i, 1, 26) sum[i] = 0;
	hz[n + 1] = 0;
	DF(i, n, 1) {
		++sum[a[i]];
		if (sum[a[i]] & 1) hz[i] = hz[i + 1] + 1;
		else hz[i] = hz[i + 1] - 1;
	}
	hsh[0] = 0;
	F(i, 1, n) hsh[i] = hsh[i - 1] + a[i] * cm[i];
	LL ans = 0;
	F(i, 0, 26) s[i] = 0;
	F(i, 2, n - 1) {
		int pos = i;
		F(j, qz[i - 1], 26) ++s[j];
		while(pos < n) {
			if(hsh[i] * cm[pos - i] != hsh[pos] - hsh[pos - i]) break;
			ans += s[hz[pos + 1]];
			pos += i;
		}
	}
	writeln(ans);
}

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	int t;
	read(t);
	prepare();
	while (t--) solve();
	return 0;
}

