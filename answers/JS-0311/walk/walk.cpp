#include <iostream>
#include <cstdio>
using namespace std;
int n, k, ans;
int w[100], a[100], b[100], c[1000007], d[1000007];
bool in()
{
	for (int i = 1; i <= k; i++) if (b[i] <= 0 || b[i] > w[i]) return 0;
	return 1;
}
void dfs (int step)
{
	if (step == k)
	{
		for (int i = 1; i <= n; i++) b[i] = a[i];
		int i = 1;
		while (in())
		{
			b[c[i]] = b[c[i]] + d[i];
			i = (i % n) + 1;
			ans++;
		}
	}
	for (int i = 1; i <= w[step + 1]; i++)
	{
		a[step + 1] = i;
		dfs (step + 1);
	}
}
int main()
{
	freopen ("walk.in", "r", stdin);
	freopen ("walk.out", "w", stdout);
	cin >> n >> k;
	for (int i = 1; i <= k; i++) cin >> w[i];
	for (int i = 1; i <= n; i++) cin >> c[i] >> d[i];
	dfs (0);
	cout << ans;
}
