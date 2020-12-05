#include <bits/stdc++.h>
using namespace std;
const int maxn = 1048576 + 10;
int T, n, sum[30], num[maxn];
char c[maxn];
string s;
bool check(int x, int y) {
	int k = x / y;
	for (int i = 1; i < k; i++) {
		for (int j = 1; j <= y; j++) {
			if (c[j + y * (i - 1)] != c[j + y * i]) {
				return 0;
			}
		}
	}
	return 1;
}
int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> T;
	while (T--) {
		cin >> s;
		n = s.size();
		for (int i = 1; i <= n; i++) {
			c[i] = s[i - 1];
		}
		memset(sum, 0, sizeof(sum));
		memset(num, 0, sizeof(num));
		for (int i = 1; i <= n; i++) {
			sum[c[i] - 'a']++;
			if (sum[c[i] - 'a'] & 1) {
				num[i] = num[i - 1] + 1;
			} else {
				num[i] = num[i - 1] - 1;
			}
		}
		memset(sum, 0, sizeof(sum));
		int tot = 0, ans = 0;
		for (int i = n; i >= 3; i--) {
			sum[c[i] - 'a']++;
			if (sum[c[i] - 'a'] & 1) {
				tot++;
			} else {
				tot--;
			}
			for (int j = 1; j < i - 1; j++) {
				if (num[j] <= tot) {
					for (int k = 1; k * k <= i - 1; k++) {
						if ((i - 1) % k == 0) {
							int a = (i - 1) / k, b = k;
							if (a == b) {
								b = 0;
							}
							if (j < a) {
								if (check(i - 1, a)) {
									ans++;
								}
							}
							if (j < b) {
								if (check(i - 1, b)) {
									ans++;
								}
							}
						}
					}
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
}

