#include<bits/stdc++.h>
using namespace std;

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

const int maxn = (1 << 16) + 7;
const int maxm =  + 7;
const int base1 = 37;
const int mod1 = 1000000007;
const int base2 = 101;
const int mod2 = mod;

int n, m;
int H1[maxn], H2[maxn], w[maxn][27];
vector <int> v[maxn];

char s[maxn];

int fpow(int x, int p, int M) {
	int res = 1;
	while(p) {
		if(p & 1) res = res * x % M; p >>= 1;
		x = x * x % M;
	}
	return res;
}

int cnt[27];
int cas;

inline void Preprocess(void) {
	int num = 0, bas1 = base1, bas2 = base2;
	for(int i = 1; i <= n; i++) {
		if(i != 1 && cas == 1) for(int j = 1; i * j <= (1 << 16); j++) {
			v[i * j].push_back(i);
		}
		H1[i] = (H1[i - 1] + bas1 * (s[i] - 'a' + 1)) % mod1;
		if(n <= 1000) H2[i] = (H2[i - 1] + bas2 * (s[i] - 'a' + 1)) % mod2;
		bas1 = bas1 * base1 % mod1;
		if(n <= 1000) bas2 = bas2 * base2 % mod2;
//		bas1 = bas1 * base1 % mod1;
		cnt[s[i] - 'a']++;
		if(cnt[s[i] - 'a'] & 1) ++num;
		else if(cnt[s[i] - 'a'] != 0) --num;
		memcpy(w[i], w[i - 1], sizeof(w[i]));
		for(int j = num; j <= 26; j++) w[i][j]++;
	}
}

inline void Init(void) {
	scanf("%s", s + 1);
	n = strlen(s + 1);
}

int ans;

inline void Work(void) {
	Preprocess();
	memset(cnt, 0, sizeof(cnt));
	int num = 0;
	for(int c = n; c >= 1; c--) {
		cnt[s[c] - 'a']++;
		if(cnt[s[c] - 'a'] & 1) ++num;
		else if(cnt[s[c] - 'a'] != 0) --num;
		int i = c - 1;
		for(int j = 0; j < (int)v[i].size(); j++) {
			int x = v[i][j];
//			if(x == i) continue;
			int duan = i / x;
//			bool equ = true;
//			for(int pp = 1; pp <= i; pp++) {
//				if(s[pp] != s[(pp - 1) % x + 1]) {
//					equ = false; break;
//				}
//			}
//			if(equ == false) continue;
			int u1 = fpow(base1, x, mod1), u2 = fpow(base2, x, mod2);
			int sum1 = (fpow(u1, duan, mod1) - 1) * fpow(u1 - 1, mod1 - 2, mod1) % mod1;
			int sum2; if(n <= 1000) sum2 = (fpow(u2, duan, mod2) - 1) * fpow(u2 - 1, mod2 - 2, mod2) % mod2;
			if(H1[x] * sum1 % mod1 != H1[i]) continue;
			if(n <= 1000 && H2[x] * sum2 % mod2 != H2[i]) continue;
			ans += w[x - 1][num];
		}
	}
	printf("%lld\n", ans);
}

inline void Reset(void) {
//	for(int i = 1; i <= n; i++) v[i].clear();
	memset(cnt, 0, sizeof(cnt));
	ans = 0;
}

signed main(void) {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	int T; scanf("%lld", &T);
	while(T--) {
		++cas;
		Init();
		Work();
		if(T) Reset();
	}
//	Init();
//	Work();
}

