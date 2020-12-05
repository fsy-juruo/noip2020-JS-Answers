#include <bits/stdc++.h>

using namespace std;

const int N = 100005;
int n, m;
bool st[N];
pair<int, int> ans[N];
int l[N];

int g(int u, int v)
{
	if(u > v) swap(u, v);
	if(v % u == 0) return u;
	return g(v % u, u);
}

int main()
{
	freopen("water.in", "r", stdin);
	freopen("water.out", "w", stdout);
	scanf("%d%d", &n, &m);
	memset(l, 1, sizeof(l));
	for (int i = 1; i <= m; i ++ )
	{
		ans[i].first = 1;
		ans[i].second = 1;
	}
	
	for (int i = 1; i <= n; i ++ )
	{
		int d;
		scanf("%d", &d);
		l[i] = l[i - 1] * d;
		for (int j = 1; j <= d; j ++ )
		{
			int a;
			scanf("%d", &a);
			if (d == 0)
			{
				st[i] = true;
			}
			int gb = g(l[i], ans[a].second);
			if (gb != 1) ans[a].first = ans[a].second / gb + ans[a].first * (l[i] / gb);
			else ans[a].first = ans[a].second + ans[a].first * l[i];
			ans[a].second = l[i];
		}
	}
	
	for (int i = 1; i <= n; i ++ )
	{
		if (st[i] == true)
		{
			printf("%d %d", ans[i].first, ans[i].second);
			printf("\n");
		}
	}
	return 0;
}
