#include<bits/stdc++.h>
using namespace std;
map<string, bool> mp;
int z[55][55];
int c[55][55];
stack<int> a[55];
int x[820005], y[820005];
int n, m;
int check() {
	string st = "";
	stack<int> s;
	for(int i = 1; i <= n + 1; i++) {
		s = a[i];
		while(!s.empty()) {
			st += char(s.top());
			s.pop();
		}
	}
	if(mp[st]) return 2;
	mp[st] = 1;
	for(int i = 1; i <= n + 1; i++) {
		s = a[i];
		if(s.size() != 0 || s.size() != m)
			return 0;
		int tt = s.top();
		while(!s.empty()) {
			if(s.top() != tt) {
				return 0;
			}
			s.pop();
		}
	}
	return 1;
}
void dfs(int dep) {
	int nmsl = check();
	if(nmsl == 1) {
		cout << dep << endl;
		for(int i = 1; i <= dep; i++) {
			cout << x[i] << ' ' << y[i] << endl;
		}
		exit(0);
	}
	if(nmsl == 2) return ;
	dep++;
	for(int i = 1; i <= n + 1; i++) {
		for(int j = 1; j <= n + 1; j++) {
			if(i != j && !a[i].empty() && a[j].size() < m) {
				int t = a[i].top();
				a[i].pop();
				a[j].push(t);
				x[dep] = i;
				y[dep] = j;
				dfs(dep);
				a[i].push(t);
				a[j].pop();
			}
		}
	}
	return ;
}
int main() {
	freopen("ball.in", "r", stdin);
	freopen("ball.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) {
			int xx;
			cin >> xx;
			a[i].push(xx);
		}
	}
	dfs(0);
	return 0;
}

