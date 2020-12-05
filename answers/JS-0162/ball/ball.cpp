#include <bits/stdc++.h>
using namespace std;
const int N = 55, M = 405;
int n, m, cnt, pcnt[N], bot[N], st[N][M], top[N];
pair <int, int> ans[820005], p[N][M];
void doit (int x, int y) {
	ans[++ cnt] = make_pair (x, y);
//	if (cnt == 1)
//		cout << x << " " << y << endl;
	
//	if (cnt == 1) {
//	for (int i = 1; i <= n + 1; i ++) {
//		for (int j = 1; j <= m; j ++)
//			cout << st[i][j] << " ";
//		cout << endl;
//	}
//	cout << cnt << ":" << x << " " << y << endl;
//}
	top[y] ++;
	st[y][top[y]] = st[x][top[x]];
	st[x][top[x]] = 0;
	top[x] --;
//	if (cnt == 1) {
//	for (int i = 1; i <= n + 1; i ++) {
//		for (int j = 1; j <= m; j ++)
//			cout << st[i][j] << " ";
//		cout << endl;
//	}
//	cout << cnt << ":" << x << " " << y << endl;
//}
	return ;
}
void mv (int x, int pos, int y) {
	for (int i = 1; i < pos; i ++) {
		doit (x, n + 1);
	}
	doit (y, n + 1);
	doit (x, y);
	while (top[n + 1])
		doit (n + 1, x);
	return ;
}
void sink_top (int x) {
	if (x != n)
		doit (n, n + 1);
	else
		doit (n - 1, n + 1);
	if (x != n)
		doit (x, n);
	else
		doit (x, n - 1);
	while (top[x])
		doit (x, n + 1);
	if (x != n)
		doit (n, x);
	else
		doit (n - 1, x);
	while (top[n + 1] > 1)
		doit (n + 1, x);
	if (x != n)
		doit (n + 1, n);
	else
		doit (n + 1, n - 1);
	return ;
}
void sink (int x, int pos) {
	if (x != n)
		doit (n, n + 1);
	else
		doit (n - 1, n + 1);
	for (int i = 1; i < pos; i ++)
		doit (x, n + 1);
	if (x != n)
		doit (x, n);
	else
		doit (x, n - 1);
	while (top[x])
		doit (x, n + 1);
	if (x != n)
		doit (n, x);
	else
		doit (n - 1, x);
	while (top[n + 1] > 1)
		doit (n + 1, x);
	if (x != n)
		doit (n + 1, n);
	else
		doit (n + 1, n - 1);
	return ;
}
int main () {
	freopen ("ball.in", "r", stdin);
	freopen ("ball.out", "w", stdout);
	scanf ("%d%d", &n, &m);
	for (int i = 1; i <= n; i ++) {
		for (int j = 1; j <= m; j ++)
			scanf ("%d", &st[i][j]);
		top[i] = m;
	}
	for (int i = 1; i <= n; i ++)
		while (st[i][top[i]] == i)
			sink_top (i);
	for (int i = 1; i <= n; i ++)
		for (int j = 1; j <= m; j ++)
			p[st[i][j]][++ pcnt[st[i][j]]] = make_pair (i, j);
	for (int i = 1; i <= n; i ++)
		for (int j = 1; j <= pcnt[i]; j ++)
			if (p[i][j].first == i)
				sink (i, p[i][j].second);
			else {
				mv (p[i][j].first, p[i][j].second, i);
				sink_top (i);
			}
//	return 0;
	printf ("%d\n", cnt);
	for (int i = 1; i <= cnt; i ++)
		printf ("%d %d\n", ans[i].first, ans[i].second);
	return 0;
}

