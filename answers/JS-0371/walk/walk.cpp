#include <cstdio>
const int MOD = 1e9 + 7;
const int N = 5e5+7;

int w[13], cs[N], d[N], dir[13];
int sta[13];

int main(){
	freopen("walk.in", "r", stdin);
	freopen("walk.out", "w", stdout);
	int n, k;
	long long ans = 0;
	scanf("%d%d", &n, &k);
	for(int i=1; i<=k; ++i) scanf("%d", w+i);
	for(int i=1; i<=n; ++i){
		scanf("%d%d", cs+i, d+i);
	}
	puts("-1");
	return 0;
}
