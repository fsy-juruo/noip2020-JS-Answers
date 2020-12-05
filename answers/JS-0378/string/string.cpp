#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 2e6 + 5;

char s[MAXN];
int f[MAXN];
int g[MAXN];//最小循环节 
int cnt[999];
int geshu[MAXN], geshu_qian[MAXN];

int t;
int a[MAXN], ss[MAXN];

int main() {
freopen("string.in", "r", stdin);
freopen("string.out", "w", stdout);
//	freopen("test.in", "r", stdin);
//	freopen("biao.txt", "w", stdout);
//	cout << "int biao[] = {0, ";
//	freopen("string4.in", "r", stdin);
	cin >> t;
	while (t--) {
		cin >> s + 1;
		int n = strlen(s + 1);
		for (int i = 1; i <= n; ++i)
			f[i] = g[i] = 0;
		for (int i = 2; i <= n; ++i) {
			int j = f[i - 1];
			while (j != 0 && s[i] != s[j + 1]) j = f[j];
			if (s[i] == s[j + 1]) j++;
			f[i] = j;
		}
		for (int i = 1; i <= n; ++i) {
			if (f[i] == 0) continue;
			if (i % (i - f[i]) == 0) g[i] = i - f[i];
		} 
	//	for (int i = 1; i <= n; ++i)
	//		cout << g[i] << ' ';
		for (int i = 'a'; i <= 'z'; ++i) cnt[i] = 0;
		geshu[n + 1] = 0;
		for (int i = n; i >= 1; --i) {
			geshu[i] = geshu[i + 1];
			cnt[s[i]]++;
			if (cnt[s[i]] & 1) geshu[i]++;
			else geshu[i]--;
		}
		
		for (int i = 'a'; i <= 'z'; ++i) cnt[i] = 0;
		geshu_qian[0] = 0;
		for (int i = 1; i <= n; ++i) {
			geshu_qian[i] = geshu_qian[i - 1];
			cnt[s[i]]++;
			if (cnt[s[i]] & 1) geshu_qian[i]++;
			else geshu_qian[i]--;
		}
		ll ans = 0;
		for (int i = 2; i < n; ++i) {
			int c = geshu[i + 1];
			for (int j = 1; j < i; ++j) {
				if (geshu_qian[j] <= c) a[j] = 1;
				else a[j] = 0;
				ss[j] = ss[j - 1] + a[j];
			}
			if (g[i] == 0) {
				ans += ss[i - 1];
			//	cout << "g" << i << '=' << 0 << endl;
			//	cout << ss[i - 1] << endl;
				continue;
			}
			for (int j = 1; j <= i; ++j) {
				if ((i / g[i]) % j) continue;
				ans += ss[i / j - 1];
			//	cout << i << ' ';
			//	cout << "div to " << j << ' ';
			//	cout << ss[i / j - 1] << endl;
			}
		}
		cout << ans << "\n";
	//	biao[++ddd] = ans;
	}
//	freopen("biao.txt", "w", stdout);
//	cout << "int biao[] = {0, ";
//	for (int i = 1; i <= ddd; ++i) {
//		cout << biao[i] << ", ";
//	}
	
	return 0;
}

