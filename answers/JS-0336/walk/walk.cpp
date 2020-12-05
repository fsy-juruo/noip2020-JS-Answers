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
const int N = 5e5 + 5, M = 15, mod = 1e9 + 7;
int n, m, tmp, ans, s[M], a[M], h[M], w[M], c[N], d[N];
inline void work(){
	for (int i = 1; i <= m; ++i)
		a[i] = s[i];
	while (1){
		for (int i = 1; i <= n; ++i){
			a[c[i]] += d[i];
			++ans;
			if (a[c[i]] > w[c[i]] || a[c[i]] < 1) return;
		}
	}
}
void dfs(int dep){
	if (dep > m){
		work();
		return;
	}
	for (int i = 1; i <= w[dep]; ++i){
		s[dep] = i;
		dfs(dep + 1);
	}
}
int main(){
	freopen("walk.in", "r", stdin);
	freopen("walk.out", "w", stdout);
	read(n), read(m);
	for (int i = 1; i <= m; ++i)
		read(w[i]), tmp += w[i];
	for (int i = 1; i <= n; ++i){
		read(c[i]), read(d[i]);
		h[c[i]] += d[i];
	}
	
	int flag = 0;
	for (int i = 1; i <= m ;++i)
		if (h[i]) flag = 1;
	if (!flag){
		puts("-1"); return 0;	
	}
	
	dfs(1);
	
	printf("%d\n", ans);
	return 0;
}

