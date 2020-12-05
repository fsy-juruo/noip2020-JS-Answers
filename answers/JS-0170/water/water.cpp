#include<bits/stdc++.h>
using namespace std;
int n,m,d[100005],a,h[100005];
long long p[100005],q[100005];
vector<int>e[100005];
int gcd(int x,int y){
	if(y==0)return x;
	else return gcd(y,x%y);
}
void dfs(int u,int pu,int qu){
	if(d[u]==0){
		int Q=qu*q[u]/gcd(qu,q[u]);
		p[u]=Q/q[u]*p[u]+Q/qu*pu;
		q[u]=Q;
	//	p[u]=p[u]/gcd(p[u],q[u]);
	//	q[u]=q[u]/gcd(p[u],q[u]);
		return;
	}
	int g1=gcd(pu,d[u]);
	pu=pu/g1;
	qu=qu*(d[u]/g1);
	for(int v=0;v<e[u].size();v++)
		dfs(e[u][v],pu,qu);
	return;
}
int main(){
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		scanf("%d",&d[i]);
		q[i]=1;
		for(int j=1;j<=d[i];j++){
			scanf("%d",&a);
			h[a]=1;
			e[i].push_back(a);
		}
	}
	for(int i=1;i<=n;i++)
		if(h[i]==0)
			dfs(i,1,1);
	for(int i=1;i<=n;i++)
		if(d[i]==0)printf("%lld %lld\n",p[i]/gcd(p[i],q[i]),q[i]/gcd(p[i],q[i]));
	fclose(stdin);
	fclose(stdout);
	return 0;
}
