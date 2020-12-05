#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll read()
{
	ll x=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();
	return x*f;
}
ll gcd(ll x,ll y)
{
	if(y==0) return x;
	return gcd(y,x%y);
}
struct e
{
	ll a,b;
}f[100005];
ll n,m;
vector<ll> q[100005],s;
void dfs(ll k,ll fm)
{
	ll fz=1;
	if(q[k].size()==0)
	{
		if(f[k].a==0) f[k].a=1,f[k].b=fm;
		else
		{
			ll ma=f[k].b*fm/gcd(f[k].b,fm);
			f[k].a=f[k].a*(ma/f[k].b)+fz*(ma/fm);
			f[k].b=ma;
			ma=gcd(f[k].a,f[k].b);
			f[k].a/=ma,f[k].b/=ma;
		}
	}
	else for(int i=0;i<q[k].size();i++)
	{
		ll to=q[k][i];
		dfs(to,fm*q[k].size());
	}
}
int main()
{
	freopen("water.in","r",stdin);
	freopen("water.out","r",stdin);
	n=read(),m=read();
	for(int i=1;i<=n;i++)
	{
		ll t=read(),x;
		if(t==0) s.push_back(i);
		while(t--) x=read(),q[i].push_back(x);
	}
	for(int i=1;i<=m;i++) if(q[i].size()) dfs(i,1);
	for(int i=0;i<s.size();i++) printf("%lld %lld\n",f[s[i]].a,f[s[i]].b);
	return 0;
}
