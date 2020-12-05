#include<bits/stdc++.h>
#define fox(i,a,b) for(register int i=a;i<=b;++i)
#define ll long long
using namespace std;

const int N = (1 << 20) + 10, P1 = 89, P2 = 998344353;
int n, hs[N], nm[30], pw[N], nd[N], T;
char s[N];
ll ans, sum[28][N];

inline int up(int x) {return x < 0 ? x + P2 : x;}

inline int _hash(int l, int r) {
	int res = up(hs[r] - 1LL * hs[l - 1] * pw[r - l + 1] % P2);
	return res;
}

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	pw[0] = 1;
	fox (i, 1, N - 10) pw[i] = (1LL * pw[i - 1] * P1) % P2;
	for (scanf("%d", &T); T--;) {
		scanf("%s", s + 1);
		n = strlen(s + 1);
		
		int p, g = 0;
		fox (i, 1, 26) nm[i] = 0;
		fox (i, 1, n) {
			++nm[p = s[i] - 96];
			nm[p] & 1 ? ++g : --g;
			fox (j, 0, 26) sum[j][i + 1] = sum[j][i];
			fox (j, g, 26) ++sum[j][i + 1];
			
			hs[i] = (1LL * hs[i-1] * P1 + p) % P2;
		}
		
		g = 0;
		fox (i, 1, 26) nm[i] = 0;
		for (register int i = n; i; --i) {
			++nm[p = s[i] - 96];
			nm[p] & 1 ? ++g : --g;
			nd[i] = g;
		}
		
		int t = 0;
		for (register int i = n; i; --i) {
			p = _hash(1, i);
			for(register int j = i + 1; j <= n - i + 1; j += i) {
				if (_hash(j, j + i - 1) == p) {
					sum[nd[j+i]][j+i-1] += sum[nd[j+i]][i], ++t;
					continue;
				} break;
			}
		}
		//cout << t << endl;
		
		ans = 0;
		fox (i, 3, n) 
			ans += sum[nd[i]][i-1];
		printf("%lld\n", ans);
		
		fox (i, 1, n) s[i] = 0;
	}
	return 0;
}

