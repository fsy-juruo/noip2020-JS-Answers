#include<bits/stdc++.h>
#define fox(i,a,b) for(int i=a;i<=b;++i)
using namespace std;

inline int rd() {
	int x = 0, f = 1; char c = getchar();
	for (; !isdigit(c); c = getchar()) if (c == '-') f = 0;
	for (; isdigit(c); c = getchar()) x = x * 10 + c - '0';
	return f ? x : -x;
}

const int N = 60, M = 410, A = 1e6;
int n, m, a[N][M];
int ans, ax[A], ay[A];

inline void move(int x_1, int y_1, int x_2, int y_2) {
	if (ans > A - 10) return;
	ax[++ans] = x_1, ay[ans] = x_2;
	swap(a[x_1][y_1], a[x_2][y_2]);
}

void getit(int x, int y, int p) {
	int g, o;
	fox (i, 1, m) 
		if (a[p][i] != a[p][1]) {
			g = i;
			break;
		}
	fox (i, g, m) move(p, m - i + g, n + 1, i - g + 1);
	int j = m, k = m - g + 1;
	while (j != y && k != m - 1) {
		move(x, j, p, k + 1);
		++k, --j;
	}
	o = g;
	while (j != y) {
		move(x, j, p, o + 1);
		++o, --j;
	}
	move(x, y, n + 1, ++k);
	--j;
	while (o > g) {
		move(p, o, x, j + 1);
		++j, --o;
	}
	move(n + 1, k, p, o + 1);
	++o, --k;
	while (j < m) {
		move(n + 1, k, x, j + 1);
		--k, ++j;
	}
	while (o < m) {
		move(n + 1, k, p, o + 1);
		++o, --k;
	}
}

int main() {
	freopen("ball.in", "r", stdin);
	freopen("ball.out", "w", stdout);
	n = rd(), m = rd();
	fox (i ,1, n) fox (j, 1 , m) a[i][j] = rd();
	fox (i, 1, n - 2) {
		fox (j, i + 1, n) {
			fox (k, 1, m) {
				if (a[j][k] == a[i][1]) {
					getit(j, k, i);
				}
			}
		}
		int p = 0;
		fox (j, 1, m) {
			if (a[i][j] != a[i][1]) {
				p = j;
				break;
			}
		}
		
		fox (j, p, m) move(i, m - j + p, n + 1, j - p + 1);
		fox (j, p, m) move(n, m - j + p, i, j);
		fox (j, p, m) move(n + 1, m - j + 1, n, j);
		fox (j, 1, m) if (a[n][j] == a[i][1]) {
			getit(n, j, i);
		}
	}
	
	int x = n - 1, y = n, g, p;
	fox (i, 1, m) {
		if (a[x][i] != a[x][1]) {
			g = i - 1;
			break;
		}
	}
	fox (i, 1, m) {
		if (a[y][i] == a[x][1]) {
			p = i - 1;
			break;
		}
	}
	//cout << g << endl;
	int i = m, j = m, k = 0;
	
	
	while (g != m) {
		while (i > g) {
			move(x, i, n + 1, ++k);
			--i;
		}
		while (k != m && j > p) {
			if (a[y][j] == a[x][1]) {
				move(y, j, x, i + 1);
				++i, --j, ++g;
			} else {
				move(y, j, n + 1, k + 1);
				++k, --j;
			}
		}
		while (j && a[y][j] == a[x][1]) {
			move(y, j, x, i + 1);
			++i, --j, ++g;
		}
		while (j != m) {
			if (a[n + 1][k] == a[x][1]) {
				move(n + 1, k, x, i + 1);
				++i, --k;
			} else {
				move(n + 1, k, y, j + 1);
				++j, --k;
			}
		}
		while (k && a[n + 1][k] == a[x][1]) {
			move(n + 1, k, x, i + 1);
				++i, --k, ++g;
		}
		while (k) {
			move(n + 1, k, x, i + 1);
				++i, --k;
		}
		
		
		while (j > p) {
			move(y, j, n + 1, ++k);
			--j;
		}
		while (k != m && i > g) {
			if (a[x][i] != a[x][1]) {
				move(x, i, y, j + 1);
				++j, --i, ++p;
			} else {
				move(x, i, n + 1, k + 1);
				++k, --i;
			}
		}
		while (i && a[x][i] != a[x][1]) {
			move(x, i, y, j + 1);
			++j, --i, ++p;
		}
		while (i != m) {
			if (a[n + 1][k] != a[x][1]) {
				move(n + 1, k, y, j + 1);
				++j, --k, ++p;
			} else {
				move(n + 1, k, x, i + 1);
				++i, --k;
			}
		}
		while (k && a[n + 1][k] != a[x][1]) {
			move(n + 1, k, y, j + 1);
				++j, --k, ++p;
		}
		while (k) {
			move(n + 1, k, y, j + 1);
				++j, --k;
		}
		
		
		
		while (j > p) {
			move(y, j, n + 1, ++k);
			--j;
		}
		while (k != m && i > g) {
			if (a[x][i] != a[x][1]) {
				move(x, i, y, j + 1);
				++j, --i, ++p;
			} else {
				move(x, i, n + 1, k + 1);
				++k, --i;
			}
		}
		while (i && a[x][i] != a[x][1]) {
			move(x, i, y, j + 1);
			++j, --i, ++p;
		}
		while (i != m) {
			if (a[n + 1][k] != a[x][1]) {
				move(n + 1, k, y, j + 1);
				++j, --k, ++p;
			} else {
				move(n + 1, k, x, i + 1);
				++i, --k;
			}
		}
		while (k && a[n + 1][k] != a[x][1]) {
			move(n + 1, k, y, j + 1);
				++j, --k, ++p;
		}
		while (k) {
			move(n + 1, k, y, j + 1);
				++j, --k;
		}
		
		while (i > g) {
			move(x, i, n + 1, ++k);
			--i;
		}
		while (k != m && j > p) {
			if (a[y][j] == a[x][1]) {
				move(y, j, x, i + 1);
				++i, --j, ++g;
			} else {
				move(y, j, n + 1, k + 1);
				++k, --j;
			}
		}
		while (j && a[y][j] == a[x][1]) {
			move(y, j, x, i + 1);
			++i, --j, ++g;
		}
		while (j != m) {
			if (a[n + 1][k] == a[x][1]) {
				move(n + 1, k, x, i + 1);
				++i, --k;
			} else {
				move(n + 1, k, y, j + 1);
				++j, --k;
			}
		}
		while (k && a[n + 1][k] == a[x][1]) {
			move(n + 1, k, x, i + 1);
				++i, --k, ++g;
		}
		while (k) {
			move(n + 1, k, x, i + 1);
				++i, --k;
		}
		
	}
	
	printf("%d\n", ans);
	fox (i, 1, ans) {
		printf("%d %d\n", ax[i], ay[i]);
	}
	return 0;
}

