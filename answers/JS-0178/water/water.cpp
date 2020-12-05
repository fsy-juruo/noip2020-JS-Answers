#include<bits/stdc++.h>
using namespace std;
int n,m;
const int maxn=1e5+1;
struct node {
	int to,nxt;
} e[5*maxn];
int cn,head[maxn];
void add(int u,int v) {
	cn++;
	e[cn].to=v;
	e[cn].nxt=head[u];
	head[u]=cn;
}

long long gcd(long long a,long long b) {

	if(b%a==0)return a;

	return gcd(b%a,a);
}
long long x[maxn],fenzi[maxn],fenmu[maxn];
void dfs(int k) {
	for(int i=head[k]; i; i=e[i].nxt) {
		int v=e[i].to;
		if(!fenmu[v])
		dfs(v);
		if(!fenmu[k]) {
			fenmu[k]=x[v]*fenmu[v];
			fenzi[k]=fenzi[v];
		} else {
			if(x[v]*fenmu[v]==fenmu[k]) {
				fenzi[k]+=fenzi[v];
			} else {
				fenzi[k]=fenzi[k]*fenmu[v]*x[v]+fenzi[v]*fenmu[k];
				fenmu[k]*=fenmu[v];
				fenmu[k]*=x[v];
			}
		}
		long long mod=gcd(fenzi[v],fenmu[v]);
		fenzi[v]/=mod;
		fenmu[v]/=mod;

	}
}
int main() {
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1; i<=n; i++) {
		scanf("%lld",&x[i]);
		for(long long j=1; j<=x[i]; j++) {
			int v;
			scanf("%d",&v);
			add(v,i);
		}
	}
	for(int i=1; i<=m; i++) {
		fenzi[i]=fenmu[i]=1;

	}
	for(int i=1; i<=n; i++) {
		if(!x[i])dfs(i);
	}
	for(int i=1; i<=n; i++) {
		if(!x[i]) {
			long long mod=gcd(fenzi[i],fenmu[i]);
			printf("%lld %lld\n",fenzi[i]/mod,fenmu[i]/mod);
		}

	}
	return 0;
}

