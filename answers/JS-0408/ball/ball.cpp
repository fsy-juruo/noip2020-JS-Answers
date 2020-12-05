#include <bits/stdc++.h>
using namespace std;

int n, m;
int a[55][555], sz[555];

vector<pair<int, int> > ans;

void Swap(int i1, int j1, int i2, int j2) {
	int bsz2 = sz[i2];
	if (j1 >= j2) {
		for (int i = 1; i <= m - j2 + 1; ++i)
			ans.push_back(make_pair(i2, n + 1)), --sz[i2], a[n+1][++sz[n + 1]]=a[i2][sz[i2]+1];
		for (int i = 1; i <= m - j1 + 1; ++i)
			ans.push_back(make_pair(i1, i2)), --sz[i1], a[i2][++sz[i2]]=a[i1][sz[i1]+1];
		for (int i = 1; i <= m - sz[i1]; ++i)
			ans.push_back(make_pair(n + 1, i1)), --sz[n+1], a[i1][++sz[i1]]=a[n+1][sz[n+1]+1];
		for (int i = 1; i <= sz[n+1]; ++i)
			ans.push_back(make_pair(n + 1, i2)), --sz[n+1], a[i2][++sz[i2]]=a[n+1][sz[n+1]+1];
	} else {
		for (int i = 1; i <= m - j1 + 1; ++i)
			ans.push_back(make_pair(i1, n + 1)), --sz[i1], a[n+1][++sz[n + 1]]=a[i1][sz[i1]+1];
		for (int i = 1; i <= m - j2 + 1; ++i)
			ans.push_back(make_pair(i2, i1)), --sz[i2], a[i1][++sz[i1]]=a[i2][sz[i2]+1];
		for (int i = 1; i < min(sz[n+1]+1, m-sz[i2]); ++i)
			ans.push_back(make_pair(n + 1, i2)), --sz[n+1], a[i2][++sz[i2]]=a[n+1][sz[n+1]+1];
		ans.push_back(make_pair(i1, i2)), --sz[i1], a[i2][++sz[i2]]=a[i1][sz[i1]+1];
		for (int i = 1; i <= m-j2; ++i)
			ans.push_back(make_pair(i1, n+1)), --sz[i1], a[n+1][++sz[n+1]]=a[i1][sz[i1]+1];
		ans.push_back(make_pair(i2, i1)), --sz[i2], a[i1][++sz[i1]]=a[i2][sz[i2]+1];
		for (int i = 1; i <= sz[n+1]; ++i)
			ans.push_back(make_pair(n+1, i1)), --sz[n+1], a[i1][++sz[i1]]=a[n+1][sz[n+1]+1];
	}
//	cerr << ans.size() << '\n';
}

int main() {
	freopen("ball.in", "r", stdin);
	freopen("ball.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		sz[i] = m;
		for (int j = 1; j <= m; ++j)
			cin >> a[i][j];
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) if (a[i][j] != i) {
			for (int k = i + 1; k <= n; ++k) {
				for (int j1 = 1; j1 <= m; ++j1) if (a[k][j1] == i) {
					Swap(i, j, k, j1);
				}
			}
		}
	}
	cout << (int) ans.size() << '\n';
	for (int i = 0; i < (int) ans.size(); ++i)
		cout << ans[i].first << " " << ans[i].second << '\n';
	return 0;
}
