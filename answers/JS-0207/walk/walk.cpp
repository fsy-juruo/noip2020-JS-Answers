#include<bits/stdc++.h>
using namespace std;
#define c first
#define d second
const int MAXN = 5e5 + 200;
const int MAXK = 10 + 5;
const int MOD = 1e9 + 7;
typedef pair <int, int> Pii;
Pii walk[MAXN];
int w[MAXK], st[MAXK], maxn[MAXK], minn[MAXK], one[MAXK];
int n, k, ans, cnt;
bool ff = true;
bool check(){
	++ cnt;
	if(cnt > 1) return ff;
	for(int i(1); i <= k; ++ i)
		if(one[i] != 0){
			ff = false;
			break;
		}
	return ff;
}
void solve(){
	int now[MAXK];
	for(int i(1); i <= k; ++ i) now[i] = st[i];
	bool flag = true;
	while(flag){
		for(int i(1); i <= k; ++ i)
			if(now[i] + maxn[i] > w[i] || now[i] + minn[i] < 1){
				flag = false;
				break;
			}
		if(flag){
			bool f = check();
			if(f){
				puts("-1");
				exit(0);
			}
			ans += n, ans %= MOD;
			for(int i(1); i <= k; ++ i) now[i] += one[i];
			continue;
		}
		else{
			for(int i(0); i != n; ++ i, i %= n){
				now[walk[i].c] += walk[i].d, ++ ans, ans %= MOD;
				if(now[walk[i].c] < 1 || now[walk[i].c] > w[walk[i].c]) break;
			}
			break;
		}
	}
}
void dep(int pos){
	if(pos == k + 1){
		solve();
		return;
	}
	for(int i(1); i <= w[pos]; ++ i){
		st[pos] = i;
		dep(pos + 1);
	}
}
int main(){
	freopen("walk.in", "r", stdin);
	freopen("walk.out", "w", stdout);
	scanf("%d%d", &n, &k);
	for(int i(1); i <= k; ++ i) scanf("%d", &w[i]);
	for(int i(0); i != n; ++ i){
		scanf("%d%d", &walk[i].c, &walk[i].d);
		one[walk[i].c] += walk[i].d;
		maxn[walk[i].c] = max(maxn[walk[i].c], one[walk[i].c]);
		minn[walk[i].c] = min(minn[walk[i].c], one[walk[i].c]);
	}
	dep(1);
	printf("%d\n", ans);
	return 0;
}
