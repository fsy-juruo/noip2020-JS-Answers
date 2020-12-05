#include<bits/stdc++.h>
#define ll long long
#define N 500005
#define P 1000000007
#define ge getchar()
using namespace std;
ll n,w,a[N],c[N],d[N],q[N],p[N],g[N],ans=0,fl=1;
inline ll read(){
	ll x=0,f=1;char e=ge;
	for(;e<48||e>57;e=ge)if(e==45)f=0;
	for(;48<=e&&e<=57;e=ge)
	x=(x<<3)+(x<<1)+(e^48);
	return f?x:-x;
}
inline void work(){
	for(int i=1;i<=w;++i)p[i]=q[i];
	int t=1;for(;;){
		int h=c[t];p[h]+=d[t];++ans;
		if(p[h]<1||p[h]>a[h])return;
		if(t==n){t=1;if(fl){printf("-1");exit(0);}}
		else ++t;
	}
	
}
void dfs(int h){
	if(h>w){work();return;}
	for(int i=1;i<=a[h];++i)
	{q[h]=i;dfs(h+1);}
}
int main(){
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	n=read();w=read();
	for(int i=1;i<=w;++i)a[i]=read();
	for(int i=1;i<=n;++i){
		c[i]=read();d[i]=read();
		g[c[i]]+=d[i];
	}
	for(int i=1;i<=w;++i)
	if(g[i]){fl=0;break;}
	dfs(1);printf("%lld",ans%P);
	return 0;
}
