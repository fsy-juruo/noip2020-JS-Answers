#include<bits/stdc++.h>
#define F(i,l,r) for(int i=l;i<=r;i++)
#define D(i,l,r) for(int i=l;i>=r;i--)
#define ll long long
#define mem(a,b) memset(a,b,sizeof(a))
#define p_b push_back
#define m_p make_pair
#define fi first
#define se second
using namespace std;
#define pii pair<ll,ll>
int fr() {
	int x=0,f=1;
	char ch=getchar();
	while((ch>'9'||ch<'0')&&ch!='-') ch=getchar();
	if(ch=='-') ch=getchar(),f=-1;
	while(ch<='9'&&ch>='0') x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
	return x*f;
}
const int INF=0x7f7f7f7f,N=1e5+5;
int n,m;
int ind[N],outd[N];
struct edge {
	int to,nxt;
}e[N];
int head[N],tot;
void add(int u,int v) {
	e[++tot].to=v;
	e[tot].nxt=head[u];
	head[u]=tot;
}
ll gcd(ll a,ll b) {
	while(b!=0) {
		ll t=a%b;
		a=b,b=t;
	}
	return a;
}
pii dis[N];
pii Div(pii c) {
	ll x=gcd(c.fi,c.se);
	c.fi/=x,c.se/=x;
	return c;
}
pii Plus(pii a,pii b) {
	pii c;
	c.se=a.se/gcd(a.se,b.se)*b.se;
	c.fi=c.se/a.se*a.fi+c.se/b.se*b.fi;
	c=Div(c);
	return c;
}
void dfs(int x) {
	if(!outd[x]||!dis[x].fi||!dis[x].se) return ;
	pii a=dis[x];
	a.se*=outd[x];
	a=Div(a);
	dis[x]=m_p(0,0);
	for(int i=head[x];~i;i=e[i].nxt) {
		int to=e[i].to;
		if(!dis[to].fi||!dis[to].se) dis[to]=a;
		else dis[to]=Plus(dis[to],a);
	}
	for(int i=head[x];~i;i=e[i].nxt) dfs(e[i].to);
}
int main() {
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	mem(head,-1);
	n=fr(),m=fr();
	F(i,1,n) {
		outd[i]=fr();
		F(j,1,outd[i]) {
			int to=fr();
			add(i,to);
		}
	}
	F(i,1,m) dis[i]=m_p(1,1);
	F(i,1,m) dfs(i);
	F(i,1,n) if(!outd[i]) printf("%lld %lld\n",dis[i].fi,dis[i].se);
	return 0;
}


