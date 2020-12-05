#include<bits/stdc++.h>
#define rep(i,a,b) for(register int i=a;i<=b;++i)
#define dec(i,a,b) for(register int i=a;i>=b;--i)
#define il inline
typedef long long ll;
using namespace std;

il void filejudge(){
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
}

namespace io{
	il int read(){
		int x=0;char ch=getchar();bool f=0;
		while(!isdigit(ch)){if(ch=='-') f=1; ch=getchar();}
		while(isdigit(ch)){ x=(x<<3)+(x<<1)+(ch^48);ch=getchar();}
		return f?-x:x;
	}
}
using io::read;

struct node{
	ll a,b;
	il void init(){ a=0;b=1;}
};
il ll gcd(ll x,ll y){ if(y==0) return x; return gcd(y,x%y);}
/*---- calc ----*/
il void up(node &x){
	ll g=gcd(x.a,x.b);
	x.a/=g;x.b/=g;
}
il void div(node &x, ll y){
	x.b*=y;
	up(x);
}
il void add(node &x,node y){
	x.a=x.a*y.b+x.b*y.a;
	x.b=x.b*y.b;
	up(x);
}
/*---- calc -----*/
/*---- graph ----*/
const int N=100100;
const int M=500100;
#define repe(i,u) for(register int i=head[u];i;i=e[i].nxt)
struct Edge{ int v,nxt;} e[M];int tot,head[N],d[N];
node res[N];
il void add_edge(int u,int v){ e[++tot].v=v;e[tot].nxt=head[u];head[u]=tot;d[v]++;}
queue<int> q;
/*--- graph ----*/
int n,m;
ll out[N];
/*--- top ----*/
il void topsort(){
	rep(i,1,n){
		res[i].init();
		if(d[i]==0){
			res[i].a=1;
			q.push(i);
		}
	}
	while(!q.empty()){
		int u=q.front();q.pop();
		if(out[u]==0) continue;
		div(res[u],out[u]);
		repe(i,u){
			int v=e[i].v;
			add(res[v],res[u]);
			d[v]--; 
			if(!d[v]) q.push(v);
		}
	}
}
/*--- top ----*/
int main(){
	filejudge();
	n=read();m=read();
	rep(i,1,n){
		out[i]=read();
		if(out[i]==0) continue;
		rep(j,1,out[i]){
			int v=read();
			add_edge(i,v);
		}
	}
	topsort();
	rep(i,1,n){
		if(out[i]==0) printf("%lld %lld\n",res[i].a,res[i].b);
	}
	return 0;
}
