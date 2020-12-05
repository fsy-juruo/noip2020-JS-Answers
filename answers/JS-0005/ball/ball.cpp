#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;

inline ll in() {
	ll x = 0; bool f = 0; char c = getchar();
	while (!isdigit(c)) {
		f |= (c == '-');
		c = getchar();
	} while (isdigit(c)) {
		x = (x << 3) + (x << 1) + (c ^ 48);
		c = getchar();
	}
	return f ? -x : x;
}

const int N = 1005, M = 820010;
int f[N][N], d[N], cnt[N][N], sc;
PII srt[N], step[M];

inline void upd(int x, int y) {
	f[y][++d[y]] = f[x][d[x]--];
	step[++sc] = {x, y};
}

int main() {
	freopen("ball.in", "r", stdin);
	freopen("ball.out", "w", stdout);
	
	int n = in(), m = in();
	for (int i = 1; i <= n; i++) {
		d[i] = m;
		for (int j = 1; j <= m; j++)  
			f[i][j] = in();
	}
	for (int ball_idx = n; ball_idx > 1; ball_idx--) { // ball_idx is The Index of the ball
		int cnt[N]; for (int i = 1; i <= n; i++) cnt[i] = 0;
		for (int z = n; z; z--) {
			int la = z - 1;
			if (!la) la = n;
			for (int p = d[z]; p; p--)
				if (f[z][p] == ball_idx) cnt[z]++;
			for (int i = 1; i <= cnt[z]; i++)
				upd(la, n + 1);
			for (int p = m; p; p--) {
				if (f[z][p] == ball_idx) upd(z, la);
				else upd(z, n + 1);
			}
			for (int i = 1; i <= m; i++)
				upd(n + 1, z);
			for (int i = 1; i <= cnt[z]; i++)
				upd(la, n + 1);
			for (int i = 1; i <= cnt[z]; i++)
				upd(z, la);
		}
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= cnt[i]; j++)
				upd(ball_idx, i);
		for (int i = 1; i <= m; i++) 
			upd(n + 1, ball_idx);
	}
	printf("%d\n", sc);
	for (int i = 1; i <= sc; i++)
		printf("%d %d\n", step[i].first, step[i].second);
	

	return 0;
}


