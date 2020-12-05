#include<bits/stdc++.h>
using namespace std;
void write(int num) {
	if (!num) putchar('0');
	int res[30], tot = 0;
	while (num) res[++tot] = num%10, num /= 10;
	for (int i = tot; i > 0; i--) putchar(res[i]+'0');
}
vector<pair<int, int> > ans;
int m, a[55][401], top[55], vis[55];
void move(int x, int y) {
	ans.push_back(make_pair(x, y));
	a[y][++top[y]] = a[x][top[x]--];
}
void srt(int now, int tmp, int targ, int empty) {
	int cnt = 0, maxn = m + 1;
	for (int i = m; i >= 1; i--)
		if (a[now][i] == targ) ++cnt, maxn = i;
	for (int i = 1; i <= cnt; i++) move(tmp, empty);
	while (top[now] >= maxn)
		if (a[now][top[now]] == targ) move(now, tmp);
		else move(now, empty);
	while (top[empty] > cnt) move(empty, now);
	for (int i = 1; i <= cnt; i++) move(tmp, now);
	for (int i = 1; i <= cnt; i++) move(empty, tmp);
}
void solve(int col, int n) {
	if (n == 1) return;
	srt(1, 2, col, n+1);
	for (int i = 2; i <= n; i++) srt(i, i-1, col, n+1);
	for (int i = 1; i <= n; i++)
		while (top[i] && a[i][top[i]] == col)
			move(i, n+1);
	for (int i = 1; i < n; i++)
		while (top[i] < m) move(n, i);
	vis[col] = 1;
}
int calc(int col, int n) {
	int res = 0;
	for (int i = 1; i <= n; i++) {
		int maxn = m + 1;
		for (int j = m; j >= 1; j--)
			if (a[i][j] == col) maxn = j;
		res += m - maxn + 1;
	}
	return res;
}
int main() {
	freopen("ball.in", "r", stdin);
	freopen("ball.out", "w", stdout);
	int n;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		top[i] = m;
		for (int j = 1; j <= m; j++) cin >> a[i][j];
		top[i] = m;
	}
	for (int i = n; i >= 2; i--) {
		int step = 0x3f3f3f3f, id = 0;
		for (int j = 1; j <= n; j++)
			if (!vis[j]) {
				int tmp = calc(j, i);
				if (tmp < step) step = tmp, id = j;
			}
		solve(id, i);
	}
	write(ans.size()), putchar('\n');
	for (int i = 0; i < (int)ans.size(); i++) 
		write(ans[i].first), putchar(' '), write(ans[i].second), putchar('\n');
}
