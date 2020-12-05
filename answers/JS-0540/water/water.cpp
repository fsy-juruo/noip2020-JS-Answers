#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
const int M=5e5+100;
typedef long long ll;
struct edge{
	int v,nxt;
}e[M];
int fst[N],ne=0;
void addedge(int u,int v){
	e[ne].v=v;
	e[ne].nxt=fst[u];
	fst[u]=ne++;
}
struct fens{
	ll fm,fz;
	fens(){
		fm=fz=1;
	}
}a[N];
ll gcd(ll a,ll b){
	if(b==0ll)return a;
	return gcd(b,a%b);
}

fens addf(fens a,fens b){
	ll g=gcd(a.fm,b.fm);
	fens ans;
	ans.fm=(a.fm/g)*b.fm;
	ans.fz=((b.fm/g)*a.fz)+((a.fm/g)*b.fz);
	g=gcd(ans.fz,ans.fm);
	ans.fm/=g;
	ans.fz/=g;
	return ans;
}
fens qq(fens a,ll b){
	int g=gcd(a.fz,b);
	a.fz/=g;
	b/=g;
	a.fm*=b;
	return a;
}
int n,m,d[N];
void dfs(int x){
	if(a[x].fz)return;
	
	for(int i=fst[x];i!=-1;i=e[i].nxt){
		int v=e[i].v;
		
		dfs(v);
		a[x]=addf(a[x],qq(a[v],d[v]));
		//printf("%d:%lld/%lld\n",x,a[x].fz,a[x].fm);
	}
	
}

/*
5 1
3 2 3 5
2 4 5
2 5 4
0
0

*/
int main(){
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	memset(fst,-1,sizeof(fst));
	scanf("%d%d",&n,&m);
	int v;
	for(int i=1;i<=n;i++){
		scanf("%d",&d[i]);
		for(int j=1;j<=d[i];j++){
			scanf("%d",&v);
			addedge(v,i);
			a[v].fz=0ll;
		}
	}
	
	for(int i=1;i<=n;i++){
		if(d[i]==0ll){
			dfs(i);
			printf("%lld %lld\n",a[i].fz,a[i].fm);
		}
	}

	return 0;
}
