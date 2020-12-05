#include<bits/stdc++.h>
#define re register
#define rep(i,x,y) for(re int i=x;i<=y;++i)
#define Rep(i,x,y) for(re int i=x;i>=y;--i)
#define _rep(i,x,y) for(re int i=x;i<y;++i)
#define _Rep(i,x,y) for(re int i=x;i>y;--i)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef double db;
template <typename T> inline T chkmax(T&x,T y){return (x=(x>y?x:y));}
template <typename T >inline T chkmin(T&x,T y){return (x=(x<y?x:y));}
template <typename T> inline void read(T&x)
{
	T f=1;x=0;char ch=getchar();
	while(ch<48||ch>57){if(ch=='-')f=-1;ch=getchar();}
	while(ch>=48&&ch<=57){x=(x<<3)+(x<<1)+ch-48;ch=getchar();}
	x*=f;
}
const int N=1e5+5;
ll f(ll x,ll y)
{
	if(y==0)
	return x;
	return f(y,x%y);
}
ll a[N],b[N];
int cnt[N],fa[N],to[N][10];
bool ff[N];
void add(int u,ll x,ll y)
{
	ll p=a[u],q=b[u];
	ll t=f(q,y);
	b[u]=q/t*y;
	a[u]=b[u]/q*p+b[u]/y*x;
	t=f(a[u],b[u]);
	a[u]/=t;b[u]/=t;
}
void dfs(int u)
{
//	cout<<u<<' '<<a[u]<<' '<<b[u]<<endl;
	if(fa[u]==0)
	{
		ll x=a[u],y=b[u],z=cnt[u];
		ll t=f(x,z);
		x/=t,z/=t,y*=z;
		rep(i,1,cnt[u])
		add(to[u][i],x,y),fa[to[u][i]]--,dfs(to[u][i]);
	}
	return;
}
int n,m;
int main()
{
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	scanf("%d%d",&n,&m);
	rep(i,1,n)
	{
		scanf("%d",&cnt[i]);
		rep(j,1,cnt[i])
		scanf("%d",&to[i][j]),fa[to[i][j]]++;
	}
	rep(i,1,n)b[i]=1;
	rep(i,1,n)
	if(fa[i]==0)
	ff[i]=1;
	rep(i,1,n)
	if(ff[i])
	a[i]=1,dfs(i);
	rep(i,1,n)
	if(cnt[i]==0)
	printf("%lld %lld\n",a[i],b[i]);
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
