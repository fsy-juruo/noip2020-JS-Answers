//AFO

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

const int mod = 998244353;

template < typename Tp > inline void smax(Tp &x, Tp y) { if(x < y) x = y; }
template < typename Tp > inline void smin(Tp &x, Tp y) { if(x > y) x = y; }
template < typename Tp > inline void chkadd(Tp &x, Tp y) { x = (x + y) % mod; }
template < typename Tp > inline Tp abs(Tp x) { if(x < 0) return -x; else return x; }

const int maxn =  + 7;
const int maxm =  + 7;

int n, m;
int a[3][40];

int ax[1000000], ay[1000000], rear;

map <pair <int, pair<int, int> > , bool> mp;
int lim;

void dfs(int x, int y, int z, int xx, int yy, int zz) {
	if(rear > 820000) return ;
	if(mp[make_pair(xx, make_pair(yy, zz))] == true) return ;
	mp[make_pair(xx, make_pair(yy, zz))] = true;
	if((!x || !y || !z) && ((xx == (1 << m) - 1 && yy == 0) || (xx == (1 << m) - 1 && zz == 0) || (yy == (1 << m) - 1 && xx == 0) || (yy == (1 << m) - 1 && zz == 0) || (zz == (1 << m) - 1 && xx == 0) || (zz == (1 << m) - 1 && yy == 0))) {
		printf("%d\n", rear);
		for(int i = 1; i <= rear; i++) {
			printf("%d %d\n", ax[i], ay[i]);
			
		}
		exit(0);
	}
	if(x < m) {
		if(y) {
			int p = yy & 1; yy >>= 1; y--;
			xx = (xx << 1) | p; ++x;
			ax[++rear] = 2, ay[rear] = 1;
			dfs(x, y, z, xx, yy, zz);
			y++; yy = (yy << 1) | p;
			--x; xx >>= 1;
			--rear;
		}
		if(z) {
			int p = zz & 1; zz >>= 1; z--;
			xx = (xx << 1) | p; ++x;
			ax[++rear] = 3, ay[rear] = 1;
			dfs(x, y, z, xx, yy, zz);
			z++; zz = (zz << 1) | p;
			--x; xx >>= 1;
			--rear;
		}
	}
	if(y < m) {
		if(x) {
			int p = xx & 1; xx >>= 1; x--;
			yy = (yy << 1) | p; ++y;
			ax[++rear] = 1, ay[rear] = 2;
			dfs(x, y, z, xx, yy, zz);
			x++; xx = (xx << 1) | p;
			--y; yy >>= 1;
			--rear;
		}
		if(z) {
			int p = zz & 1; zz >>= 1; z--;
			yy = (yy << 1) | p; ++y;
			ax[++rear] = 3, ay[rear] = 2;
			dfs(x, y, z, xx, yy, zz);
			z++; zz = (zz << 1) | p;
			--y; yy >>= 1;
			--rear;
		}
	}
	if(z < m) {
		if(y) {
			int p = yy & 1; yy >>= 1; y--;
			zz = (zz << 1) | p; ++z;
			ax[++rear] = 2, ay[rear] = 3;
			dfs(x, y, z, xx, yy, zz);
			y++; yy = (yy << 1) | p;
			--z; zz >>= 1;
			--rear;
		}
		if(x) {
			int p = xx & 1; xx >>= 1; x--;
			zz = (zz << 1) | p; ++z;
			ax[++rear] = 1, ay[rear] = 3;
			dfs(x, y, z, xx, yy, zz);
			x++; xx = (xx << 1) | p;
			--z; zz >>= 1;
			--rear;
		}
	}
}

inline void Init(void) {
	rd(n); rd(m);
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) {
			rd(a[i][j]); --a[i][j];
		}
	}
}

inline void Work(void) {
	int x1 = 0, x2 = 0;
	for(int i = 1; i <= m; i++) {
		x1 = (x1 << 1) | a[1][i];
		x2 = (x2 << 1) | a[2][i];
	}
	dfs(m, m, 0, x1, x2, 0);
}

signed main(void) {
	freopen("ball.in", "r", stdin);
	freopen("ball.out", "w", stdout);
	Init();
	Work();
}

