#include <bits/stdc++.h>
using namespace std;

inline long long calc(int n) {
	return n >> 1;
}

const int maxn = (1 << 20);

int cnt[44];
bool chk(string A, string C) {
	memset(cnt, 0, sizeof(cnt));
	int ca = 0;
	for (int i = 0; i < (int) A.size(); ++i)
		++cnt[A[i] - 'a'];
	for (int i = 0; i < 26; ++i) ca += cnt[i] % 2;
	memset(cnt, 0, sizeof(cnt));
	for (int i = 0; i < (int) C.size(); ++i)
		++cnt[C[i] - 'a'];
	int cc = 0;
	for (int i = 0; i < 26; ++i) cc += cnt[i] % 2;
	return ca <= cc;
}

string s;

void solve() {
	cin >> s;
	int n = (int) s.size();
	bool flg = 1;
	for (int i = 0; i < n; ++i) flg &= s[i] == s[0];
	if (flg == 0) {
		long long ans = 0;
		for (int i = 1; i <= n; ++i) {
			string A = s.substr(0, i);
			for (int j = n; j >= i; --j) {
				string C = s.substr(j - 1, n - j + 1);
				if (!chk(A, C)) continue;
				for (int k = i + 1; k < j; ++k) {
					string B = s.substr(i, k - i);
					string AB = A + B, tmp = AB;
					bool ok = true;
					if ((s.size() - C.size()) % AB.size() != 0) {
						ok = false;
					} else {
						while (AB.size() <= s.size() - C.size()) {
							if (AB != s.substr(0, AB.size())) { ok = false; break; }
							AB += tmp;
						}
					}
					/*
					if (ok) {
						cerr << "{\n";
						cerr << "AB: " << A << " " << B << '\n';
						cerr << "C: " << C << '\n';
						cerr << "}\n";
					}
					*/
					ans += ok;
				}
			}
		}
		cout << ans << '\n';
	} else {
		long long ans = 0;
		for (int i = 1; i <= n; ++i) {
			// |C| = i
			for (int j = 1; j * j <= n - i; ++j) if ((n - i) % j == 0) {
				int k = j;
				if (i % 2 == 0) ans += calc(k - 1);
				else ans += k - 1;
				int k1 = (n - i) / j;
				if (k1 != k) {
					if (i % 2 == 0) ans += calc(k1 - 1);
					else ans += k1 - 1;
				}
			}
		}
		cout << ans << '\n';
	}
}

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	int tt; cin >> tt; while (tt--) solve();
	return 0;
}
