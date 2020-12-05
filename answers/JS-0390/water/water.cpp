#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int read(){
	char c=getchar();
	int s=0,f=1;
	while (c<'0' || c>'9'){if (c=='-') f=-1;c=getchar();}
	while (c>='0' && c<='9'){s=s*10+c-'0';c=getchar();}
	return s*f;
}

int readu(){
	char c=getchar();
	int s=0;
	while (c<'0' || c>'9') c=getchar();
	while (c>='0' && c<='9'){s=s*10+c-'0';c=getchar();}
	return s;
}

ll readll(){
	char c=getchar();
	ll s=0ll,f=1ll;
	while (c<'0' || c>'9'){if (c=='-') f=-1ll;c=getchar();}
	while (c>='0' && c<='9'){s=s*10ll+c-'0';c=getchar();}
	return s*f;
}

ll readull(){
	char c=getchar();
	ll s=0ll;
	while (c<'0' || c>'9') c=getchar();
	while (c>='0' && c<='9'){s=s*10ll+c-'0';c=getchar();}
	return s;
}

const int MAXINT=2147483647;
const int INF=0x3f3f3f3f;
const ll INFLL=0x3f3f3f3f3f3f3f3f;
const double EPS=1e-6;
const int MAXN=100005;
const int MAXE=500005;

struct Edge{
	int v,nxt;
	Edge(int x=0){
		v=x;
	}
}e[MAXE];

int tot=0,n,m,frt[MAXN],d[MAXN],ind[MAXN],q[MAXN];
bool mark[MAXN];
ll fz[MAXN],fm[MAXN];

ll gcd(ll x,ll y){
	if (y>0) return gcd(y,x%y);
	return x;
}

void addedge(int u,int v){
	e[++tot].v=v;
	e[tot].nxt=frt[u];
	frt[u]=tot;
	return;
}

void topsort(){
	int head=1,tail=0;
	for (register int i=1;i<=n;++i){
		if (!ind[i]){
			q[++tail]=i;
			mark[i]=true;
		}
	}
//	printf("\n*%d*\n",tail);
	while (head<=tail){
		int u=q[head++];
		for (register int j=frt[u];j;j=e[j].nxt){
			int v=e[j].v;
			ind[v]--;
			if (!ind[v]) q[++tail]=v;
		}
	}
}

void huajian(ll &pp,ll &qq){
	ll x=gcd(pp,qq);
	pp/=x;
	qq/=x;
}

void add(ll &p1,ll &q1,ll p2,ll q2){
	int x=q1*q2/gcd(q1,q2);
	p1*=(x/q1);
	p2*=(x/q2);
	p1+=p2;
	q1=x;
}

int main(){
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	n=readu();m=readu();
	for (register int i=1;i<=n;++i){
		d[i]=readu();
		for (register int j=1;j<=d[i];++j){
			int x=readu();
			addedge(i,x);
			ind[x]++;
		}
	}
	topsort();
	/*
	for (register int i=1;i<=n;++i){
		printf("%d ",q[i]);
	}
	*/
	for (register int i=1;i<=n;++i){
		if (mark[i]) fz[i]=1ll;
		else fz[i]=0ll;
		fm[i]=1ll;
	}
	for (register int i=1;i<=n;++i){
		int u=q[i];
//		printf("%d: %lld %lld\n",u,fz[u],fm[u]);
		if (fz[u]>0 && d[u]>0){
			fm[u]*=(ll)d[u];
			huajian(fz[u],fm[u]);
			for (register int j=frt[u];j;j=e[j].nxt){
				int v=e[j].v;
				add(fz[v],fm[v],fz[u],fm[u]);
				huajian(fz[v],fm[v]);
			}
		}
	}
	for (register int i=1;i<=n;++i){
		if (!d[i]) printf("%lld %lld\n",fz[i],fm[i]);
	}
	return 0;
}

