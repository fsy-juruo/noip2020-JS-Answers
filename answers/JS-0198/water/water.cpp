#include<bits/stdc++.h>
#include<queue>
#define ll long long
using namespace std;

struct edge{
	int next,to;
}e[500005];
struct fen{
 	ll m,s;
}a[100005];
int head[100005],cnt,post[100005],pre[100005],n,M;
queue<int> q;
ll gcd(ll x,ll y){
	if (x<y) swap(x,y);
	while (y){
		ll tmp=y;
		y=x%y;
		x=tmp;
	}
	return x;
}
fen add(fen x,fen y){
	ll am,as;
	am=x.m*y.m;
	as=x.s*y.m+x.m*y.s;
	ll tmp=gcd(am,as);
	am/=tmp;as/=tmp;
	return (fen){am,as};
}
void add_edge(int u,int v){
	e[++cnt]=(edge){head[u],v};
	head[u]=cnt;
}
int main(){
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	cin>>n>>M;
	int u,v;
	for (int i=1;i<=n;i++){
		scanf("%d",&post[i]);
		for (int j=1;j<=post[i];j++){
			scanf("%d",&v);
			add_edge(i,v);
			pre[v]++;
		}
	}
	
	for (int i=1;i<=n;i++){
		if (!pre[i]) q.push(i),a[i]=(fen){1,1};
		else a[i]=(fen){1,0};
	}
	
	while (!q.empty()){
		u=q.front();q.pop();
		if (!post[u]) continue;
		fen tmp=a[u];
		if (!tmp.s%post[u]){
			tmp.s/=post[u];
		}
		else tmp.m*=post[u];
		for (int i=head[u];i;i=e[i].next){
			int v=e[i].to;
			a[v]=add(a[v],tmp);
			pre[v]--;
			if (!pre[v]) q.push(v);
		}
	}
	for (int i=1;i<=n;i++){
		if (!post[i]){
			printf("%lld %lld\n",a[i].s,a[i].m);
		}
	}
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
