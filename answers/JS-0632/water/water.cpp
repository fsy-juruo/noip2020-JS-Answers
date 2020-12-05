//It finally comes...
#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
typedef long long ll;
using namespace std;
int n,m,k,p1,in[100005],out[100005];
vector <int> ve[100005];
pair<ll,ll> p[100005];
queue <int> que;
int RLG_gcd(int a,int b){
	if (a%b==0) return b; else return RLG_gcd(b,a%b);
}
pair<ll,ll> RLG_add(pair<ll,ll> f1,pair<ll,ll> f2){
	ll c=f1.second*f2.second/RLG_gcd(f1.second,f2.second);
	ll f1u=f1.first*c/f1.second;
	ll f2u=f2.first*c/f2.second;
	ll fu=f1u+f2u;
	ll div=RLG_gcd(fu,c);
	fu/=div;
	c/=div;
	return mp(fu,c);
}
int main(){
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++){
		scanf("%d",&k);
		for (int j=0;j<k;j++){
			scanf("%d",&p1);
			ve[i].pb(p1);
			in[p1]++;
		}
		out[i]=k;
	}
	for (int i=1;i<=n;i++){
		if (!in[i]){
			p[i]=mp(1,1);
			que.push(i);
		}else{
			p[i]=mp(0,1);
		}
	}
	while (!que.empty()){
		int x=que.front();
		que.pop();
		if (out[x]==0) continue;
		pair<ll,ll> om=p[x];
		if (om.first%out[x]==0){
			om.first/=out[x];
		}else{
			om.second*=out[x];
		}
		for (int i=0;i<ve[x].size();i++){
			int nx=ve[x][i];
			p[nx]=RLG_add(p[nx],om);
			in[nx]--;
			if (in[nx]==0) que.push(nx);
		}
	}
	for (int i=1;i<=n;i++){
		if (!out[i]){
			if (p[i].first==0) p[i].second=1;
			printf("%lld %lld",p[i].first,p[i].second);
			puts("");
		}
	}
	return 0;
}
