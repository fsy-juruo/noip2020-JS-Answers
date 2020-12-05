#include<bits/stdc++.h>
#include<stdio.h>
using namespace std;
#define rg register
#define inf 0x7f7f7f7f
#define ll long long
#define maxn 100005
inline int read(){
	rg int ret=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		ret=ret*10+ch-'0';
		ch=getchar();
	}
	return ret*f;
}
struct node{
	int nex,to;
}e[maxn*5];
int n,m,d[maxn],v,head[maxn],cnt,out[maxn],cnt2;
bool vis[maxn];
ll q[maxn],p[maxn];
inline ll gc(ll a,ll b){
	return b==0?a:gc(b,a%b);
}
inline void add(int u,int v){
	e[++cnt].nex=head[u];
	e[cnt].to=v;
	head[u]=cnt;
}
inline void solve(int x,int k){
	for(rg int i=head[x];i;i=e[i].nex){
		p[e[i].to]=p[e[i].to]*k*d[x]+q[e[i].to];
		q[e[i].to]*=k*d[x];
		ll gcdd=gc(p[e[i].to],q[e[i].to]);
		p[e[i].to]/=gcdd;
		q[e[i].to]/=gcdd;
		solve(e[i].to,k*d[x]);
	}
}
int main(){
	//hsy try tie tie!
	//hsy ak ioi
	//fuck U ccf!
	//nmsl ccf!
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	n=read(); m=read();
	for(rg int i=1;i<=n;++i){
		d[i]=read(); 
		if(d[i]==0) out[++cnt2]=i;
		for(rg int j=1;j<=d[i];++j){
			v=read(); add(i,v);
		}
		q[i]=1;
	}
	for(rg int i=1;i<=m;++i){
		q[i]=p[i]=1;
		solve(i,1);
	}
	for(rg int i=1;i<=cnt2;++i){
		printf("%lld %lld\n",p[out[i]],q[out[i]]);
	}
}
