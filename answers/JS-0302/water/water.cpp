#include<bits/stdc++.h>
#define fox(i,a,b) for(int i=a;i<=b;++i)
#define ll long long
using namespace std;

inline int rd() {
	int x = 0, f = 1; char c = getchar();
	for (; !isdigit(c); c = getchar()) if (c == '-') f = 0;
	for (; isdigit(c); c = getchar()) x = x * 10 + c - '0';
	return f ? x : -x;
}

const int N = 1e5 + 10;
int n, m, len[N], deg[N], d[10][N];

struct fenshu{
	ll z, m;
} res, sum[N];

ll gcd(ll x, ll y) {return y == 0 ? x : gcd(y, x % y);}

fenshu operator + (const fenshu x, const fenshu y) {
	ll g = gcd(x.m, y.m);
	res.m = x.m / g * y.m;
	res.z = y.m / g * x.z + x.m / g * y.z;
	g = gcd(res.m, res.z);
	res.m /= g, res.z /= g;
	return res;
}

queue<int>q;

int main() {
	freopen("water.in", "r", stdin);
	freopen("water.out", "w", stdout);
	n = rd(), m = rd();
	int x, y;
	fox (i, 1, n) {
		len[i] = rd();
		fox (j, 1, len[i]) ++deg[d[j][i] = rd()];
		sum[i].m = 1;
	}
	
	fox (i, 1, m) {
		q.push(i);
		sum[i].z = 1;
	}
	while (!q.empty()) {
		x = q.front(), q.pop();
		if (!len[x]) continue;
		if (sum[x].z % len[x] == 0) sum[x].z /= len[x];
		else sum[x].m *= len[x];
		fox (i, 1, len[x]) {
			y = d[i][x];
			--deg[y];
			if (!deg[y]) q.push(y);
			sum[y] = sum[y] + sum[x];
		}
	}
	
	fox (i, 1, n) {
		if (!len[i]) {
 			printf("%lld %lld\n", sum[i].z, sum[i].m);
		}
	}
	return 0;
}

