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

const int maxk = 10;
const int maxn = 1e5 + 5;
const int INF = 1e9 + 7;

int n, k;
int w[maxk];
int c[maxn], d[maxn];

namespace Solve1{
	const int maxw = 1e5 + 5;
	int pre[maxw];
	ll f[maxw], g[maxw];
	ll ans[maxw];
	
	inline int check(int i, int md){
		ll delta = 1ll * pre[n - 1] * md;
		if(i + delta < 1 || i + delta > w[0])
			return 0;
		return min(f[i + delta], g[w[0] - (i + delta) + 1]);
	}
	
	inline void work(){
		scanf("%d", w + 0);
		FOR(i, 0, n){
			scanf("%d%d", c + i, d + i);
			pre[i] = (i ? pre[i - 1] : 0) + d[i];
		}
		memset(f, 0x3f, sizeof(f));
		memset(g, 0x3f, sizeof(g));
		for(int i = n - 1; i >= 0; --i){
			if(pre[i] <= 0)
				f[-pre[i]] = i + 1;
			if(pre[i] >= 0)
				g[pre[i]] = i + 1;
		}
		
		memset(ans, 0x3f, sizeof(ans));
		REP(i, 1, w[0])
			ans[i] = min(f[i], g[w[0] - i + 1]);
//		REP(i, 1, w[0])
//			printf("%lld ", ans[i]); puts("");
		REP(i, 1, w[0]) if(i + pre[n - 1] >= 1 && i + pre[n - 1] <= w[0])
			ans[i] = min(ans[i], ans[i + pre[n - 1]] + n);
		for(int i = w[0]; i >= 1; --i) if(i + pre[n - 1] >= 1 && i + pre[n - 1] <= w[0])
			ans[i] = min(ans[i], ans[i + pre[n - 1]] + n);
//		REP(i, 1, w[0])
//			printf("%lld ", ans[i]); puts("");
		ll sum = 0;
		REP(i, 1, w[0]){
			if(ans[i] == 0x3f3f3f3f3f3f3f3f){
				puts("-1");
				return;
			}
			sum += ans[i];
		}
		printf("%lld\n", sum);
		return;
	}
}

namespace Solve2{
	const int maxp = 1005;
	const int myMaxn = 105;
	
	int tot;
	int tmp[maxk];
	int a[maxp][maxk];
	int f[myMaxn][maxp];
	vector<pii> g[myMaxn][maxp];
	inline void dfs(int dep){
		if(dep == k){
			FOR(i, 0, k)
				a[tot][i] = tmp[i];
			tot++;
			return;
		}
		REP(i, 1, w[dep])
			tmp[dep] = i, dfs(dep + 1);
		return;
	}
	
	inline void go(int i, int j){
		FOR(l, 0, g[i][j].size()){
			f[g[i][j][l].fst][g[i][j][l].snd] = f[i][j] + 1;
			go(g[i][j][l].fst, g[i][j][l].snd);
		}
		return;
	}
	
	inline int getID(){
		int ret = 0;
		FOR(i, 0, k)
			(ret *= w[i]) += (tmp[i] - 1);
		return ret;
	}
	
	inline void work(){
		FOR(i, 0, k)
			scanf("%d", w + i);
		FOR(i, 0, n)
			scanf("%d%d", c + i, d + i), --c[i];
		dfs(0);
		
		memset(f, -1, sizeof(f));
		
		FOR(i, 0, n) FOR(j, 0, tot){
			FOR(l, 0, k)
				tmp[l] = a[j][l];
			tmp[c[i]] += d[i];
			if(tmp[c[i]] < 1 || tmp[c[i]] > w[c[i]])
				f[i][j] = 1;
			else{
				g[(i + 1) % n][getID()].PB(MP(i, j));
			}
		}
		
		FOR(i, 0, n) FOR(j, 0, tot) if(f[i][j] == 1)
			go(i, j);
	
		ll sum = 0;
		FOR(j, 0, tot){
			if(f[0][j] == -1){
				puts("-1");
				return;
			}
			else
				sum += f[0][j];
		}
		
		printf("%lld\n", sum);
		return;
	}
}

int main(){
	freopen("walk.in", "r", stdin);
	freopen("walk.out", "w", stdout);
	
	scanf("%d%d", &n, &k);
	if(k == 1)
		Solve1::work();
	else
		Solve2::work();
	return 0;
}

