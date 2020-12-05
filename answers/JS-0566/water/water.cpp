#include<bits/stdc++.h>
using namespace std;
#define Sf scanf
#define Pf printf
#define ll long long
#define Pii pair<int,int>
#define P2 pair
#define Sz size
#define Vct vector
#define Pb push_back
#define Cb make_pair
#define Fi first
#define Se second
#define Ins insert
#define Que queue
#define Fr front
#define Psh push
#define Pp pop

ll n,m;
Vct<ll>v[100005];
ll sz[100005];
ll dp[100005][2];
ll deg[100005];
Que<ll> q;
ll gcd(ll a,ll b)
{
	if(a<b)swap(a,b);
	if(a%b==0)return b;
	return gcd(b,a%b);
}
int main()
{
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	Sf("%lld%lld",&n,&m);
	ll t;
	for(ll i=1;i<=n;i++)
	{
		Sf("%lld",&sz[i]);
		for(ll j=1;j<=sz[i];j++)
		{
			Sf("%lld",&t);
			v[i].Pb(t);
			deg[t]++;
		}
		dp[i][1]=1;
	}
	for(ll i=1;i<=m;i++)
	{
		dp[i][0]=1;
		dp[i][1]=1;
		q.Psh(i);
	}
	ll u;
	ll y;
	while(!q.empty())
	{
		u=q.Fr();
		deg[u]=-1;
		q.Pp();
		for(ll i=0;i<v[u].Sz();i++)
		{
			t=v[u][i];
			deg[t]--;
			dp[t][0]=dp[t][1]*dp[u][0]+dp[t][0]*dp[u][1]*sz[u];
			dp[t][1]=dp[t][1]*dp[u][1]*sz[u];
			if(deg[t]==0)q.Psh(t);
			if(dp[t][0]!=0)
			{
				//cout<<"!";
				y=gcd(dp[t][0],dp[t][1]);
				dp[t][0]/=y;
				//cout<<"!";
				dp[t][1]/=y;
			}
			else dp[t][1]=1;
		}
	}
	for(ll i=1;i<=n;i++)
	{
		if(sz[i]==0)
		{
			Pf("%lld %lld\n",dp[i][0],dp[i][1]);
		}
	}
	return 0;
}
