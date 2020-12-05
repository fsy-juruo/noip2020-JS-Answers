#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define dbg(x) cerr << #x << " = " << x << "   ";
#define dbgll(x) cerr << #x << " = " << x << endl;
#define int long long

template < typename Tp >
inline void rd(Tp &x) {
	x = 0; char ch = 1; int fh = 1;
	while(ch != '-' && !isdigit(ch)) ch = getchar();
	if(ch == '-') ch = getchar(), fh = -1;
	while(isdigit(ch)) x = x * 10 + ch - '0', ch = getchar();
	x *= fh;
}

const int mod = 998244353;

template < typename Tp > inline void smax(Tp &x, Tp y) { if(x < y) x = y; }
template < typename Tp > inline void smin(Tp &x, Tp y) { if(x > y) x = y; }
template < typename Tp > inline void chkadd(Tp &x, Tp y) { x = (x + y) % mod; }
template < typename Tp > inline Tp abs(Tp x) { if(x < 0) return -x; else return x; }

const int maxn = 100000 + 7;
const int maxm =  + 7;

int n, m;
vector <int> v[maxn];
int d[maxn], to[maxn][6];
int deg[maxn];

inline void Init(void) {
	rd(n); rd(m);
	for(int i = 1; i <= n; i++) {
		rd(d[i]);
		for(int j = 1, x; j <= d[i]; j++) {
			rd(x); v[x].pb(i);
			to[i][j] = x; deg[x]++;
		}
	}
}

int que[maxn], fr, re = 1;

inline void toposort(void) {
	for(int i = 1; i <= n; i++) {
		if(deg[i] == 0) que[++fr] = i;
	}
	while(re <= fr) {
		int x = que[re]; ++re;
		for(int i = 1; i <= d[x]; i++) {
			deg[to[x][i]]--;
			if(deg[to[x][i]] == 0) que[++fr] = to[x][i];
		}
	}
}

int gcd(int x, int y) {
	return y ? gcd(y, x % y) : x;
}

int fenzi[maxn], fenmu[maxn];

inline void Work(void) {
	toposort();
	for(int i = 1; i <= n; i++) {
		int x = que[i];
		if(x <= m) fenzi[x] = fenmu[x] = 1; 
		else {
			fenzi[x] = 0, fenmu[x] = 1;
			for(int j = 0; j < (int)v[x].size(); j++) {
				fenzi[x] = fenzi[x] * fenmu[v[x][j]] * d[v[x][j]] + fenzi[v[x][j]] * fenmu[x];
				fenmu[x] = fenmu[x] * fenmu[v[x][j]] * d[v[x][j]];
				int cpc = gcd(fenzi[x], fenmu[x]);
				fenzi[x] /= cpc, fenmu[x] /= cpc;
			}
		}
	}
	for(int i = 1; i <= n; i++) {
		if(d[i] == 0) printf("%lld %lld\n", fenzi[i], fenmu[i]);
	}
}

signed main(void) {
	freopen("water.in", "r", stdin);
	freopen("water.out", "w", stdout);
	Init();
	Work();
}

