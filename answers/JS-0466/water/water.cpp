#include<bits/stdc++.h>
#define fir(a, b, c) for(int a = b; a <= c; ++ a)
#define ll long long
#define inf 1e8
using namespace std;

const int N = 5e5 + 100;
int n, m, head[N], tot;
struct node {
	int v, nxt;
}e[N];
ll ru[N], chu[N];

inline void add(int x, int y) {
	e[++tot].v = y; e[tot].nxt = head[x]; head[x] = tot;
}

struct huge {
	ll zi, mu;
}num[N];

queue<int> q;

inline ll gcd(ll x, ll y) {
	if (x < y) swap(x, y);
	if (y == 0) return x;
	return gcd(y, x%y);
}

inline ll lcm(ll x, ll y) {
	return x*y/gcd(x, y);
}

inline void solve(int y, huge t) {
	if (num[y].zi == 0 && num[y].mu == 0) {
		num[y].zi = t.zi; 
		num[y].mu = t.mu;
		return;
	}
		
	ll a = lcm(num[y].mu, t.mu);
	ll k1 = a/num[y].mu, k2 = a/t.mu;
	num[y].mu = a, num[y].zi = num[y].zi*k1+t.zi*k2;
	
	k1 = gcd(num[y].zi, num[y].mu);
	num[y].zi /= k1, num[y].mu /= k1;
}

int main() {
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	scanf("%d%d", &n, &m);
	fir (i, 1, n) head[i] = -1;
	fir(i, 1, n) {
		ll s;
		int x; 
		scanf("%lld", &s);
		chu[i] = s;
		fir (j, 1, s) {
			scanf("%d", &x);
			add(i, x);
			++ ru[x];
		}
	}
	fir (i, 1, n) {
		if (ru[i] == 0) q.push(i), num[i].zi = num[i].mu = 1ll;
	}
	
	while (!q.empty()) {
		int x = q.front(); q.pop();
		huge t = num[x];
		t.mu *= chu[x];
		ll k = gcd(t.mu, t.zi);
		t.zi /= k, t.mu /= k;
		for (int i = head[x]; i != -1; i = e[i].nxt) {
			int y = e[i].v;
			solve(y, t);
			-- ru[y];
			if (chu[y] != 0 && ru[y] == 0) q.push(y);
		}
	}
	
	fir (i, 1, n) {
		if (chu[i] != 0) continue;
		ll x = num[i].zi, y = num[i].mu;
		ll k = gcd(x, y);
		printf("%lld %lld\n", x/k ,	y/k);
	}
	return 0;
}

