#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;
bool f = true;
int n, k, d[50010], c[50010], w[20], sum = 0, step = 0;

void work2 (int p, int i, int j){
	if (i == 0 || i == n + 1 || j == 0 || j == n + 1){
		return ;
	}
	if (p == n + 1 && i > 0 && i <= n && j > 0 && j <= n){
		work2 (1, i, j);
	}
	if (p <= n){
		step ++;
		if (c[p] == 1){
			work2 (p + 1, i + c[p], j);
		}
		if (c[p] == 2){
			work2 (p + 1, i, j + c[p]);
		}
	}
}

int main (){
	freopen ("walk.in", "r", stdin);
	freopen ("walk.out", "w", stdout);
	cin >> n >> k;
	for (int i = 1; i <= k; i ++){
		cin >> w[i];
	}
	for (int i = 1; i <= n; i ++){
		cin >> c[i] >> d[i];
	}
	if (k == 1){
		for (int i = 1; i <= n; i ++){
			sum = w[1] * n;
		}
		cout << sum << endl;
		return 0;
	}
	if (n <= 100){
		if (k == 2){
			for (int i = 1; i <= w[1]; i ++){
				for (int j = 1; j <= w[2]; j ++){
					work2 (1, i, j);
					cout << step << endl;
					sum += step;
					sum %= MOD;
					step = 0;
				}
			}
			cout << sum << endl;
		}
		return 0;
	}
	cout << -1 << endl;
	fclose (stdin);
	fclose (stdout);
	return 0;
}
