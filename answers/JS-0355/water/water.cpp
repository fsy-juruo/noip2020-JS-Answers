#include<bits/stdc++.h>
#define LL long long
using namespace std;
inline void read(int &x){
	x = 0;
	static int f; static char ch; f = 1,ch = getchar();
	while (!isdigit(ch)){ if (ch == '-') f = -1; ch = getchar(); }
	while (isdigit(ch)) x = x * 10 + ch - '0',ch = getchar();
	x *= f;
}
const int N = 100050;
const LL BASE = 10000;
struct Num{
	int a[11];
	inline void init(){ a[0] = a[1] = 1; }
	
	inline int mod2(){ return a[1] & 1; }
	inline int mod(int p){
		int res = 0;
		for (int i = a[0]; i ; --i) res = (res * BASE + a[i]) % p;
		return res;
	}
	inline bool zero(){ return a[0] == 1 && a[1] == 0; }
};
inline void print(Num &A){
	printf("%d",A.a[A.a[0]]);
	for (int i = A.a[0]-1; i ; --i) printf("%04d",A.a[i]);
}
Num operator + (Num A,Num B){
	static Num T; static int i; T = A;
	while (T.a[0] < B.a[0]) T.a[++T.a[0]] = 0;
	for (i = 1; i <= B.a[0]; ++i) T.a[i] += B.a[i];
	for (i = 1; i < T.a[0]; ++i) if (T.a[i] >= BASE) T.a[i+1] += T.a[i] / BASE,T.a[i] %= BASE;
	while (T.a[T.a[0]] >= BASE){
		++T.a[0]; T.a[T.a[0]] = T.a[T.a[0]-1] / BASE,T.a[T.a[0]-1] %= BASE;
	}
	return T;
}
Num operator * (Num A,int B){
	static Num T; static int i; T = A;
	for (i = 1; i <= T.a[0]; ++i) T.a[i] *= B;
	for (i = 1; i < T.a[0]; ++i) if (T.a[i] >= BASE) T.a[i+1] += T.a[i] / BASE,T.a[i] %= BASE;
	while (T.a[T.a[0]] >= BASE){
		++T.a[0]; T.a[T.a[0]] = T.a[T.a[0]-1] / BASE,T.a[T.a[0]-1] %= BASE;
	}
	return T;
}
Num operator / (Num A,int x){
	static Num T; static int i; T = A;
	for (i = T.a[0]; i ; --i){
		if (i > 1 && (T.a[i] % x)) T.a[i-1] += BASE * (T.a[i]%x); T.a[i] /= x;
	}
	while (T.a[0] > 1 && T.a[T.a[0]] == 0) --T.a[0];
	return T;
}
inline void work(Num &x,Num &y){
	if (x.zero()){ y.a[0] = 1,y.a[1] = 1; return; }
	while (x.mod2() == 0 && y.mod2() == 0) x = x / 2,y = y / 2;
	while (x.mod(3) == 0 && y.mod(3) == 0) x = x / 3,y = y / 3;
	while (x.mod(5) == 0 && y.mod(5) == 0) x = x / 5,y = y / 5;
}
Num llcm;
vector<int>fG[N];
inline void add(int x,int y){
	fG[y].push_back(x);
}
int deg[N],G[N][6];
int n,m;
Num dp[N]; int vis[N];
inline void DP(int x){
	if (vis[x]) return;
	if (x <= m){ dp[x] = llcm; vis[x] = 1; return; }
	vis[x] = 1,dp[x].a[0] = 1,dp[x].a[1] = 0;
	for (int i = 0; i < (int)fG[x].size(); ++i) DP(fG[x][i]),dp[x] = dp[x] + (dp[fG[x][i]] / deg[fG[x][i]]);
}
int main(){
	freopen("water.in","r",stdin); freopen("water.out","w",stdout);
	int i,j;
	llcm.init();
	for (i = 1; i <= 11; ++i) llcm = llcm * 4,llcm = llcm * 3,llcm = llcm * 5;
	read(n),read(m);
	for (i = 1; i <= n; ++i){
		read(deg[i]);
		for (j = 1; j <= deg[i]; ++j) read(G[i][j]),add(i,G[i][j]);
	}
	for (i = 1; i <= n; ++i) DP(i);
	Num a,b;
	for (i = 1; i <= n; ++i) if (!deg[i]){
		a = dp[i],b = llcm;
		work(a,b);
		print(a),putchar(' '),print(b),putchar('\n');
	}
	return 0;
}
