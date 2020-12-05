#include <bits/stdc++.h>
using namespace std;

const int N = 5e5 + 10, P = 1e9 + 7;

void upd(int &x,int y) { x += y; if (x >= P) x -= P; }

struct walk { int c, d; } walk[N];
int n, k, w[N];

namespace subtask1 {
	int a[23], ans;
	
	void calc() {
//		for (int i = 1; i <= k; ++i) cerr << a[i] << " ";
//	 	cerr << ": ";
		static int b[23];
		for (int i = 1; i <= k; ++i) b[i] = a[i];
		int cnt = 0;
		while (true) {
			int out = 0;
			for (int i = 1; i <= n; ++i) {
				int p = walk[i].c, d = walk[i].d;
				b[p] += d;
				++cnt;
	//			cerr << "Walk: " << p << " " << d << '\n';
				if (b[p] < 1 || b[p] > w[p]) {
	//				cerr << "OUT " << "b[" << p << "] = " << b[p] << '\n';
					out = 1;	
					break;
				}
			}
			if (out) break;
			bool loop = 1;
			for (int i = 1; i <= k; ++i)
				loop &= b[i] == a[i];
			if (loop) { cout << "-1\n"; exit(0); }
		}
		upd(ans, cnt);
	}
	
	void dfs(int cur) {
		if (cur > k) { calc(); return; }
		for (int i = 1; i <= w[cur]; ++i) {
			a[cur] = i;
			dfs(cur + 1);
			a[cur] = 0;
		}
	}
	
	void naive1() { ans = 0, dfs(1), cout << ans << '\n'; }
}
using subtask1::naive1;

int main() {
	freopen("walk.in", "r", stdin);
	freopen("walk.out", "w", stdout);
	cin >> n >> k;
	for (int i = 1; i <= k; ++i) cin >> w[i];
	for (int i = 1; i <= n; ++i) cin >> walk[i].c >> walk[i].d;
	if (n <= 100) naive1();
//	else naive2();
	return 0;
}
