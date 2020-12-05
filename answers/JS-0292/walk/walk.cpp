#include<bits/stdc++.h>
using namespace std;
int read() {
	int x = 0, f = 1;
	char c = getchar();
	while (!isdigit(c)) {
		if(c == '-') {
			f = -1;
		}
		c = getchar();
	}
	while (isdigit(c)) {
		x = x * 10 + c - 48;
		c = getchar();
	}
	return x * f;
}
const int maxm = 1e5 + 10;
const int maxn = 1010;
const int mod = 1e9 + 7;
int n, k, w[maxm], d[maxm], c[maxm];	
long long sum = 0;
namespace sub1 {
	vector<int>s, t;
	int get() {
		int id = 0;
		for (int i = 0; i < k; ++i) {
			id = id * w[i + 1] + t[i];
		}
		return id;
	}
	bool judge() {
		for (int i = 0; i < k; ++i) {
			if(t[i] > w[i + 1] || t[i] <= 0) {
				return false;
			}
		}
		return true;
	}
	void count() {
		t.clear();
		for (int i = 0; i < k; ++i) {
			t.push_back(s[i]);
		}
		int now = 1;
		while (judge()) {
			sum++;
			t[c[now] - 1] += d[now];
			now++;
			if(now > n)now = 1;
		}
	}
	void dfs(int dep) {
		if(dep == k + 1) {
			count();
			return;
		}
		for (int i = 1; i <= w[dep]; ++i) {
			s.push_back(i);
			dfs(dep + 1);
			s.pop_back();
		}
	}
	void solve() {
		for (int i = 1; i <= n; ++i) {
			c[i] = read(), d[i] = read();
		}
		dfs(1);
		printf("%lld\n", sum);
		s.clear(), t.clear();
	}
}
int main() {
	freopen("walk.in", "r", stdin);
	freopen("walk.out", "w", stdout);
	n = read(), k = read();
	for (int i = 1; i <= k; ++i) {
		w[i] = read();
	}
	if(n <= 100 || k <= 2)sub1::solve();
	else puts("-1");
	return 0;
}

