#include<bits/stdc++.h>
using namespace std;
 
const int Maxn = 5 * 1e5 + 7;
inline int read(){
	char c=getchar();
	int x = 0, y = 1;
	while(c<'0' | c>'9'){
		if (c == '-') y = -1;
		c = getchar();
	}
	while( c >= '0' && c <= '9'){
		x = x * 10 + c - '0';
		c=getchar();
	}
	return x * y;
}

int n, k, w[15], c[Maxn], d[Maxn], maxm[15], pr[15], minm[15], zs = 1;
int dfs(int id, int sum){
	for(int i = 1; i <= n; ++i){
		if((pr[c[i]] >= 0 && d[i] > 0) || (pr[c[i]] <= 0 && d[i] < 0)){
			int q = zs/w[c[i]];
			sum += (id * n + i) * q;
			zs -= q;
			w[c[i]]--;
			if(zs == 0) return sum;
		}
		pr[c[i]] += d[i];
	}
	
	return dfs(id + 1, sum);
}
int main(){
	freopen("walk.in", "r", stdin);
	freopen("walk.out", "w", stdout);
	
	n = read();
	k = read();
	for(int i = 1; i <= k; ++i){
		w[i] = read();
		zs *= w[i];
	}
	
	for(int i = 1; i <= n; ++i){
		c[i] = read();
		d[i] = read();
		pr[c[i]] += d[i];
		int t = pr[c[i]];
		
		maxm[c[i]] = max(maxm[c[i]], max(0, t));
		minm[c[i]] = min(minm[c[i]], min(0, t));
	}
	
	bool check = true;
	for(int i = 1; i <= k; ++i){
		if(pr[i] != 0 | maxm[i] - minm[i] > w[k]){
			check = false;
			break;
		}
	}
	
	if(check){
		printf("%d", -1);
		return 0;
	}
	int ans = dfs(0, 0);
	printf("%d", ans);
	return 0;
}
