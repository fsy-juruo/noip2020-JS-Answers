#include <bits/stdc++.h>
using namespace std;

int n, k, ans;
int p[110], pst[110], w[110], c[100010], d[100010];

int check()
{
	for (int i = 1; i <= k; i++)
		p[i] = pst[i];
	int res = 0;
	while (true)
	{
		for (int i = 1; i <= n; i++)
		{
			p[c[i]] += d[i];
			++res;
			if (p[c[i]] < 1 || p[c[i]] > w[c[i]])
				return res;
		}
	}
}

void dfs(int dep)
{
	if (dep > k)
	{
		ans += check();
		return;
	}
	for (int i = 1; i <= w[dep]; i++)
	{
		pst[dep] = i;
		dfs(dep + 1);
	}
}

int main()
{
	// mod
	freopen("walk.in", "r", stdin);
	freopen("walk.out", "w", stdout);
	ios::sync_with_stdio(false);
	
	cin >> n >> k;
	for (int i = 1; i <= k; i++)
		cin >> w[i];
	for (int i = 1; i <= n; i++)
	{
		cin >> c[i] >> d[i];
	}
	dfs(1);
	cout << ans << endl;

	return 0;
}

