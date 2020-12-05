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

const int N = 1e5 + 100;

int num[N], v[N][11], du[N];

LL ans1[N], ans2[N];

inline LL gcd(LL x,LL y) {
	if(y == 0) return x;
	return gcd(y, x % y);
}

queue <int> q;

int main() {
	freopen("water.in", "r", stdin);
	freopen("water.out", "w", stdout);
	int n, m;
	read(n);
	read(m);
	F(i, 1, n) {
		read(num[i]);
		F(j, 1, num[i]) {
			int x;
			read(x);
			v[i][j] = x;
			++du[x];
		}
	}
	F(i, 1, n)
		if (du[i] == 0) {
			ans1[i] = 1;
			ans2[i] = 1;
			q.push(i);
		}
	while (!q.empty()) {
		int tx = q.front(); q.pop();
		F(i, 1, num[tx]) {
			--du[v[tx][i]];
			if (du[v[tx][i]] == 0) q.push(v[tx][i]);
			LL x = ans1[tx], y = ans2[tx] * num[tx];
			LL gc = gcd(x, y);
			x /= gc;
			y /= gc;
			if (ans1[v[tx][i]] == 0) {
				ans1[v[tx][i]] = x;
				ans2[v[tx][i]] = y;
			}
			else {
				ans1[v[tx][i]] = ans1[v[tx][i]] * y + ans2[v[tx][i]] * x;
				ans2[v[tx][i]] = ans2[v[tx][i]] * y;
				gc = gcd(ans1[v[tx][i]], ans2[v[tx][i]]);
				ans1[v[tx][i]] /= gc;
				ans2[v[tx][i]] /= gc;
			}
		}
	}
	F(i, 1, n)
		if (num[i] == 0) {
			LL x = ans1[i], y = ans2[i];
			LL gc = gcd(x, y);
			writes(x / gc);
			writeln(y / gc);
		}
	return 0;
}

