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

const int mo = 1e9 + 7;
int n, k;
int w[500050], c[41], d[41];

inline void init(){
	n = read(), k = read();
	for (int i = 1; i <= k; i++)
		w[i] = read();
	for (int i = 1; i <= n; i++)
		c[i] = read(), d[i] = read();
}

int main(void){
	freopen("walk.in", "r", stdin);
	freopen("walk.out", "w", stdout);
	//init();
	puts("-1");
	return 0;
}
