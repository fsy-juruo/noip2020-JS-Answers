#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
ll gcd(ll x, ll y){
	return y == 0 ? x : gcd(y, x % y);
}
ll lcm(ll x, ll y){
	return x / gcd(x, y) * y;
}
struct Frac{
	ll p, q;
	Frac(){
		p = q = 0;
	}
	Frac(ll _p, ll _q){
		p = _p; q = _q;
	}
	inline void check(){
		ll g = gcd(p, q);
		p /= g; q /= g;
	}
	Frac operator+(const Frac &o){
		Frac ret(p * o.q + o.p * q, q * o.q);
		ret.check();
		return ret;
	}
	Frac operator-(const Frac &o){
		Frac ret(p * o.q - o.p * q, q * o.q);
		ret.check();
		return ret;
	}
	Frac operator*(const Frac &o){
		Frac ret(p * o.p, q * o.q);
		ret.check();
		return ret;
	}
	Frac operator/(const Frac &o){
		Frac ret(p * o.q, q * o.p);
		ret.check();
		return ret;
	}
	void print(){
		check();
		printf("%lld %lld\n", p, q);
	}
};
const int maxn = 1e5+5;
int n, m, indeg[maxn];
vector<int> G[maxn];
Frac dp[maxn];
queue<int> Q;
int main(){
	freopen("water.in", "r", stdin);
	freopen("water.out", "w", stdout);
	scanf("%d%d", &n, &m);
	memset(indeg, 0, sizeof(indeg));
	for(int i=1; i<=n; i++){
		int d, x;
		scanf("%d", &d);
		for(int j=1; j<=d; j++){
			scanf("%d", &x);
			G[i].push_back(x);
			indeg[x] ++;
		}
	}
	for(int i=1; i<=m; i++){
		dp[i] = Frac(1, 1);
		Q.push(i);
	}
	for(int i=m+1; i<=n; i++) dp[i] = Frac(0, 1);
	while(!Q.empty()){
		int t = Q.front();
		Q.pop();
		for(int i=0; i<G[t].size(); i++){
			dp[G[t][i]] = dp[G[t][i]] + (dp[t] / Frac(G[t].size(), 1));
			indeg[G[t][i]] --;
			if(indeg[G[t][i]] == 0){
				Q.push(G[t][i]);
			}
		}
	}
	for(int i=1; i<=n; i++){
		if(G[i].size() == 0){
			dp[i].print();
		}
	}
	return 0;
}


