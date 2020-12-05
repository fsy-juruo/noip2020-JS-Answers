#include <bits/stdc++.h>
#define LL long long
#define ULL unsigned long long
#define LD long double
#define _rep(i, x, y) for(int i = x; i <= y; i++)
#define _per(i, x, y) for(int i = x; i >= y; i--)
template <typename T>
inline void read(T &x) {
	x = 0; T f = (T) 1;
	char c = getchar();
	for(; !isdigit(c); c = getchar()) if(c == '-') f = -f;
	for(; isdigit(c); c = getchar()) x = x * 10 + c - '0';
	x *= f;
}
template <typename T>
inline void write(T x) {
	if(x < 0) x = -x, putchar('-');
	if(x > 9) write(x / 10);
	putchar(x % 10 + '0');
}
template <typename T>
inline void writesp(T x, char sp) {
	write(x); putchar(sp);
}

LL gcd(LL a, LL b) {
	if(!a || !b) return a + b;
	return gcd(b, a % b);
}
struct Fraction {
	LL den, num; 
	void init(LL d, LL n) {den = d, num = n;}
	void reduce() {
		LL g = gcd(den, num);
		den /= g; num /= g;
	}
	void output() {
		writesp(den, ' '); writesp(num, '\n');
	}
};
Fraction operator * (Fraction A, Fraction B) {
	Fraction res; res.init(A.den * B.den, A.num * B.num);
	res.reduce();
	return res;
}
Fraction operator + (Fraction A, Fraction B) {
	Fraction res; res.init(A.den * B.num + A.num * B.den, A.num * B.num);
	res.reduce();
	return res;
}
Fraction operator / (Fraction A, Fraction B) {
	Fraction res; res.init(A.den * B.num, A.num * B.den);
	res.reduce();
	return res;
}

const int maxN = 1e5 + 10;
int n, m, deg[maxN], Topo[maxN], vis[maxN], tot = 0;
Fraction Answer[maxN];
std::vector<int> sews[maxN];

void topo() {
	std::queue<int> q;
	_rep(i, 1, m) q.push(i);
	while(!q.empty()) {
		int u = q.front(); q.pop(); Topo[++tot] = u; vis[u] = 1; int l = sews[u].size();
		_rep(j, 0, l - 1) {
			int v = sews[u][j]; 
			if(vis[v]) continue;
			--deg[v];
			if(deg[v] == 0) q.push(v);
		}
	}
}

void solve() {
	_rep(i, 1, m) Answer[i].init(1, 1);
	_rep(i, m + 1, n) Answer[i].init(0, 1);
	_rep(i, 1, n) {
		int k = Topo[i], l = sews[k].size();
		Fraction p; p.init(Answer[k].den, 1ll * Answer[k].num * l);
		_rep(j, 0, l - 1) Answer[sews[k][j]] = Answer[sews[k][j]] + p;
	}
}
int main() {
	freopen("water.in", "r", stdin);
	freopen("water.out", "w", stdout);
	read(n); read(m);
	_rep(i, 1, n) {
		int l; read(l);
		_rep(j, 1, l) {int x; read(x); sews[i].push_back(x); ++deg[x];}
	}
	
	topo(); solve();
	
	_rep(i, 1, n) {
		if(sews[i].empty()) {
			Answer[i].output();
		}
	}
	return 0;
}

