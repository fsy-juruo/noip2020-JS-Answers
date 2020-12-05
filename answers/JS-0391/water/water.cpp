#include<bits/stdc++.h>
using namespace std;
#define re register
#define Re register
#define ll long long
#define ull unsigned long long
#define MAXN 100005
struct num{
	ll p,q;
}a[MAXN];
num operator+(num x,num y){
	num ans;
	ans.q = x.q * y.q;
	ans.p = x.p * y.q + y.p * x.q;
	ll tmp = __gcd(ans.p,ans.q);
	ans.p /= tmp;ans.q /= tmp;
	return ans;
}
int n,m,d[MAXN];
int h[MAXN],nxt[MAXN],e[MAXN],idx;//graph
void addedge(int u,int v){
	e[idx] = v;nxt[idx] = h[u];h[u] = idx++;
}
bool ok[MAXN];
void dfs(int pos,num val){
	if(d[pos] == 0){a[pos] = a[pos] + val;ok[pos] = true;return;}
	val.q *= d[pos];
	for(re int i = h[pos];i != -1;i = nxt[i]){
		dfs(e[i],val);
	}
}
int main() {
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	scanf("%d%d",&n,&m);
	memset(h,-1,sizeof h);
	for(re int i = 1;i <= n;i++){
		scanf("%d",&d[i]);
		a[i].q = 1;
		for(re int j = 1;j <= d[i];j++){
			int v;
			scanf("%d",&v);
			addedge(i,v);
		}
	}
	for(re int i = 1;i <= m;i++){
		dfs(i,(num){1,1});
	}
	for(re int i = 1;i <= n;i++){
		if(ok[i])printf("%lld %lld\n",a[i].p,a[i].q);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
