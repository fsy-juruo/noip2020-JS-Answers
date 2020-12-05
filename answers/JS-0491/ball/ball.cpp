#include <bits/stdc++.h>
using namespace std;
#define maxn 1000
typedef unsigned long long ull;
typedef long long ll;
#define rep(i, a, b) for(int (i) = (a); (i) <= (b); i++)

int read() {
	char ch = getchar();
	int s = 1, w = 0;
	while(ch < '0' || ch > '9') {if(ch == '-') s = -1; ch = getchar();}
	while(ch >= '0' && ch <= '9') {w = w * 10 + ch - '0'; ch = getchar();}
	return s * w;
}

struct method{
	int from, to;
}step[820005];
int n, m, cntstep;
int col[maxn][maxn], colcnt[maxn];
bool yes = false;

bool check() {
	rep(i, 1, n + 1) {
		rep(j, 1, m - 1) {
			if(col[i][j] != col[i][j + 1]) return false;
		}
	}
	return true;
}

void dfs() {
	if(cntstep > 820) return;
	if(check()) {
		yes = true;
		cout << cntstep << endl;
		rep(i, 1, cntstep) {
			cout << step[i].from << " " << step[i].to << endl;
		}
		return;
	}
	rep(i, 1, n + 1) {
		if(colcnt[i] == 0) continue;
		rep(j, 1, n + 1) {
			if(step[cntstep].from == j && step[cntstep].to == i) continue;
			if(j == i || colcnt[j] == m) continue;
			colcnt[j]++;
			col[j][colcnt[j]] = col[i][colcnt[i]];
			col[i][colcnt[i]] = 0;
			colcnt[i]--;
			cntstep++;
			//cout << i << "->" << j << endl;
			step[cntstep] = method{i, j};
			dfs();
			if(yes) return;
			cntstep--;
			colcnt[i]++;
			col[i][colcnt[i]] = col[j][colcnt[j]];
			col[j][colcnt[j]] = 0;
			colcnt[j]--;
		}
	}
}

int main() {
	freopen("ball.in", "r", stdin);
	freopen("ball.out", "w", stdout);
	n = read(), m = read();
	rep(i, 1, n) {
		rep(j, 1, m) {
			col[i][j] = read();
		}
		colcnt[i] = m;
	}
	dfs();
	return 0;
}
