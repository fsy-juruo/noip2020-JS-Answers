#include<bits/stdc++.h>
using namespace std;

#define dbg(x) cerr << #x << " = " << x << "   ";
#define dbgll(x) cerr << #x << " = " << x << endl;

template < typename Tp >
inline void rd(Tp &x) {
	x = 0; char ch = 1; int fh = 1;
	while(ch != '-' && !isdigit(ch)) ch = getchar();
	if(ch == '-') ch = getchar(), fh = -1;
	while(isdigit(ch)) x = x * 10 + ch - '0', ch = getchar();
	x *= fh;
}

const int mod = 1000000007;

template < typename Tp > inline void smax(Tp &x, Tp y) { if(x < y) x = y; }
template < typename Tp > inline void smin(Tp &x, Tp y) { if(x > y) x = y; }
template < typename Tp > inline void chkadd(Tp &x, Tp y) { x = (x + y) % mod; }
template < typename Tp > inline Tp abs(Tp x) { if(x < 0) return -x; else return x; }

const int maxn = 500000 + 7;
const int maxm =  + 7;

int n, m;
int c[maxn], d[maxn];
int Mx[20], Mn[20];
int nx[20], w[20];

inline void Init(void) {
	rd(n); rd(m);
	for(int i = 1; i <= m; i++) {
		rd(w[i]);
	}
	for(int i = 1; i <= n; i++) {
		rd(c[i]); rd(d[i]);
		nx[c[i]] += d[i];
		smax(Mx[c[i]], nx[c[i]]);
		smin(Mn[c[i]], nx[c[i]]);
	}
	for(int i = 1; i <= m; i++) {
		if(nx[i] != 0) return ;
		if(Mx[i] - Mn[i] >= w[i]) return ;
	}
	puts("-1");
	exit(0);
}

int ans;
int p[20], ppp[20];
namespace Sub1 {
	
	void solve(void) {
		
	}
	void dfs(int step) {
		if(step == m + 1) {
			memcpy(ppp, p, sizeof(p));
			while(true) {
				for(int i = 1; i <= n; i++) {
					p[c[i]] += d[i];
					++ans; if(ans == mod) ans = 0;
					if(p[c[i]] > w[c[i]] || p[c[i]] <= 0) {
						memcpy(p, ppp ,sizeof(p));
						return ;
					}
				}
			}
			memcpy(p, ppp ,sizeof(p));
			return ;
		}
		for(int i = 1; i <= w[step]; i++) {
			p[step] = i; dfs(step + 1);
		}
	}
	void Main(void) {
		dfs(1);
		printf("%d\n", ans);
	}
}

inline void Work(void) {
	Sub1::Main();
}

signed main(void) {
	
	freopen("walk.in", "r", stdin);
	freopen("walk.out", "w", stdout);
	Init();
	Work();
}

