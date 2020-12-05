#include <bits/stdc++.h>
using namespace std;

const int MAXN = 5e5 + 5;
const int INF = 1e7;

int n, k;
int w[8];
int c[MAXN], d[MAXN];
//int f[8][MAXN];
//int st[8];
//int rg_min[8], rg_max[8];

int calc(vector<int> p0) {
	vector<int> p = p0;
	int cur = 0;
	for (int i = 1; i <= n; ++i) {
		p[c[i]] += d[i];
		if (p[c[i]] < 1 || p[c[i]] > w[c[i]]) return cur + 1;
		cur++;
	}
	bool flag = 0;
	for (int i = 0; i < k; ++i) {
		if (p0[i] != p[i]) {
			flag = 1;
			break;
		}
	}
	if (flag == 0) {
		puts("-1");
		exit(0);
	}
//	for (int i = 0; i < k; ++i) {
//		cout << p0[i] << ' ';
//	}
//	cout << endl;
//	for (int i = 0; i < k; ++i) {
//		cout << p0[i] << ' ';
//	}
//	system("pause");
	return n + calc(p);
}


int main() {
freopen("walk.in", "r", stdin);
freopen("walk.out", "w", stdout);
	scanf("%d%d", &n, &k);
	for (int i = 0; i < k; ++i) {
		scanf("%d", &w[i]);
	}
//	for (int i = 1; i <= k; ++i) {
//		st[i] = w[i];
//	}
//	for (int i = 1; i <= k; ++i) {
//		for (int j = 0; j <= w[i] * 2; ++j)
//			f[i][j] = INF;
//		f[i][w[i]] = 0;
//		rg_min[i] = rg_max[i] = w[i];
//	}
	for (int i = 1; i <= n; ++i) {
		scanf("%d%d", &c[i], &d[i]);
		c[i]--;
//		scanf("%d%d", &c, &d);
//		st[c] += d;
//		if (st[c] < 0 || st[c] > w[c] * 2) continue;
//		if (f[c][st[c]] != INF) f[c][st[c]] = i;
	}
	int ans = 0;
	if (k == 1) {
		for (int i0 = 1; i0 <= w[0]; ++i0) {
			vector<int> x;
			x.push_back(i0);
			ans += calc(x);
		}
	} else if (k == 2) {
		for (int i0 = 1; i0 <= w[0]; ++i0) {
			for (int i1 = 1; i1 <= w[1]; ++i1) {
				vector<int> x;
				x.push_back(i0);
				x.push_back(i1);
				ans += calc(x);
			}
		}
	} else if (k == 3) {
		for (int i0 = 1; i0 <= w[0]; ++i0) {
			for (int i1 = 1; i1 <= w[1]; ++i1) {
				for (int i2 = 1; i2 <= w[2]; ++i2) {
					vector<int> x;
					x.push_back(i0);
					x.push_back(i1);
					x.push_back(i2);
					ans += calc(x);
				}
			}
		}
	} else if (k == 4) {
		for (int i0 = 1; i0 <= w[0]; ++i0) {
			for (int i1 = 1; i1 <= w[1]; ++i1) {
				for (int i2 = 1; i2 <= w[2]; ++i2) {
					for (int i3 = 1; i3 <= w[3]; ++i3) {
						vector<int> x;
						x.push_back(i0);
						x.push_back(i1);
						x.push_back(i2);
						x.push_back(i3);
						ans += calc(x);
					}
				}
			}
		}
	} else if (k == 5) {
		for (int i0 = 1; i0 <= w[0]; ++i0) {
			for (int i1 = 1; i1 <= w[1]; ++i1) {
				for (int i2 = 1; i2 <= w[2]; ++i2) {
					for (int i3 = 1; i3 <= w[3]; ++i3) {
						for (int i4 = 1; i4 <= w[4]; ++i4) {
							vector<int> x;
							x.push_back(i0);
							x.push_back(i1);
							x.push_back(i2);
							x.push_back(i3);
							x.push_back(i4);
							ans += calc(x);
						}
					}
				}
			}
		}
	}
	printf("%d", ans);
	return 0;
}

