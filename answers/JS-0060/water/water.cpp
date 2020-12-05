#include<bits/stdc++.h>
#define ll long long
#define int ll
#define ri register int
#define pb push_back
#define pii pair<int,int>
#define fi first
#define se second
#define mp make_pair
#define rep(i,a,b) for(ri i=(a);i<=(b);++i)
#define REP(i,a,b) for(ri i=(a);i>=(b);--i)
using namespace std;

inline int read(){
	ri x=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9')x=(x<<1)+(x<<3)+(c^48),c=getchar();
	return x*f;
}

const int N=1e5+5;
int n,m,t[N],du[N],q[N],a[N],b[N];
vector<int>gv[N];
inline int gcd(ri x,ri y){return y?gcd(y,x%y):x;}
signed main()
{
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	n=read();m=read();
	rep(i,1,n){
		t[i]=read();
		rep(j,1,t[i]){
			ri x=read();++du[x];
			gv[i].pb(x);
		}
	}
	ri l=1,r=0;
	rep(i,1,n)b[i]=1,a[i]=0;
	rep(i,1,n)if(!du[i])q[++r]=i,a[i]=1;
	while(l<=r){
		ri u=q[l],v,x=b[u]*t[u];++l;//cout<<u<<":";
		for(ri i=0;i<t[u];++i){
			v=gv[u][i];
			--du[v];ri aa=a[v]*x+b[v]*a[u],bb=x*b[v],gg=gcd(aa,bb);
			a[v]=aa/gg;b[v]=bb/gg;
			if(!du[v])q[++r]=v;
		}
		//rep(i,1,n)if(!t[i])cout<<i<<' '<<a[i]<<' '<<b[i]<<"      ";cout<<endl;
	}
	rep(i,1,n)if(!t[i]){
		//cerr<<a[i]<<' '<<b[i]<<endl;
		printf("%lld %lld\n",a[i],b[i]);
	}
	return 0;
}
