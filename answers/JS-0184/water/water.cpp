#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+5;
ll n,m;
vector<ll> g[N];
pair<ll,ll> a[N];
queue<ll> q;
ll gcd(ll x,ll y){
	if(x%y==0)return y;
	return gcd(y,x%y);
}
pair<ll,ll> gao(pair<ll,ll> x,ll y){
	x.second*=y;
	ll z=gcd(x.first,x.second);
	x.first/=z;
	x.second/=z;
	return x;
}
pair<ll,ll> add(pair<ll,ll> x,pair<ll,ll> y){
	pair<ll,ll> res;
	res.first=x.first*y.second+y.first*x.second;
	res.second=y.second*x.second;
	ll z=gcd(res.first,res.second);
	res.first/=z;
	res.second/=z;
	return res;
}
int main(){
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++){
		ll ab,x;
		scanf("%lld",&ab);
		while(ab--){
			scanf("%lld",&x);
			g[i].push_back(x);
		}
		if(i<=m){
			a[i].first=a[i].second=1;
			q.push(i);
		}
		else{
			a[i].first=0;
			a[i].second=1;
		}
	}
	while(!q.empty()){
		ll x=q.front();
		q.pop();
		if(g[x].size()==0)continue;
		pair<ll,ll> y=gao(a[x],g[x].size());
		for(int i=0;i<g[x].size();i++){
			a[g[x][i]]=add(a[g[x][i]],y);
			q.push(g[x][i]);
		}
		a[x].first=0,a[x].second=1;
	}
	for(int i=1;i<=n;i++)
		if(g[i].size()==0)
			printf("%lld %lld\n",a[i].first,a[i].second);
	return 0;
}
//I AK IOI
