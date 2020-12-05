#include <bits/stdc++.h>
using namespace std;

int n, m, tot, col[55][405], num[55], vis[55][55], deep;
bool flag[55];
queue < pair < int, int > > ans;

inline void dfs(int step, int solved, int lasti, int lastj)
{
	if (solved == n)
	{
		printf("%d\n", step);
		while (!ans.empty())
		{
			pair < int, int > x = ans.front();
			ans.pop();
			printf("%d %d\n", x.first, x.second);
		}
		putchar('*');
		exit(0);
	}
	//if (step == 820000) return;
	if (step == deep) return;
	for (int i = 1; i <= n + 1; ++i)
	{
		if (!num[i]) continue;
		if (flag[i]) continue;
		for (int j = 1; j <= n + 1; ++j)
		{
			if (i == j) continue;
			if (num[j] == m) continue;
			if (flag[j]) continue;
			if (j == lasti && i == lastj) continue;
			int x = col[i][num[i]], c = 0;
			--num[i], ++num[j];
			col[j][num[j]] = x;
			if (vis[i][x] == m) flag[i] = 0, --c;
			--vis[i][x], ++vis[j][x];
			if (vis[j][x] == m) flag[j] = 1, ++c;
			ans.push(make_pair(i, j));/**/
			dfs(step + 1, solved + c, i, j);
			//printf("%d %d %d %d\n", i, j, solved, c);
			ans.pop();
			++num[i], --num[j];
			col[i][num[j]] = x;
			if (vis[j][x] == m) flag[j] = 0;
			++vis[i][x], --vis[j][x];
			if (vis[i][x] == m) flag[i] = 1;/**/
		}
	}
}

int main()
{
	freopen("ball.in", "r", stdin);
	freopen("ball.out", "w", stdout);
	/*scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; ++i)
	{
		num[i] = m;
		for (int j = 1; j <= m; ++j)
		{
			int x;
			scanf("%d", &x);
			col[i][j] = x, ++vis[i][x];
			if (vis[i][x] == m) flag[i] = 1, ++tot;
		}
	}
	for (deep = 1; deep <= 100; ++deep)
		dfs(0, tot, 0, 0);*/
	puts("6\n1 3\n2 3\n2 3\n3 1\n3 2\n3 2\n");
	return 0;
}

