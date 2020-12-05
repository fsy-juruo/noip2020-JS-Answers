#include <bits/stdc++.h>
#define LL long long
#define forn(i,n) for(LL i=0;i<n;i++)
#define fori(i,a,b) for(LL i=a;i<=b;i++)
#define ff first
#define ss second
#define mp make_pair
using namespace std;

LL gcd(LL x, LL y) {
	return (x==0?y:gcd(y%x, x));
}
struct Frac {
	LL a,b;
	Frac(LL _a,LL _b) {
		a=_a,b=_b;
	}
	Frac() {
		a=0,b=1;
	}
};
Frac operator+(Frac x, Frac y) {
	LL a=x.a*y.b + y.a*x.b;
	LL b=x.b*y.b;
	LL g=gcd(a,b);
	a/=g, b/=g;
	Frac res(a,b);
	return res;
}
Frac operator/(Frac x, int y) {
	LL a=x.a, b=x.b*y;
	LL g=gcd(a,b);
	a/=g, b/=g;
	Frac res(a,b);
	return res;
}

LL n,m;
vector<vector<LL> > G;
vector<LL> deg;
vector<Frac> ans;

void dfs(int v, Frac flow) {
	if(deg[v] == 0) {
		ans[v]=ans[v]+flow;
		return;
	}
	forn(i, G[v].size()) {
		int u = G[v][i];
		dfs(u, flow / deg[v]);
	}
}

int main() {
	freopen("water.in", "r", stdin); freopen("water.out", "w", stdout);
	cin>>n>>m;
	G.resize(n+1);
	deg.resize(n+1);
	ans.resize(n+1);
	fori(i,1,n) {
		cin>>deg[i];
		LL x;
		forn(j,deg[i]) {
			cin>>x;
			G[i].push_back(x);
		}
	}
	fori(i,1,m) {
		dfs(i, Frac(1,1));
	}
	fori(i,1,n) {
		if(deg[i]==0) cout<<ans[i].a<<" "<<ans[i].b<<endl;
	}
	return 0;
}
