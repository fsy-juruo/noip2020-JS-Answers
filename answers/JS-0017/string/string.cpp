#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define per(i, a, b) for (int i = a; i >= b; i--)

typedef long long ll;
using namespace std;
map <char, int> h[2000010];
int jif[2000010], jib[2000010];

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	int _; scanf("%d", &_);
	while (_--) {
		string s; cin >> s;
		int n = s.length();
		for (char j = 'a'; j <= 'z'; j++) h[j].clear();
		rep(i, 0, n-1) {
			jif[i] = jib[i] = 0;
			for (char j = 'a'; j <= 'z'; j++) {
				if (j != s[i]) {
					if (i == 0) h[j][i] = 0;
					else h[j][i] = h[j][i-1];
				} else {
					if (i == 0) h[j][i] = 1;
					else h[j][i] = h[j][i-1]+1;
				}
				if (h[j][i]&1) jif[i]++;
			}
		}
		per(i, n-1, 0) {
			for (char j = 'a'; j <= 'z'; j++) {
				int s = h[j][n-1];
				if (i > 0) s -= h[j][i-1];
				if (s&1) jib[i]++;
			}
		}
//		rep(i, 0, n-1) printf("%d ", jif[i]);
//		puts("");
//		rep(i, 0, n-1) printf("%d ", jib[i]);
//		puts("");
		ll ans = 0;
		rep(i, 2, n-1) {
			//C:i~n-1  AB:0~i-1
//			printf("%d |", i);
			string s1 = s.substr(0, i);
			int k = 0;
			while (true) {
//				printf("%d (", k);
				if (k+i > n-1) break;
				string s2 = s.substr(k, i);
				k += i;
				if (s2 == s1) {
					//C:k~n-1
//					string C = s.substr(k, n-k);
					int cji = jib[k];
					rep(j, 0, i-2) {
						if (jif[j] <= cji) ans++;
//						printf("%d ", j);
					}
				}
				else break;
//				printf(")");
			}
//			printf("| %d", ans);
//			puts("");
		}
		printf("%lld\n", ans);
	}
	return 0;
}

