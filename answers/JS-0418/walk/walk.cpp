#include<bits/stdc++.h>
using namespace std;
struct node{int c,d;}step[500003];
int n,k,w[13],is[13],oi[13];
long long ans=0;
inline bool checks(){
	for(int i=1;i<=k;++i)if(oi[i]<1||oi[i]>w[i])return 0;
	return 1;
}
inline void dfs(int s){
	if(s==k+1){
		int nw=0;
		for(int i=1;i<=k;++i)oi[i]=is[i];
		while(checks()){
			oi[step[nw].c]+=step[nw].d;
			++ans;
			nw=(nw+1)%n;
		}
	}else{
		for(is[s]=1;is[s]<=w[s];++is[s]){
			dfs(s+1);
			if(ans==-1)return;
		}
	}
}
signed main(){
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=k;++i)scanf("%d",&w[i]);
	for(int i=0;i<n;++i)scanf("%d%d",&step[i].c,&step[i].d);
	dfs(1);
	printf("%lld",ans);
	return 0;
}
