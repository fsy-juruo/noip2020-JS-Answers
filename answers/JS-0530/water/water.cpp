#include<bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;
typedef long long ll;
const int N=1e5+10;
struct Node {
	ll x,y;
	Node() {
		
	}
	Node(ll _x,ll _y) {
		x=_x;
		y=_y;
	}
}w[N];
ll gcd(ll x,ll y) {
	if(x%y==0) {
		return y;
	}
	return gcd(y,x%y);
}
inline Node calc(Node a) {
	ll k=gcd(a.x,a.y);
	return Node(a.x/k,a.y/k);
}
inline void add(Node &a,Node b) {
	ll k=gcd(a.y,b.y);
	a=calc(Node(b.y/k*a.x+a.y/k*b.x,a.y/k*b.y));
}
struct Edge {
	int v,nxt;
}e[N*5];
int head[N],ne;
inline void init() {
	memset(head,-1,sizeof(head));
	ne=0;
}
inline void add_edge(int u,int v) {
	e[ne].v=v;
	e[ne].nxt=head[u];
	head[u]=ne++;
}
int n,m;
int a[N],num;
int d[N];
bool vis[N];
void dfs(int x) {
	vis[x]=true;
	if(d[x]==0) {
		return;
	}
	Node k=calc(Node(w[x].x,w[x].y*d[x]));
	for(int i=head[x];i!=-1;i=e[i].nxt) {
		int v=e[i].v;
		add(w[v],k);
		dfs(v);
	}
	w[x]=Node(0,1);
}
int main() {
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	init();
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) {
		scanf("%d",&d[i]);
		if(d[i]==0) {
			a[++num]=i;
			continue;
		}
		for(int j=1;j<=d[i];j++) {
			int v;
			scanf("%d",&v);
			add_edge(i,v);
		}
	}
	for(int i=1;i<=n;i++) {
		w[i].x=0;
		w[i].y=1;
	}
	for(int i=1;i<=m;i++) {
		add(w[i],Node(1,1));
		dfs(i);
	}
	for(int i=1;i<=num;i++) {
		printf("%lld %lld\n",w[a[i]].x,w[a[i]].y);
	}
	return 0;
}
