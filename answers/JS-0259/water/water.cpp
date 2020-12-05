#include<bits/stdc++.h>
using namespace std;
#define reg register
typedef long long ll;
const int N=1e6+5;
inline int read(){
	int x=0,f=1;char c;
	while((c=getchar())<'0'||c>'9') if(c=='-') f=0;
	while(c>='0'&&c<='9') x=(x<<3)+(x<<1)+(c^48),c=getchar();
	return f?x:-x;
}
int n,m,h[N],cnt,nxt[N],to[N],in[N];
ll fz[N],fm[N],out[N];
ll Gcd(ll a,ll b){
	if(!b) return a;
	return Gcd(b,a%b);
}
inline void add(int u,int v){
	to[++cnt]=v,nxt[cnt]=h[u],h[u]=cnt,in[v]++,out[u]++;
}
queue<int> q;
void topo(){
	for(reg int i=1;i<=n;i++) if(!in[i]) fz[i]=1,q.push(i);
	while(!q.empty()){
		reg int u=q.front();q.pop();
		for(reg int i=h[u];i;i=nxt[i]){
			reg int v=to[i];
			ll x=fm[u]*out[u]*fz[v]+fm[v]*fz[u],y=fm[u]*fm[v]*out[u];
			ll gcd=Gcd(x,y);
			fm[v]=y/gcd,fz[v]=x/gcd;
			in[v]--;
			if(!in[v]) q.push(v);
		}
	}
}
int main()
{
	freopen("water.in","r",stdin);freopen("water.out","w",stdout);
	n=read(),m=read();int x,y;
	for(reg int i=1;i<=n;i++){
		x=read();
		while(x--){
			y=read();add(i,y);
		}
	}
	for(reg int i=1;i<=n;i++) fm[i]=1;
	topo();
	for(reg int i=1;i<=n;i++)
		if(!out[i]) printf("%lld %lld\n",fz[i],fm[i]);
	return 0;
}
