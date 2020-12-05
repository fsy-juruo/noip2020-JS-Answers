#include<bits/stdc++.h>
#define int long long
#define N 100015
#define rep(i,a,b) for(int i=a;i<=b;++i)
#define per(i,a,b) for(int i=b;i>=a;--i)
#define all(x) x.begin(),x.end()
#define VI vector<int>
#define pii pair<int,int>
#define SZ(x) ((int)x.size())
#define fi first
#define se second
#define mp make_pair
#define pb push_back
using namespace std;
struct frac{
	int a,b; // a/b
	frac(){a = 0;b = 1;}
	int gcd(int x,int y){
		if(y == 0) return x;
		return gcd(y,x%y);
	}
	void hj(){int g = gcd(a,b); a /= g; b /= g;}
	frac(int x,int y){a = x;b = y; hj();}
	frac operator +(const frac &o) const{ // a/b + o.a/o.b = a*o.b+b*o.a/b*o.b
		frac res;
		res = frac(a*o.b+b*o.a,b*o.b);
		return res;
	}
	frac operator -(const frac &o) const{
		frac oo = frac(-o.a,o.b);
		frac res;
		res = frac(a*oo.b+b*oo.a,b*oo.b);
		return res;
	}
	frac operator *(const frac &o) const{
		return frac(a*o.a,b*o.b);
	}
	frac operator *(const int o) const{
		return frac(a*o,b);
	}
	frac operator /(const int o) const{
		if(o == 0) return frac(0,1);
	//	printf("a: %lld b: %lld o: %lld\n",a,b,o);
		return frac(a,b*o);
	}
	void print(){
		printf("%lld %lld\n",a,b);
	}
}V[N];
int n,m,in[N];
VI e[N],ans;
queue<int> q;
void topo(){
	rep(i,1,n) if(in[i] == 0) q.push(i);
	while(!q.empty()){
		int u = q.front(); q.pop();
	//	printf("u: %lld\n",u);
		frac val = V[u]/SZ(e[u]);
		//val.print();
		rep(j,0,SZ(e[u])-1){
			int v = e[u][j];
			V[v] = V[v]+val;
			if(--in[v] == 0) q.push(v);
		}
	}
}
signed main(){
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	rep(i,1,m) V[i] = frac(1,1);
//	V[1].print();
//	V[2].print();
	rep(i,1,n){
		int sz; scanf("%lld",&sz);
		if(sz == 0) ans.pb(i);
		rep(j,1,sz){
			int to; scanf("%lld",&to);
			e[i].pb(to);
			in[to]++;
		}
	}
	topo();
	//puts("zpsakking");
	rep(i,0,SZ(ans)-1) V[ans[i]].print();
	return 0;
}

