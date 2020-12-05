#include <bits/stdc++.h>
#define LL long long
using namespace std;

LL Ans = 0, stepx[500005], stepy[500005], Sum[12], c[12], n, m, w[12];

void doit()
{
	bool flag = 0;
	while (1)
	{
		for (int i = 1; i <= n; i++)
		{
			Ans++;
			Sum[stepx[i]] += stepy[i];
			if (Sum[stepx[i]] > w[stepx[i]] || Sum[stepx[i]] <= 0) 
			{
				flag = 1;
				break;
			}
			
		}
		if (flag) break;
	}
}

void dfs(int dep)
{
	if (dep > m)
	{
		for (int i = 1; i <= m; i++)
			Sum[i] = c[i];
		doit();
		return ;
	}
	else 
	{
		for (int i = 1; i <= w[dep]; i++)
		{
			c[dep] = i;
			dfs(dep + 1);
		}
	}
}

int main()
{
	freopen("walk.in", "r", stdin);
	freopen("walk.out", "w", stdout);
	scanf("%lld%lld", &n, &m);
	for (int i = 1; i <= m; i++)
		scanf("%lld", &w[i]);
	for (int i = 1; i <= n; i++)
		scanf("%lld%lld", &stepx[i], &stepy[i]);
	dfs(1);
	printf("%lld\n", Ans);
	return 0;
}

