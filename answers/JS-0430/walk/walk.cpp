#include <bits/stdc++.h>
const int INF = 1e9 + 7;
const int N = 15;

int n, k;
int w[N];
int c[N], d[N];
int pos[N];
int cnt;

bool inside() {
	for (int i = 1; i <= k; i += 1) {
		if (pos[i] < 1 || pos[i] > w[i]) {
			return false;
		}
	}
	return true;
}

bool dfs(int at) {
	if (at > k) {
		for (int ii = 1; ii <= 1000; ii += 1) {
			for (int i = 1; i <= n; i += 1) {
				pos[c[i]] += d[i];
				cnt += std::abs(d[i]);
				if (!inside()) {
					return true;
				}
			}
		}
		return false;
	}
	for (int i = 1; i <= w[at]; i += 1) {
		pos[at] = i;
		if (!dfs(at + 1)) {
			return false;
		}
	}
	return true;
};

int main() {
	freopen("walk.in", "r", stdin);
	freopen("walk.out", "w", stdout);
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	std::cout.tie(0);
	
	cnt = 0;
	
	std::cin >> n >> k;
	if (n > 5) {
		std::cout << -1 << std::endl;
		return 0;
	}
	
	for (int i = 1; i <= k; i += 1) {
		std::cin >> w[i];
	}
	for (int i = 1; i <= n; i += 1) {
		std::cin >> c[i] >> d[i];
	}
	
	if (!dfs(1)) {
		std::cout << -1 << std::endl;
	} else {
		std::cout << cnt << std::endl;
	}
	return 0;
}

