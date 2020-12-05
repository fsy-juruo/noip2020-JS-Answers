#include <iostream>
#include <deque>
#include <cstdlib>
#include <cstdio>
#include <map>

using namespace std;

int n, m;

deque<pair<int, int> > path;
int state[402][402];
int top[402];

bool check() {
	for (int i = 1; i <= (n + 1); ++ i) {
		if (top[i] == 0) continue;
		if (top[i] != m) return false;
		int color = state[i][1];
		for (int j = 1; j <= m; ++ j) {
			if (state[i][j] != color) {
				return false;
			}
		}
	}
	return true;
}

void dfs(int from, int to, int depth) {
	if (top[from] < 1 || top[to] > m || from == to) {
		return;
	}
	if (top[from] < top[to]) return;
	pair<int, int> prev = path.back();
	if (prev.first == to && prev.second == from) return;
	path.push_back(make_pair(from, to));
	top[to] ++;
	state[to][top[to]] = state[from][top[from]];
	top[from] --;
	if (check()) {
		cout << depth << endl;
		while (!path.empty()) {
			pair<int, int> item = path.front();
			path.pop_front();
			cout << item.first << " " << item.second << endl;
		}
		exit(0);
	}
	for (int i = 1; i <= (n + 1); ++ i) {
		for (int j = 1; j <= (n + 1); ++ j) {
			dfs(i, j, depth + 1);
		}
	}
	path.pop_back();
}

int main() {
	
	freopen("ball.in", "r", stdin);
	freopen("ball.out", "w", stdout);
	
	cin >> n >> m;
	
	for (int i = 1; i <= n; ++ i) {
		for (int j = 1; j <= m; ++ j) {
			cin >> state[i][j];
		}
		top[i] = m;
	}
	
	top[n + 1] = 0;
	
	for (int i = 1; i <= n; ++ i) {
		dfs(i, n + 1, 1);
	}
	
	return 0;
	
}
