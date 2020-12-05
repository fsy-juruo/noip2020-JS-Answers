#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

inline LL read(){
	LL s = 0, w = 1;
	char ch = getchar();
	for (; ch < '0' || ch > '9'; ch = getchar()) if (ch == '-') w = -1;
	for (; ch >= '0' && ch <= '9'; ch = getchar()) s = s * 10 + ch - '0';
	return s * w;
}

const int MAXN = 100020;
int n, m;
int r[MAXN], c[MAXN];
vector <int> g[MAXN];
queue <int> q;
struct xcj{
	LL u, d;
}f[MAXN];

inline LL gcd(LL a, LL b){
	if (b == 0) return a;
	return gcd(b, a % b);
}

inline xcj yf(xcj a){
	//if (a.d == 0) return a;
	xcj ans;
	LL ggcd = gcd (a.u, a.d);
	ans.u = a.u / ggcd;
	ans.d = a.d / ggcd;
	return ans;
}

inline xcj add(xcj a, xcj b){
	if (a.u == 0 && a.d == 0) return b;
	//if (b.u == 0 && b.d == 0) return a;
	LL lcm = a.d * b.d / gcd(a.d, b.d);
	a.u *= (lcm / a.d);
	b.u *= (lcm / b.d);
	xcj ans;
	ans.u = a.u + b.u;
	ans.d = lcm;
	return yf(ans);
}

inline void print(xcj a){
	a = yf(a);
	printf("%lld %lld\n", a.u, a.d);
	return;
}

inline void init(){
	n = read(), m = read();
	for (int i = 1; i <= n; i++){
		c[i] = read();
		f[i].u = 0, f[i].d = 1;
		for (int j = 1; j <= c[i]; j++){
			int a = read();
			g[i].push_back(a);
			r[a]++;
		}
	}
	for (int i = 1; i <= n; i++){
		if (r[i] == 0){
			q.push(i);
			f[i].u = 1, f[i].d = 1;
		}
	}
}

inline void work(){
	while (!q.empty()){
		int x = q.front();
		q.pop();
		xcj a = f[x];
		a.d = a.d * c[x];
		for (int i = 0; i < c[x]; i++){
			int y = g[x][i];
			f[y] = add(f[y], a);
			r[y]--;
			if (r[y] == 0) q.push(y);
		}
	}
	
	for (int i = 1; i <= n; i++)
		if (c[i] == 0)
			print(f[i]);
}

int main(void){
	freopen("water.in", "r", stdin);
	freopen("water.out", "w", stdout);
	init();
	work();
	return 0;
}
