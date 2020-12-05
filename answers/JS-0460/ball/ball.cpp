#include <bits/stdc++.h>
using namespace std;
const int maxn = 60;
const int maxm = 410;
const int maxk = 820010;
struct node {
	int a[maxm], sum[maxm], tot;
} p[maxn], q[maxn];
int n, m, ans1[maxk], ans2[maxk], km, c[maxn];
bool flag;
void init() {
	for (int i = 1; i <= n; i++) {
		q[i].tot = p[i].tot;
		for (int j = 1; j <= m; j++) {
			q[i].a[j] = p[i].a[j];
			q[i].sum[j] = p[i].sum[j];
		}
	}
}
void mo(int x, int y) {
	ans1[++km] = x;
	if (km > 820000) {
		flag = 0;
		return;
	}
	ans2[km] = y;
	q[y].a[++q[y].tot] = q[x].a[q[x].tot];
	q[y].sum[q[x].a[q[x].tot]]++;
	q[x].sum[q[x].a[q[x].tot]]--;
	q[x].a[q[x].tot] = 0;
	q[x].tot--;
}
void work(int x, int t, int y, int r) {
	for (int i = m; i >= r; i--) {
		mo(y, n + 1);
		if (flag == 0) {
			return;
		}
	}
	while (q[x].tot >= t) {
		if (q[y].tot < m - 1) {
			mo(x, y);
		} else if (q[y].tot == m - 1) {
			mo(n + 1, y);
			mo(x, n + 1);
		} else {
			mo(x, n + 1);
		}
		if (flag == 0) {
			return;
		}
	}
	if (q[y].tot == m) {
		mo(y, x);
		mo(n + 1, y);
	} else {
		mo(n + 1, x);
		while (q[y].tot < m) {
			mo(n + 1, y);
		}
	}
	if (flag == 0) {
		return;
	}
	while (q[n + 1].tot) {
		mo(n + 1, x);
		if (flag == 0) {
			return;
		}
	}
}
int main() {
	freopen("ball.in", "r", stdin);
	freopen("ball.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> p[i].a[j];
			p[i].sum[p[i].a[j]]++;
		}
		p[i].tot = m;
	}
	for (int i = 1; i <= n; i++) {
		c[i] = i;
	}
	do {
		km = 0;
		init();
		flag = 1;
		for (int i = 1; i <= n; i++) {
			int t = 0;
			for (int j = 1; j <= m; j++) {
				if (p[i].a[j] == c[i]) {
					t++;
				} else {
					break;
				}
			}
			for (int j = i + 1; j <= n; j++) {
				while (q[j].sum[c[i]] != 0) {
					for (int k = 1; k <= m; k++) {
						if (q[j].a[k] == c[i]) {
							t++;
							work(i, t, j, k);
							if (flag == 0) {
								break;
							}
						}
					}
					if (flag == 0) {
						break;
					}
				}
				if (flag == 0) {
					break;
				}
			}
			if (flag == 0) {
				break;
			}
		}
		if (flag) {
			cout << km << endl;
			for (int i = 1; i <= km; i++) {
				cout << ans1[i] << " " << ans2[i] << endl;
			}
			break;
		}
	} while (next_permutation(c + 1, c + n + 1));;
	return 0;
}

