#include <cstdio>
#define MOD 1000000007
using namespace std;
int n, k;
int side[500010], step[500010], l[20], m[11][500010], np[11], np2[11], w[11]; // i wei j bu
long long ans = 0;
bool C(int n){
	for(int i = 1; i <= n; i++)
	 if(np[i] > l[i] || np[i] <= 0) return false;
	return true;
}
bool S(int n){
	for(int i = 1; i <= n; i++)
	 if(np[i] != w[i]) return false;
	return true;
}
void check(int c){
	if(ans == -1) return;
	if(c == 0){
		long long x = ans;
		bool flag = 1;
		int j = 0;
		for(int i = 1; i <= k; i++)
		 np[i] = w[i];
		do{
			j = (j + 1) % n;
			if(j == 0) j = n;
			np[side[j]] += step[j];
			ans = (ans + 1) % MOD;
			if(j == n && S(k)) { ans = -1; return; }
		} while(C(k));
		return;
	}
	for(int i = l[c]; i >= 1; i--){
		w[c] = i;
		check(c-1);
	}
	return;
}
int main(){
	freopen("walk.in", "r", stdin);
	freopen("walk.out", "w", stdout);
	
	scanf("%d%d", &n, &k);
	for(int i = 1; i <= k; i++)
	 scanf("%d", &l[i]);
	for(int i = 1; i <= n; i++)
	 scanf("%d%d", &side[i], &step[i]);
	if(n <= 100){
		check(k);
		printf("%lld", ans);
		return 0;
	}
	printf("-1");
	return 0;
}
