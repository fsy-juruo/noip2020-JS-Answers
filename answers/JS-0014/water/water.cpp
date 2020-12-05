#include <bits/stdc++.h>
using namespace std;
#define RG register
#define U(x, y, z) for (RG int x = y; x <= z; ++x)
#define D(x, y, z) for (RG int x = y; x >= z; --x)
template <typename T> inline void read(T &n){
	n = 0; char c; T f = 1;
	for (c = getchar(); !isdigit(c); c = getchar()) if (c == '-') f = -1;
	for (; isdigit(c); c = getchar()) n = (n << 1) + (n << 3) + (c ^ 48);
	n *= f;
}
template <typename T> inline void write(T n){
	if (n < 0){
		putchar('-');
		n = -n;
	}
	if (n > 9) write(n / 10);
	putchar(n % 10 + '0');
}
template <typename T> inline void writesp(T n){
	write(n);
	putchar(' ');
}
template <typename T> inline void writeln(T n){
	write(n);
	putchar('\n');
}
inline void FO(string s){
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}
#define N 100010
int n, m, tot;
int ind[N];
#define ll long long
vector <int> e[N];
#define pll pair<ll, ll>
#define mp make_pair
pll dp[N];
inline ll gcd(ll a, ll b){
	if (b == 0) return a;
	return gcd(b, a % b);
}
inline void add(pll &a, pll b){
	pll x;
	x.first = a.first * b.second + b.first * a.second;
	x.second = a.second * b.second;
	ll g = gcd(x.first, x.second);
	x.first /= g;
	x.second /= g;
	a = x;
}
inline void bfs(){
	queue <int> Q;
	U(i, 1, m)
		Q.push(i);
	while (!Q.empty()){
		int u = Q.front();
		int cnt = e[u].size();
		Q.pop();
		pll w = dp[u];
		w.second *= cnt;
		for (int i = 0; i < cnt; ++i){
			int v = e[u][i];
			if (dp[v].first) add(dp[v], w);
			else dp[v] = w;
			--ind[v];
			if (!ind[v]) Q.push(v);	
		}
	}
}
int main(){
	FO("water");
	read(n), read(m);
	U(i, 1, m)
		dp[i].first = dp[i].second = 1;
	U(i, 1, n){
		int c;
		read(c);
		U(j, 1, c){
			int v;
			read(v);
			e[i].push_back(v);
			ind[v]++;
		}
	}
	bfs();
	U(i, 1, n){
		int cnt = e[i].size();
		if (!cnt){
			long long g = gcd(dp[i].first, dp[i].second);
			writesp(dp[i].first / g);
			writeln(dp[i].second / g);
		}
	}
	return 0;
}
/*
5 1
3 2 3 5
2 4 5
2 5 4
0 
0
*/
