#include <bits/stdc++.h>
using namespace std;
int read(){
	int n = 0, f = 1;
	char x =  getchar();
	while((x < '0' || x > '9') && x != '-') x = getchar();
	if(x == '-'){f = -1; x = getchar();}
	while(x >= '0' && x <= '9'){n = n * 10 + x - '0';x = getchar();}
	return n * f;
}
int n, k;
int w[20];
int d[500010], c[500010];
int zu[20];
int MAX[20];
int MIN[20];
long long mod = 1e9 + 7;
bool can(){
	for(int i = 1;i <= k;i ++){
		if(zu[i]) return 1;
	}
	return 0;
}
int dfn[20];
int wz[20];
bool check(int num){
	for(int i = 1;i <= k;i ++){
		if(wz[i] + (num - 1) * zu[i] + MIN[i] < 1 || wz[i] + (num - 1) * zu[i] + MAX[i] > w[i]) return 0;
		if(wz[i] + MIN[i] < 1 || wz[i] + MAX[i] > w[i]) return 0;
	}
	return 1;
}
long long ans = 0;
void work(){
	int up = 1 << 18;
	for(int i = 1;i <= k;i ++) wz[i] = dfn[i];
	while(up > 0){
		if(check(up)){
			for(int i = 1;i <= k;i ++){
				wz[i] += up * zu[i];
			}
			ans = (long long)(ans + (n * up % mod)) % mod;
		}
		up >>= 1;
	}
	for(int i = 1;i <= n;i ++){
		wz[c[i]] += d[i];
		if(wz[c[i]] < 1 || wz[c[i]] > w[c[i]]){
			ans += i;
			ans %= mod;
			break;
		}
	}
}
void dfs(int wei){
	if(wei > k){
		work();
	}
	for(int i = 1;i <= w[wei];i ++){
		dfn[wei] = i;
		dfs(wei + 1);
	}
}
int main(){
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	memset(MIN, 0x3f, sizeof(MIN));
	n = read();k = read();
	for(int i = 1;i <= k;i ++) w[i] = read();
	for(int i = 1;i <= n;i ++){
		c[i] = read();d[i] = read();
		zu[c[i]] += d[i];
		MAX[c[i]] = max(MAX[c[i]], zu[c[i]]);
		MIN[c[i]] = min(MIN[c[i]], zu[c[i]]);
	}
	if(can()); else{
		printf("-1\n");
		return 0;
	}
	dfs(1);
	printf("%lld\n", ans);
	return 0;
}

