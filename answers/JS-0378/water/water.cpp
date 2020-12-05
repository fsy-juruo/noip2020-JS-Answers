#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXM = 2e6 + 5;
const int MAXN = 1e5 + 5;

ll gcd(ll a, ll b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}

struct Number {
	ll x, y; //    x / y
};

Number Add(Number a, Number b) {
	Number ret;
	ret.y = a.y * b.y;
	ret.x = a.x * b.y + b.x * a.y;
	ll g = gcd(ret.y, ret.x);
	ret.y /= g, ret.x /= g;
	return ret;
}

Number Div(Number a, ll b) {
	Number ret;
	ll g = gcd(a.x, b);
	ret.x = a.x / g;
	ret.y = a.y * b / g;
	return ret;
}

struct Edge {
	int v, nxt;
} edge[MAXM];
int head[MAXN], cnt;

inline void AddEdge(int u, int v) {
	edge[++cnt].v = v;
	edge[cnt].nxt = head[u];
	head[u] = cnt;
}

int n, m;
int d_out[MAXN], d_in[MAXN];
bool is_start[MAXN], is_end[MAXN];
Number f[MAXN];

queue<int> q;

int main() {
freopen("water.in", "r", stdin);
freopen("water.out", "w", stdout);
//	freopen("water3.in", "r", stdin);
//	freopen("mans.out", "w", stdout);
//	Number a = (Number){1, 4};
//	Number b = (Number){1, 2};
//	Number c = Add(a, b);
//	cout << c.x << ' ' << c.y;
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &d_out[i]);
		for (int j = 1; j <= d_out[i]; ++j) {
			int v;
			scanf("%d", &v);
			AddEdge(i, v);
			d_in[v]++;
		}
	}
	for (int i = 1; i <= n; ++i) {
		if (d_in[i] == 0) is_start[i] = 1, q.push(i), f[i].x = 1, f[i].y = 1;
		else f[i].x = 0, f[i].y = 1;
		if (d_out[i] == 0) is_end[i] = 1;
	}
	while (q.size()) {
		int u = q.front();
	//	cout << u << endl;
	//	system("pause");
		q.pop();
		if (d_out[u] == 0) continue;
		Number tmp = Div(f[u], d_out[u]);
	//	cout << tmp.x << ' ' << tmp.y << endl;
	//	system("pause");
		for (int i = head[u]; i; i = edge[i].nxt) {
			int v = edge[i].v;
			f[v] = Add(f[v], tmp);
			d_in[v]--;
			if (d_in[v] == 0) q.push(v);
		}
	}
	for (int i = 1; i <= n; ++i) {
		if (is_end[i]) {
			printf("%lld %lld\n", f[i].x, f[i].y);
		}
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

