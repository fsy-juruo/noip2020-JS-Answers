#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int n,m,ind[N];
long long p[N],q[N];
vector<int> G[N];
queue<int> qu;
long long mgcd(long long x,long long y){
	return !y?x:__gcd(y,x%y);
}
void add(int t,int s){
	long long p1=p[t],q1=q[t],p2=p[s],q2=q[s]*G[s].size(),pp=p1*q2+p2*q1,qq=q1*q2,mo=mgcd(pp,qq);
	q[t]=qq/mo,p[t]=pp/mo;
}
void topo(){
	int u,v;
	while(!qu.empty()){
		u=qu.front();qu.pop();
		for(int i=0;i<(int)G[u].size();i++){
			v=G[u][i];
			add(v,u);
			ind[v]--;
			if(!ind[v])qu.push(v);
		}
	}
}
int main(){
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	int d,a;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&d);
		while(d--){
			scanf("%d",&a);
			G[i].push_back(a);
			ind[a]++;
		}
		if(i<=m)p[i]=q[i]=1;
		else q[i]=1;
	}
	for(int i=1;i<=n;i++)if(!ind[i])qu.push(i);
	topo();
	for(int i=1;i<=n;i++)if(G[i].empty())printf("%lld %lld\n",p[i],q[i]);
	return 0;
}
