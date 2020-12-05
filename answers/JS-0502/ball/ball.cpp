#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

template <typename T> inline void read(T &x)
{
	int f = 1; x = 0; char c = getchar();
	for (; !isdigit(c); c = getchar()) if (c == '-') f = -1;
	for (; isdigit(c); c = getchar()) x = (x << 3) + (x << 1) + (c ^ 48);
	x *= f;
}

const int N = 55;
const int M = 405;

int n, m, col[N];
vector <int> vec[N];

vector < pair <int, int> > ans;

inline void push(int x, int y)
{
	ans.push_back(make_pair(x, y));
	
	vec[y].push_back(vec[x].back());
	vec[x].pop_back();
}

inline bool check()
{
	for (int i = 1; i <= n + 1; i++)
	for (int j = 1; j < (int) vec[i].size(); j++)
	if (vec[i][j] != vec[i][j - 1]) return 0;
	
	bool flag = 0;
	for (int i = 1; i <= n + 1; i++)
	if (vec[i].empty())
	{
		if (flag) return 0;
		flag = 1;
	}
	return flag;
}

int main()
{
	srand(time(0));
	freopen ("ball.in", "r", stdin);
	freopen ("ball.out", "w", stdout);
	read(n); read(m);
	for (int i = 1; i <= n; i++)
	for (int j = 1, x; j <= m; j++)
	{
		read(x);
		vec[i].push_back(x);
	}
	
	int lx = -1, ly = -1;
	while (!check())
	{
		int x, y;
		do
		{
			x = rand() % (n + 1) + 1; y = rand() % (n + 1) + 1;
			if (x == y) y = y % (n + 1) + 1;
			if (vec[x].empty() || (int) vec[y].size() == m) x = y = -1;
		}
		while (x == y || (x == ly && y == lx));
		
		push(x, y);
		lx = x; ly = y;
	}
	
	printf ("%d\n", (int) ans.size());
	for (int i = 0; i < (int) ans.size(); i++) printf ("%d %d\n", ans[i].first, ans[i].second);
	return 0;
}
