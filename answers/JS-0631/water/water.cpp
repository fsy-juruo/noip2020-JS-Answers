#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn = 1e5 + 10;
inline int read(){
	int x = 0, f = 1; char ch = getchar();
	for(; !isdigit(ch); ch = getchar()) if(ch == '-') f = -f;
	for(; isdigit(ch); ch = getchar()) x = (x << 3) + (x << 1) + ch - '0';
	return x * f;
}
ll gcd(ll x, ll y){
	if(x < y) {ll h = x;x = y; y = h;}
	if(x % y == 0) return y;
	return gcd(y, x % y);
}
ll fgcd(ll x, ll y){
	return x * y / gcd(x, y);
}

int vis[2000];
vector<ll> ans[2000];//shu chu
int n, m;
vector<int> Q[maxn];//建图 
ll pipe[2000];//每个节点的出度 
int pai[maxn], c;//排水管
void dfs(int x, ll k){
	if(Q[x].empty()){ 
		if(!vis[x]) pai[++c] = x, vis[x] = 1; 
		ans[x].push_back(k); return; 
	} 
	for(int i = 0, sz = Q[x].size(); i < sz; i ++){
		dfs(Q[x][i], k * pipe[x]);
	}
}
int main(){
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	n = read(), m = read();
	for(int i = 1, s, tmp; i <= n; i ++){
		s = read(); pipe[i] = s;
		for(int j = 1; j <= s; j ++){
			tmp = read();
			Q[i].push_back(tmp);
		}
	}
	for(int i = 1; i <= m; i ++) dfs(m, 1);
	sort(pai + 1, pai + 1 + c);
	for(int i = 1; i <= c; i ++){
		int gz = pai[i];
		ll fGCD = ans[gz][0], p = 0;
		for(int j = 1; j < ans[gz].size(); j ++) fGCD = fgcd(fGCD, ans[gz][j]);
		for(int j = 0; j < ans[gz].size(); j ++) p += fGCD / ans[gz][j];
		printf("%lld %lld\n", p / gcd(p, fGCD), fGCD / gcd(p, fGCD));
	}
	return 0;
}

