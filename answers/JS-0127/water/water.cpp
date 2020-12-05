#include <bits/stdc++.h>
#define fir first
#define sec second
#define PB push_back
#define MP make_pair

using namespace std;

#define REP(i, _a, _b) for (int (i) = (int)(_a); (i) < (int)(_b); ++(i))
#define REV(i, _b, _a) for (int (i) = (int)(_b) - 1; (i) >= (int)(_a); --(i))

template <class T> void chkmax(T& x, T y) { x = (x > y ? x : y); }
template <class T> void chkmin(T& x, T y) { x = (x < y ? x : y); }

typedef long long LL;
typedef pair <int, int> pi;
typedef vector <int> vi;

const int N = 1e5 + 5;

int n, m;
int in[N], out[N];
bool vis[N];

vi e[N];

struct Frac {
	LL p, q;
	
	Frac(){ p = 0ll, q = 1ll; }
	Frac(LL _p, LL _q){ p = _p, q = max(1ll, _q); }
	
	LL gcd(LL x, LL y){
		return y ? gcd(y, x % y) : x;
	}
	
	Frac add(Frac a){
		Frac res(p * a.q + a.p * q, q * a.q);
		LL d = gcd(res.p, res.q);
		res.p /= d;
		res.q /= d;
		p = res.p;
		q = res.q;
	}
	
	Frac mul(LL k){
		q *= k;
		LL d = gcd(p, q);
		p /= d;
		q /= d;
	}
};

Frac ans[N];

int main(){
	freopen("water.in", "r", stdin);
	freopen("water.out", "w", stdout);
	scanf("%d%d", &n, &m);
	REP(i, 1, n + 1){
		int d, u; scanf("%d", &d);
		out[i] += d;
		REP(j, 0, d){
			scanf("%d", &u);
			++in[u];
			e[i].PB(u);
		}
	}
	
	queue <int> Q;
	/*REP(i, 1, n + 1){
		printf("%lld %lld\n", ans[i].p, ans[i].q);
	}*/
	REP(i, 1, n + 1) if (!in[i]){
		ans[i].p = 1ll, ans[i].q = 1ll;
		Q.push(i);
		vis[i] = 1;
	}
	
	while (!Q.empty()){
		int p = Q.front(); Q.pop();
		if (!out[p]) continue;
		ans[p].mul(out[p]);
		for (int i = 0; i < e[p].size(); ++i){
			int v = e[p][i];
			ans[v].add(ans[p]);
			--in[v];
			if (!in[v] && !vis[v]){
				Q.push(v);
				vis[v] = 1;
			}
		}
		/*printf("---------\n");
		REP(i, 1, n + 1){
			printf("%lld %lld\n", ans[i].p, ans[i].q);
		}*/
	}
	
	REP(i, 1, n + 1) if (!out[i]){
		printf("%lld %lld\n", ans[i].p, ans[i].q);
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
