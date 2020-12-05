#include<bits/stdc++.h>

#define N 405
#define INF 0x3f3f3f3f

using namespace std;

int n, m, x, st[3][N], siz[3], t[3], l[3];
int ans[3][820005];

void add(int a, int b)
{
	ans[1][++ ans[0][0]] = a;
	ans[2][ans[0][0]] = b;
}

void ftl(int x)
{
	t[x] = st[x][siz[x]]; l[x] = 0;
	for(int i = siz[x]; i > 0; -- i)
	{
		if(st[x][i] == t[x]) ++ l[x];
		else break;
	}
}

signed main()
{
	freopen("ball.in", "r", stdin);
	freopen("ball.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; ++ i)
		for(int j = 1; j <= m; ++ j)
			scanf("%d", &x), st[i][j] = x;
	siz[1] = siz[2] = m;
	ftl(1); ftl(2);
	while(l[1] < m)
	{
		if(t[1] == t[2])
		{
			t[3] = t[1];
			siz[1] -= l[1];
			siz[2] -= l[2];
			for(int i = 1; i <= l[1]; ++ i) add(1, 3);
			for(int i = 1; i <= l[2]; ++ i) add(2, 3);
			ftl(1); ftl(2);
			if(l[1] >= l[2])
				for(int i = 1; i <= l[1] && siz[2] < m; ++ i)
					st[2][++ siz[2]] = t[1], siz[1] --, add(1, 2);
			else
				for(int i = 1; i <= l[2] && siz[1] < m; ++ i)
					st[1][++ siz[1]] = t[2], siz[2] --, add(2, 1);
		}
		else
		{
			if(l[1] >= l[2])
			{
				t[3] = t[1];
				siz[1] -= l[1];
				for(int i = 1; i <= l[1]; ++ i) add(1, 3);
				for(int i = 1; i <= l[2] && siz[1] < m; ++ i)
					st[1][++ siz[1]] = t[2], siz[2] --, add(2, 1);
			}
			else
			{
				t[3] = t[2];
				siz[2] -= l[2];
				for(int i = 1; i <= l[2]; ++ i) add(2, 3);
				for(int i = 1; i <= l[1] && siz[2] < m; ++ i)
					st[2][++ siz[2]] = t[1], siz[1] --, add(1, 2);
			}
		}
		while(siz[1] < m) st[1][++ siz[1]] = t[3], add(3, 1);
		while(siz[2] < m) st[2][++ siz[2]] = t[3], add(3, 2);
		ftl(1); ftl(2);
	}
	cout << ans[0][0] << endl;
	for(int i = 1; i <= ans[0][0]; ++ i)
		printf("%d %d\n", ans[1][i], ans[2][i]);
	return 0;
}

