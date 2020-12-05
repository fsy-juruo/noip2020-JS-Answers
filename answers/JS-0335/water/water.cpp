#include<cstdio>
#include<cctype>
#define MaxN 100010
#define MaxM 100010

inline int gcd(int x, int y) {
	return x % y == 0 ? y : gcd(y, x % y);
}

inline int lcm(int x, int y) {
	return (int) (1LL * x / gcd(x, y) * y);
}

struct number {
	int x, y; //x / y
	number operator + (const number &rhs) const {
		if (!x && !y) return rhs;
		if (!rhs.x && !rhs.y) return (number) {x, y};
		int _y = lcm(y, rhs.y);
		int _x = (int) (1LL * x * _y / y + 1LL * rhs.x * _y / rhs.y);
		int d = gcd(_x, _y);
		return (number) {_x / d, _y / d};
	}
} ans[MaxN];
struct edge {int v, nxt;} e[MaxM];

int head[MaxN], n, m, k, x, indegree[MaxN], outdegree[MaxN], tot;

inline int read() {
	int x = 0, f = 1; char c = getchar();
	for (; !isdigit(c); c = getchar()) if (c == '-') f = -1;
	for (; isdigit(c); c = getchar()) x = x * 10 + c - '0';
	return x * f;
}

void addedge(int x, int y) {
	e[++tot] = (edge) {y, head[x]};
	head[x] = tot;
}

void dfs(int x, number flow) {
	for (int i = head[x]; i; i = e[i].nxt) {
		int y = e[i].v;
		ans[y] = ans[y] + (number) {flow.x, flow.y * outdegree[x]};
		dfs(y, (number) {flow.x, flow.y * outdegree[x]});
	}
}

int main() {
	freopen("water.in", "r", stdin);
	freopen("water.out", "w", stdout);
	n = read(); m = read();
	for (int i = 1; i <= n; ++i) {
		k = read();
		for (int j = 1; j <= k; ++j) {
			x = read();
			addedge(i, x);
			++indegree[x];
			++outdegree[i];
		}
	}	
	for (int i = 1; i <= n; ++i) 
		if (!indegree[i]) ans[i] = (number) {1, 1}, dfs(i, (number) {1, 1});
	for (int i = 1; i <= n; ++i)
		if (!outdegree[i]) printf("%d %d\n", ans[i].x, ans[i].y);
	return 0;
}
