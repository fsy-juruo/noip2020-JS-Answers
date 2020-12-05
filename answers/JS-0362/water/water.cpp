#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define mp make_pair
#define fir first
#define sec second
inline int read() {
	int x(0),neg(1);char ch(getchar());
	while(!isdigit(ch)) {if (ch=='-') neg=-1;ch=getchar();}
	while(isdigit(ch)) {x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
	return x*neg;
}
const int MAXN=200000;
inline int gcd(int x,int y) {
	if (!y) return x;
	return gcd(y,x%y);
}
vector<int> g[MAXN+5];
int q[MAXN+5],l,r;
int d[MAXN+5];
int a[MAXN+5],b[MAXN+5],c[MAXN+5];
inline void calc(int u,int v) {
	if (a[v]==0 && b[v]==0) {
		int mu=b[u]*c[u],o=a[u];
		int g=gcd(mu,o);
		a[v]=o/g,b[v]=mu/g;
	}
	else {
		int mu=b[u]*b[v]*c[u],o=a[u]*b[v]+a[v]*b[u]*c[u];
		int g=gcd(mu,o);
		a[v]=o/g,b[v]=mu/g;
	}
//	cout<<u<<' '<<v<<' '<<a[v]<<' '<<b[v]<<endl;
}
signed main() { 
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	int	n=read(),m=read();
	for (int i=1;i<=n;++i) {
		c[i]=read();
		for (int j=1;j<=c[i];++j) {
			int v(read());
			g[i].pb(v);
			++d[v];
		}
	}
	l=r=1;
	for (int i=1;i<=m;++i) q[++r]=i,a[i]=1,b[i]=1;
	while(l<r) {
		int u=q[++l];
		for (int i=0;i<g[u].size();++i) {
			int v=g[u][i];
			calc(u,v);
			--d[v];
			if (!d[v]) q[++r]=v;
		}
	}
	for (int i=m+1;i<=n;++i) {
		if (!c[i]) {
			printf("%lld %lld\n",a[i],b[i]);
		}
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
