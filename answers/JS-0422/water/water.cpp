#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, m;
int ind[1000001], outd[1000001];
bool vis[1000001];
struct dv{
	ll u, d;
};
dv tot[1000001];
vector<int> G[1000001];
ll egcd(ll x, ll y){
	if(y == 0) return x;
	return egcd(y, x % y);
}
void bfs(int x){
	queue<int> q;
	q.push(x);
	tot[x].u += tot[x].d;
	ll e = egcd(tot[x].u, tot[x].d);
	tot[x].u /= e, tot[x].d /= e;
	while(!q.empty()){
		int t = q.front();
		q.pop();
		dv gi;
		gi = tot[t];
		gi.d *= 1ll * outd[t];
		for(int i = 0;i < G[t].size();i++){
			int v = G[t][i];			
			tot[v].u = gi.u * tot[v].d + tot[v].u * gi.d;
			tot[v].d *= gi.d;
			ll e = egcd(tot[v].u, tot[v].d);
			tot[v].u /= e, tot[v].d /= e;
			q.push(v);
		}
		if(outd[t]) tot[t].u = 0, tot[t].d = 1;
	}
}
void naive(){
	for(int i = 1;i <= n;i++){
		int d;
		scanf("%d", &d);
		for(int j = 0;j < d;j++){
			int v;
			scanf("%d", &v);
			G[i].push_back(v);
			ind[v]++;
			outd[i]++;
		}
		tot[i].u = 0, tot[i].d = 1;
	}
	for(int i = 1;i <= n;i++){
		if(!ind[i]) bfs(i);
	}
	for(int i = 1;i <= n;i++){
		if(!outd[i]){
			printf("%lld %lld\n", tot[i].u, tot[i].d);
		}
	}
}
int main(){
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	scanf("%d %d", &n, &m);
	naive();
	return 0;
}
