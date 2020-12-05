#include <stdio.h>
#include <iostream>
using namespace std;

const int MAXN = 55, MAXM = 405, MAXK = 820000;
int n, m, balls[MAXN][MAXM], top[MAXN], k, ans[MAXK][2];
bool ok = false;

bool Check() {
	for (int i = 0; i < n; i++) {
		for (int j = 1; j < m; j++) {
			if (balls[i][j] != balls[i][j - 1]) return false;
		}
	}
	return true;
}

void DFS(int x, int from, int to) {
	if (ok) return;
	if (x > MAXK) return;
	if (Check()) {
		printf("%d\n", k - 1);//cout << k << endl;
		for (int i = 0; i < x; i++) {
			printf("%d %d\n", ans[i][0] + 1, ans[i][1] + 1);//cout << ans[i][0] << ' ' << ans[i][1];
		}
		ok = true;
		return;
	}
	for (int i = 0; i < n + 1; i++) {
		for (int j = 0; j < n + 1; j++) {
			if (i != j && i != to && j != from && top[i] > 0 && top[j] <= m - 1) {
				swap(balls[i][top[i] - 1], balls[j][top[j]]);
				top[i]--; top[j]++;
				ans[x][0] = i; ans[x][1] = j;
				k++;
				DFS(x + 1, i, j);
				k--;
				swap(balls[i][top[i]], balls[j][top[j] - 1]);
				top[i]++; top[j]--;
			}
		}
	}
}

int main() {
	freopen("ball.in", "r", stdin);
	freopen("ball.out", "w", stdout);
	
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d %d", &balls[i][j]);
		}
		top[i] = m;
	}
	
	DFS(0, -1, -1);
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
