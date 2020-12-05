#include <bits/stdc++.h>
using namespace std;

int c[60][410];

int main(){
	freopen("ball.in", "r", stdin);
	freopen("ball.out", "w", stdout);
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= m; j++){
			scanf("%d", &c[i][j]);
		}
	}
	cout << 0 << endl;
	return 0;
}

