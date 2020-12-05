#include<bits/stdc++.h>
#define maxn 10005
#define int long long
using namespace std;
struct node{
	int u,v,nex;
};
struct node1{
	int p,q;
};
node edge[maxn*5];
node1 f[maxn];
int n,m,head[maxn],h[maxn],t[maxn],s[maxn],T=0,g[maxn];
int gym(int x,int y){
	int xa=min(x,y),ya=max(x,y);
	while(ya%xa!=0){
		int g=xa;
		xa=ya%xa;ya=g;
	}
	return (x/xa)*xa*(y/xa);
}
void add(int y,int p,int q){
	int p1=f[y].p,q1=f[y].q;
	if(p1==0&&q1==0){
		f[y].p=p;f[y].q=q;
	}
	else{
		int g=gym(q1,q);
		f[y].q=g;f[y].p=p1*(g/q1)+p*(g/q);
	}
	return ;
}
void work(int x,int p,int q){
	int k=q*g[x];
	for(int i=head[x];i;i=edge[i].nex){
		int y=edge[i].v;
		add(y,p,k);
		work(y,p,k);
	}
	return ;
}
void check(int x){
	int p=f[x].p,q=f[x].q;
	int xa=min(p,q),ya=max(p,q);
	while(ya%xa!=0){
		int g=xa;
		xa=ya%xa;ya=g;
	}
	f[x].p=f[x].p/xa;f[x].q=f[x].q/xa;
}
signed main(){
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	memset(s,0,sizeof(s));
	memset(f,0,sizeof(f));
	cin>>n>>m;
	int tot=0,H=0;
	for(int i=1;i<=n;i++){
		cin>>g[i];
		for(int j=1;j<=g[i];j++){
			int x=i,y;
			cin>>y;
			s[y]++;
			edge[++tot].u=x;edge[tot].v=y;edge[tot].nex=head[x];head[x]=tot;
		}
		if(g[i]==0) t[++T]=i;
	}
	for(int i=1;i<=n;i++)if(s[i]==0)h[++H]=i;
	for(int i=1;i<=m;i++)work(i,1,1);
	for(int i=1;i<=T;i++){
		check(t[i]);
		cout<<f[t[i]].p<<" "<<f[t[i]].q<<endl;
	}
	return 0;
}
