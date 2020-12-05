#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
const int MAXN=1e5+10,MAXM=5e5+10;
struct Edge{
	int u,v;
}edge[MAXM];
int first[MAXN],next[MAXM],tot;
int n,m;
int d[MAXN],insize[MAXN];
int topo[MAXN],topotot;
long long fz[MAXN],fm[MAXN]; //·Ö×Ó,·ÖÄ¸ 
queue<int>q;
inline void addedge(int u,int v){
	edge[++tot].u=u;edge[tot].v=v;
	next[tot]=first[u];first[u]=tot;
}
long long gcd(long long a,long long b){
	if(!b)return a;
	return gcd(b,a%b); 
}
long long lcm(long long a,long long b){
	return a/gcd(a,b)*b;
}
int main(){
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&d[i]);
		for(int j=1,v;j<=d[i];j++){
			scanf("%d",&v);
			insize[v]++;
			addedge(i,v);
		}
	}
	for(int i=1;i<=n;i++){
		fm[i] = 1;
		if(!insize[i]){
			topo[++topotot] = i;
			q.push(i);
			fz[i] = 1;
		}
	}
	while(!q.empty()){
		int u = q.front();q.pop();
		for(int j=first[u];j;j=next[j]){
			int v = edge[j].v;insize[v]--;
			if(!insize[v]){
				topo[++topotot] = v;
				q.push(v);
			}
		}
	}
	for(int i=1;i<=n;i++){
		int u = topo[i];
		long long fzu = fz[u],fmu = fm[u] * d[u];
		for(int j=first[u];j;j=next[j]){
			int v = edge[j].v;
			//fz[v]/fm[v] + fzu/fmu
			long long nfm = lcm(fm[v],fmu);
			fz[v] = fz[v] * (nfm/fm[v]) + fzu * (nfm/fmu);
			fm[v] = nfm;
			nfm = gcd(fz[v],fm[v]);
			fz[v] /= nfm;
			fm[v] /= nfm;
		}
	}
	for(int i=1;i<=n;i++){
		if(d[i])continue;
		printf("%lld %lld\n",fz[i],fm[i]);
	}
	return 0;
}
