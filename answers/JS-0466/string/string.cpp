#include<bits/stdc++.h>
#define fir(a, b, c) for(int a = b; a <= c; ++ a)
#define ll long long
#define inf 1e8
using namespace std;

const int N = 2e6 + 10;
int T, n;
char a[N];
int f[100];
int ff[N], nxt[N];

int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d", &T);
	while (T--) {
		scanf("%s", a+1);
		ll ans = 0ll;
		n = strlen(a+1);
		fir (j, 0, 30) f[j] = 0;
		fir (j, 1, n) {
			++ f[a[j]-'a'];
			if (f[a[j]-'a'] & 1) ff[j] = ff[j-1]+1;
			else ff[j] = ff[j-1] - 1;
		}
		for (int i = n-1; i >= 2; -- i) {
			fir (j, 0, 30) f[j] = 0;
			int cnt = 0;
			fir (j, i+1, n) 
				f[a[j]-'a'] += 1;
			for (int j = 0; j <= 'z'-'a'; ++ j)
				if(f[j]&1) ++ cnt;
			
			fir (j, 1, (i+1)/2) {
				if (i%j != 0) continue;
				nxt[1] = 0;
				int len = i/j;
				if (j > 1) {
					for (int k = 2, o = 0; k <= len; ++ k) {
						while (o > 0 && a[k] != a[o+1]) o = nxt[o];
						if (a[k] == a[o+1]) ++ o;
						nxt[k] = o;
					}
					bool bl = 0;
					for (int k = 1, o = 0; k <= i; ++ k) {
						while (o > 0 && (o == len || a[o+1] != a[k])) o = nxt[o];
						if (a[o+1] == a[k]) ++ o;
						if (k % len == 0 && o != len) {
							bl = 1; break;
						}
					}
					memset(nxt, 0, (len+10)*4);
					if (bl) continue;
				}
				
				fir (k, 1, len-1) 
					if (ff[k] <= cnt) ans += 1ll;
			}
		}
		printf("%lld\n", ans);
		memset(ff, 0, (n+10)*4);
	}
	return 0;
}

