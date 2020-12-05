#include<bits/stdc++.h>
using namespace std;
string s;
int nxt[1<<20], len[1<<20], cnt[30];
int pre[1<<20], suf[1<<20], k[30];
void add(int x) {
	while (x <= 26) ++k[x], x += x & -x;
}
int query(int x) {
	int ans = 0;
	while (x) ans += k[x], x -= x & -x;
	return ans;
}
int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	int t;
	cin >> t;
	while (t--) {
		cin >> s;
		nxt[0] = -1;
		for (int i = 1, j = -1; i < (int)s.size(); i++) {
			while (j + 1 && s[j+1] != s[i]) j = nxt[j];
			if (s[j+1] == s[i]) ++j;
			nxt[i] = j;
			if (j+1 && (i+1)%(i-j) == 0) len[i] = i-j;
			else len[i] = i + 1;
		}
		int val = 0;
		for (int i = 0; i < (int)s.size(); i++) {
			int c = s[i] - 'a';
			if (cnt[c] & 1) --val;
			else ++val;
			++cnt[c], pre[i] = val;
		}
		val = 0;
		memset(cnt, 0, sizeof(cnt));
		for (int i = (int)s.size() - 1; i >= 0; i--) {
			int c = s[i] - 'a';
			if (cnt[c] & 1) --val;
			else ++val;
			++cnt[c], suf[i] = val;
		}
		memset(cnt, 0, sizeof(cnt));
		long long ans = 0;
		for (int i = 1; i < (int)s.size(); i++) {
			int v[2] = {-1,-1}, c[2] = {0,0}, now = 0;
			add(pre[i-1]+1);
			for (int j = i; j < (int)s.size()-1 && (i+1)%len[j] == 0; j += i+1) {
				if (v[now] == -1) v[now] = suf[j+1];
				++c[now], now ^= 1;
			}
			if (c[0]) ans += 1ll*c[0]*query(v[0]+1);
			if (c[1]) ans += 1ll*c[1]*query(v[1]+1);
		}
		memset(k, 0, sizeof(k));
		cout << ans << endl;
	}
}
