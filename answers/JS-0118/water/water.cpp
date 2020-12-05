//I love Natsumi
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
void read(ll &x);
void add(ll x,ll y);
ll gcd(ll x,ll y);
ll lcm(ll x,ll y);
ll gc[6007][6007];
const ll MAXN=100007;
struct lsqxx{
	ll to,nxt;
	//ll val;
}g[MAXN*5];ll head[MAXN],d[MAXN],numofe;
struct fs{
	ll fz,fm;
	fs operator+(const fs&a)const{
		fs ls;ll b1,b2,g1;
		//cout<<this->fz<<' '<<this->fm<<' '<<a.fz<<' '<<a.fm<<endl;
		if(this->fz==0){
			ls=a;
			return ls;
		}
		if(a.fz==0){
			ls=*this;
			return ls;
		}
		ls.fm=lcm(this->fm,a.fm);
		b1=ls.fm/this->fm;b2=ls.fm/a.fm;
		ls.fz=(this->fz*b1)+(a.fz*b2);
		g1=gcd(ls.fm,ls.fz);
		ls.fm/=g1;
		ls.fz/=g1;
		return ls;
	}
}ans[MAXN];
ll n,m;
void work(ll x,fs wat)
{
	if(!d[x]){
		ans[x]=ans[x]+wat;
		return;
	}
	fs nx=wat;
	nx.fm*=d[x];
	for(register ll i=head[x];i;i=g[i].nxt)
	{
		work(g[i].to,nx);
	}
}
signed main()//60Pts
{
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	read(n);read(m);
	for(register ll i=1;i<=n;i++)
	{
		ans[i].fm=1;
		ll nx;read(d[i]);
		for(register ll j=1;j<=d[i];j++)
		{
			read(nx);
			add(i,nx);
		}
	}
	fs yi;
	yi.fm=1;yi.fz=1;

	for(register ll i=1;i<=m;i++)
		work(i,yi);
	for(register ll i=1;i<=n;i++)
	{
		if(!d[i])
		{
			cout<<ans[i].fz<<' '<<ans[i].fm<<endl;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
inline void add(ll x,ll y/*,ll z*/)
{
	g[++numofe].nxt=head[x];
	g[numofe].to=y;
	//g[numofe].val=z;
	head[x]=numofe;
}
inline void read(ll &x)
{
	x=0;ll f=1;
	char ch=getchar();
	while(!isdigit(ch))
	{
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(isdigit(ch))
	{
		x=(x<<3)+(x<<1)+ch-'0';
		ch=getchar();
	}
	x*=f;
}
ll gcd(ll x,ll y)
{
	if(!y)
		return x;
	if(x<=6000&&y<=6000)
		if(gc[x][y])
			return gc[x][y];
	if(x<=6000&&y<=6000)
		return gc[x][y]=gcd(y,x%y);
	else return gcd(y,x%y);
}
inline ll lcm(ll x,ll y)
{
	return (ll(x))*(ll(y))/(gcd(x,y));
}
