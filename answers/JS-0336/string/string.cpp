#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = (1 << 20) + 5;
bool prime[N];
int q, n, nxt[N], h[26], sum2[N];
ll ans, sum1[N][27];
char st[N];
//inline void clear(){
//	ans = 0;
//	memset(nxt, 0, sizeof nxt);
//	memset(h, 0, sizeof h);
//	memset(sum1, 0, sizeof sum1);
//	memset(sum2, 0, sizeof sum2);
//}
inline void sieve(int maxn){
	for (int i = 2; i <= maxn; ++i){
		if (!prime[i]){
			for (int j = i; j <= maxn / i; ++j)
				prime[i * j] = 1;
		}
	}
}
inline void solve(){
	ans = 0;
	scanf(" %s", st + 1);
	n = strlen(st + 1);
//	clear();
	for (int i = 1; i <= n + 1; ++i){
		sum2[i] = nxt[i] = prime[i] = 0;
		for (int j = 0; j <= 26; ++j){
			sum1[i][j] = h[j] = 0;
		}
	}
	sieve(n);
	
	int tmp = 0;
	for (int i = 1; i <= n; ++i){
		h[st[i] - 'a'] ^= 1;
		tmp += h[st[i] - 'a'] ? 1 : -1;
		for (int j = 0; j <= 26; ++j){
			sum1[i][j] = sum1[i - 1][j];
			if (j >= tmp) ++sum1[i][j];
		}
	}
	tmp = 0;
	memset(h, 0, sizeof h);
	for (int i = n; i >= 1; --i){
		h[st[i] - 'a'] ^= 1;
		tmp += h[st[i] - 'a'] ? 1 : -1;
		sum2[i] = tmp;
	}
	
	nxt[1] = 0;
	for (int i = 2, j = 0; i < n; ++i){
		while (j > 0 && st[j + 1] != st[i]) j = nxt[j];
		if (st[j + 1] == st[i]) ++j;
		nxt[i] = j;
		int len, num;
		if (i % (i - nxt[i]) == 0){
			len = i - nxt[i], num = i / (i - nxt[i]);
		}else len = i, num = 1;
		int tot = sqrt(num);
		if (prime[num]){
			for (int k = 1; k <= tot; ++k)
				if (num % k == 0){
					ans += sum1[k * len - 1][sum2[i + 1]];
					if (k != num / k) ans += sum1[num / k * len - 1][sum2[i + 1]];
				}
		}else{
			ans += sum1[len - 1][sum2[i + 1]];
		}
	}
	
	printf("%lld\n", ans);
}
int main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	scanf(" %d", &q);
	while (q--) solve();
	return 0;
}

