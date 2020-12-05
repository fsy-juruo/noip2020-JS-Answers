#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int maxnode = 1e5, maxedge = 5e5, maxm = 10;

int n, m, head[maxnode + 1], num[maxnode + 1], tot;
ll ansp[maxnode + 1], ansq[maxnode + 1];
struct edge
{
	int v, nxt;
} e[maxedge];

void clear_graph()
{
	fill(head + 1, head + n + 1, -1);
	fill(ansp + 1, ansp + n + 1, -1);
	fill(ansq + 1, ansq + n + 1, -1);
	tot = 0;
}
void add_edge(int u, int v)
{
	e[tot].v = v;
	e[tot].nxt = head[u];
	head[u] = tot++;
}

ll mygcd(ll x, ll y)
{
	return y ? mygcd(y, x % y) : x;
}
void add(int u, int p, int q)
{
	if (ansp[u] == -1)
	{
		ansp[u] = p;
		ansq[u] = q;
	}
	else
	{
		ll tmpp = p * ansq[u] + q * ansp[u], tmpq = q * ansq[u];
		ll tmp = mygcd(tmpp, tmpq);
		ansp[u] = tmpp / tmp;
		ansq[u] = tmpq / tmp;
	}
}
void dfs(int u, int p, int q)
{
	if (!num[u])
	{
		add(u, p, q);
		return;
	}
	
	for (int i = head[u]; ~i; i = e[i].nxt)
	{
		int v = e[i].v;
		dfs(v, p, q * num[u]);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	freopen("water.in", "r", stdin);
	freopen("water.out", "w", stdout);

	cin >> n >> m;
	clear_graph();
	for (int u = 1; u <= n; u++)
	{
		cin >> num[u];
		for (int i = 1; i <= num[u]; i++)
		{
			int v;
			cin >> v;
			add_edge(u, v);
		}
	}
	
	for (int i = 1; i <= m; i++)
		dfs(i, 1, 1);
		
	for (int i = 1; i <= n; i++)
	{
		if (num[i] == 0)
			cout << ansp[i] << " " << ansq[i] << "\n";
	}

	return 0;
}

