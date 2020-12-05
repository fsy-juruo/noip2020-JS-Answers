#include <bits/stdc++.h>
#define LL long long
using namespace std;

LL a[100005][6], S[100005], cnt = 0, n, m;

struct Node
{
	LL fz, fm;
}f[100005];

void dfs(LL x, LL fz, LL fm)
{
	if (a[x][0] == 0) 
	{
		if (f[x].fm == 0 && f[x].fz == 0) 
		{
			f[x].fm = fm;
			f[x].fz = fz;
			return ;
		}
		LL p = fm * f[x].fm / __gcd(fm, f[x].fm);
		f[x].fz = p / fm * fz + p / f[x].fm * f[x].fz;
		f[x].fm = p;
		LL l = __gcd(f[x].fz, f[x].fm);
		f[x].fz /= l;
		f[x].fm /= l;
		return ;
	}
	for (int i = 1; i <= a[x][0]; i++)
		dfs(a[x][i], fz, fm * a[x][0]);
}

int main()
{
	freopen("water.in", "r", stdin);
	freopen("water.out", "w", stdout);
	scanf("%lld%lld", &n, &m);
	for (int i = 1; i <= n; i++)
	{
		scanf("%lld", &a[i][0]);
		if (a[i][0] == 0) S[++cnt] = i;
		for (int j = 1; j <= a[i][0]; j++)
			scanf("%lld", &a[i][j]);
	}
	for (int i = 1; i <= m; i++)
		dfs(i, 1, 1);
	for (int i = 1; i <= cnt; i++)
		printf("%lld %lld\n", f[S[i]].fz, f[S[i]].fm);
	return 0;
}

