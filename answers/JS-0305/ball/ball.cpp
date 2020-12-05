#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN = 70, MAXM = 420;
int n, m, a[MAXN][MAXM], cnt[MAXN][MAXM], top[MAXN], ans;

void solve(int step)
{
    bool flag = true;
    for (int i = 1; i <= n; i++) {
	if (cnt[i][i] == m) continue;
	flag = false;
    }
    if (flag) {
	cout << step << endl;
	return;
    }
    for (int i = 1; i <= n; i++) {
	if (cnt[i][i] == top[i]) continue;
	while (cnt[i][i] != top[i] && top[n + 1] < m) {
	    flag = true;
	    top[n + 1]++;
	    a[n + 1][top[n + 1]] = a[i][top[i]];
	    cnt[i][a[i][top[i]]]--;
	    cnt[n + 1][a[i][top[i]]]++;
	    top[i]--;
	    solve(step + 1);
	    printf("%d %d\n", i, n + 1);
	}
    }
    if (!flag) {
	for (int i = top[n + 1]; i >= 1; i--) {
	    int x = a[n + 1][i];
	    if (top[x] < m) {
		top[x]++;
		a[x][top[x]] = x;
		solve(step + 1);
		printf("%d %d\n", n + 1, x);
	    }
	}
    }
}

int main()
{
    freopen("ball.in", "r", stdin);
    freopen("ball.out", "w", stdout);
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
	top[i] = m;
	for (int j = 1; j <= m; j++) {
	    scanf("%d", &a[i][j]);
	    cnt[i][a[i][j]]++;
	}
    }
    solve(1);

    return 0;
}
