/*
fuck!
Œ“tm 
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int maxn = 1 << 17;
int T, n;
unsigned int cnt[maxn];
string s, t;
set<pair<pair<string, string>, string> > used;
void solve(){
	used.clear();
	cin>>s;
	s = " " + s;
	n = s.size() - 1;
	for(int i=1; i<=n; i++){
		cnt[i] = cnt[i - 1] ^ (1 << (s[i] - 'a'));
	}
	int ans = 0;
	for(int l=1; l<=n; l++){
		for(int i=l; i<=n; i++){
			for(int j=i+2; j<=n; j++){
				string A = s.substr(l, i - l + 1);
				string B = s.substr(i + 1, j - i - 1);
				string C = s.substr(j);
				int oddinA = __builtin_popcount(cnt[l - 1] ^ cnt[i]);
				int oddinC = __builtin_popcount(cnt[j - 1] ^ cnt[n]);
				if(oddinA <= oddinC){
					if(used.find(make_pair(make_pair(A, B), C)) != used.end()) continue;
					used.insert(make_pair(make_pair(A, B), C));
					ans ++;
				}
			}
		}		
	}
	cout<<(int)((ans + 1) / 2)<<endl;
}
int main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin>>T;
	while(T --) solve();
	return 0;
}


