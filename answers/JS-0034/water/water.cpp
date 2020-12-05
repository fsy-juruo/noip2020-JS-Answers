#include<bits/stdc++.h>
#include<vector>
using namespace std;
long long getgcd(long long x,long long y){
	if(y==0) return x;
	return getgcd(y,x%y);
}
struct fen{
	long long fm,fz;
	fen(){
		fm=1,fz=0;
	}
	fen(long long m,long long z){
		fm=m;fz=z;
	}
	fen operator +(fen x2) const{
		long long nfm=fm*x2.fm,nfz=fz*x2.fm+fm*x2.fz;
		long long g=getgcd(nfm,nfz);
		if(g!=0) nfm/=g,nfz/=g;
		fen x;
		x=fen(nfm,nfz);
		return x;
	}
	fen operator *(fen x2) const{
		long long nfm=fm*x2.fm,nfz=fz*x2.fz;
		long long g=getgcd(nfm,nfz);
		if(g!=0) nfm/=g,nfz/=g;
		fen x;
		x=fen(nfm,nfz);
		return x;
	}
};
vector<int> nei[100005],renei[100005];
vector<int> ver;
bool vis[100005];
void dfs(int v){
	vis[v]=1;
	for(int i=0;i<nei[v].size();i++){
		int u=nei[v][i];
		if(vis[u]) continue;
		dfs(u);
	}
	ver.push_back(v);
}
fen dp[100005];
vector<int> anpos;
int main(){
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	int n,m;
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++){
		int t;
		scanf("%d",&t);
		for(int j=0;j<t;j++){
			int x;
			scanf("%d",&x);
			x--;
			nei[i].push_back(x);
			renei[x].push_back(i);
		}
		if(!t) anpos.push_back(i);
	}
	for(int i=0;i<n;i++){
		if(!vis[i]) dfs(i);
	}
	reverse(ver.begin(),ver.end());
	for(int i=0;i<n;i++){
		int v=ver[i];
		if(v<m) dp[v]=fen(1,1);
		for(int j=0;j<renei[v].size();j++){
			int u=renei[v][j];
			fen tmp=fen((int)nei[u].size(),1);
			dp[v]=dp[v]+(dp[u]*tmp);
		}
	}
	for(int i=0;i<anpos.size();i++){
		printf("%lld %lld\n",dp[anpos[i]].fz,dp[anpos[i]].fm);
	}
	return 0;
}
