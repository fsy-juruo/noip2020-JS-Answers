#include<bits/stdc++.h>
#define ll long long
#define pll pair<ll,ll>
#define F first
#define S second
#define mp make_pair
using namespace std;
const int N=1e5+5;
pll ans[N];int NotRoot[N];
int n,m,len[N],v[N][7],q[N];
int H,T;
ll gcd(ll a,ll b)
{
	if(a%b==0)return b;
	else return gcd(b,a%b);
}
ll lcm(ll a,ll b)
{
	return a/gcd(a,b)*b;
}
pll Div(pll x,ll y)
{
	x.S*=y;
	ll lc=gcd(x.F,x.S);
	x.F/=lc,x.S/=lc;
	return x;
}
pll add(pll a,pll b)
{
	pll res;
	res.F=0;
	res.S=lcm(a.S,b.S);
	res.F=res.S/a.S*a.F+res.S/b.S*b.F;
	ll lc=gcd(res.F,res.S);
	res.F/=lc,res.S/=lc;
	return res;
}//log

int main()
{
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&len[i]);
		for(int j=0;j<len[i];j++)
		{
			scanf("%d",&v[i][j]);
			v[i][j]--;NotRoot[v[i][j]]++;
		}
	}
	for(int i=0;i<n;i++)
	{
		if(!NotRoot[i])
			q[T++]=i,ans[i].F=1;
		ans[i].S=1;
	}
	while(H<T)
	{
		int now=q[H++];
		if(len[now])ans[now]=Div(ans[now],len[now]);
		for(int i=0;i<len[now];i++)
		{
			int to=v[now][i];
			NotRoot[to]--;
			if(!NotRoot[to])q[T++]=to;
			ans[to]=add(ans[to],ans[now]);
		}
	}
	for(int i=0;i<n;i++)
		if(!len[i])
			printf("%lld %lld\n",ans[i].F,ans[i].S);
	return 0;
}
//8?9?10 :20
