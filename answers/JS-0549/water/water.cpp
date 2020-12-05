#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll maxn=100000+100;
const long double mnINF=0.0000000001;
ll n,m,k,t;
long double y;
vector <ll> twd[maxn];
vector <ll> frm[maxn];
ll endpnt[maxn];
ll endcnt;
long double dis[maxn];
ll beginpnt[maxn];
map <long double,pair<ll,ll> > dividemp;
long double solve(ll x)
{
	if(dis[x]!=0)
	{
		return dis[x];
	}
	for(ll i=0; i<frm[x].size(); i++)
	{
		dis[x]+=solve(frm[x][i])/(long double)(twd[frm[x][i]].size());
	}
	return dis[x];
}

ll mathround(long double x)
{
	return floor(x+0.5);
}

void displayout(long double x)
{
	if(dividemp[x].first!=0)
	{
		cout<<dividemp[x].first<<" "<<dividemp[x].second<<endl;
		return;
	}
	if(abs(x-mathround(x))<=mnINF)
	{
		cout<<x<<" "<<1<<endl;
		return;
	}
	for(long double i=1;; i+=1)
	{
		y=i/x;
		if(abs(y-mathround(y))<=mnINF)
		{
			dividemp[x].first=i;
			dividemp[x].second=mathround(y);
			cout<<dividemp[x].first<<" "<<dividemp[x].second<<endl;
			return;
		}
	}
}


int main()
{
	//ios::sync_with_stdio(0);
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);

	cin>>n>>m;
	for(ll i=1; i<=n; i++)
	{
		cin>>k;
		if(k==0)
		{
			endcnt++;
			endpnt[endcnt]=i;
		}
		for(ll j=1; j<=k; j++)
		{
			cin>>t;
			twd[i].push_back(t);
			frm[t].push_back(i);
		}
	}

	for(ll i=1; i<=n; i++)
	{
		if(frm[i].empty()==1)
		{
			beginpnt[i]=1;
			dis[i]=1;
		}
	}
	for(ll i=1; i<=endcnt; i++)
	{
		solve(endpnt[i]);
	}

	/*for(ll i=1; i<=n; i++)
	{
		cout<<i<<" "<<dis[i]<<endl;
	}*/

	for(ll i=1; i<=endcnt; i++)
	{
		displayout(dis[endpnt[i]]);
	}


	return 0;
}
