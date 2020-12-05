#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int P = 1e9 + 7;

inline ll in() {
	ll x = 0; bool f = 0; char c = getchar();
	while (!isdigit(c)) {
		f |= (c == '-');
		c = getchar();
	} while (isdigit(c)) {
		x = (x << 3) + (x << 1) + (c ^ 48);
		c = getchar();
	}
	return f ? -x : x;
}

const int N = 1005;
ll n, m, w[N], c[N], d[N], t[N];
ll cc[N], dd[N], pos[N], ans;
ll k[N];

inline void dfs(int dep) {
	if (dep > m) {
		ll xz = 1e9, tt = 0;
		memcpy(k, pos, sizeof(k));
		while (1) {
			bool flag = 1;
			for (int i = 1; i <= m; i++) {
				k[i] += t[i];
				if (k[i] > w[i] || k[i] <= 0) {
					flag = 0;
					break;
				}
				tt++;
			}
			if (!flag) break;
		}
		ans = (ans + tt) % P;
		return;
	}
	for (int i = 1; i <= w[i]; i++) {
		pos[dep] = i;
		dfs(dep + 1);
	}
}
 
int main() {
	freopen("walk.in", "r", stdin);
	freopen("walk.out", "w", stdout);
	
	n = in(), m = in();
	for (int i = 1; i <= m; i++)
		w[i] = in();
	for (int i = 1; i <= n; i++) {
		c[i] = in(), d[i] = in();
		t[c[i]] += d[i];
	}
	cout << endl;
	bool flag = 0;
	for (int i = 1; i <= n; i++) 
		if (t[i]) {
			flag = 1;
			break;
		}
	if (!flag) {
		puts("-1");
		return 0;
	}
	dfs(1);
	cout << ans << endl;

	return 0;
}


