#include<bits/stdc++.h>

#define LL long long
#define ull unsigned long long
#define F(i,j,k) for(int i = j; i <= k; ++i)
#define DF(i,j,k) for(int i = j; i >= k; --i)
#define mp make_pair

using namespace std;

template <typename T> inline void read(T &n) {
	T w = 1;
	n = 0;
	char ch = getchar();
	while (!isdigit(ch) && ch != EOF) {
		if(ch == '-') w = -1;
		ch = getchar();
	}
	while (isdigit(ch) && ch != EOF) {
		n = (n << 3) + (n << 1) + (ch & 15);
		ch = getchar();
	}
	n *= w;
}

template <typename T> inline void write(T x) {
	T l = 0;
	ull y = 0;
	if (x < 0) {
		putchar('-');
		x = -x;
	}
	if (!x) {
		putchar(48);
		return;
	}
	while(x) {
		y = y * 10 + x % 10;
		x /= 10;
		++l;
	}
	while(l) {
		putchar(y % 10 + 48);
		y /= 10;
		--l;
	}
}

template <typename T> inline void writes(T x) {
	write(x);
	putchar(' ');
}

template <typename T> inline void writeln(T x) {
	write(x);
	puts("");
}

template <typename T> inline void checkmax(T &a,T b) { a = a > b ? a : b; }

template <typename T> inline void checkmin(T &a,T b) { a = a < b ? a : b; }

const int N = 410, INF = 2e9;

int a[N][N], s[N], no[N], us[N], sum[N], pos[N], num;

vector <pair<int, int> > ans;

int main() {
	freopen("ball.in", "r", stdin);
	freopen("ball.out", "w", stdout);
	int n, m;
	read(n);
	read(m);
	F(i, 1, n)
		DF(j, m, 1)
			read(a[i][j]);
	F(i, 1, n - 1) {
		F(j, 1, n) s[j] = 0;
		F(j, i + 1, n) {
			F(k, 1, n) no[k] = 0;
			F(k, 1, m) no[a[j][k]] = k;
			F(k, 1, n) s[k] += no[k];
		}
		int mi = INF, mii;
		F(j, 1, n) {
			if (us[j]) continue;
			if (s[j] < mi) {
				mi = s[j];
				mii = j;
			}
		}
		us[mii] = 1;
		F(j, 1, n) sum[j] = 0;
		F(j, i + 1, n) {
			F(k, 1, m) if (a[j][k] == mii) ++sum[j];
			if (!sum[j]) continue;
			F(k, 1, sum[j]) {
				++num;
				ans.push_back(mp(j - 1, n + 1));
			}
			int now = 0;
			F(k, 1, m) {
				++num;
				if (a[j][k] == mii) { ++now; ans.push_back(mp(j, j - 1)); }
				else ans.push_back(mp(j, n + 1));
				if (now == sum[j]) {
					F(l, 1, k - sum[j]) {
						++num;
						ans.push_back(mp(n + 1, j));
					}
					F(l, 1, sum[j]) {
						++num;
						ans.push_back(mp(j - 1, j));
					}
					F(l, 1, sum[j]) {
						++num;
						ans.push_back(mp(n + 1, j - 1));
					}
					break;
				}
			}
			now = m;
			DF(k, m, 1) {
				while (a[j][now] == mii && now >= 1) --now;
				if (now < 1) break;
				a[j][k] = a[j][now];
				if (now > 0) --now;
			}
			DF(k, sum[j], 1) a[j][k] = mii;
			pos[j] = sum[j];
		}
		F(j, 1, m) {
			++num;
			ans.push_back(mp(i, n + 1));
			a[n + 1][m - j + 1] = a[i][j];
		}
		F(j, i + 1, n)
			F(k, 1, sum[j]) {
				++num;
				ans.push_back(mp(j, i));
			}
		int nowj = i + 1;
		F(j, 1, m) {
			++num;
			if (a[n + 1][j] == mii) ans.push_back(mp(n + 1, i));
			else {
				while (pos[nowj] == 0) ++nowj;
				a[nowj][pos[nowj]] = a[n + 1][j];
				--pos[nowj];
				ans.push_back(mp(n + 1, nowj));
			}
			a[i][j] = mii;
		}
	}
	writeln(num);
	F(i, 1, num) {
		writes(ans[i - 1].first);
		writeln(ans[i - 1].second);
	}
	return 0;
}

