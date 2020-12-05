#include <bits/stdc++.h>
using namespace std;
#define rg register
#define xh(i,l,r) for (rg int i=(l);i<=(r);i++)
#define read(a) scanf("%d",&(a))
#define write(a) printf("%d ",(a))
#define writeln puts("")
#define qmax(a,b) ((a)<(b)?(b):(a))
#define qmin(a,b) ((a)>(b)?(b):(a))
#define Babara_is_so_cute(f) freopen(f".in","r",stdin);freopen(f".out","w",stdout);
#define Babara_is_the_best fclose(stdin);fclose(stdout);

typedef long long ll;
#define readl(a) scanf("%lld",&(a))
#define writel(a) printf("%lld ",(a))

const int N=1e5+5;
struct edge{
	int to,nxt;
}e[N];
int head[N],cnt=0;
void addedge(int fro,int tod){
	++cnt;
	e[cnt].to=tod;
	e[cnt].nxt=head[fro];
	head[fro]=cnt;
}
#define tjwnb(i,u) for (rg int i=head[u];i;i=e[i].nxt)

int n,m,dou[N],din[N];
ll stm[N][3];
queue<int> qu;

ll gcd(ll a,ll b){
	if (a%b==0) return b;
	return gcd(b,a%b);
}
void pls(ll a,ll b,int v){// stm[v]+a/b
	ll c=stm[v][1],d=stm[v][2];
	ll x=b*c+a*d,y=b*d;
	ll dd=gcd(x,y);
	x/=dd;y/=dd;
	stm[v][1]=x;stm[v][2]=y;
}
void init(){
	memset(head,0,sizeof(head));
	read(n);read(m);
	int v;
	xh(i,1,n){
		if (i<=m) stm[i][1]=stm[i][2]=1;
		else stm[i][1]=0,stm[i][2]=1;
		read(dou[i]);
		xh(j,1,dou[i]){
			read(v);addedge(i,v);
			din[v]++;
		}
	}
}
void solve(){
	xh(i,1,m){
		qu.push(i);
	}
	while (!qu.empty()){
		int u=qu.front();
		qu.pop();
		tjwnb(i,u){
			int v=e[i].to;
			ll dd=gcd(stm[u][1],dou[u]);
			pls(stm[u][1]/dd,dou[u]/dd*stm[u][2],v);
			din[v]--;
			if (din[v]==0) qu.push(v);
		}
	}
	xh(i,1,n){
		if (dou[i]==0) {
			writel(stm[i][1]);writel(stm[i][2]);writeln;
		}
	}
}

int main(){
	Babara_is_so_cute("water")
	init();
	solve();
	Babara_is_the_best
	return 0;
}
