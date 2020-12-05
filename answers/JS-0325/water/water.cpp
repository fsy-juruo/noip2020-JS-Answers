#include<bits/stdc++.h>
using namespace std;

template<class T> inline void readNum(T& num) {
	num = 0; register char c = getchar(); bool neg = false;
	while (!isdigit(c)) { if (c == '-') neg = true; c = getchar(); }
	while (isdigit(c)) { num = num * 10 + c - '0'; c = getchar(); }
	if (neg) num = ~num + 1;
}

#define ll long long

const int N_MAX = 100005;
const int D_MAX = 5;

struct edge {
	int to, nxt;
};

template<class T> inline T gcd(T a, T b) {
	if (!b) return a;
	return gcd(b, a % b);
}

struct frac {
	ll a, b;
	frac() :a(0), b(1) {}
	frac (ll _i): a(_i), b(1) {}
	frac(ll _a, ll _b) {
		register ll t = gcd(_a, _b);
		a = _a / t;
		b = _b / t;
	}
	
	frac operator+(const frac& f) { return frac(a * f.b + b * f.a, b * f.b); }
	frac operator/(ll i) { return frac(a, b * i); }
};

int n, m, ep;
int incomes[N_MAX];
int outcomes[N_MAX];
int heads[N_MAX];
edge edges[N_MAX * D_MAX << 1];
frac flow[N_MAX];

void addEdge(int x, int y) { edges[ep].to = y; edges[ep].nxt = heads[x]; heads[x] = ep++; }

void input() {
	memset(heads, -1, sizeof(heads));
	readNum(n);
	readNum(m);
	int d, t;
	for (register int i = 1; i <= n; ++i) {
		readNum(d);
		for (register int j = 0; j < d; ++j) {
			readNum(t);
			++incomes[t];
			++outcomes[i];
			addEdge(i, t);
		}
	}
}

void run() {
	queue<int> que;
	for (register int i = 1; i <= n; ++i) {
		if (!incomes[i]) {
			que.push(i);
			flow[i] = frac(1);
		}
	}
	
	while (!que.empty()) {
		const int cur = que.front();
		que.pop();
		frac output = flow[cur] / outcomes[cur];
		for (register int i = heads[cur]; i != -1; i = edges[i].nxt) {
			flow[edges[i].to] = flow[edges[i].to] + output;
			--incomes[edges[i].to];
			if (!incomes[edges[i].to])
				que.push(edges[i].to);
		}
	}
}

void print() {
	for (register int i = 1; i <= n; ++i)
		if (!outcomes[i])
			printf("%lld %lld\n", flow[i].a, flow[i].b);
}

int main() {
	freopen("water.in", "r", stdin);
	freopen("water.out", "w", stdout);
	input();
	run();
	print();
	return 0;
}
