#include<bits/stdc++.h>
using namespace std;
#define pb push_back
const int maxn=1e5+7;
const int maxm=5e5+7;
int n,m,head[maxm],cnt=1,cntf=1,tonum[maxn],final[maxn];
bool toed[maxn];
long long w_up[maxn],w_down[maxn];

inline int read(){
	int x=0,f=1;char c=getchar();
	while (c<'0'||c>'9') {if (c=='-') f=-1;c=getchar();}
	while (c>='0'&&c<='9') {
		x=(x<<1)+(x<<3)+(c^48);
		c=getchar();
	}
	return x*f;
}
struct node{
	int nxt,to;
} edge[maxm];
void addline(int u,int v){
	edge[cnt].nxt=head[u];
	edge[cnt].to=v;
	//edge[cnt].w=w;
	head[u]=cnt++;
	return ;
}
long long gcd(long long x,long long y){//x>y
	if (y>x){
		long long t=y;
		y=x;x=t;
	}
	if (!(x%y)) return y;
	return gcd(y,x%y);
}
long long max_gcd(long long x,long long y){
	return x*y/gcd(x,y);
}
void add(int x,int y){
	long long xup=w_up[x],xdown=w_down[x];
	long long yup=w_up[y],ydown=w_down[y];
	if (!yup) {
		w_down[y]=w_down[x];
		w_up[y]=w_up[x];
		return ;
	}
	long long maxd=max_gcd(xdown,ydown);
	xup*=maxd/xdown,yup*=maxd/ydown;
	yup+=xup;
	long long mind=gcd(yup,maxd);
	w_up[y]=yup/mind,w_down[y]=maxd/mind;
	return ;
}
void dfs(int x){
	//cout<<x<<" "<<w_up[x]<<"/"<<w_down[x]<<endl;
	long long div=(long long)tonum[x];
	if (!tonum[x]) return ;
	if (!(w_up[x]%div)){
		w_up[x]/=div;
	}
	else{
		w_down[x]*=div;
	}
	
	for (int i=head[x];i;i=edge[i].nxt){
		int v=edge[i].to;
		add(x,v);
		dfs(v);
	}
	w_up[x]=0,w_down[x]=1;
	return ;
}
int main(){
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	n=read();m=read();
	for (int i=1;i<=n;i++){
		tonum[i]=read();
		w_down[i]=1;
		if (!tonum[i]) {
			final[cntf++]=i;
		}
		for (int j=1;j<=tonum[i];j++){
			int x=read();
			toed[x]=1;
			addline(i,x);
		}
	}
	for (int i=1;i<=n;i++){
		if (!toed[i]){
			w_up[i]=1;
			dfs(i);
			//cout<<i<<endl;
		}
	}
	for (int i=1;i<cntf;i++){
		printf("%lld %lld\n",w_up[final[i]],w_down[final[i]]);
	}
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
