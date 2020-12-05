#include<iostream>
#include<cstdio>
#include<queue>
#define ll long long int 
#define pr pair<ll, ll> 
#define fz first 
#define fm second 
using namespace std;

const int maxn = 2000006;
int n, m;
int st[maxn], tt, to[maxn], nx[maxn];
ll num_in[maxn], num_out[maxn];
pr ans[maxn];
queue <int> q;

void adde(int x, int y) {
	tt++;
	nx[tt]=st[x];
	st[x]=tt;
	to[tt]=y;
	num_out[x]++;
	num_in[y]++;
	return;
}

ll gcd(ll a, ll b) {
	if(b == 0) return a;
	return gcd(b, a%b);
}

pr addd(pr a, pr b, ll c) { //a+b/c
	pr tans;
	tans.fm=a.fm*b.fm*c;
	tans.fz=a.fz*b.fm*c+b.fz*a.fm;
	if(tans.fz == 0) {
		tans.fm=1; return tans;
	}
	ll t=gcd(tans.fz, tans.fm); 
	tans.fz/=t;
	tans.fm/=t;
	return tans;
}

int main() {
	freopen("water.in", "r", stdin);
	freopen("water.out", "w", stdout);
	int i, tn, j, ty;
	scanf("%d%d", &n, &m);
	for(i=1; i <= n; i++) {
		scanf("%d", &tn);
		for(j=1; j <= tn; j++) {
			scanf("%d", &ty);
			adde(i, ty);
		}
		ans[i].fm=1;
	}
	for(i=1; i <= n; i++) {
		if(num_in[i] == 0) q.push(i), ans[i].fz=1;
	}
	while(!q.empty()) {
		tn=q.front(); q.pop();
		for(i=st[tn]; i != 0; i=nx[i]) {
			ty=to[i];
			ans[ty]=addd(ans[ty], ans[tn], num_out[tn]);
			num_in[ty]--;
			if(num_in[ty] == 0) q.push(ty);
		}
	}
	
	for(i=1; i <= n; i++) {
		if(num_out[i] == 0) printf("%lld %lld\n", ans[i].fz, ans[i].fm);
	}
	return 0;
}
