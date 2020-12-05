#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair 
using namespace std;

typedef pair <int, int> pii;

vector <int> a[60];
vector <pii> op;
int m;

void add_op(int x, int y) {
	assert(a[x].size() && a[y].size() < m);
	a[y].push_back(a[x].back()), a[x].pop_back();
	op.push_back(mp(x, y));
}

void move_ball(int n, int m, int x, int y, int to) {
	int sz = a[to].size(), lst = -1;
	for (int i = 0; i <= n; i++) {
		if (i == x || i == to) continue;
		while (a[i].size() < m) {
			if (a[x].size() == y + 1) goto END;
			add_op(x, i), lst = i;
		}
	}
	END:;
	if (a[x].size() == y + 1) {
		add_op(x, to);
		return ;
	}
	while (a[x].size() != y + 1) {
		add_op(x, to);
	}
	int p = -1;
	for (int i = 0; i <= n; i++) {
		if (i == x || i == to) continue;
		p = i;
		break;
	}
	add_op(p, to), add_op(x, p);
	while (a[to].size() != sz) {
		add_op(to, x);
	}
	add_op(p, to);
}

void calc(int n, int m, int empty) {
	if (n == 0) return ;
	int col = a[0].back();
	for (int i = 0; i < n; i++) {
		int flag = 1;
		while (flag) {
			flag = 0;
			for (int j = (int)a[i].size() - 1; j >= 0; j--) {
				if (a[i][j] == col) {
					move_ball(n, m, i, j, empty);
					flag = 1;
					break;
				}
			}
		}
	}
	for (int i = 0; i < n - 1; i++) {
		while (a[i].size() < m) move_ball(n, m, n - 1, (int)a[n - 1].size() - 1, i);
	}
	calc(n - 1, m, n - 1);
}

int main() {
	freopen("ball.in", "r", stdin);
	freopen("ball.out", "w", stdout);
	int n; scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int x; scanf("%d", &x);
			a[i].push_back(x);
		}
	}
	calc(n, m, n);
	printf("%d\n", (int)op.size());
	for (int i = 0; i < op.size(); i++) {
		printf("%d %d\n", op[i].fi + 1, op[i].se + 1);
	}
	return 0;
}
/*
2 3
1 1 2
2 1 2


*/
