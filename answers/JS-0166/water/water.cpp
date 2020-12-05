#include<bits/stdc++.h>
using namespace std;
#define MAXN 100005
typedef long long ll;
ll dat[MAXN][6];
ll num[MAXN];
int cnt[MAXN];
ll n,m;
char chll;bool flagp=0;
ll gcd(ll a,ll b)
{
	if(b==0)return a;
	else gcd(b,a%b);
}
ll yt;
struct mm{
	ll a,b;
	void yf()
	{
		yt=gcd(a,b);
		a/=yt,b/=yt;	
	}
}qq[MAXN];
mm plusk(mm x,mm y)
{
	mm c;
	c.a=x.a*y.b+x.b*y.a;
	c.b=x.b*y.b;
	c.yf();
	return c;
}
void sc(ll &axp)
{
	axp=0;
	flagp=0;chll=getchar();
	while(!isdigit(chll)){if(chll=='-')flagp=1;chll=getchar();}
	while(isdigit(chll)){axp=(axp<<1)+(axp<<3)+(chll-48);chll=getchar();}
	if(flagp)axp=-axp;
	return ;
}
void pr(ll axp)
{
	if(axp==0) return ;
	if(axp<0){putchar('-');axp=-axp;}
	pr(axp/10);
	putchar(axp%10+'0');
	return ;
}
void dfs(ll x,mm k)
{
//	cout<<1<<endl;
	qq[x]=plusk(k,qq[x]);
	k.b*=num[x];
	for(ll i=1;i<=num[x];i++)
		dfs(dat[x][i],k);
	return ;		
}
int main()
{
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	for(ll i=1;i<=MAXN;i++)qq[i].a=0,qq[i].b=1;
	mm tp;
	tp.a=1;tp.b=1;
	sc(n),sc(m);
	for(ll i=1;i<=n;i++)
	{
		sc(num[i]);
		for(ll j=1;j<=num[i];j++){
			sc(dat[i][j]);cnt[dat[i][j]]++;
		}
	}
	for(ll i=1;i<=n;i++)if(cnt[i]==0)dfs(i,tp);
	for(ll i=1;i<=n;i++)if(num[i]==0)cout<<qq[i].a<<" "<<qq[i].b<<endl;
	return 0;
}
