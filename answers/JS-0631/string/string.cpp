#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn = 1e6;
inline int read(){
	int x = 0, f = 1; char ch = getchar();
	for(; !isdigit(ch); ch = getchar()) if(ch == '-') f = -f;
	for(; isdigit(ch); ch = getchar()) x = (x << 3) + (x << 1) + ch - '0';
	return x * f;
}
int n, len;
string s;
int cnt[1500][30];//到第i位j出现的个数 
int F(int x, int y){
	int sum = 0;
	for(int i = 'a'; i <= 'z'; i ++)
	if((cnt[y][i - 'a'] - cnt[x - 1][i - 'a']) & 1) sum ++;
	return sum;
}
void solve(){
	ll ans = 0;
	len = s.size() - 1;
	for(int i = 1; i <= len; i ++){//扫描到第i位 
		for(int j = 'a'; j <= 'z'; j ++) cnt[i][j - 'a'] = cnt[i - 1][j - 'a'];
		cnt[i][s[i] - 'a'] ++;
	}
	for(int i = 3; i <= len; i ++){//C : 3 - len
		for(int j = 1; j < i - 1; j ++){// A : 1 - j
			if(F(1, j) > F(i, len)) continue;			
			for(int k = j + 1; k < i; k ++){
				string w = s.substr(1, i - 1);
				string p = s.substr(1, k);
				string d = p;
				while(d.length() <= w.length()) {
					if(d == w){
						ans ++;
						break;
					} 
					else d = d + p;
				}
			}
		}
	}	
	printf("%lld\n", ans);
	return;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	n = read();
	for(int i = 1; i <= n ;i ++){
		string t;s = "A";
		cin >> t; s = s + t;
		solve();
	}
	return 0;
}

