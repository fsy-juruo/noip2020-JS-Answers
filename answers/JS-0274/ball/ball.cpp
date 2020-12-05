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

int n, m;
int g[55][410];

inline void init(){
	n = read(), m = read();
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= m; j++){
			g[i][j] = read();
		}
	}
}

inline void work1(){
	int f1 = g[1][1], f2 = g[2][2], f;
	int n1, n2, n0, s;
	for (int i = 1; i <= n; i++){
		if (g[1][i] != f1){
			n1 = i;
			break;
		}
	}
	for (int i = 1; i <= n; i++){
		if (g[2][i] != f2){
			n2 = i;
			break;
		}
	}
	if (n1 > n2) f = f1, n0 = n1, s = 1;
	else f = f2, n0 = n2, s = 2;
	for (int i = 1; i <= n; i++){
		
	}
}

int main(void){
	freopen("ball.in", "r", stdin);
	freopen("ball.out", "w", stdout);
	init();
	if (n == 2) work1();
	return 0;
}
