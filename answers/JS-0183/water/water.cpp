#include <bits/stdc++.h>
#define N 100005
#define int long long
using namespace std;
int n, m, d[N], s1[N], s2[N];
vector<int> q[N];
int gcd(int x, int y){
	if(x % y == 0) return y;
	return gcd(y, x % y);
}
void dfs(int u){
	if(!d[u]) return;
	s2[u] *= d[u];
	int g = gcd(s1[u], s2[u]);
	s1[u] /= g; s2[u] /= g;
	for(int i = 0; i < d[u]; ++i){
		int to = q[u][i];
		g = s2[u] / gcd(s2[u], s2[to]) * s2[to];
		s1[u] *= g / s2[u]; s1[to] *= g / s2[to]; s2[to] = g;
		s1[to] += s1[u]; s1[u] /= g / s2[u];
		g = gcd(s1[to], s2[to]);
		s1[to] /= g; s2[to] /= g;
		dfs(to);
	}
	s1[u] = 0; s2[u] = 1;
}
signed main(){
	freopen("water.in", "r", stdin);
	freopen("water.out", "w", stdout);
	scanf("%lld%lld", &n, &m);
	for(int i = 1; i <= n; ++i){
		scanf("%lld", &d[i]);
		for(int j = 1; j <= d[i]; ++j){
			int t;
			scanf("%lld", &t);
			q[i].push_back(t); 
		}
	}
	for(int i = 1; i <= n; ++i) s2[i] = 1;
	for(int i = 1; i <= m; ++i){
		s1[i] = 1; 
		dfs(i);	
	} 
	for(int i = 1; i <= n; ++i)	if(!d[i]) printf("%lld %lld\n", s1[i], s2[i]);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
5 1
3 2 3 5
2 4 5
2 5 4
0
0
*/
