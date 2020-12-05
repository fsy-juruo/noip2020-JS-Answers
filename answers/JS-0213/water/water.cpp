#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>
#define rep(i,j,k) for (i=j;i<=k;i++)
#define ll long long
using namespace std;
queue <int> q;
const int N = 1000005;
struct arr{
	ll u;ll d;
}a[N],b,ans[N];
int oud[N],ind[N],head[N],nxt[N],ver[N],id[N],tt,tot,n,m,i,j,k,x,y,l,r;
void add(int x,int y){
	ver[++tot]=y;nxt[tot]=head[x],head[x]=tot;
}
void swp(ll &a,ll &b){
	ll c=a;a=b;b=c;
}
ll gcd(ll a,ll b){
	if (b==0) return a;
	return gcd(b,a%b);
}
ll Gcd(ll a,ll b){
	if (a<b) swp(a,b);
	return gcd(a,b);
}
void zjb(arr &a){
	ll g=Gcd(a.u,a.d);
	a.u/=g,a.d/=g;
}
void addct(arr &a,arr b){
	a.u=a.u*b.d+a.d*b.u;
	a.d*=b.d;
	if (a.d>=10000000||a.u>=10000000) zjb(a);
}
int main(){
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	scanf("%d%d",&n,&m);
	rep(i,1,n){
		scanf("%d",&k);
		rep(j,1,k) scanf("%d",&x),add(i,x),ind[x]++;
		oud[i]=k;
		if (k==0) id[i]=++tt;
	}
	rep(i,1,m) q.push(i),a[i].u=a[i].d=1;
	rep(i,m+1,n) a[i].d=1,a[i].u=0;
	while (!q.empty()){
		int rt=q.front();
		if (oud[rt]==0){
			zjb(a[rt]);
			ans[id[rt]].u=a[rt].u,ans[id[rt]].d=a[rt].d;
			q.pop();
			continue;
		}
		b.u=a[rt].u,b.d=a[rt].d*oud[rt];
		for (i=head[rt];i;i=nxt[i]){
			y=ver[i];
			addct(a[y],b);
			ind[y]--;
			if (ind[y]==0) zjb(a[y]),q.push(y);
		}
		q.pop();
	}
	rep(i,1,tt) printf("%lld %lld\n",ans[i].u,ans[i].d);
	return 0;
}
/*
5 1
3 2 3 5
2 4 5
2 5 4
0
0

*/
