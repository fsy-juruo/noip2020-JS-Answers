#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
const int MAXN=2e5+10;
int n,k,q[20],maxq,w[20],c[MAXN],d[MAXN];
struct Edge{
	int u,v;
}edge[MAXN];
int first[MAXN],next[MAXN],tot;
int insize[MAXN];
int topo[MAXN],topotot;
long long val[MAXN],cnt[MAXN],f[MAXN];
inline void addedge(int u,int v){
	edge[++tot].u=u;edge[tot].v=v;
	next[tot]=first[u];first[u]=tot;
	insize[v]++;
}
int h(int pos[]){
	int value = 0;
	for(int i=1;i<=k;i++){
		value = value + q[i-1] * pos[i];
	}
	return value;
}
int dfspos[20],tmpos[20];
int getnext(bool& flag){
	for(int i=1;i<=k;i++){
		tmpos[i] = dfspos[i];
	}
	for(int i=1;i<=n;i++){
		tmpos[c[i]]+=d[i];
		if(tmpos[c[i]] > w[c[i]] || tmpos[c[i]] < 1){
			flag = 0;return i;
		}
	}
	return h(tmpos);
}
void dfs(int r){
	if(r>k){
		//求后继 
		int u = h(dfspos);
		cnt[u] = 1;
		bool flag = 1;
		long long value = getnext(flag);
		if(flag == 0){
			val[u] = value;
		}else{
			val[u] = n;
			addedge(u,value);
		}
		return;
	}
	for(int i=1;i<=w[r];i++){
		dfspos[r] = i;
		dfs(r+1);
		dfspos[r] = 0;
	}
} 
int cz[MAXN],st[MAXN][20];
int power[30];
int main(){
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	
	scanf("%d%d",&n,&k);
	for(int i=1;i<=k;i++){
		scanf("%d",&w[i]);
		maxq = max(maxq,w[i]+1);
	}
	//maxq进制
	q[0] = 1;
	for(int i=1;i<=k;i++){
		q[i] = q[i-1] * maxq;
	} 
	for(int i=1;i<=n;i++){
		scanf("%d%d",&c[i],&d[i]);
	}
	if(n<=100){
		//dfs求出每个点的后继点
		dfs(1);
	}else{
		printf("-1");return 0;
	}
	queue<int>qu; 
	int lim = q[k]; //hash的上界
	for(int i=1;i<=lim;i++){
		if(!insize[i]){
			topo[++topotot] = i;
			qu.push(i);
			cnt[i] = 1;
		}
	} 
	while(!qu.empty()){
		int u = qu.front();qu.pop();
		for(int j=first[u];j;j=next[j]){
			int v = edge[j].v;
			insize[v]--;
			if(!insize[v]){
				topo[++topotot] = v;
				qu.push(v);
			}
		}
	}
	for(int i=1;i<=lim;i++){
		if(insize[i]){
			printf("-1");return 0; //有环 
		}
	}
	//DP 
	long long ans = 0;
	for(int i=1;i<=topotot;i++){
		int u = topo[i];
		f[u] += cnt[u] * val[u];
		if(!first[u]){
			ans += f[u];
		}
		for(int j=first[u];j;j=next[j]){
			int v = edge[j].v;
			cnt[v] += cnt[u];
			f[v] += f[u];
		}
	}
	printf("%lld",ans);
	return 0;
}
