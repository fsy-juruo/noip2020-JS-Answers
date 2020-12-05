#include<bits/stdc++.h>
#define MAXN ((int)(1e5+5))
#define ll long long
using namespace std;
int n,m;
vector<int > g[MAXN];
vector<int > p;
vector<int > f[MAXN];
vector<ll > ans[MAXN];
ll gcd(ll a,ll b){
	return b==0?a:gcd(b,a%b);
}
pair<ll,ll> s[MAXN];
void sum(int x){
	if(s[x].first!=0)return;
	for(int i=0;i<ans[x].size();i++){
		int u=ans[x].at(i);
		sum(u);
		if(s[x].first==0){s[x].first=s[u].first,s[x].second=s[u].second*g[u].size();}
		else{
			
			ll gg=gcd(s[u].second*g[u].size(),s[x].second);
			long long suc=s[u].second*g[u].size()/gg,sxc=s[x].second/gg;
			
			s[x].first=s[x].first*suc+s[u].first*sxc;
			s[x].second=suc*sxc*gg;
		}
		ll ggg=gcd(s[x].first,s[x].second);
		s[x].first/=ggg,s[x].second/=ggg;
	}
}
int  main(){
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		int k;
		scanf("%d",&k);
		if(k==0){
			p.push_back(i);
			continue;
		}
		for(int _=1;_<=k;_++){
			int xx;
			scanf("%d",&xx);
			g[i].push_back(xx);
			f[xx].push_back(i);
		}
	}
	for(int i=1;i<=m;i++)s[i].first=s[i].second=1;
	for(int i=m+1;i<=n;i++){
		for(int _=0;_<f[i].size();_++){
			int u=f[i].at(_);
			ans[i].push_back(u);
		}
	}
	for(int i=m+1;i<=n;i++){
		sum(i);
	}
	for(int i=0;i<p.size();i++){
		int u=p.at(i);
		printf("%lld %lld\n",s[u].first,s[u].second);
	}
	return 0;
}
