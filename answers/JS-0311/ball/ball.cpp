#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;
int n, m, ans;
int a[57][57], b[57][57], cnt[57], f[57], r[57];
bool check()
{
	int cnt = 0;
	for (int i = 1; i <= n; i++)
		if (f[i] != m) ++cnt;
	if (cnt > 1) return 1;
	return 0;
}
int main()
{
	freopen ("ball2.in", "r", stdin);
	freopen ("ball.out", "w", stdout);
	scanf ("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
	{
		cnt[i] = m;
		for (int j = 1; j <= m; j++)
			scanf ("%d", &a[i][j]), b[i][j] = a[i][j];
	}
	while (check())
	{
		for (int i = 1; i <= n; i++)
		if (a[i][cnt[i]] != i && f[i] != m) r[a[i][cnt[i]]]++;
		int mx = 0, id = 1;
		for (int i = 1; i <= n; i++) if (r[i] > mx) mx = r[i], id = i;
		if (mx == 0)
		{
			ans += 3;
			int p = 0, q = 0;
			for (int i = 1; i <= n; i++)
			{
				if (p) {q = i; break;}
				else p = i;
			}
			mx = 1, id = p;
			swap (a[p][m], a[q][m]);
		}
		for (int i = f[id] + 1; i <= cnt[id]; i++)
			cnt[n + 1]++, a[n + 1][cnt[n + 1]] = a[id][cnt[id] - i + 1], ans++;
		cnt[id] = f[id];
		for (int i = 1; i <= n + 1; i++)
			if (i != id) while (a[i][cnt[i]] == id)
				cnt[i]--, cnt[id]++, f[id]++, a[id][cnt[id]] = id, ans++;
		for (int i = 1; i <= n; i++)
			while (cnt[i] < m)
				cnt[i]++, cnt[n + 1]--, a[i][cnt[i]] = a[n + 1][cnt[n + 1] + 1], ans++;
	}
	for (int i = 1; i <= n; i++) f[i] = 0, cnt[i] = m;
	for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) a[i][j] = b[i][j]; 
	cout << ans << endl;
	while (check())
	{
		for (int i = 1; i <= n; i++) r[i] = 0;
		for (int i = 1; i <= n; i++)
		if (a[i][cnt[i]] != i && f[i] != m) r[a[i][cnt[i]]]++;
		int mx = 0, id = 1;
		for (int i = 1; i <= n; i++)
			if (r[i] > mx) mx = r[i], id = i;
		if (mx == 0)
		{
			int p = 0, q = 0;
			for (int i = 1; i <= n; i++)
				if (p) {q = i; break;}
				else p = i;
			printf ("%d %d\n%d %d\n%d %d\n", p, n + 1, q, p, n + 1, q);
			mx = 1, id = p;
			swap (a[p][m], a[q][m]);
		}
		for (int i = f[id] + 1; i <= cnt[id]; i++)
			printf ("%d %d\n", id, n + 1), cnt[n + 1]++, a[n + 1][cnt[n + 1]] = a[id][cnt[id] - i + 1];
		cnt[id] = f[id];
		for (int i = 1; i <= n + 1; i++)
		{
			if (i != id) while (a[i][cnt[i]] == id)
			{
				cnt[i]--, cnt[id]++, f[id]++;
				a[id][cnt[id]] = id;
				printf ("%d %d\n", i, id);
			}
		}
		for (int i = 1; i <= n; i++)
		{
			while (cnt[i] < m)
			{
				cnt[i]++, cnt[n + 1]--;
				a[i][cnt[i]] = a[n + 1][cnt[n + 1] + 1];
				printf ("%d %d\n", n + 1, i);
			}
		}
//		for (int i = 1; i <= n; i++)
//		{
//			for (int j = 1; j <= m; j++) cout << a[i][j] << " ";
//			cout << endl;
//		}
//		for (int i = 1; i <= n + 1; i++) cout << cnt[i] << " ";
//		cout << endl;
//		for (int i = 1; i <= n + 1; i++) cout << f[i] << " ";
//		cout << endl;
//		system ("pause");
	}
}
