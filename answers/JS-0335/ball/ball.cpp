#include<cstdio>
#include<cstdlib>
#include<ctime>
#include<utility>

int n, m, top[60], a[60][500], x, y, h[10010][15][25], tot;
std::pair<int, int> ans[820010];
bool findans;

inline bool check() {
	for (int i = 1; i <= n + 1; ++i) {
		if (top[i] != m && top[i] != 0) return 0;
		for (int j = 1; j < m; ++j)
			if (a[i][j] != a[i][j + 1]) return 0;
	}
	return 1;
}

void dfs(int dep, int x, int y) {
	//if (dep > 10) return ;
	if (findans) return ;
	if (check()) {
		for (int i = 1; i < dep; ++i) printf("%d %d\n", ans[i].first, ans[i].second);
		findans = 1;
		return ;
	}
	for (int i = 1; i <= n + 1; ++i)
		for (int j = 1; j <= n + 1; ++j) {
			if (i == j || i == y && j == x) continue;
			if (top[i] <= 0 || top[j] >= m) continue;
			printf("%d %d %d\n", dep, i, j);
			a[j][++top[j]] = a[i][top[i]--];
			bool flag = 1;
			for (int t = 1; t <= tot; ++t) {
				for (int xx = 1; xx <= n + 1; ++xx) {
					for (int yy = 1; yy <= top[xx]; ++yy)
						if (a[xx][yy] != h[t][xx][yy]) {flag = 0; break;}
					if (!flag) break;
				}
				if (!flag) break;
			}	
			if (flag && tot > 0) {a[i][++top[i]] = a[j][top[j]--]; continue;}
			ans[dep] = std::make_pair(i, j);
			for (int xx = 1; xx <= n + 1; ++xx)
				for (int yy = 1; yy <= top[x]; ++yy)
					h[++tot][xx][yy] = a[xx][yy];
			dfs(dep + 1, i, j);
			a[i][++top[i]] = a[j][top[j]--];
		}
}

int main() {
	freopen("ball.in", "r", stdin);
	freopen("ball.out", "w", stdout);
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; ++i) {
		top[i] = m;
		for (int j = 1; j <= m; ++j)
			scanf("%d", &a[i][j]);	
	}
	dfs(1, 0, 0);
	return 0;
}
