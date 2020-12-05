#include<bits/stdc++.h>
#define N 100005
#define M 500005
using namespace std;
typedef long long ll;
ll n,m,deg[N],degj[N],degc[N],dp[N],ans;
ll ver[M],nx[M],fi[N],tot;
queue<ll> q;
ll read(){
	ll f=1,x=0;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while('0'<=ch&&ch<='9'){x=(x<<1)+(x<<3)+ch-'0';ch=getchar();}
	return f*x;
}
void add(ll x,ll y){
	ver[++tot]=y;nx[tot]=fi[x];fi[x]=tot;
}
ll gcd(ll a,ll b){
	if(!b)return a;
	return gcd(b,a%b);
}
void bfs(){
	for(ll i=1;i<=n;i++)deg[i]=degj[i],dp[i]=1;
	for(ll i=1;i<=m;i++)q.push(i),dp[i]=1;
	while(!q.empty()){
		ll x=q.front();q.pop();
		for(ll i=fi[x];i;i=nx[i]){
			ll y=ver[i],GCD=gcd(dp[y],dp[x]*degc[x]);
			dp[y]*=(dp[x]*degc[x]/GCD);
			--deg[y];
			if(!deg[y])q.push(y);
		}
	}
	ans=1;
	for(ll i=1;i<=n;i++){
		ll x=gcd(ans,dp[i]);
		ans/=x;ans*=dp[i];
	}
}
void work(){
	for(ll i=1;i<=n;i++)deg[i]=degj[i];
	memset(dp,0ll,sizeof(dp));
	for(ll i=1;i<=m;i++)q.push(i),dp[i]=ans;
	while(!q.empty()){
		ll x=q.front();q.pop();
		for(ll i=fi[x];i;i=nx[i]){
			ll y=ver[i];
			dp[y]+=dp[x]/degc[x];
			--deg[y];
			if(!deg[y])q.push(y);
		}
	}
}
int main(){
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	n=read(),m=read();
	for(ll i=1;i<=n;++i){
		ll a=read();
		for(ll j=1;j<=a;j++){
			ll b=read();
			add(i,b);
			degj[b]++;
		}
		degc[i]=a;
	}
	bfs();
	work();
	for(ll i=1;i<=n;i++)
		if(!degc[i]){
			ll x=gcd(ans,dp[i]);
			printf("%lld %lld\n",dp[i]/x,ans/x);
		}
	return 0;
}
/*
5 1
3 2 5 3
2 4 5
2 5 4
0
0
*/
