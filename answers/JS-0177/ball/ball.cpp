#include <bits/stdc++.h>

using namespace std;

int n, m;
vector<vector<int> > v(4);

bool check(vector<vector<int> > x)
{
	if (!x[1].empty() && !x[2].empty() && !x[3].empty())
		return false;
		
	if (x[1].empty())
		swap(x[1], x[3]);
	else if (x[2].empty())
		swap(x[2], x[3]);
	
	for (int i = 1; i < x[1].size(); i++)
	{	
		if (x[1][i] != x[1][i - 1])
			return false;
	}
}
void bfs()
{
	queue<pair<vector<vector<int> >, vector<pair<int, int> > > > qu;
	vector<pair<int, int> > t;
	qu.push(make_pair(v, t));
	while (!qu.empty())
	{
		vector<vector<int> > v = qu.front().first, tmp = v;
		vector<pair<int, int> > t = qu.front().second, tmpt = t;
		qu.pop();
		for (int i = 1; i <= 3; i++)
		{	
			for (int j = 1; j <= 3; j++)
			{
				if (v[i].empty() || v[j].size() == m)
					continue;
				v[j].push_back(v[i].back());
				v[i].pop_back();
				t.push_back(make_pair(i, j));
				qu.push(make_pair(v, t));
				if (check(v))
				{
					cout << t.size() << "\n";
					for (int i = 0; i < t.size(); i++)
						cout << t[i].first << " " << t[i].second << "\n";
					return;
				}
				v = tmp;
				t = tmpt;
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	freopen("ball.in", "r", stdin);
	freopen("ball.out", "w", stdout);

	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			int k;
			cin >> k;
			v[i].push_back(k);
		}
	}
	
	bfs();

	return 0;
}

