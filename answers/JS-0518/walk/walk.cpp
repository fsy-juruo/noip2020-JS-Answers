#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int maxn = 12;
const int maxw = 5e5+5;
const int mod = 1e9+7;
int n, k, w[maxn];
int step[maxn], minonce[maxn], maxonce[maxn];
int dfa[maxn], ans;
int c[maxw], d[maxw];
void dfs(int p){
	if(p == k + 1){
		int tmp = 0, pos = 1;
		int stp[maxn];
		for(int i=1; i<=k; i++) stp[i] = dfa[i];
		for(int i=1,j=1; i<=n; i=i%n+1,j++){
			stp[c[i]] += d[i];
			if(stp[c[i]] < 1 || stp[c[i]] > w[c[i]]){
				tmp = j; break;
			}
		}
		ans = (0ll + ans + tmp) % mod;
		return;
	}
	for(int i=1; i<=w[p]; i++){
		dfa[p] = i;
		dfs(p + 1);
	}
}
int main(){
	freopen("walk.in", "r", stdin);
	freopen("walk.out", "w", stdout);
	scanf("%d%d", &n, &k);
	for(int i=1; i<=k; i++) scanf("%d", &w[i]);
	for(int i=1; i<=n; i++){
		scanf("%d%d", &c[i], &d[i]);
		step[c[i]] += d[i];
	}
	bool allzero = true;
	for(int i=1; i<=k; i++) if(step[i] != 0){
		allzero = false; break;
	}
	if(allzero){
		puts("-1");
		return 0;
	}
	dfs(1);
	printf("%d\n", ans);
	return 0;
}


