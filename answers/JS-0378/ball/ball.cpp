#include <bits/stdc++.h>
using namespace std;

int lim = 0;
vector<int> z[55];
int n, m;

bool check() {
	int cnt = 0;
	for (int i = 1; i <= n + 1; ++i) {
		if ((int)z[i].size() != m) continue;
		int c0 = z[i][0];
		bool flag = 1;
		for (int j = 1; j < m; ++j) {
			if (z[i][j] != c0) {
				flag = 0;
				break;
			}
		}
		if (flag) cnt++;
	}
	return cnt == n;
}

bool checkkk(int p) {
	if ((int)z[p].size() != m) return 0;
	int c0 = z[p][0];
	for (int j = 1; j < m; ++j) {
		if (z[p][j] != c0) return 0;
	}
	return 1;
}

pair<int, int> s[830000];
int cnt = 0;

void dfs(int cur) {
//	cout << cur << endl;
	if (cur > lim) {
		if (check()) {
			cout << lim << endl;
			for (int i = 1; i <= lim; ++i) {
				cout << s[i].first << ' ' << s[i].second << endl;
			}
			exit(0);
		}
		return;
	}
	for (int i = 1; i <= n + 1; ++i) {
		for (int j = 1; j <= n + 1; ++j) {
			if (i == j) continue;
			if (j == s[cnt - 1].first && i == s[cnt - 1].second) continue;
			if ((int)z[i].size() == 0 || (int)z[j].size() == m) continue;
			vector<int>::iterator it = z[i].end();
			it--;
			int tmp = *it;
			if (z[j].size()) {
				it = z[j].end();
				it--;
				int tmp2 = *it;
				if (tmp != tmp2) continue;
			} 
			if (checkkk(i)) continue;
			z[i].pop_back();
			z[j].push_back(tmp);
			s[++cnt] = make_pair(i, j);
			dfs(cur + 1);
			z[j].pop_back();
			z[i].push_back(tmp);
			cnt--;
		}
	}
}

int main() {
//	freopen("ball2.in", "r", stdin);
freopen("ball.in", "r", stdin);
freopen("ball.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			int x;
			cin >> x;
			z[i].push_back(x);
		}
	}
	if (check()) {
		puts("0");
		return 0;
	}
	for (lim = 1; lim <= 820000; ++lim) {
	//	cout << lim << endl;
		dfs(1);
	}

	return 0;
}

