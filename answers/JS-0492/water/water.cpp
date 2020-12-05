#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const int MAXN=1e5+10;
struct node
{
	ll up,dwn;
};
node dp[MAXN];
int n,m,cnt,arr[MAXN],d[MAXN],b1[MAXN],ind[MAXN],poi[MAXN],b2[MAXN];
vector <int> t[MAXN];
void toposort()
{
	queue <int> q;
	for(int i=1;i<=n;i++)
	{
		dp[i].up=0ll;
		if(!ind[i])
		{
			dp[i].up=dp[i].dwn=1ll;
			q.push(i);
		}
	}	
	int cnt1=0;
	while(cnt1<n && !q.empty())
	{
		int p=q.front();q.pop();
		arr[++cnt1]=p,b2[p]=1,dp[p].dwn=1ll;
		for(int i=0;i<t[p].size();i++)
		{
			int to=t[p][i];
			ind[to]--;
			if(!ind[to] && !b2[to])
				q.push(to);
		}
	}
}
ll gcd(ll a,ll b)
{
	if(!b)
		return a;
	return gcd(b,a%b);
}
int main()
{
    freopen("water.in","r",stdin);
    freopen("water.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&d[i]);
		for(int j=1;j<=d[i];j++)
		{
			int v;
			scanf("%d",&v);
			t[i].push_back(v);
			ind[v]++;
		}
	}
	int cnt1=0;
	toposort();
	for(int j=1;j<=n;j++)
	{
		for(int k=0;k<t[arr[j]].size();k++)
		{
			ll to=t[arr[j]][k],fr=arr[j],num=t[fr].size();
			ll pub=dp[fr].dwn*num*dp[to].dwn/gcd(dp[fr].dwn*num,dp[to].dwn);
			dp[to].up=dp[to].up*pub/dp[to].dwn+dp[fr].up*pub/dp[fr].dwn/num,dp[to].dwn=pub;
			ll mgcd=gcd(dp[to].up,dp[to].dwn);
			dp[to].up/=mgcd,dp[to].dwn/=mgcd;
		}
	}
	for(int i=1;i<=n;i++)
		if(!d[i])
			printf("%lld %lld\n",dp[i].up,dp[i].dwn);
	return 0;
}
