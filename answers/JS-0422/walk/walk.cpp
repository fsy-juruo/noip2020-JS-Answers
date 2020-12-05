#include<bits/stdc++.h>
using namespace std;
int n, k;
int w[11], st[11], tmp[11];
int c[500001], d[500001];
const int mod = 1e9 + 7;
typedef long long ll;
void getnext(){
	st[k]++;
	for(int i = k;i;i--){
		if(st[i] > w[i]){
			st[i] = 1;
			st[i-1]++;
		}
	}
}
void naive(){
	ll ans = 0, p = 1;
	for(int i = 1;i <= k;i++) p *= w[i], st[i] = 1;
	for(int i = 1;i <= p;i++){
		for(int j = 1;j <= k;j++){
			tmp[j] = st[j];
		}
		ll tot = 0;
		for(;;){
			bool ok = 1;
			for(int j = 1;j <= n;j++){
				tmp[c[j]] += d[j];
				tot++;
				if(tmp[c[j]] < 1 || tmp[c[j]] > w[c[j]]){
					ok = 0;
					break;
				}
			}
			if(!ok) break;
		}
		ans += tot;
		ans %= mod;
		getnext();
	}
	printf("%lld\n", ans % mod);
}
int main(){
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	scanf("%d %d", &n, &k);
	for(int i = 1;i <= k;i++){
		scanf("%d", &w[i]);
	}
	for(int i = 1;i <= n;i++){
		scanf("%d %d", &c[i], &d[i]);
	}
	naive();
	return 0;
}
