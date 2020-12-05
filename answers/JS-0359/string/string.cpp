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

const int maxn = 1 << 21;
const int full = (1 << 14) - 1;

int n;
int pop[1 << 16];
int f[maxn], g[maxn], z[maxn];
int sum[35];
char s[maxn];

inline void zMatch(){
	FOR(i, 0, n)
		z[i] = 0;
	z[0] = n;
	int l = 0, r = 0;
	FOR(i, 1, n){
		if(i <= r)
			z[i] = min(z[i - l], r - i);
		for(int &j = z[i]; i + j < n && s[j] == s[i + j]; ++j);
		if(i + z[i] - 1 > r)
			l = i, r = i + z[i] - 1;
	}
	return;
}

inline int popcnt(int x){
	return pop[x & full] + pop[x >> 14];
}

inline void solve(){
	scanf("%s", s);
	n = strlen(s);
	zMatch();
	FOR(i, 0, n)
		f[i] = (i ? f[i - 1] : 0) ^ (1 << s[i] - 'a');
	for(int i = n - 1; i >= 0; --i)
		g[i] = (i != n - 1 ? g[i + 1] : 0) ^ (1 << s[i] - 'a');
	ll ans = 0;
	REP(i, 0, 26)
		sum[i] = 0;
	FOR(i, 2, n){
		for(int j = popcnt(f[i - 2]); j <= 26; ++j)
			++sum[j];
		for(int r = i; r < n; r += i){
//			printf("i = %d r = %d g = %d %d\n", i, r, popcnt(g[r]), g[r]);
			ans += sum[popcnt(g[r])];
			if(z[r] < i)
				break;
		}
//		printf("%lld\n", ans);
	}
	printf("%lld\n", ans);
	return;
}

int main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	
	int T;
	FOR(i, 0, 1 << 14)
		pop[i] = pop[i >> 1] + (i & 1);
	for(scanf("%d", &T); T--; solve());
	return 0;
}

