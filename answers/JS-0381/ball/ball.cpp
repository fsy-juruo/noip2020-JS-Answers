// give up
#include <bits/stdc++.h>
using namespace std;
/*things you should actually check:
0. memory limit                     // < 1M
1. overflow                         // 400
2. special cases                    // no
3. do smth. better than noth.       //
4. stay organized                   //
5. complete freopen                 // completed
6. simple is better than ugly       //
7. flat is better than nested       //
8. sparse is better than dense      //
9. readablity counts                //
*/
int n, m, a[55][405], cnt[55]; // ~ 10K
int completed[55], total = 0;
vector<pair<int, int> > ans; // < 0.9M
void move(int src, int dst)
{
	ans.push_back(make_pair(src, dst));
	if (completed[dst] == cnt[dst] && a[src][cnt[src] - 1] == dst)
	{
		completed[dst]++;
		total++;
	}
	a[dst][cnt[dst]++] = a[src][--cnt[src]];
}
#define list_checked
#ifdef list_checked
int main()
{
#ifndef LOCAL
	freopen("ball.in", "r", stdin);
	freopen("ball.out", "w", stdout);
#endif
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j < m; j++) scanf("%d", &a[i][j]);
		cnt[i] = m;
	}
	for (int i = 1; i <= n; i++)
	{
		while (a[i][completed[i]] == i) completed[i]++;
		total += completed[i];
	}
	while (total < n * m)
	{
		int tmp[55];
		for (int i = 1; i <= n; i++) tmp[a[i][cnt[i] - 1]]++;
		int target = 1;
		for (int i = 2; i <= n; i++) if (tmp[i] > tmp[target]) target = i;
		while (cnt[target] > completed[target]) move(target, n + 1);
		for (int i = 1; i <= n; i++) if (i != target) while (a[i][cnt[i] - 1] == target) move(i, target);
		for (int i = 1; i <= n; i++) while (cnt[i] < m) move(n + 1, i);
	}
//	printf("%d\n", (int)(ans.size()));
	for (int i = 0; i < ans.size(); i++) printf("%d %d\n", ans[i].first, ans[i].second);
	return 0;
}
#endif

/*sample:
2 3
1 1 2
2 1 2
*/
