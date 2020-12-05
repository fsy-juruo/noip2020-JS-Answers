#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll ans, mod = 1000000007;
int n, k, w[15], path[12], maxn[12], minn[12], s[12], c[100010], d[100010];
void read(int &x){
	x = 0;
	int f = 1;
	char s = getchar();
	while(s < '0' || s > '9'){
		if(s == '-') f = -1;
		s = getchar();
	}
	while(s <= '9' && s >= '0'){
		x = x * 10 + int(s - '0');
		s = getchar();
	}
	x *= f;
}
void dfs(int x){
	if(x == k+1){
		int p2[15];
		for(int i = 1; i <= k; i++) p2[i] = path[i];
		int cnt = 0;
		for(int i = 1;i <= 1000;i++){
			int id = i % n;
			if(id == 0) id = n;
			path[c[id]] += d[id];
			cnt++;
			if(path[c[id]] < 1 || path[c[id]] > w[c[id]]){
				ans = (ans + cnt) % mod;
				for(int j = 1; j <= k; j++) path[j] = p2[j];
				return ;
			}
		}
	}	
	for(int i = 1; i <= w[x]; i++){
		path[x] = i;
		dfs(x+1);
	}
}
int main(){
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	read(n); read(k);
	for(int i = 1; i <= k; i++){
		read(w[i]);
		maxn[i] = -10000;
		minn[i] = 10000;
	}
	for(int i = 1; i <= n; i++){
		read(c[i]); read(d[i]);
		s[c[i]] = s[c[i]] + d[i];
		maxn[c[i]] = max(maxn[c[i]],s[c[i]]);
		minn[c[i]] = min(minn[c[i]],s[c[i]]);
	}
	for(int i = 1; i <= k; i++){
		if(s[i] == 0 && minn[i] + 1 <= w[i] - maxn[i]){
			cout << "-1" << endl;
			return 0;
		}
	}
	dfs(1);
	printf("%lld\n",ans%mod);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
