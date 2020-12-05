#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn = 1e5 + 10, maxm = 1e6 + 10;

ll gcd(ll a, ll b){
	return b ? gcd(b, a % b) : a;
}

struct node {
	ll a, b;
	
	void Div(){
		ll g = gcd(a, b);
		if (!g) return;
		a /= g; b /= g;
	}
	
	node (ll a = 0, ll b = 0) : a(a), b(b) { }
} d[maxn];

node Add(node a, node b){
	if (b.b == 0) return a;
	if (a.b == 0) return b;
	node re = node(a.a * b.b + b.a * a.b, a.b * b.b);
	re.Div();
	return re;
}

node Div(node a, int k){
	a.b *= k; a.Div();
	return a;
}

int s[maxn], n, m;
int to[maxm], nxt[maxm], head[maxn], tot;
bool inq[maxn];

void addedge(int u, int v){
	to[++tot] = v;
	nxt[tot] = head[u];
	head[u] = tot;
}

void bfs(){
	queue<int> q;
	memset(d, 0, sizeof d);
	for (int i = 1; i <= m; i++) q.push(i), d[i] = node(1, 1), inq[i] = 1;
	while (q.size()){
		int x = q.front(); q.pop();
		if (!s[x]) continue;
		inq[x] = 0;
		node c = Div(d[x], s[x]); d[x] = node(0, 0);
		for (int i = head[x], p; i; i = nxt[i]){
			p = to[i];
			d[p] = Add(d[p], c);
			if (!inq[p]){
				q.push(p);
				inq[p] = 1;
			}
		}
	}
}

int main(){
	freopen("water.in", "r", stdin);
	freopen("water.out", "w", stdout);
	scanf("%d%d", &n, &m);
	for (int i = 1, t, v; i <= n; i++){
		scanf("%d", s + i);
		for (int j = 1; j <= s[i]; j++){
			scanf("%d", &v);
			addedge(i, v);
		}
	}
	bfs();
	for (int i = 1; i <= n; i++)
		if (!s[i]){
			d[i].Div();
			printf("%lld %lld\n", d[i].a, d[i].b);
		}
	return 0;
}
