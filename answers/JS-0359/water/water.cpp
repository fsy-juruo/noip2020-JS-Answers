#include<bits/stdc++.h>

using namespace std;

#define FOR(i, x, y) for(int i = (int)(x); i < (int)(y); ++i)
#define REP(i, x, y) for(int i = (int)(x); i <= (int)(y); ++i)
#define MP make_pair
#define PB push_back
#define PH push
#define fst first
#define snd second
typedef long long ll;
typedef unsigned long long ull;
typedef double lf;
typedef long double Lf;
typedef pair<int, int> pii;

const int maxn = 1e5 + 5;
const int maxd = 10;

inline ll myGcd(ll x, ll y){ return y ? myGcd(y, x % y) : x; }

class Ratio{
public:
	ll p, q;
	Ratio(){}
	Ratio(ll x): p(x), q(1){}
	inline Ratio operator / (const ll &oth)const{
		Ratio ret = *this;
		ll g = myGcd(ret.p, oth);
		ret.p /= g;
		ret.q *= oth / g;
		return ret;
	}
	inline Ratio operator + (const Ratio &oth)const{
		Ratio ret;
		ll l = q / myGcd(q, oth.q) * oth.q;
		ret.p = p * l / q + oth.p * l / oth.q;
		ret.q = l;
//		ret.p = p * oth.q + q * oth.p;
//		ret.q = q * oth.q;
		ll g = myGcd(ret.p, ret.q);
		ret.p /= g, ret.q /= g;
		return ret;
	}
	inline Ratio& operator += (const Ratio &oth){
		*this = *this + oth;
		return *this;
	}
} f[maxn];

int n, m, hd, tl;
int d[maxn], nd[maxn];
int que[maxn];
int a[maxn][maxd];

inline void topoSort(){
	hd = tl = 0;
	FOR(i, 0, n) if(!nd[i])
		que[tl++] = i;
	for(; hd < tl; ++hd){
		int u = que[hd];
		FOR(i, 0, d[u]){
			int v = a[u][i];
			if(!(--nd[v]))
				que[tl++] = v;
		}
	}
	return;
}

int main(){
	freopen("water.in", "r", stdin);
	freopen("water.out", "w", stdout);
	
	scanf("%d%d", &n, &m);
	FOR(i, 0, n){
		scanf("%d", d + i);
		FOR(j, 0, d[i]){
			scanf("%d", &a[i][j]);
			++nd[--a[i][j]];
		}
	}
	
	topoSort();
	FOR(i, 0, m)
		f[i] = Ratio(1);
	FOR(i, m, n)
		f[i] = Ratio(0);
	FOR(i, 0, tl){
		int u = que[i];
		if(!d[u])
			continue;
//		printf("u = %d\n", u);
		Ratio res = f[u] / d[u];
//		puts("ok");
		FOR(j, 0, d[u])
			f[a[u][j]] += res;
	}
	
	FOR(i, 0, n) if(!d[i])
		printf("%lld %lld\n", f[i].p, f[i].q);
	return 0;
}

