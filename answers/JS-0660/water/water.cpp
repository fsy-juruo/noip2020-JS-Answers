#include<bits/stdc++.h>
using namespace std;
inline int read() {
	int s = 0, w = 1;
	char c = getchar();
	while(c < '0' || c > '9') {
		if(c == '-') w = -1;
		c = getchar();
	}
	while(c >= '0' && c <= '9') {
		s = (s << 3) + (s << 1) + c - 48;
		c = getchar();
	}
	return s * w;
}
void write(long long n) {
	if(n < 10) {
		putchar(n + 48);
		return ;
	}
	write(n / 10);
	putchar(n % 10 + 48);
	return ;
}
int a[100005][10];
int in[100005];
long long x[100005];
long long y[100005];
void add(int to, long long xx, long long yy) {
	if(x[to] == 0) {
		x[to] = xx;
		y[to] = yy;
		return ;
	}
	long long z1 = xx * y[to] + yy * x[to];
	long long z2 = yy * y[to];
	long long z3 = __gcd(z1, z2);
	x[to] = z1 / z3;
	y[to] = z2 / z3;
	return ;
}
void dfs(int num) {
	if(a[num][0] == 0) return ;
	long long xx = x[num], yy = y[num] * a[num][0];
	long long zz = __gcd(xx, yy);
	xx /= zz; yy /= zz; 
	for(int i = 1; i <= a[num][0]; i++) {
		int to = a[num][i];
		add(to, xx, yy); // f[to] += xx / yy;
		in[to]--;
		if(!in[to]) {
			dfs(to);
		}
	}
	return ;
}
int main() {
	freopen("water.in", "r", stdin);
	freopen("water.out", "w", stdout);
	int n, m;
	n = read();
	m = read();
	for(int i = 1; i <= n; i++) {
		a[i][0] = read();
		for(int j = 1; j <= a[i][0]; j++) {
			a[i][j] = read();
			in[a[i][j]]++;
		}
	}
	for(int i = 1; i <= m; i++) {
		x[i] = y[i] = 1;
	}
	for(int i = 1; i <= m; i++) {
		dfs(i);
	}
	for(int i = 1; i <= n; i++) {
		if(a[i][0] == 0) {
			write(x[i]); putchar(' ');
			write(y[i]); puts("");
		}
	}
	return 0;
}

