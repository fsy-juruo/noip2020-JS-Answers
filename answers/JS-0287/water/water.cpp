#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

#define dbg(x) cerr << #x << " = " << x << endl
template<typename T>void chkmin(T &a, T b){ a = min(a, b); }
template<typename T>void chkmax(T &a, T b){ a = max(a, b); }

const int MAXN = 2e5 + 10;
const int MAXM = 3e6 + 10;
#define int long long
int fread(void){
	char ch = getchar(); int ret = 0, opt = 1;
	for(; !isdigit(ch); ch = getchar()) if(ch == '-') opt = -1;
	for(; isdigit(ch); ch = getchar()) ret = ret * 10 + ch - '0';
	return  ret * opt;
}

int gcd(int x, int y){
	if(y == 0) return x;
	return gcd(y, x % y);
}
struct Frac{
	int up, dwn;
	void Div(void){
		int g = gcd(up, dwn); up /= g, dwn /= g;
	}
	Frac(){ up = 0, dwn = 1; }
	Frac(int _up, int _dwn) : up(_up), dwn(_dwn) {}
	Frac operator + (const Frac &b){
		Frac ret; ret.dwn = dwn / gcd(dwn, b.dwn) * b.dwn;
		ret.up = up * (ret.dwn / dwn) + b.up * (ret.dwn / b.dwn);
		ret.Div();
		return ret;
	}
	Frac operator / (const int &b){
		Frac ret = (*this);
		ret.dwn *= b; ret.Div();
		return ret;
	}
}f[MAXN];

int head[MAXN], nxt[MAXM], to[MAXM], ind, out[MAXN], deg[MAXN];
inline void add_edge(int u, int v){
	nxt[++ ind] = head[u]; head[u] = ind; to[ind] = v; out[u]++; deg[v] ++;
}
int n, m;
inline void init(void){
	n = fread(), m = fread();
	int d, v;
	for(int u = 1; u <= n; ++ u){
		d = fread();
		for(int i = 1; i <= d; ++ i){
			v = fread(); add_edge(u, v);
		}
	}
}
queue<int>Q;
void Topsort(void){
	for(int i = 1; i <= m; ++ i) Q.push(i), f[i] = Frac(1, 1); 
	while(!Q.empty()){
		int u = Q.front(); Q.pop();
		for(int i = head[u]; i; i = nxt[i]){
			int v = to[i];
			f[v] = f[v] + f[u] / out[u];
			deg[v]--;
			if(!deg[v]) Q.push(v);
		}
	}
}
inline void work(void){
	Topsort();
	for(int i = 1; i <= n; ++ i){
		if(!out[i]) printf("%lld %lld\n", f[i].up, f[i].dwn);
	}
}
#undef int
int main(){
	freopen("water.in", "r", stdin); freopen("water.out", "w", stdout);
	init(); work();
	fclose(stdin); fclose(stdout);
	return 0;
}

