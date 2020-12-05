#include <bits/stdc++.h>
using namespace std;
namespace base{
	template<class T>inline void read(T&n){
		n = 0; T f = 1; char ch = 0;
		for (; ch < '0' || ch > '9'; ch = getchar()) if (ch == '-') f = -f;
		for (; ch >= '0' && ch <= '9'; ch = getchar()) n = (n << 1) + (n << 3) + (ch ^ 48);
		n *= f;
	}
	template<class T>inline void write(T n, char ch){
		if (n == 0) putchar('0');
		if (n < 0) n = -n, putchar('-');
		static char buf[233]; int tmp = 0;
		for (; n; n /= 10) buf[++tmp] = n % 10 + 48;
		for (; tmp; --tmp) putchar(buf[tmp]);
		putchar(ch);
	}
}
using namespace base;
typedef long long ll;
const int N = 1e5 + 5;
struct Edge{
	int v, nxt;	
}E[N * 5];
int n, m, tot;
int hd[N], deg[N], degree[N];
ll sum[N], MAXN = 1;
queue<int> qq;
ll gcd(ll x, ll y){
	return y ? gcd(y, x % y) : x;
}
inline void add(int u, int v){
	E[++tot] = (Edge){v, hd[u]}, hd[u] = tot;
}
void topsort(){
	for (int i = 1; i <= m; ++i)
		sum[i] = MAXN, qq.push(i);
	while (qq.size()){
		int u = qq.front(); qq.pop();
		for (int i = hd[u]; i; i = E[i].nxt){
			int v = E[i].v;
			sum[v] += sum[u] / deg[u];
			degree[v]--;
			if (!degree[v]) qq.push(v);
		}
	}
}
int main(){
	freopen("water.in", "r", stdin);
	freopen("water.out", "w", stdout);
	read(n), read(m);
	for (int i = 1; i <= 11; ++i)
		MAXN = MAXN * 3 * 5;
	for (int i = 1; i <= 8; ++i)
		MAXN = MAXN * 4;
	for (int i = 1, tmp; i <= n; ++i){
		read(tmp);
		for (int j = 1, x; j <= tmp; ++j){
			read(x);
			add(i, x);
			degree[x]++;
		}
		deg[i] = tmp;
	}
	
	topsort();
	
	for (int i = 1; i <= n; ++i){
		if (!deg[i]){
			ll x = sum[i], y = MAXN;
			ll GCD = gcd(x, y);
			write(x / GCD, ' '), write(y / GCD, '\n');
		}
	}
	return 0;
}

