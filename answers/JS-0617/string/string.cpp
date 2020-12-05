#include<bits/stdc++.h>
using namespace std;
template<typename T> inline void read(T &F) {
	F = 0; int R = 1; char CH = getchar();
	for(; !isdigit(CH); CH = getchar()) if(CH == '-') R = -1;
	for(; isdigit(CH); CH = getchar()) F = F * 10 + CH - 48;
	F *= R;
}
#define mod1 1000000007
#define mod2 1000000009
const int N = 1100000;
int ch[27], f[27], q[N], h[N]; long long res;
long long ny1[N], ny2[N], b1, b2, hs1[N], hs2[N];
long long Qpow(long long xi, long long qi, long long mod) {
	if(qi <= 1) return qi ? xi % mod : 1;
	long long hi = Qpow(xi, qi / 2, mod); hi = hi * hi % mod;
	if(qi & 1) return hi * xi % mod;
	else return hi; 
}
long long hash1(int l, int r) {
	if(l == 0) return hs1[r];
	return ((hs1[r] - hs1[l - 1]) * ny1[l] % mod1 + mod1) % mod1;
	
}
long long hash2(int l, int r) {
	if(l == 0) return hs2[r];
	return ((hs2[r] - hs2[l - 1]) * ny2[l] % mod2 + mod2) % mod2;
}
bool check(int l1, int r1, int l2, int r2) {
	return hash1(l1, r1) != hash1(l2, r2) || hash2(l1, r1) != hash2(l2, r2);
}
int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	int T; read(T);
	b1 = Qpow(27, mod1 - 2, mod1), b2 = Qpow(27, mod2 - 2, mod2);
	ny1[0] = ny2[0] = 1;
	for(int i = 1; i <= N - 1; i++)	
		ny1[i] = ny1[i - 1] * b1 % mod1, ny2[i] = ny2[i - 1] * b2 % mod2;
	while(T--) {
		string a;
		cin >> a; memset(ch, 0, sizeof(ch));
		memset(q, 0, sizeof(q));
		memset(h, 0, sizeof(h));
		memset(f, 0, sizeof(f));
		memset(hs1, 0, sizeof(hs1));
		memset(hs2, 0, sizeof(hs2));
		int n = a.length(); res = 0;
		long long bas1 = 1, bas2 = 1;
		for(int i = 0; i < n; i++) {
			ch[a[i] - 'a']++;
			if(ch[a[i] - 'a'] & 1) q[i] = q[i - 1] + 1;
			else q[i] = q[i - 1] - 1;
			if(i >= 1) {
				bas1 = bas1 * 27LL % mod1; bas2 = bas2 * 27LL % mod2;
				hs1[i] = (hs1[i - 1] + (a[i] - 'a') * 1LL * bas1 % mod1) % mod1;
				hs2[i] = (hs2[i - 1] + (a[i] - 'a') * 1LL * bas2 % mod2) % mod2; 
			}
			else hs1[i] = hs2[i] = (a[i] - 'a');
		//	cout << i << " " << q[i] << endl;
		}
		//cout << check(0, 1, 1, 2) << endl;
		memset(ch, 0, sizeof(ch));
		for(int i = n - 1; i >= 0; i--) {
			ch[a[i] - 'a']++;
			if(ch[a[i] - 'a'] & 1) h[i] = h[i + 1] + 1;
			else h[i] = h[i + 1] - 1;
		//	cout << i << " " << h[i] << endl;
		}
		for(int i = 2; i <= n; i++) {
			for(int j = q[i - 2]; j <= 26; j++) f[j]++;
			for(int j = 1; j <= n / i; j++) {
				if(i * j == n) continue;
				if(j >= 2 && check(0, i - 1, i * j - i, i * j - 1)) break;
				res += f[h[i * j]];
			}
		}
		cout << res << endl;
	}
	return 0;
}

