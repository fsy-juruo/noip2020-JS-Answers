#include <bits/stdc++.h>
using namespace std;

const int MAXN = 55, MAXM = 405;
int val[MAXN][MAXM], tp[MAXN], vis[MAXN], n, m;
vector<pair<int, int> > ans;
void push(int x, int y) {
	ans.push_back(make_pair(x, y));
	assert(tp[x] > 0 && tp[y] < m);
	val[y][++tp[y]] = val[x][tp[x]];
	val[x][tp[x]--] = 0;
}

void divide(vector<int> vec, int fr) {
	memset(vis, 0, sizeof(vis));
	int n = vec.size();
	if (n == 1) return;
	for (int i = 0; i < n; i++) {
		assert(tp[vec[i]] == m);
		for (int j = 1; j <= m; j++)
			vis[val[vec[i]][j]] = 1;
	}
	int cnt = 0;
	for (int i = 1; i <= ::n; i++) if (vis[i])
		if (++cnt > n / 2) vis[i] = 2;
	vector<int> lft, rgt;
	while ((int)vec.size() > 1) {
		int s = vec.size(), a = vec[s - 2], b = vec[s - 1];
		vec.pop_back(); vec.pop_back();
		int cl = 0, cr = 0;
		for (int i = 1; i <= m; i++) {
			cl += vis[val[a][i]] == 1;
			cr += vis[val[a][i]] == 2;
			cl += vis[val[b][i]] == 1;
			cr += vis[val[b][i]] == 2;
		}
		int tmp = 0, x = 1, y = 2;
		if (cl > cr) swap(x, y);
		for (int i = 1; i <= m; i++)
			tmp += vis[val[a][i]] == y;
		assert(!tp[fr]);
		for (int i = 1; i <= tmp; i++) push(b, fr);
		assert(tp[a] == m);
		for (int i = m; i > 0; i--) {
			if (vis[val[a][i]] == x) push(a, fr);
			else push(a, b);
		}
		assert(!tp[a]);
		for (int i = 1; i <= tmp; i++) push(b, a);
		for (int i = 1; i <= m - tmp; i++) push(fr, a);
		for (int i = 1; i <= tmp; i++) push(fr, b);
		for (int i = 1; i <= m - tmp; i++) push(a, fr);
		assert(tp[b] == m);
		for (int i = m; i > 0; i--) {
			if (tp[a] == m || vis[val[b][i]] == x) push(b, fr);
			else push(b, a);
		}
		assert(tp[a] == m);
		for (int i = 1; i <= m; i++) assert(vis[val[a][i]] == y);
		while (tp[fr] > 0) push(fr, b);
		vec.push_back(b);
		if (y == 1) lft.push_back(a);
		else rgt.push_back(a);
	}
	if (vis[val[vec[0]][1]] == 1) lft.push_back(vec[0]);
	else rgt.push_back(vec[0]);
	divide(lft, fr);
	divide(rgt, fr);
}

int main() {
	freopen("ball.in", "r", stdin);
	freopen("ball.out", "w", stdout);
	scanf("%d%d", &n, &m);
	vector<int> vec;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++)
			scanf("%d", &val[i][j]);
		tp[i] = m;
		vec.push_back(i);
	}
	divide(vec, n + 1);
	int t = ans.size();
	printf("%d\n", t);
	for (int i = 0; i < t; i++)
		printf("%d %d\n", ans[i].first, ans[i].second);
//	printf("Debug:\n");
//	for (int i = 1; i <= n + 1; i++, puts(""))
//	for (int j = 1; j <= m; j++)
//		printf("%d ", val[i][j]);
	return 0;
}
