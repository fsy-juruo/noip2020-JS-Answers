#include <bits/stdc++.h>
using namespace std;

#define SZ(a) ((int)((a).size()))
#define fi first
#define se second
#define mk make_pair

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef pair<int, int> pii;

int Rand(int l, int r) {
	return rand() % (r - l + 1) + l;
}
int n, m;
vector<int> a[55];
vector<pii> ans;
pii getpos() {
	int x = Rand(1, n + 1);
	int y = Rand(1, n + 1);
	while (x == y || SZ(a[x]) == 0 || SZ(a[y]) == m) {
		x = Rand(1, n + 1);
		y = Rand(1, n + 1);
	}
	return mk(x, y);
}
bool check() {
	for (int i = 1; i <= n + 1; ++i) {
		if (SZ(a[i]) != 0 && SZ(a[i]) != m) {
			return false;
		}
		if (!SZ(a[i]))
			continue;
		for (int j = 1; j < m; ++j) {
			if (a[i][j] != a[i][0]) {
				return false;
			}
		}
	}
	return true;
}
int main() {
	freopen("ball.in", "r", stdin);
	freopen("ball.out", "w", stdout);
	
	srand((ull)time(0) ^ (ull)(new char));
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		a[i].resize(m);
		for (int j = 0; j < m; ++j) {
			cin >> a[i][j];
		}
	}
	
	while (!check()) {
		pii t = getpos();
		int x = t.fi;
		int y = t.se;
		a[y].push_back(a[x].back());
		a[x].pop_back();
		ans.push_back(t);
	}
	cout << SZ(ans) << endl;
	for (int i = 0; i < SZ(ans); ++i) {
		cout << ans[i].fi << " " << ans[i].se << endl;
	}
	return 0;
}
