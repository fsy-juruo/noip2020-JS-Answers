#include<bits/stdc++.h>
#define LL long long
using namespace std;
inline void read(int &x){
	x = 0;
	static int f; static char ch; f = 1,ch = getchar();
	while (!isdigit(ch)){ if (ch == '-') f = -1; ch = getchar(); }
	while (isdigit(ch)) x = x * 10 + ch - '0',ch = getchar();
	x *= f;
}
inline char Get(){
	static char c; c = getchar();
	while (!isalpha(c) && c != '\n' && c != EOF) c = getchar();
	return c;
}

const int N = (1<<20) + 5;
int n,z[N]; char s[N];

int now[500],cntt;
inline void init(){ memset(now,0,sizeof(now)),cntt = 0; }
inline void add(int x){ cntt -= now[x],now[x] ^= 1,cntt += now[x]; }

int f[N],g[N],pref[N][27]; LL ans;
inline void solve(){
	int i,j; char ch; n = 0; ans = 0;
	while (!isalpha(ch = Get())) ; s[n=0] = ch;
	while (isalpha(ch = Get())) s[++n] = ch;
	
	init(); for (i = 0; i <= n; ++i) add(s[i]),f[i] = cntt;
	init(); for (i = n; i >= 0; --i) add(s[i]),g[i] = cntt;
	for (i = 0; i <= n; ++i) memset(pref[i],0,sizeof(pref[i]));
	for (i = 0; i <= n; ++i) ++pref[i][f[i]];
	for (i = 0; i <= n; ++i) for (j = 1; j <= 26; ++j) pref[i][j] += pref[i][j-1];
	for (i = 1; i <= n; ++i) for (j = 0; j <= 26; ++j) pref[i][j] += pref[i-1][j];
	
	z[0] = 0;
	int mx = -1,mxi = 0;
	for (i = 1; i <= n; ++i){
		z[i] = 0;
		if (i < mx) z[i] = min(z[i-mxi],mx-i);
		while (s[z[i]] == s[i+z[i]]) ++z[i];
		if (i + z[i] > mx) mx = i+z[i],mxi = i;
	//	cerr << z[i] << ' ' ;
	}
//	cerr<<'\n';
	ans = 0;
	int len;
	for (i = 1; i < n; ++i){
		j = i,len = i+1;
		while (j < n){
			ans += pref[i-1][g[j+1]];
			if (z[j+1] >= len) j += len; else break;
		}
	//	cerr << i << ' ' << ans << '\n';
	}
	cout << ans << '\n';
}

int main(){
	freopen("string.in","r",stdin); freopen("string.out","w",stdout);
	int T;
	read(T);
	while (T--) solve();
	return 0;
}
