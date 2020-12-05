#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int maxn = 5e5, maxk = 10, mod = 1e9 + 7;

int n, k, w[maxk + 1], c[maxn + 1], d[maxn + 1], mx[maxk + 1], mn[maxk + 1], fn[maxk + 1];
vector<int> pos(maxk + 1), tmppos(maxk + 1);
map<vector<int>, ll> mp;
ll ans;

void move()
{
	for (int i = 1; i <= k; i++)
		pos[i] += fn[i];
}
void move(int x)
{
	pos[c[x]] += d[x];
}
bool legal()
{
	for (int i = 1; i <= k; i++)
	{
		if ((pos[i] > w[i]) || (pos[i] < 1))
			return false;
	}
	return true;
}
ll work()
{
	if (mp.count(pos))
		return mp[pos];
	
	ll ret = 0;
	bool flag = true;
	for (int i = 1; i <= k; i++)
	{	
		if ((pos[i] + mx[i] > w[i]) || (pos[i] + mn[i] < 1))
		{
			flag = false;
			break;
		}
	}
	
	if (flag)
	{
		move();
		ret = (ret + n) % mod;
		ret += work();
	} 
	else
	{
		for (int i = 1; i <= n; i++)
		{
			ret = (ret + 1) % mod;
			move(i);
			if (!legal())
				break;
		}
	}
	
	return mp[pos] = ret;
}
void dfs(int step)
{
	if (step > k)
	{
		for (int i = 1; i <= k; i++)
			pos[i] = tmppos[i];
		ans = (ans + work()) % mod;
		return;
	}
	
	for (int i = 1; i <= w[step]; i++)
	{
		tmppos[step] = i;
		dfs(step + 1);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	freopen("walk.in", "r", stdin);
	freopen("walk.out", "w", stdout);

	cin >> n >> k;
	for (int i = 1; i <= k; i++)
		cin >> w[i];
	for (int i = 1; i <= n; i++)
	{	
		cin >> c[i] >> d[i];
		fn[c[i]] += d[i];
		mx[c[i]] = max(mx[c[i]], fn[c[i]]);
		mn[c[i]] = min(mn[c[i]], fn[c[i]]);
	}
	
	bool flag = true;
	for (int i = 1; i <= k; i++)
	{	
		if ((mx[i] - mn[i] >= w[i]) || fn[i])
			flag = false;
	}
	if (flag)
	{
		cout << -1 << "\n";
		return 0;
	}
	
	dfs(1);
	
	cout << ans << "\n";

	return 0;
}

