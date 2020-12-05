#include <bits/stdc++.h>

using namespace std;

const int maxk = 110, maxn = 1e5 + 10;

int n, k;
int ans;
int w[maxk], tw[maxk], s[maxk];
int c[maxn], d[maxn];
bool END;

void dfs(int x){
	if (END) return;
	if (x > k){
		for (int i = 1; i <= k; i++) tw[i] = s[i];
		int cnt = 0; bool h = 0;
		for (int l = 0; l <= n && !h; l++){
			for (int i = 1; i <= n && !h; i++){
				tw[c[i]] += d[i];
				cnt++;
				if (tw[c[i]] > w[c[i]]) h = 1;
				if (tw[c[i]] < 1) h = 1;
			}
		}
		if (!h){
			puts("-1");
			END = 1;
			return;
		}
		ans += cnt;
		return;
	}
	for (int i = 1; i <= w[x]; i++){
		s[x] = i;
		dfs(x + 1);
		s[x] = 0;
	}
}

int main(){
	freopen("walk.in", "r", stdin);
	freopen("walk.out", "w", stdout);
	scanf("%d%d", &n, &k);
	if (n > 100001){
		puts("-1");
		return 0;
	}
	for (int i = 1; i <= k; i++) scanf("%d", w + i);
	for (int i = 1; i <= n; i++) scanf("%d%d", c + i, d + i);
	dfs(1);
	if (!END) printf("%d\n", ans);
	return 0;
}
