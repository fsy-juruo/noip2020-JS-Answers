#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll rd() {
	ll s = 0, f = 1;
	char x = getchar();
	for (; !isdigit(x); x = getchar()) if (x == '-') f = -1;
	for (; isdigit(x); x = getchar()) s = s*10+x-48;
	return s*f;
}

const int N = 55, M = 405, MA = 1e6+10;
int ans, sa[MA], sb[MA];
int a[N][M], s[N];
int n, m, x, nx, lx, tg, sum, t;

int chm(int k, int p) {
	for (int i = k; k <= n; k++)
		for (int j = 1; j <= m; j++)
			if (a[i][j] == a[p][1]) return i;
	return n+1;
}

void mov(int x, int y) {
	ans++;
	sa[ans] = x;
	sb[ans] = y;
	s[y]++;
	a[y][s[y]] = a[x][s[x]];
	s[x]--;
	return;
}

int main() {
	freopen("ball.in", "r", stdin);
	freopen("ball.out", "w", stdout);
	n = rd();
	m = rd();
	for (int i = 1; i <= n; i++) {
		s[i] = m;
		for (int j = 1; j <= m; j++) a[i][j] = rd();
	}
	for (int i = 1; i < n; i++) {
		for (t = 1; a[i][t+1] == a[i][t]; t++);
		if (t == m) continue;
		x = chm(i+1, i);
		tg = m+1;
		sum = 0;
		for (int j = t+1; j <= m; j++)
			if (a[i][j] == a[i][1]) {
				tg = 1;
				sum++;
			}
		t += sum;
		for (int j = 1; j <= sum; j++) mov(x, n+1);
		for (; s[i] >= t+1; )
			if (a[i][s[i]] == a[i][1])
				mov(i, x); else
				mov(i, n+1);
		for (int j = 1; j <= sum; j++) mov(x, i);
		lx = n+1;
		for (; x != n+1; x = nx) {
			tg = 0;
			sum = 0;
			for (int e = 1; e <= s[x]; e++)
				if (a[x][e] == a[i][1]) {
					if (tg == 0) tg = e;
					sum++;
				}
			for (; s[lx] < m; )
				if (a[x][s[x]] == a[i][1]) {
					mov(x, i);
					t++;
				} else mov(x, lx);
			tg = s[x]+1;
			sum = 0;
			for (int e = 1; e <= s[x]; e++)
				if (a[x][e] == a[i][1]) {
					if (tg == s[x]+1) tg = e;
					sum++;
				}
			nx = chm(x+1, i);
			for (int e = 1; e <= sum; e++) mov(nx, i);
			for (; s[x] >= tg; )
				if (a[x][s[x]] == a[i][1])
					mov(x, nx); else
					mov(x, i);
			for (; s[i] >= t+1; ) mov(i, x);
			for (int e = 1; e <= sum; e++) mov(nx, i);
			t += sum;
			lx = x;
		}
		x = chm(i+1, i);
		for (int j = s[x]; j < s[m]; j++) mov(n+1, x);
	}
	cout << ans << endl;
	for (int i = 1; i <= ans; i++) cout << sa[i] << ' ' << sb[i] << endl;
	return 0;
}
