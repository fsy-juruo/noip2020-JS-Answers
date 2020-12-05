#include<bits/stdc++.h>
#define pb push_back
#define MP make_pair
#define PII pair<int,int>
#define fir first
#define sec second
using namespace std;
typedef long long ll;
const int Inf=0x3f3f3f3f;
const ll Infll=1e18+7;
const int MAXN=1e6+10;
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-') f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+(ch-48);ch=getchar();}
	return x*f;
}
inline ll readll(){
	ll x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-') f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+(ch-48);ch=getchar();}
	return x*f;
}
struct Edge{int to,nxt;}e[MAXN];
int ecnt,head[MAXN];
inline void add_edge(int u,int v){e[++ecnt].to=v;e[ecnt].nxt=head[u];head[u]=ecnt;}

inline ll Gcd(ll a,ll b){return b==0ll?a:Gcd(b,a%b);}
int n,m;
int ind[MAXN],oud[MAXN];
ll p[MAXN],q[MAXN];
queue<int> qq;
inline void Work(int x,int y){
	ll d=q[x]*q[y]*oud[x];
	ll c=p[x]*q[y]+p[y]*q[x]*oud[x];
	ll g=Gcd(c,d);
	d/=g;c/=g;
	p[y]=c;q[y]=d;
}
inline void Topo(){
	for(int i=1;i<=m;++i){
		p[i]=1;
		qq.push(i);
	}
	while(!qq.empty()){
		int x=qq.front();qq.pop();
		for(int i=head[x],y;i;i=e[i].nxt){
			y=e[i].to;--ind[y];
			Work(x,y);
			if(!ind[y]) qq.push(y);
		}
	}
}
int main(){
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	n=read();m=read();
	for(int i=1,d;i<=n;++i){
		d=read();
		for(int j=1,x;j<=d;++j){
			x=read();++oud[i];++ind[x];
			add_edge(i,x);
		}
		q[i]=1;
	}
	Topo();
	for(int i=m+1;i<=n;++i){
		if(oud[i]) continue;
		printf("%lld %lld\n",p[i],q[i]);
	}
	return 0;
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
