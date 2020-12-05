#include<cstdio>
typedef long long ll;
const int N = 1e5 + 7, M = 5e5 + 7;
int n, m, eg, hd[N], nt[M], to[M];
int in[N], out[N], st[20], ed[N], cntst, cnted;
ll water[N][10];

inline ll gcd(ll a, ll b){
	if(b == 0) return a;
	return gcd(b, a%b);
}
inline ll lcm(ll a, ll b){
	return a / gcd(a, b) * b;
}
inline ll yf(ll &a, ll &b){
	ll g = gcd(a, b);
	a /= g, b /= g;
}

void dfs(int s){
	if(out[s]) water[s][1] *= out[s];
	else return;
	yf(water[s][1], water[s][0]);
	for(int i = hd[s]; i; i = nt[i]){
		int v = to[i];
		ll l = lcm(water[s][1], water[v][1]);
		water[v][0] *= l / water[v][1];
		water[v][1] = l;
		water[v][0] += l / water[s][1] * water[s][0];
		yf(water[v][0], water[v][1]);
		dfs(v);
	}
	water[s][1] = 1, water[s][0] = 0;
}
int main(){
	freopen("water.in", "r", stdin);
	freopen("water.out", "w", stdout);
	scanf("%d%d", &n, &m);
	for(int i = 1, t; i <= n; ++i){
		scanf("%d", &t);
		out[i] += t;
		if(t == 0) ed[++cnted] = i;
		water[i][1] = 1;
		for(int j = 1, u; j <= t; ++j){
			scanf("%d", &u);
			nt[++eg] = hd[i], hd[i] = eg, to[eg] = u;
			++in[u];
		}
	}
	for(int i = 1; i <= n; ++i){
		if(in[i] == 0){
			water[i][0] = 1;
			dfs(i);
		}
	}
	for(int i = 1; i <= cnted; ++i) printf("%lld %lld\n", water[ed[i]][0], water[ed[i]][1]);
	return 0;
}
