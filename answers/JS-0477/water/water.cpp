#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
//#define bug cerr<<">>>"<<__LINE__<<endl
#define int long long
const int maxn=100010,maxm=500010;
int n,m,d[maxn];
int head[maxn],nxt[maxm],to[maxm],edcnt;
void link(int u,int v){
	nxt[++edcnt]=head[u];
	head[u]=edcnt;
	to[edcnt]=v;
}
int indgr[maxn],q[maxn],qhead,qtail;
int gcd(int a,int b){
	return b?gcd(b,a%b):a;
}
struct deci{
	int p,q;
	deci(int p=0,int q=1):p(p),q(q){}
}ans[maxn];
deci operator +(const deci &a,const deci &b){
	int p2=a.p*b.q+a.q*b.p,q2=a.q*b.q,g=gcd(p2,q2);
	return deci(p2/g,q2/g);
}
deci operator *(const deci &a,const deci &b){
	int p2=a.p*b.p,q2=a.q*b.q,g=gcd(p2,q2);
	return deci(p2/g,q2/g);
}
signed main(){
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;++i){
		scanf("%lld",d+i);
		for(int j=0,t;j<d[i];++j)
			scanf("%lld",&t),
			link(i,t),
			++indgr[t];
	}
	for(int i=1;i<=n;++i)
		if(!indgr[i])
			q[qtail++]=i,ans[i]=1;
	while(qhead<qtail){
		int t=q[qhead++];
		for(int i=head[t];i;i=nxt[i]){
			if(!--indgr[to[i]]) q[qtail++]=to[i];
			ans[to[i]]=ans[to[i]]+deci(ans[t])*deci(1,d[t]);
		}
	}
	for(int i=1;i<=n;++i)
		if(!d[i])
			printf("%lld %lld\n",ans[i].p,ans[i].q);
}
