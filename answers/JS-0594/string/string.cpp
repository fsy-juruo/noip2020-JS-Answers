#include<bits/stdc++.h>
using namespace std;
const int N = 1e3 + 50;
typedef long long ll;
inline int read() {
	int f=1,x=0;char ch=getchar();
	for(; !isdigit(ch); ch=getchar()) if(ch=='-') f=0;
	for(; isdigit(ch); ch=getchar()) x=x*10+ch-'0';
	return f?x:-x;
}

int T;
int n;
string s;
string _cut[N];
ll t[N][N];
bool f[N][N];//AB_end->i C_begin->j
ll sum1[N], sum2[N];
ll tot1[27], tot2[27];

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	T = read();
	while(T --) {
		cin >> s;
		n = s.size();
		memset(sum1, 0, sizeof(sum1));
		memset(sum2, 0, sizeof(sum2));
		memset(tot1, 0, sizeof(tot1));
		memset(tot2, 0, sizeof(tot2));
		memset(f, 0, sizeof(f));
		memset(t, 0, sizeof(t));
		for(int i = 0; i < n; i ++) {
			tot1[(int)(s[i]-'a')] ++;
			for(int j = 0; j <= 25; j ++)
				if(tot1[j]%2) {
					sum1[i] ++;	
				} 
		}
		for(int i = n-1; i >= 0; i --) {
			tot2[(int)(s[i]-'a')] ++;
			for(int j = 0; j <= 25; j ++)
				if(tot2[j]%2) {
					sum2[i] ++;
				} 
		}
		for(int i = 0; i < n; i ++)
			_cut[i].clear();
		for(int i = 0; i < n; i ++)
			for(int j = 0; j <= i; j ++)
				_cut[i] += s[j];
		string now; 
		for(int i = 0; i < n; i ++) {
			now += s[i];
			f[i][i+1] = 1;
			string _new = now;
			int j = _new.size(); 
			for(; j < n; ) {
				_new += now;
				j = _new.size();
				if(j > n) break;
				if(_new != _cut[j-1]) break;
				f[i][j] = 1; 
			}
		}
		for(int j = 0; j < n; j ++) {
			for(int i = 0; i < j; i ++)
				t[i][j] = t[i-1][j]+f[i][j];
		}
		ll ans = 0;
		for(int i = n-1; i >= 0; i --) {//C
			for(int j = 0; j <= i-1; j ++) {//A
				if(sum1[j] <= sum2[i]) {
					/*for(int k = j+1; k < i; k ++) {//B
						if(f[k][i]) {
							ans ++;
						}
					}*/
					ans += t[i-1][i]-t[j][i];
				}
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
}

