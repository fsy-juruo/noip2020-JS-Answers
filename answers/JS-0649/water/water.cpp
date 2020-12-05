#include <bits/stdc++.h>
#define ll long long
#define N 100005
using namespace std;

ll e[N][10],mp[N][5],mpp[N][5];
int n,m,t[N],cnt;
//q/p q->1 p->2

ll gcd(ll a,ll b){
	if(!b) return a;
	gcd(b,a%b);
}

void y(int n){
	ll k=gcd(mp[n][2],mp[n][1]);
	mp[n][2]/=k,mp[n][1]/=k;
}

void flow(int u,int v){
	ll k=gcd(mp[u][2],mp[v][2]);
	ll pv=(mp[u][2]/k),pu=(mp[v][2]/k);
	mp[v][1]=mp[u][1]*pu+mp[v][1]*pv;
	mp[v][2]*=pv;
	y(v);
}

void sub(int n,ll k){
	mp[n][2]=mp[n][2]*k;
	y(n);
}

void dfs(int n){
	if(!e[n][0]){
		return;
	}
	sub(n,e[n][0]);
	for(int i=1;i<=e[n][0];++i){
		flow(n,e[n][i]);
		dfs(e[n][i]);
	}
	mp[n][1]=0,mp[n][2]=1;
}

int main()
{
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i) mp[i][2]=1;
	for(int i=1;i<=n;++i){
		scanf("%lld",&e[i][0]);
		if(!e[i][0]){
			t[++cnt]=i;
			continue;
		}
		for(int k=1;k<=e[i][0];++k)
			scanf("%lld",&e[i][k]);
	}
	for(int i=1;i<=m;++i)
		mp[i][1]=1,mp[i][2]=1;
	for(int i=1;i<=m;++i)
		dfs(i);
	for(int i=1;i<=cnt;++i)
		printf("%lld %lld\n",mp[t[i]][1],mp[t[i]][2]);
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
