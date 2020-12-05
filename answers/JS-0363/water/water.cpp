#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=1e5+10;
struct Node{
	ll p,q;
}ans[N];
ll n,m,s[N],fa[N];
vector<ll> e[N];
ll mygcd(ll x,ll y){
	if(y==0)return x;
	return mygcd(y,x%y);
}
Node qans(Node a,Node b){
	Node ret;
	ret.p=a.p*b.q+b.p*a.q;ret.q=a.q*b.q;
	ll x=mygcd(ret.p,ret.q);
	ret.p/=x;ret.q/=x;
	return ret;
}
void dfs(ll x){
	if(s[x]==0)return;
	ans[x].q*=s[x];
	for(ll i=0;i<s[x];i++){
		ll v=e[x][i];
		if(ans[v].q==0)ans[v]=ans[x];
		else ans[v]=qans(ans[x],ans[v]);
		dfs(v);
	}
	ans[x].p=0;
}
int main(){
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		cin>>s[i];
		for(ll j=1;j<=s[i];j++){
			ll x;cin>>x;fa[x]=1;
			e[i].push_back(x);
		}
	}
	for(ll i=1;i<=n;i++){
		if(fa[i]==0){
			ans[i].p=1;ans[i].q=1;
			dfs(i);
		}
	}
	for(ll i=1;i<=n;i++){
		if(s[i]==0){
			cout<<ans[i].p<<" "<<ans[i].q<<endl;
		}
	}
	return 0;
}//100
/*
5 1
3 2 3 5
2 4 5
2 5 4
0
0
*/
