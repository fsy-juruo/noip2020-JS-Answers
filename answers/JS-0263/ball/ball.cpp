#include <bits/stdc++.h>
using namespace std;
template <typename T>
void readin(T &x) {
	x = 0;
	char ch = getchar();
	T fh = 1;
	for (; !isdigit(ch); ch = getchar()) if (ch == '-') fh = -1;
	for (; isdigit(ch); ch = getchar()) x = (x << 1) + (x << 3) + (ch ^ 48);
	x *= fh;
}
template <typename T>
void wt(T x) {
	if (x > 9) wt(x / 10);
	putchar(x % 10 + 48);
}
template <typename T>
void writeln(T x, char ch) {
	if (x < 0) {
		putchar('-');
		x = -x;
	}
	wt(x);
	putchar(ch);
}
const int N = 55;
vector <int> v[N];
int hd[N], n, m, col[N], bel[N];
bool check() {
	for (int i = 1; i <= n; i ++) {
		bool flg = false;
		for (int j = hd[i]; j < m; j ++) {
			if (v[i][j] != bel[i]) {
				flg = true;
				hd[i] = j;
				break;
			}
		}
		if (!flg) hd[i] = m;
		if (hd[i] != m) return false;
	}
	return true;
}
vector <pair <int, int> > ans;
vector <int> rec;
int main() {
	freopen("ball.in", "r", stdin);
	freopen("ball.out", "w", stdout);
	readin(n); readin(m);
	int x;
	for (int i = 1; i <= n; i ++) {
		for (int j = 1; j <= m; j ++) {
			readin(x);
			v[i].push_back(x);
		}
	}
	for (int i = 1; i <= n; i ++) {
		if (!col[v[i][0]]) {
			col[v[i][0]] = i;
			bel[i] = v[i][0];
			for (int j = 0; j < m; j ++) {
				if (v[i][j] != v[i][0]) {
					hd[i] = j;
					break;
				}
			}
			if (!hd[i]) hd[i] = m;
		}
		else {
			rec.push_back(i);	
		}
	}
	for (int i = 1; i <= n; i ++) {
		if (!col[i]) {
			col[i] = rec.back();
			bel[col[i]] = i;
			rec.pop_back();
		}
	}
	int tot = 0;
	while (!check()) {
		int pos = -1;
		for (int i = 1; i <= n; i ++) {
			if (v[i].back() != bel[i]) {
				pos = i;
				break;
			}
		}
		if (pos == -1) {
			int p1 = 0, p2 = 0;
			for (int i = 1; i <= n; i ++) {
				if (v[i].back() != bel[i]) {
					if (!p1) p1 = i;
					else {
						p2 = i;
						break;
					}
				}
			}
			ans.push_back(make_pair(p1, n + 1));
			ans.push_back(make_pair(p2, n + 1));
			ans.push_back(make_pair(n + 1, p1));
			ans.push_back(make_pair(n + 1, p2));
			int tmp = v[p1].back(), tnp = v[p2].back();
			v[p1].pop_back(); v[p2].pop_back();
			v[p1].push_back(tnp); v[p2].push_back(tmp);
			pos = p1;
		}
		int u = v[pos].back();
		for (int i = 1; i <= m - hd[col[u]]; i ++) {
			ans.push_back(make_pair(col[u], n + 1));
			v[n + 1].push_back(v[col[u]].back());
			v[col[u]].pop_back();
		}
		for (int i = 1; i <= n; i ++) {
			if (i == col[u]) continue;
			if (v[i].back() == u) {
				ans.push_back(make_pair(i, col[u]));
				v[i].pop_back();
				v[col[u]].push_back(u);
				hd[col[u]] ++;
			}
		}
		for (int i = 1; i <= n; i ++) {
			while ((int)v[i].size() != m) {
				ans.push_back(make_pair(n + 1, i));
				v[i].push_back(v[n + 1].back());
				v[n + 1].pop_back();
			}
		}
	}
	writeln(ans.size(), '\n');
	for (int i = 0; i < ans.size(); i ++) {
		writeln(ans[i].first, ' ');
		writeln(ans[i].second, '\n');
	}
	return 0;
}

