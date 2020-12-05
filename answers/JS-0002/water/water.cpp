#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

#define rep(i , l , r) for (int i = (l); i < (r); ++i)

const int MN = 2e5 + 5 , MM = 1e6 + 5;

struct Edge {
	int to , nxt; 
} E[MM << 2];

int N , M , tot , indeg[MN] , outdeg[MN] , as[MN] , head[MN] , cnt;
LL p[MN] , q[MN];
queue < int > que;

inline void AddEdge(int u , int v) {
	E[++tot] = (Edge) {v , head[u]};
	head[u] = tot;
}
inline LL gcd(LL x , LL y) {
	if (y == 0) return x;
	else return gcd(y , x % y);
}
inline void add(int x , LL a1 , LL b1) {
	LL g = gcd(a1 , b1); a1 /= g , b1 /= g;
	LL a2 = p[x] , b2 = q[x];
	if (a2 == 0 && b2 == 0) {
		p[x] = a1; q[x] = b1;
		return;
	}
    LL nq = 1LL * b1 / gcd(b1 , b2) * b2;
	p[x] = (nq / b1 * a1) + (nq / b2 * a2);
	q[x] = nq;
	g = gcd(p[x] , q[x]);
	p[x] /= g , q[x] /= g;
	return;
}

int main() {
	
	#ifndef evenbao
	freopen("water.in" , "r" , stdin);
	freopen("water.out" , "w" , stdout);
	#endif
	
	scanf("%d%d" , &N , &M);
	for (int i = 1; i <= N; ++i) {
		int x; scanf("%d" , &x);
		while (x--) {
			int y; scanf("%d" , &y); ++indeg[y]; ++outdeg[i];
			AddEdge(i , y);
		}
	}
	for (int i = 1; i <= N; ++i)
		if (outdeg[i] == 0) as[++cnt] = i;
	for (int i = 1; i <= M; ++i) {
		que.push(i);
		p[i] = 1; q[i] = 1;
	}
	while (!que.empty()) {
		int u = que.front(); que.pop();
		for (int i = head[u]; i; i = E[i].nxt) {
			int v = E[i].to; --indeg[v];
			add(v , p[u] , 1ll * q[u] * outdeg[u]);
			if (indeg[v] == 0) que.push(v);
		} 
	}
	for (int i = 1; i <= cnt; ++i) printf("%lld %lld\n" , p[as[i]] , q[as[i]]);
	return 0; 
}
