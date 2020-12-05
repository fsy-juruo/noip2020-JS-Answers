#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,m,w[15],p[15],st[15];
int c[N],d[N];
bool flag;
long long ans;
bool chk(){
	for(int i=1;i<=m;++i){
		if(st[i]!=p[i]) return 0;
	}
	return 1;
}
void dfs(int dep){
	if(dep>m){
		for(int i=1;i<=m;++i){
			st[i]=p[i];
		}
		for(int i=1;;i=i%n+1){
			p[c[i]]+=d[i];
			++ans;
			if(p[c[i]]<1||p[c[i]]>w[c[i]]) break;
			if(i==n) flag=chk();
		}
		for(int i=1;i<=m;++i){
			p[i]=st[i];
		}
		return;
	}
	for(int i=1;i<=w[dep];++i){
		p[dep]=i;
		dfs(dep+1);
		if(flag) return;
	}
}
int main(){
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;++i){
		scanf("%d",&w[i]);
	}
	for(int i=1;i<=n;++i){
		scanf("%d%d",&c[i],&d[i]);
	}
	dfs(1);
	if(flag){
		puts("-1");
		return 0;
	}
	printf("%lld\n",ans);
	return 0;
}
