#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll powmod(ll a,ll b,ll p){
	ll res=1;
	for(;b;b>>=1){
		if(b&1)res=res*a%p;
		a=a*a%p;
	}
	return res;
}
ll gcd(ll a,ll b){
	ll r;
	while(b>0){
		r=a%b;
		a=b;
		b=r;
	}
	return a;
}
ll read(){
	ll x=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}
	return x*f;
}
#define MAXN 100010
ll n,m,tot,num,head[MAXN],val[MAXN],p[MAXN],q[MAXN],vis[MAXN];
struct EDGE{
	ll nxt,to;
}edge[MAXN<<1];
void add_edge(ll u,ll v){
	edge[++tot].nxt=head[u];
	edge[tot].to=v;
	head[u]=tot;
}
bool isfl[MAXN];
ll lcm(ll a,ll b){
	return 1ll*a*b/gcd(a,b);
}

void dfs(ll u,ll fa){
	if(vis[u]==1){return;vis[u]=0;
	}
	vis[u]=1;
	ll p1=p[u],q1=q[u],xt=val[u];
	ll g=gcd(p1,xt);p1/=g;xt/=g;
	q1*=xt;
	for(int i=head[u];i;i=edge[i].nxt){
		ll v=edge[i].to;
		if(p[v]==0||q[v]==0){
			p[v]=p1;
			q[v]=q1;
		}
		else{
			ll p2=p1,q2=q1;
			ll l=lcm(q2,q[v]);
			p2=p2*(l/q2);
			p[v]=p[v]*(l/q[v]);
			q[v]=l;p[v]+=p2;
			ll g=gcd(p[v],q[v]);p[v]/=g;q[v]/=g;
		}
		dfs(v,u);
	}
}
int main(){
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=n;i++){
		num=read();
		if(num==0)isfl[i]=1;
		for(int j=1;j<=num;j++){
			ll x=read();
			add_edge(i,x);
		}
		val[i]=num;
	}
	for(int i=1;i<=m;i++){
		p[i]=1;q[i]=1;
		dfs(i,0);
	}
	for(int i=1;i<=n;i++){
		if(isfl[i]){
			printf("%lld %lld\n",p[i],q[i]);
		}
	}
	return 0;
}
