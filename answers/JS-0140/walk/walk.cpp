#include <bits/stdc++.h>

#define ll long long
#define N (int) (5e5+10)
#define INF 0x3f3f3f3f
#define MOD 1000000007

using namespace std;
int input () {
	int x = 0, f = 0;
	char c = getchar ();
	while (c < '0' || c > '9') f = c == '-', c = getchar ();
	while (c >= '0' && c <= '9') x = (x << 1) + (x << 3) + (c ^ 48), c = getchar ();
	return f ? - x : x;
}

int n, k;
int w[N], c[N], d[N];
int max_w;

int ans = 0;

struct Edge {
	int v;
	int nxt;
} edge[N];
int fst[N], ecnt;
void add_edge (int u, int v) {
	edge[ecnt].v = v, edge[ecnt].nxt = fst[u], fst[u] = ecnt ++;
}
void init_e () {
	memset (fst, -1, sizeof (fst));
}

int tot = 0;
int calc (int x, vector <int> pos) {
	int ret = x;
	for (int i = 0; i < pos.size (); i ++) {
		ret = ret * max_w + pos[i];
		tot = max (tot, ret);
	}
	return ret;
}

void mke (vector <int> pos) {
	for (int i = 1; i <= n; i ++) {
		int v = calc (i, pos);
		pos[c[i]-1] += d[i];
		int tmp;
		if (i == n) tmp = 1; else tmp = i+1;
		int u = calc (tmp, pos);
		pos[c[i]-1] -= d[i];
		add_edge (u, v);
	}
}

void dfs (int x, vector <int> pos) {
	if (x == k) {
//		for (int i = 0; i < pos.size (); i ++) cout << pos[i] << " ";
//		cout << calc (1, pos) << endl;
//		cout << endl;
		mke (pos);
		return ;
	}
	for (int i = 1; i <= w[x+1]; i ++) {
		vector <int> pos1 = pos;
		pos1.push_back (i);
		dfs (x+1, pos1);
	}
}

int deg[N];
int dis[N];
bool tuopu () {
	for (int i = 0; i <= tot; i ++) {
		for (int e = fst[i]; e != -1; e = edge[e].nxt) {
			int v = edge[e].v;
//			cout << i << " " << v << endl;
			deg[v] ++;
		}
	}
	
	queue <int> q;
	
	for (int i = 0; i <= tot; i ++) if (! deg[i]) q.push (i); else dis[i] = INF;
	
	int cnt = 0;
	while (! q.empty ()) {
		int u = q.front ();
		cnt ++;
//		cout << cnt << endl;
		q.pop ();
		
		for (int e = fst[u]; e != -1; e = edge[e].nxt) {
			int v = edge[e].v;
			deg[v] --;
			dis[v] = min (dis[v], dis[u] + 1) % MOD;
			if (! deg[v]) q.push (v);
		}
	}
	
	if (cnt < tot) return false;
	else return true;
}

void dfs1 (int x, vector <int> pos) {
	if (x == k) {
		(ans += dis[calc (1, pos)]) %= MOD;
		return ;
	}
	for (int i = 1; i <= w[x+1]; i ++) {
		vector <int> pos1 = pos;
		pos1.push_back (i);
		dfs1 (x+1, pos1);
	}
}

void Subtask1 () {
	init_e ();
	
	vector <int> v;
	v.clear ();
	dfs (0, v);
	
	int tmp = tuopu ();
	if (! tmp) printf ("-1\n");
	else {
		dfs1 (0, v);
		printf ("%d\n", ans);
	}
}

int main () {
	freopen ("walk.in", "r", stdin);
	freopen ("walk.out", "w", stdout);
	
	n = input (), k = input ();
	for (int i = 1; i <= k; i ++) w[i] = input (), max_w = max (max_w, w[i]+1);
	for (int i = 1; i <= n; i ++) c[i] = input (), d[i] = input ();
	if (n <= 100)
		Subtask1 ();
	else
		cout << -1 << endl;
	return 0;	
}
