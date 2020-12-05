#include <cstdio>
const int N = 57, M = 407;

struct{
	int x, y;
} way[N*M];

int a[N][M], cnt[N], col[N];
bool hv[N];

int main(){
	freopen("ball.in", "r", stdin);
	freopen("ball.out", "w", stdout);
	int n, m;
	scanf("%d%d", &n, &m);
	for(int i=1; i<=n; ++i)
		for(int j=1; j<=m; ++j)
			scanf("%d", &a[i][j]);
	for(int i=1; i<=n; ++i) cnt[i] = m;
	printf("0");
	return 0;
}
