#include <stdio.h>
#include <iostream>
#include <string.h>
#include <string>
using namespace std;

const int MAXS = 1100000, MAXTYPE = 26;
int t, vh[MAXTYPE], cnts_front[MAXS], cnts_back[MAXS], ans;
string str;

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	
	cin >> t;
	for (int i = 0; i < t; i++) {
		ans = 0;
		
		cin >> str;
		int len = str.size();
		
		memset(vh, 0, sizeof(vh));
		cnts_front[0] = 1; vh[str[0] - 'a']++;
		for (int j = 1; j < len - 2; j++) {
			vh[str[j] - 'a']++;
			if (vh[str[j] - 'a'] % 2 == 0) cnts_front[j] = cnts_front[j - 1] - 1;
			else cnts_front[j] = cnts_front[j - 1] + 1;
		}
		
		memset(vh, 0, sizeof(vh));
		cnts_back[len - 1] = 1; vh[str[len - 1] - 'a']++;
		for (int j = len - 2; j >= 2; j--) {
			vh[str[j] - 'a']++;
			if (vh[str[j] - 'a'] % 2 == 0) cnts_back[j] = cnts_back[j + 1] - 1;
			else cnts_back[j] = cnts_back[j + 1] + 1;
		}
		
		for (int i = 0; i < len - 2; i++) {
			for (int j = len - 1; j >= 2; j--) {
				if (i + 2 <= j && cnts_front[i] <= cnts_back[j]) {
					for (int k = i + 1; k < j; k++) {
						if (j % (k + 1) == 0) {
							bool flag = true;
							for (int q = k + 1; q < j; q += (k + 1)) {
								if (str.substr(0, k + 1) != str.substr(q, k + 1)) {
									flag = false;
									break;
								}
							}
							if (flag) ans++;
						}
					}
				}
			}
		}
		
//		cnts_below[0][0] = 0;
//		for (int j = 1; j < MAXTYPE; j++) {
//			cnts_below[j][0] = 1;
//		}
//		for (int j = 1; j < len - 2; j++) {
//			for (int k = 0; k < MAXTYPE; k++) {
//				if (k >= cnts_front[j]) cnts_below[k][j] = cnts_below[k][j - 1] + 1;
//				else cnts_below[k][j] = cnts_below[k][j - 1];
//			}
//		}
//		
//		for (int j = len - 1; j >= 2; j--) {
//			ans += cnts_below[cnts_back[j]][j - 2];
//		}
		
		cout << ans << endl;
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
