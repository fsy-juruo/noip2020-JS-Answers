#include <bits/stdc++.h>
using namespace std;
int n, m, a[55][405];
set<pair<int, int> > buck[55];
vector<pair<int, int> > ans;
inline void Swap(pair<int, int> P1, pair<int, int> P2) {
	if (P1.second < P2.second) swap(P1, P2);
	for (int i = 0; i < m - P2.second + 1; i++) ans.push_back(make_pair(P2.first, n + 1));
	for (int i = 0; i < m - P1.second + 1; i++) ans.push_back(make_pair(P1.first, P2.first));
	ans.push_back(make_pair(n + 1, P1.first));
	ans.push_back(make_pair(P2.first, n + 1));
	for (int i = 0; i < m - P1.second; i++) ans.push_back(make_pair(P2.first, P1.first));
	for (int i = 0; i < m - P2.second + 1; i++) ans.push_back(make_pair(n + 1, P2.first));
}
int main() {
	freopen("ball.in", "r", stdin);
	freopen("ball.out", "w", stdout);
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf("%d", &a[i][j]);
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (a[i][j] != i) {
				buck[a[i][j]].insert(make_pair(i, j));
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) if (a[i][j] != i) {
			set<pair<int, int> >::iterator it = buck[i].lower_bound(make_pair(a[i][j], 0));
			if (it == buck[i].end()) it = buck[i].begin();
			pair<int, int> P1 = *it; buck[i].erase(it);
			pair<int, int> P2 = make_pair(i, j); buck[a[i][j]].erase(make_pair(i, j));
			if (P1.first != a[i][j]) buck[a[i][j]].insert(P1);
			Swap(P1, P2);
			swap(a[P1.first][P1.second], a[P2.first][P2.second]);
		}
	}
	printf("%d\n", (int)ans.size());
	for (int i = 0; i < (int)ans.size(); i++) {
		printf("%d %d\n", ans[i].first, ans[i].second);
	}
	return 0;
}
