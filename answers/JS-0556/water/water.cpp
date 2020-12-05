/*
EI说过，希望都打上了注释
那么，我就多来些注释所带来的希望罢
EI ORZ
神仙墙上的所有神仙 ORZ
NOIP RP ++
NOIP RP ++
NOIP RP ++
NOIP RP ++
NOIP RP ++
NOIP RP ++
NOIP RP ++
*/
#include<bits/stdc++.h>
#define reg register
#define ri reg int
#define ll long long
#define mp make_pair
#define pii pair<int,int>
using namespace std;
inline void read(int&x){
	x=0;
	char c=getchar();
	for(;!isdigit(c);c=getchar());
	x=c-'0';
	for(c=getchar();isdigit(c);c=getchar())x=x*10+c-'0';
}
inline void print(int x){
	if(x<0)putchar('-'),x=-x;
	if(x>9)print(x/10);
	putchar(x%10+'0');
}
struct frac{
	ll a,b;
	inline void init(){
		a=0;
		b=1;
	}
	inline void G(ll x){
		a=x;
		b=1;
	}
	inline void D(){
		if(a==0)return;
		ll t=__gcd(a,b);
		a/=t,b/=t;
	}
	inline void print(){
		printf("%lld %lld\n",a,b);
	} 
};
inline frac operator +(const frac x,const frac y){
	ll t=__gcd(x.b,y.b);
	t=x.b/t*y.b;
	frac rt;rt.init();
	rt.b=t;
	rt.a=x.a*(t/x.b)+y.a*(t/y.b);
	rt.D();
	return rt;
}
inline frac operator *(frac x,frac y){
	ll t;
	t=__gcd(x.a,y.b);
	x.a/=t,y.b/=t;
	t=__gcd(x.b,y.a);
	x.b/=t,y.a/=t;
	frac rt;rt.init();
	rt.a=x.a*y.a;
	rt.b=x.b*y.b; 
	rt.D();
	return rt;
}
inline frac operator /(frac x,frac y){
	swap(y.a,y.b);
	return x*y;
}
const int mxn=1e5+5;
frac F[mxn];
int n,m;
vector<int>g[mxn];
int ord[mxn],deg[mxn],cntord;
inline void Topsort(){
	queue<int>q;for(;q.size();)q.pop();
	for(int i=1;i<=n;++i)if(!deg[i])q.push(i);
	for(;q.size();){
		int x=q.front();q.pop();
		ord[++cntord]=x;
		for(int i=0;i<g[x].size();++i){
			int y=g[x][i];
			--deg[y];
			if(!deg[y])q.push(y);
		}
	}
}
inline void solve(){
	for(int i=1;i<=n;++i)F[i].init();
	for(int i=1;i<=m;++i)F[i].G(1);
	for(int i=1;i<=cntord;++i){
		int x=ord[i];
		if(!g[x].size())continue;
		frac t=F[x],d;
		d.G(g[x].size());
		t=t/d;
		for(int j=0;j<g[x].size();++j){
			int y=g[x][j];
			F[y]=F[y]+t;
		}
		F[x].init();
	}
}
int main(){
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	ios_base::sync_with_stdio(false);
	read(n),read(m);
	for(int i=1;i<=n;++i){
		int l;read(l);
		for(int x;l--;){
			read(x);
			g[i].push_back(x);++deg[x];
		}
	}
	Topsort();
	solve();
	for(int i=1;i<=n;++i)if(g[i].size()==0)F[i].print();
	return 0;
}
