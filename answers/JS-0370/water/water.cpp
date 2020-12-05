#include <bits/stdc++.h>
using namespace std;
#define fz(i,a,b) for(int i=a;i<=b;i++)
#define fd(i,a,b) for(int i=a;i>=b;i--)
#define ffe(it,v) for(__typeof(v.begin()) it=v.begin();it!=v.end();it++)
#define fi first
#define se second
#define fill0(a) memset(a,0,sizeof(a))
#define fill1(a) memset(a,-1,sizeof(a))
#define fillbig(a) memset(a,63,sizeof(a))
#define pb push_back
#define mp make_pair
typedef long long ll;
template<typename T>
void read(T &x){
	x=0;char c=getchar();T neg=1;
	while(!isdigit(c)){
		if(c=='-') neg=-1;
		c=getchar();
	}
	while(isdigit(c)) x=x*10+c-'0',c=getchar();
	x*=neg;
}
const int MAXN=1e5+5;
const int MAXM=5e5+5;
ll gcd(ll x,ll y){return (!y)?x:gcd(y,x%y);}
int n,m,in[MAXN],out[MAXN];
struct frac{
	ll a,b;
	frac(){a=0;b=1;}
	frac(ll _a,ll _b){a=_a;b=_b;}
	void clear(){ll g=gcd(a,b);a/=g;b/=g;}
} a[MAXN];
frac divi(frac x,ll y){
	frac ret=x;ret.b*=y;ret.clear();return ret;
}
frac add(frac x,frac y){
	ll lcm=1ll*x.b*y.b/gcd(x.b,y.b);
	frac ret;
	ret.b=lcm;
	ret.a=1ll*lcm/x.b*x.a+1ll*lcm/y.b*y.a;
	ret.clear();return ret;
}
int hd[MAXN],to[MAXM],nxt[MAXM],ec=0;
void adde(int u,int v){
	to[++ec]=v;nxt[ec]=hd[u];hd[u]=ec;
}
int main(){
	freopen("water.in","r",stdin);freopen("water.out","w",stdout);
	read(n);read(m);
	for(int i=1;i<=n;i++){
		read(out[i]);
		for(int j=1;j<=out[i];j++){
			int x;read(x);adde(i,x);in[x]++;
		}
	}
	for(int i=1;i<=m;i++) a[i]=frac(1,1);
	queue<int> q;for(int i=1;i<=n;i++) if(!in[i]) q.push(i);
	while(!q.empty()){
		int x=q.front();q.pop();
		for(int e=hd[x];e;e=nxt[e]){
			int y=to[e];
			a[y]=add(a[y],divi(a[x],out[x]));
			in[y]--;if(!in[y]) q.push(y);
		}
	}
	for(int i=1;i<=n;i++) if(!out[i])
		printf("%lld %lld\n",a[i].a,a[i].b);
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
