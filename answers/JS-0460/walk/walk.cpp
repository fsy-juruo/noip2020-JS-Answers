#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e5 + 10;
const int MO = 1e9 + 7;
int n, k, w[20], dir[2][maxn], a[20], b[20], ans;
bool flag;
int rd() {
	int x = 0, f = 1;
	char ch = getchar();
	for (; !isdigit(ch); ch = getchar()) {
		if (ch == '-') {
			f = -f;
		}
	}
	for (; isdigit(ch); ch = getchar()) {
		x = (x << 1) + (x << 3) + (ch ^ 48);
	}
	return x * f;
}
bool check() {
	for (int i = 1; i <= k; i++) {
		if (a[i] != b[i]) {
			return 0;
		}
	}
	return 1;
}
void work() {
	memcpy(b, a, sizeof(a));
	for (int i = 1; i <= n; i++) {
		b[dir[0][i]] += dir[1][i];
		ans++;
		if (ans > MO) {
			ans -= MO;
		}
		if (b[dir[0][i]] < 1 || b[dir[0][i]] > w[dir[0][i]]) {
			return;
		}
	}
	if (check()) {
		flag = 0;
		return;
	}
	while (1) {
		for (int i = 1; i <= n; i++) {
			b[dir[0][i]] += dir[1][i];
			ans++;
			if (ans > MO) {
				ans -= MO;
			}
			if (b[dir[0][i]] < 1 || b[dir[0][i]] > w[dir[0][i]]) {
				return;
			}
		}
	}
}
void dfs(int dep) {
	if (flag == 0) {
		return;
	}
	if (dep > k) {
		work();
		return;
	}
	for (int i = 1; i <= w[dep]; i++) {
		a[dep] = i;
		dfs(dep + 1);
	}
}
int main() {
	freopen("walk.in", "r", stdin);
	freopen("walk.out", "w", stdout);
	n = rd();
	k = rd();
	for (int i = 1; i <= k; i++) {
		w[i] = rd();
	}
	for (int i = 1; i <= n; i++) {
		dir[0][i] = rd();
		dir[1][i] = rd();
	}
	if (n > 100) {
		cout << -1 << endl;
		return 0;
	}
	flag = 1;
	dfs(1);
	if (flag == 0) {
		cout << -1 << endl;
	} else {
		cout << ans << endl;
	}
	return 0;
}

