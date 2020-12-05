#include<bits/stdc++.h>
#define N 10010
#define int long long
using namespace std;
void file(){
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
}
int n,m;
int deg[N];
struct fs{
	int u,v;
}val[N];
void print(fs a){
	printf("%lld %lld\n",a.u,a.v);
}
int gcd(int a,int b){
	if(!b)return a;
	else return gcd(b,a%b);
}
fs add(fs a,fs b){
	fs c;
	if(a.u==0)return b;
	if(b.u==0)return a;
	c.u=a.u*b.v+a.v*b.u;
	c.v=a.v*b.v;
	int g;
	if(c.u<c.v)g=gcd(c.u,c.v);
	else g=gcd(c.v,c.u);
	c.u/=g;c.v/=g;
	return c;
}
fs div(fs c,int n){
	c.v*=n;
	int g;
	if(c.u>c.v)g=gcd(c.u,c.v);
	else g=gcd(c.v,c.u);
	c.u/=g,c.v/=g;
	return c;
}
int ou[N];
vector<int> g[N];
void addedge(int u,int v){
	g[u].push_back(v);deg[v]++;
}
queue<int> Q;
fs M(int u,int v){
	fs t;t.u=u;t.v=v;
	return t;
}
void topo(){
	for(int i=1;i<=n;i++){
		if(!deg[i]){
			Q.push(i);
			val[i]=M(1,1);
		}
	}
	while(!Q.empty()){
		int u=Q.front();Q.pop();
		for(int i=0;i<g[u].size();i++){
			int v=g[u][i];
			val[v]=add(div(val[u],ou[u]),val[v]);
			deg[v]--;
			if(!deg[v])Q.push(v);
		}
	}
}
main()
{
	file();
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++){
		int c;scanf("%lld",&c);
		ou[i]=c;
		for(int j=1;j<=c;j++){
			int v;
			scanf("%lld",&v);
			addedge(i,v);
		}
	}
	topo();
	for(int i=1;i<=n;i++){
		if(ou[i]==0){
			print(val[i]);
		}
	}
	return 0;
}
/*
5 1
3 2 3 5
2 4 5
2 5 4
0
0*/
