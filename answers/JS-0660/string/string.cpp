#include<bits/stdc++.h>
using namespace std;
char c[1100000];
int p[1100000];
int q[1100000];
int t[1100000];
int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	int T;
	cin >> T;
	while(T--) {
		string s;
		cin >> s;
		int l = s.size();
		for(int i = 1; i <= l; i++) {
			c[i] = s[i - 1];
		}
		memset(t, 0, sizeof(t));
		for(int i = 1; i <= l; i++) {
			t[c[i]]++;
			if(t[c[i]] & 1) p[i] = p[i - 1] + 1;
			else p[i] = p[i - 1] - 1;
		}
		memset(t, 0, sizeof(t));
		for(int i = l; i >= 1; i--) {
			t[c[i]]++;
			if(t[c[i]] & 1) q[i] = q[i + 1] + 1;
			else q[i] = q[i + 1] - 1;
		}
		string a = "", b;
		int ans = 0;
		for(int i = 1; i <= l - 2; i++) {
			a += c[i];
			b = "";
			for(int j = i + 1; j < l; j++) {
				b += c[j];
				if(a != b) {
					for(int k = 1; k <= (l - 1) / j; k++) {
						if(k & 1) {
							if(p[i] <= q[j * k + 1]) {
								ans++;
							}
						} else {
							ans ++;
						}
					}
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
}
