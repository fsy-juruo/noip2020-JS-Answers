#include <bits/stdc++.h>
#define N (int) 405
using namespace std;
int n, m;

int stk[N][N], top[N];

void Subtask1 () {
	while (true) {
		for (int i = 1; i <= 2; i ++) {
			while (stk[i][top[i]] == 1) stk[3][++ top[3]] = 1, top[i] --, cout << i << " " << 3 << endl;
		}
		for (int i = 1; i <= 2; i ++) {
			if (stk[i][top[i]] == 2) {while (stk[i][top[i]] == 2) stk[3-i][++ top[3-i]] = 1, top[i] --, cout << i << " " << 3-i << endl; break;}
		}
		
		bool flg = true;
		for (int i = 1; i <= 3; i ++) {
			if (top[i] != m && top[i] != 0) {
				flg = false;
				break;
			}
			int col = stk[i][top[i]];
			for (int j = 1; j <= top[i]; j ++) if (col != stk[i][j]) flg = false;
		}
		if (flg) break;
	}
}

int main () {
	freopen ("ball.in", "r", stdin);
	freopen ("ball.out", "w", stdout);
	
	cin >> n >> m;
	for (int i = 1; i <= n; i ++) {
		for (int j = 1; j <= m; j ++) {
			cin >> stk[i][++ top[i]];
		}
	}
	
	if (n <= 2) Subtask1 ();
	
	return 0;
}
