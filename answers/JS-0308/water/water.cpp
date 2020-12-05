#include <bits/stdc++.h>
#define ll long long
#define F first
#define S second
#define INF 1000000000
#define LINF 1000000000000000000
#define N 100010
using namespace std;
struct frac{
	ll den,num;
};
ll gcd(ll a,ll b)
{
	if(a<b)
	{
		swap(a,b);
	}
	if(b==0)
	{
		return a;
	}
	return gcd(b,a%b);
}
frac dow(frac a)
{
	ll g=gcd(a.den,a.num);
	a.den/=g;
	a.num/=g;
	return a;
}
frac add(frac a,frac b)
{
	frac ret;
	ret.den=a.den*b.den;
	ret.num=a.num*b.den+b.num*a.den;
	return dow(ret);
}
frac prod(frac a,frac b)
{
	frac ret;
	ret.den=a.den*b.den;
	ret.num=a.num*b.num;
	return dow(ret);
}
frac dp[N];
bool vis[N];
ll n,m;
vector<ll> vt[N],bk[N];
void init()
{
	ll i;
	for(i=0;i<N;i++)
	{
		vt[i].clear();
		dp[i].den=1;
		dp[i].num=0;
		vis[i]=false;
	}
	return;
}
frac dfs(ll x)
{
	if(vis[x])
	{
		return dp[x];
	}
	vis[x]=true;
	if(bk[x].size()==0)
	{
		dp[x].num=1;
		return dp[x];
	}
	frac tt;
	ll i;
	for(i=0;i<bk[x].size();i++)
	{
		tt.den=vt[bk[x][i]].size();
		tt.num=1;
		tt=prod(tt,dfs(bk[x][i]));
		dp[x]=add(dp[x],tt);
	}
	return dp[x]=dow(dp[x]);
}
int main(){
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	ll i,sz,x;
	init(); 
	scanf("%lld%lld",&n,&m);
	for(i=0;i<n;i++)
	{
		scanf("%lld",&sz);
		while(sz--)
		{
			scanf("%lld",&x);
			x--;
			bk[x].push_back(i);
			vt[i].push_back(x);
		}
	}
	for(i=0;i<n;i++)
	{
		if(vt[i].size()==0)
		{
			printf("%lld %lld\n",dfs(i).num,dfs(i).den);
		}
	}
	return 0;
}
/*
1. file name
2. long long & int
3. array size
4. special cases
5. border
6. initialization
7. max&min value
8. big const->TLE
9. strange errors (/0,int->long long,iterator,unsigned long long...)
10. typo(n&m,=&-...)
*/
