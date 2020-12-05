#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define per(i, a, b) for (int i = a; i >= b; i--)
#define pb push_back

typedef long long ll;
using namespace std;
int n, m, in[100010], d[100010];
vector <int> E[100010];
vector <ll> G[100010];
//bool b[100010];
struct node {
	int x, step;
	ll V;
};

void bfs(int s) {
//	rep(i, 1, n) b[i] = 0;
	queue <node> q;
	q.push((node){s, 0, 1ll});
//	b[s] = 1;
	while (!q.empty()) {
		node t = q.front(); q.pop();
		if (t.step > 11) continue;
		if (d[t.x] == 0) {
			G[t.x].pb(t.V);
			continue;
		}
		for (int i = 0; i < E[t.x].size(); i++) {
			int y = E[t.x][i];
//			if (b[y] == 1) continue;
//			b[y] = 1;
			q.push((node){y, t.step+1, t.V*(ll)(d[t.x])});
		}
	}
}

int main() {
	freopen("water.in", "r", stdin);
	freopen("water.out", "w", stdout);
	scanf("%d %d", &n, &m);
	rep(i, 1, n) {
		scanf("%d", &d[i]);
		rep(j, 1, d[i]) {
			int x; scanf("%d", &x);
			E[i].pb(x); in[x]++;
		}
	}
	int s = 0;
	rep(i, 1, n) {
		if (in[i] == 0) bfs(i), s++;
		if (s == m) break;
	}
	rep(i, 1, n) {
		if (d[i] == 0) {
//			for (int j = 0; j < G[i].size(); j++) printf("%d ", G[i][j]);
//			puts("");
			ll X = 1, Y = G[i][0];
			for (int j = 1; j < G[i].size(); j++) {
				ll Y1 = G[i][j], X1 = 1, g = __gcd(Y, Y1), l = Y/g*Y1;
				ll t1 = l, t2 = (X1*(l/Y1)) + (X*(l/Y));
				g = __gcd(t1, t2);
				X = t2 / g, Y = t1 / g;
			}
			printf("%lld %lld\n", X, Y);
		}
	}
	return 0;
}

