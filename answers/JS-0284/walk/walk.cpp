#include <bits/stdc++.h>
using namespace std;

template <class T>
void read(T& x)
{
	x = 0;
	bool flag = 0;
	char ch = getchar();
	while (!isdigit(ch)) ((ch == '-') ? flag = 1 : flag = 0), ch = getchar();
	while (isdigit(ch)) x = x * 10 + (ch ^ 48), ch = getchar();
	x = flag ? -x : x;
}

const int N = 5e5 + 5;

struct Node
{
	int c, d;
}b[N];

int n, m, ans, w[15], a[15], land[15], f[15];

void work()
{
	int cnt = 0;
	for (int i = 1; i <= m; ++i)
		f[i] = land[i];
	for (int i = 1; ; ((i == n) ? i = 1 : (++i)))
	{
		f[b[i].c] += b[i].d;
		++cnt;
		++ans;
		if (f[b[i].c] < 1 || f[b[i].c] > w[b[i].c])
		{
			return;	
		}
		
	}
}

void dfs(int dep)
{
	if (dep > m)
	{
		work();
		return;
	}
	for (int i = 1; i <= w[dep]; ++i)
	{
		land[dep] = i;
		dfs(dep + 1);
	}
}

int main()
{
	freopen("walk.in", "r", stdin);
	freopen("walk.out", "w", stdout);
	read(n); read(m);
	for (int i = 1; i <= m; ++i)
		read(w[i]);
	for (int i = 1; i <= n; ++i)
	{
		read(b[i].c); read(b[i].d);
	}
	bool pd = 0;
	for (int i = 1; i <= m; ++i)
		if (a[i])
		{
			pd = 1;
			break;
		}
	if (pd)
	{
		puts("-1");
		return 0;
	}
	dfs(1);
	printf("%d\n", ans);
	return 0;
}

