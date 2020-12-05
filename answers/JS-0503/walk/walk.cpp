#include <bits/stdc++.h>
using namespace std;
int n, k, w[6];
int c[1005], d[1005];
long long ans;
struct Coor
{
	int x[6];
	Coor(){memset(x, 0, sizeof(x));}
};
bool ins(const Coor &co)
{
	for (int i = 1;i <= k;++i)
	{
		if (co.x[i] > w[i] || co.x[i] < 1) return 0;
	}
	return 1;
}
bool operator <(const Coor &a, const Coor &b)
{
	for (int i = 1;i <= k;++i)
	{
		if (a.x[i] > b.x[i]) return 0;
		if (a.x[i] < b.x[i]) return 1;
	}
	return 0;
}
map<Coor, int> mp;
int f(const Coor &co)
{
	int tmp = mp[co];
	if (tmp) return tmp;
	Coor cur(co);
	for (int i = 1;i <= n;++i)
	{
		cur.x[c[i]] += d[i];
		if (!ins(cur)) return mp[co] = i;
	}
	return mp[co] = n + f(cur);
}
Coor coor;
void dfs(int dep)
{
	if (dep > k)
	{
		ans += f(coor);
		return ;
	}
	for (coor.x[dep] = 1;coor.x[dep] <= w[dep];++coor.x[dep])
	{
		dfs(dep + 1);
	}
}
int main()
{
	//time_t start_time = clock();
	freopen("walk.in", "r", stdin);
	freopen("walk.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin >> n >> k;
	for (int i = 1;i <= k;++i) cin >> w[i];
	for (int i = 1;i <= n;++i) cin >> c[i] >> d[i];
	dfs(1);
	cout << ans % 1000000007 << endl;
	//cerr << "Time used: " << clock() - start_time << endl;
	return 0;
}

