#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=100010;
int h[N],e[N*5],ne[N],idx;
int f[N];
struct X{
	LL fz,fm;
}ans[N];
int n,m,t;
int re[N];
void add(int a,int b){
	e[idx]=b;
	ne[idx]=h[a];
	h[a]=idx++;
}
int gcd(LL a,LL b){
	LL temp;
	while((a%b)!=0){
		temp=a%b;
		a=b;
		b=temp;
	}
	return b;
}
void work(int u,int v){
	LL o=ans[u].fm*ans[v].fm*f[u],p=ans[u].fm*ans[v].fz*f[u]+ans[u].fz*ans[v].fm;
	LL a=gcd(o,p);
	if(a!=1) o/=a,p/=a;
	ans[v].fm=o,ans[v].fz=p;
}
void bfs(int u){
	if(f[u]){
		for(int i=h[u];i!=-1;i=ne[i]) work(u,e[i]);
		ans[u].fm=1,ans[u].fz=0;
		for(int i=h[u];i!=-1;i=ne[i]) bfs(e[i]);
	}
}
int main(){
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	scanf("%d%d",&n,&m);
	memset(h,-1,sizeof(h));
	for(int i=1;i<=n;i++){
		scanf("%d",&f[i]);
		if(f[i]) for(int j=1;j<=f[i];j++){
			int x;
			scanf("%d",&x);
			add(i,x);
		}
		else re[++t]=i;
	}
	for(int i=1;i<=m;i++) ans[i].fm=ans[i].fz=1;
	for(int i=m+1;i<=n;i++) ans[i].fm=1;
	for(int i=1;i<=m;i++) bfs(i);
	for(int i=1;i<=t;i++) printf("%lld %lld\n",ans[re[i]].fz,ans[re[i]].fm);
	return 0;
}
