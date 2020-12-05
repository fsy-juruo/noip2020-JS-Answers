#include<bits/stdc++.h>
#define pb push_back
#define rep(i,n) for(int i=0;i<n;i++)
#define forn(i,a,b) for(int i=a;i<=b;i++)
#define all(a) a.begin(),a.end()
using namespace std;
typedef long long ll;
typedef vector<int> vi;
vi v[100010],ans;
struct ddouble
{
	ll f,s;
}dp[100010];
bool use[100010];
int g[100010];
ll lcmmy(ll a,ll b)
{
	return a/__gcd(a,b)*b;
}
ll now;
inline ddouble plusdd(ddouble a,ddouble b)
{
    //cout<<a.f<<" "<<a.s<<endl<<b.f<<" "<<b.s<<endl;
    if(b.f==0)
    {
    	return a;
    	//cout<<b.f<<" "<<b.s<<endl;
	}
	else
	{
	  ddouble c;
	  c.s=lcmmy(a.s,b.s);
	  c.f=c.s/a.s*a.f+c.s/b.s*b.f;
	  now=__gcd(c.s,c.f);
	  //cout<<now<<endl;
	  c.s/=now;
	  c.f/=now;
	  return c;
    }
}
inline ddouble chu(ddouble a,ll b)
{
	//cout<<a.f<<" "<<a.s<<endl;
	//cout<<b<<endl;
	a.s*=b;
	now=__gcd(a.s,a.f);
	a.s/=now;
	a.f/=now;
	return a;
}
inline ddouble dfs(int p)
{
	if(dp[p].f!=0)
	{
	  return dp[p];
	}
	ddouble res;
	res.f=0;
	res.s=0;
	rep(i,v[p].size())
	{
		res=plusdd(chu(dfs(v[p][i]),g[v[p][i]]),res);
	}
	return dp[p]=res;
}
int main()
{
    freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);	
	int n,m,b,k;
	cin>>n>>m;
	ddouble a;
	rep(i,n)
	{
		cin>>k;
		if(k==0)
		{
			ans.pb(i);
		}
		g[i]=k;
		rep(j,k)
		{
			scanf("%d",&b);
			b--;
			v[b].pb(i);
		}
	}
	/*rep(i,n)
	{
		cout<<v[i].size()<<" ";
		rep(j,v[i].size())
		{
			cout<<v[i][j]<<" ";
		}
		cout<<endl;
	}*/
	//cout<<1<<endl;
	rep(i,m)
	{
	  dp[i].s=1;
	  dp[i].f=1;
	}
	rep(i,ans.size())
	{
		dfs(ans[i]);
	}
	/*rep(i,n)
	{
		cout<<dp[i].f<<" "<<dp[i].s<<endl;
	}*/
	rep(i,ans.size())
    {
    	cout<<dp[ans[i]].f<<" "<<dp[ans[i]].s<<endl;
    }
	return 0;
}
