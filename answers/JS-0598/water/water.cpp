#include<bits/stdc++.h>
#define filename "water"
#define reg register
#define ll long long
#define il inline

using namespace std;

template <typename T> void fi(T &x) {
	T f = 1, c = getchar(); x = 0;
	while(!isdigit(c)) {if(c == '-') f = -1; c = getchar();}
	while(isdigit(c)) {x = x * 10 + c - '0'; c = getchar();}
	x *= f;
}

int n, m;
int d[100010], a, f[100010];
vector <int> e[100010];
queue <int> q;

ll gcd(ll x, ll y) {
	if(x % y == 0) return y;
	return gcd(y, x % y);
}

struct node {
	ll x, y;
	void add(node a) {
		if(x == 0) {
			x = a.x;
			y = a.y;
			return;
		}
		x = x * a.y + y * a.x;
		y = y * a.y;
		int t = gcd(x, y);
		x /= t;
		y /= t;
		return;
	}
	void div(int a) {
		y *= a;
		int t = gcd(x, y);
		x /= t;
		y /= t;
		return;
	}
}w[100010];

int tmp, tmp1;

int main() {
	freopen(filename".in", "r", stdin);
	freopen(filename".out", "w", stdout);
	fi(n); fi(m);
	for(reg int i = 1; i <= n; ++ i ) {
		fi(d[i]);
		for(reg int j = 0; j < d[i]; ++ j ) {
			fi(a);
			++ f[a];
			e[i].push_back(a);
		}
	}
	for(reg int i = 1; i <= m; ++ i ) {
		q.push((int)i);
		w[i].x = w[i].y = 1;
	}
	while(!q.empty()) {
		tmp = q.front();
		q.pop();
		w[tmp].div(d[tmp]);
		for(reg int i = 0; i < d[tmp]; ++ i ) {
			tmp1 = e[tmp][i];
			-- f[tmp1];
			w[tmp1].add(w[tmp]);
			if(f[tmp1] == 0 && d[tmp1] != 0) {
				q.push(tmp1);
			}
		}
	}
	for(reg int i = 1; i <= n; ++ i ) {
		if(d[i] == 0) {
			printf("%lld %lld\n", w[i].x, w[i].y);
		}
	}
	return 0;
}

