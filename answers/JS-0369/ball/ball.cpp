#include <bits/stdc++.h>

using namespace std;

const int maxn = 110, maxm = 510, SIZE = 1e6 + 10;

struct node {
	int x, y;
	
	node (int x = 0, int y = 0) : x(x), y(y) { }
	
	bool operator < (const node &t) const {
		return y > t.y;
	}
} ans[SIZE], f[maxn][maxm];

int n, m;
int tot, ftot[maxn];
int siz[maxn], cnt[maxn], num[maxn], snum[maxn];
int c[maxn][maxm];

bool cmp(int x, int y){
	return siz[x] > siz[y];
}

bool scmp(int x, int y){
	return cnt[x] < cnt[y];
}

void change(node a, node b){
	ans[++tot] = node(a.x, b.x);
	swap(c[a.x][a.y], c[b.x][b.y]);
}

void work(node a, node b){
	int p = 0;
	sort(num + 1, num + n + 2, cmp);
	for (int i = siz[a.x], k = 1, j; i > a.y; i--){
		j = num[k];
		while (siz[j] == m || j == a.x) j = num[++k];
		if (!p && siz[j] == m - 1 && j != b.x){
			p = j;
			j = num[++k];
		}
		change(node(a.x, i), node(j, ++siz[j]));
	}
	if (!p && a.y != m){
		sort(num + 1, num + n + 2, cmp);
		for (int i = 1; i <= n + 1; i++){
			if (num[i] == a.x || num[i] == b.x || siz[i] == m) continue;
			for (int j = siz[b.x]; j >= b.y; j--){
				if (siz[i] == m - 1) break;
				change(node(b.x, j), node(num[i], ++siz[i]));
			}
			if (siz[num[i]] != m - 1) p = a.x;
			else p = num[i];
		}
		if (!p){
			int i = 1;
			for (; i <= n + 1; i++) if (num[i] != a.x && num[i] != b.x) break;
			change(node(b.x, b.y + 1), node(num[i], siz[i]));
			siz[b.x]++;
			siz[i]--;
			
//			change(node(num[i], siz[i]), a);
//			siz[a.x] = a.y - 1;
			p = i;
		}
	}
	if (p != a.x){
		change(node(a.x, a.y), node(p, ++siz[p]));
		siz[a.x] = a.y - 1;
	}
	sort(num + 1, num + n + 2, cmp);
	for (int i = siz[b.x], k = 1, j; i >= b.y; i--){
		j = num[k];
		while (siz[j] == m || j == b.x) j = num[++k];
		change(node(b.x, i), node(j, ++siz[j]));
	}
	change(node(p, siz[p]), node(b.x, b.y));
	siz[p]--;
	siz[b.x] = b.y;
}

int main(){
	freopen("ball.in", "r", stdin);
	freopen("ball.out", "w", stdout);
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++){
		num[i] = i;
		for (int j = 1; j <= m; j++){
			scanf("%d", &c[i][j]);
			f[c[i][j]][++ftot[c[i][j]]] = node(i, j);
			cnt[c[i][j]] += j;
		}
		siz[i] = m;
	}
	num[n + 1] = n + 1;
	for (int i = 1; i <= n; i++) sort(f[i] + 1, f[i] + m + 1);
	for (int i = 1; i <= n; i++){
		sort(num + 1, num + n + 2);
		int p = num[n + 1], t = 0;
		while (c[p][t + 1] == i) t++;
		while (t < m){
			for (int j = 1; j <= n + 1; j++){
				if (j == p) continue;
				for (int k = siz[j]; k >= 1; k--)
					if (c[j][k] == i){
						work(node(j, k), node(p, ++t));
					}
			}
		}
	}
	printf("%d\n", tot);
	for (int i = 1; i <= tot; i++) printf("%d %d\n", ans[i].x, ans[i].y);
	return 0;
}
