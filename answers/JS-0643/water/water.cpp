#include <bits/stdc++.h>
#define N 100010
#define ll long long
using namespace std;

ll n, m;
struct nod{
	ll p, q;
}ans[N];
vector <ll> e[N], ansid;
void read(ll &x){
	x = 0;
	char s = getchar();
	while(s < '0' || s > '9') s = getchar();
	while(s <= '9' && s >= '0'){
		x = x * 10 + int(s - '0');
		s = getchar();
	}
}
ll gcd(ll a, ll b){
	if(b == 0) return a;
	return gcd(b,a%b);
}
void zplus(ll x, ll p, ll q){
	ll lcm = (ans[x].q * q) / gcd(ans[x].q, q);
	ans[x].p = ans[x].p * lcm / ans[x].q + p * lcm / q;
	ans[x].q = lcm;
	ll k = gcd(ans[x].p,ans[x].q);
	if(k != 1){
		ans[x].p /= k; ans[x].q /= k;
	}
}
void work(ll x, ll p, ll q){
	ll l = e[x].size();
	if(l == 0){
		ll k = gcd(p,q);
		p /= k; q /=k;
		zplus(x,p,q);
		return ;
	}
	for(int i = 0; i < l; i++){
		work(e[x][i],p,q*l);
	}
}
int main(){
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	read(n); read(m);
	for(ll i = 1, d; i <= n; i++){
		read(d);
		ans[i].q = 1;
		if(d == 0) ansid.push_back(i);
		for(ll j = 1, x; j <= d; j++){
			read(x);
			e[i].push_back(x);
		}
	}
	for(int i = 1; i <= m; i++){
		work(i,1,1);
	}
	int l = ansid.size();
	for(int i = 0; i < l; i++){
		ll k = gcd(ans[ansid[i]].p,ans[ansid[i]].q);
		if(k != 1){
			ans[ansid[i]].p /= k;ans[ansid[i]].q /= k;
		}
		printf("%lld %lld\n",ans[ansid[i]].p,ans[ansid[i]].q);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
