#include <cstdio>
#include <queue>
typedef long long LL;
const int N = 1e5 + 7, M = 5e5 + 7;

LL gcd(LL a, LL b){
	return b == 0 ? a : gcd(b, a%b);
}

struct Fraction{
	LL p, q;
	Fraction(){
		p = 0, q = 1;
	}
} hv[N];

Fraction operator + (Fraction a, Fraction b){
	Fraction z;
	z.p = a.p * b.q + a.q * b.p;
	z.q = a.q * b.q;
	LL g = gcd(z.p, z.q);
	z.p /= g, z.q /= g;
	return z;
}

Fraction operator / (Fraction a, int b){
	a.q *= b;
	LL g = gcd(a.p, a.q);
	a.p /= g, a.q /= g;
	return a;
}

int hd[N], in[N], d[N], nt[M], to[M];

inline void add(int x, int y, int id){
	nt[id] = hd[x], hd[x] = id, to[id] = y, ++in[y];
}

std::queue<int> q;

int main(){
	freopen("water.in", "r", stdin);
	freopen("water.out", "w", stdout);
	int n, m;
	scanf("%d%d", &n, &m);
	for(int i=1, cc=0, x; i<=n; ++i){
		scanf("%d", d+i);
		for(int j=1; j<=d[i]; ++j){
			scanf("%d", &x);	
			add(i, x, ++cc);
		}
	}
	for(int i=1; i<=m; ++i) q.push(i), hv[i].p = 1; 
	while(q.size()){
		int u = q.front(); q.pop();
		Fraction w = hv[u] / d[u];
		for(int i=hd[u], v; i; i=nt[i]){
			--in[v=to[i]], hv[v] = hv[v] + w;
			if(in[v] == 0) q.push(v);
		}
	}
	for(int i=1; i<=n; ++i) if(d[i] == 0) printf("%lld %lld\n", hv[i].p, hv[i].q);
	return 0;
}
