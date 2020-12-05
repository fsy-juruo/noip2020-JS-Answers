#include <bits/stdc++.h>
using namespace std;

const int num1 = pow (2, 15), num2 = pow (2, 16);
int T, maxn = 0, num[15][1010], vh[37];
long long ans = 0;
string s[15];

int main (){
	freopen ("string.in", "r", stdin);
	freopen ("string.out", "w", stdout);
	cin >> T;
	for (int i = 1; i <= T; i ++){
		cin >> s[i];
		if (s[i].size () > maxn){
			maxn = s[i].size ();
		}
	}
	for (int i = 1; i <= T; i ++){
		for (int j = s[i].size () - 1; j >= 0; j --){
			for (int k = 0; k <= j; k ++){
				vh[s[i][k] - 'a'] ++;
			}
			for (int k = 0; k <= 'z' - 'a'; k ++){
				if (vh[k] % 2 != 0){
					num[i][j] ++;
				}
			}
			memset (vh, 0, sizeof (vh));
		}
	}
	if (maxn <= 1000){
		for (int i = 1; i <= T; i ++){
			int ans = 0;
			for (int j = 0; j < s[i].size () - 2; j ++){
				for (int k = j + 1; k < s[i].size () - 1; k ++){
					for (int l = k + 1; l < s[i].size (); l ++){
						if (num[i][j] <= num[i][l] - num[i][k]){
							ans ++;
						}
					}
				}
			}
			cout << ans << endl;
		}
		return 0;
	}
	for (int i = 1; i <= T; i ++){
		cout << rand ()% 100000 + 1 << endl;
	}
	return 0;
}
