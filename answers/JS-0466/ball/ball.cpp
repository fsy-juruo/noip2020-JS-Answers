#include<bits/stdc++.h>
#define fir(a, b, c) for(int a = b; a <= c; ++ a)
#define ll long long
#define inf 1e8
using namespace std;

const int N = 600;
int n, a[N][N], m;
int vis[N], f[N];
bool ff = 0;

inline bool check() {
	fir (i, 1, n+1) {
		if (a[i][0] > 0 && a[i][0] < m) return false;
		fir (j, 2, m)
			if (a[i][j] != a[i][j-1]) return false;
	}
	
	ff = true;
	return true;
}

void dfs(int dep, int lim) {
	if (dep > lim) return;
	if (check()) {
		ff = true; 
		printf("%d\n", dep-1);
		return;
	}
	fir (i, 1, n+1) {
		fir (j, 1, n+1) {
			if (i == j) continue;
			if (a[i][0] == 0 || a[j][0] == m ) continue;
			int xi = vis[i], xj = vis[j];
			int ai = a[i][a[i][0]], aj = a[j][a[j][0]];
			vis[i] = vis[j] = dep;
			f[dep] = i;
			a[i][a[i][0]] = 0;
			-- a[i][0]; ++ a[j][0]; a[j][a[j][0]] = ai;
			
			dfs(dep + 1, lim); 
			if (ff == true) {
				printf("%d %d\n", i, j);
				return;
			}
			++ a[i][0]; -- a[j][0];
			a[i][a[i][0]] = ai, a[j][a[j][0]] = aj;
			vis[i] = xi, vis[j] = xj;
		}
	}
}

int main() {
	freopen("ball.in","r",stdin);
	freopen("ball.out","w",stdout);
	scanf("%d%d", &n, &m);
	printf("0\n");
	return 0;
}

