#include <bits/stdc++.h>
#define N 1050000
using namespace std;
int t, zg[26], p[N], g[26][N], l[26];
int zf[26], b, c, f;
long long sum[N], ans;
string s;
int main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> t;
	while(t--){
		cin >> s; int sl = s.length(); s = " " + s; 
		memset(zg, 0, sizeof(zg)); memset(zf, 0, sizeof(zf)); memset(p, 0, sizeof(p)); memset(l, 0, sizeof(l));
		memset(g, 0, sizeof(g)); memset(sum, 0, sizeof(sum)); ans = b = c = f = 0;
		for(int i = 1; i <= sl; ++i) sum[i] = sum[i - 1] + (s[i] - '0') * 13331;
		for(int i = sl; i >= 1; --i){
			int u = s[i] - 'a';
			zg[u]++;
			p[i] = p[i + 1];
			if(zg[u] % 2 == 1){
				++c;
				++p[i];
			}
			else{
				--c;
				--p[i];
			} 
			for(int j = 0; j < 26; ++j) g[j][i] = g[j][i + 1];
			for(int j = c; j >= 0; --j) g[j][i]++;
		} 
		for(int i = 1; i <= sl - 2; ++i){
			int u = s[i] - 'a';
			zf[u]++;
			if(zf[u] % 2 == 1) ++b;
			else --b;
			ans += g[b][i + 2];
			if(i > 1){
				for(int j = i + 1; j <= sl - 2; j += i){
					if(sum[j + i - 1] - sum[j - 1] != sum[i]) break;
					else if(j + i <= sl){
						ans += l[p[i + j]];
					}
				}
			}
			
			for(int j = b; j < 26; ++j) l[j]++; 
		}
		printf("%lld\n", ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
