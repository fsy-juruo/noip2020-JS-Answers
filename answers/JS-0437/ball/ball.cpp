#include <bits/stdc++.h>
using namespace std;

int n, m, from, to, trans, fini;
int a[510][510], b[510], c[510];
vector<pair<int, int> > st;

void mov(int x, int y)
{
	b[y]++;
	a[y][b[y]] = a[x][b[x]];
	if (a[x][b[x]] == x) c[x]--;
	b[x]--;
	if (a[y][b[y]] == y) c[y]++;
	st.push_back(make_pair(x, y));
}

int main()
{
	freopen("ball.in", "r", stdin);
	freopen("ball.out", "w", stdout);
	ios::sync_with_stdio(false);
	
	srand(1000);
	
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			cin >> a[i][j];
	for (int i = 1; i <= n; i++)
	{
		b[i] = m;
		for (int j = 1; j <= m; j++)
		{
			if (a[i][j] != i)
				break;
			c[i]++;
		}
	}
	n++;
	while (true)
	{
		fini = 0;
		for (int i = 1; i <= n; i++)
		{
			if (c[i] == m)
				fini++;
		}
		if (fini == n - 1)
			break;
		do
		{
			from = rand() % n + 1;
			to = a[from][c[from] + 1];
		}
		while (c[from] == m || b[from] == 0);
		if (from == to)
		{
			for (int i = 1; i <= n; i++)
				if (b[i] != m && i != from)
				{
					mov(from, i);
					trans = i;
				}
			for (int i = trans + 1; i <= n && b[from] > c[from]; i++)
			{
				if (b[i] != m && i != from)
					mov(from, i);
			}
			mov(trans, from);
		}
		if (from != to)
		{
			for (int i = 1; i <= n && b[to] > c[to]; i++)
			{
				if (b[i] != m && i != from && i != to)
					mov(to, i);
			}
			mov(from, to);
		}
	}
	cout << st.size() << endl;
	for (int i = 0; i < st.size(); i++)
		cout << st[i].first << " " << st[i].second << endl;

	return 0;
}

