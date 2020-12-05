#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+5;
const int M=5e5+5;
struct edge{
	int to,nxt;
}e[M];
int head[N],cnt;
void add_edge(int x,int y){
	e[++cnt].to=y;
	e[cnt].nxt=head[x];
	head[x]=cnt;
}
int d[N];
bool vis[N],out[N];
ll p[N],q[N];
ll gcd(ll a,ll b){
	if(b==0){
		return a;
	}
	return gcd(b,a%b);
}
int n,m;
void simp(int u){
	ll G=gcd(p[u],q[u]);
	p[u]/=G,q[u]/=G;
}
void add(int u,int v){
	p[v]=p[v]*q[u]*d[u]+p[u]*q[v];
	q[v]=q[v]*q[u]*d[u];
	simp(v);
}
void dfs(int u){
	if(vis[u]) return;
	vis[u]=1;
	if(u<=m){
		p[u]=1,q[u]=1;
		vis[u]=1;
		return;
	}
	for(int i=head[u];i;i=e[i].nxt){
		int v=e[i].to;
		dfs(v);
		add(v,u);
	}
}
int main(){
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i){
		p[i]=0,q[i]=1;
		scanf("%d",&d[i]);
		for(int j=1;j<=d[i];++j){
			int a;
			scanf("%d",&a);
			add_edge(a,i);
		}
		out[i]=(d[i]==0);
	}
	for(int i=m+1;i<=n;++i){
		if(out[i]){
			dfs(i);
			printf("%lld %lld\n",p[i],q[i]);
		}
	}
	return 0;
}
