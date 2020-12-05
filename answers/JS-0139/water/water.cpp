#include <bits/stdc++.h>
using namespace std;

const long long B = 1000000000000000ll;

struct num {
	long long a, b;
	num() {a = 0, b = 0;}
	num operator + (const num &A) const {
		num res;
		res.a = a + A.a, res.b = b + A.b;
		res.b += res.a / B, res.a %= B;
		return res;
	}
	num operator / (const int &x) const {
		num res;
		res.a = a, res.b = b;
		res.a += res.b % x * B, res.b /= x;
		res.a /= x;
		return res;
	}
	num operator /= (const int &x) {return *this = *this / x;}
	int operator % (const int &x) const {
		return (b % x * B + a) % x;
	}
	void print() {
		if (b == 0 && a == 0) {
			printf("0");
			return ;
		}
		if (b == 0) {
			printf("%lld", a);
			return ;
		}
		printf("%lld", b);
		long long cur = a;
		while (cur * 10 < B) cur *= 10, printf("0");
		printf("%lld\n", a);
	}
};

num N;

int G[100010][10], sz[100010];
int in[100010];
num dp[100010];
queue <int> q;

int main() {
	freopen("water.in", "r", stdin);
	freopen("water.out", "w", stdout);
	N.a = 705600000000000ll, N.b = 36279;
	int n, m; scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		int k; scanf("%d", &k);
		for (int j = 0; j < k; j++) {
			scanf("%d", &G[i][j]);
			in[G[i][j]]++;
		}
		sz[i] = k;
		G[i][k] = -1;
	}
	for (int i = 1; i <= m; i++) {
		dp[i] = N;
	}
	for (int i = m + 1; i <= n; i++) {
		dp[i].a = dp[i].b = 0;
	}
	for (int i = 1; i <= n; i++) {
		if (!in[i]) q.push(i);
	}
	while (!q.empty()) {
		int x = q.front(); q.pop();
		for (int i = 0; G[x][i] != -1; i++) {
			int v = G[x][i];
			dp[v] = dp[v] + dp[x] / sz[x];
			in[v]--;
			if (in[v] == 0) q.push(v);
		}
	}
	for (int i = 1; i <= n; i++) {
		if (sz[i] != 0) continue;
		num x = dp[i], y = N;
		while (x % 2 == 0 && y % 2 == 0) x /= 2, y /= 2;
		while (x % 3 == 0 && y % 3 == 0) x /= 3, y /= 3;
		while (x % 5 == 0 && y % 5 == 0) x /= 5, y /= 5;
		x.print(), printf(" "), y.print(), printf("\n");
	}
	return 0;
}
/*
5 1
3 2 3 5
2 4 5
2 5 4
0
0


*/
