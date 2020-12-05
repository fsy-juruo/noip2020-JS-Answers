#include<bits/stdc++.h>
#define pb push_back
#define ll unsigned long long

using namespace std;

ll fenzi[10000010];
ll fenmu[10000010];

int gcd(ll a,ll b)
{
	if(a%b==0)return b;
	return gcd(b,a%b);
}

vector<ll> hqy[10000010];

ll num[10000010];

int n,m;

int main()
{
	freopen("water.in","r",stdin);
    freopen("water.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;++i)
	{
		int d;
		cin>>d;
		for(int j=1;j<=d;++j)
		{
			int e;
			cin>>e;
			hqy[i].pb(e);
			num[i]++;
		}
	}
	
	for(int i=1;i<=m;++i)
	{
		fenmu[i]=1;
		fenzi[i]=1;
	}
	
	for(int i=1;i<=n;++i)
	{
		for(int j=0;j<hqy[i].size();++j)
		{
			if(fenmu[hqy[i][j]]==0)
			{
				fenmu[hqy[i][j]]=num[i]*fenmu[i];
				fenzi[hqy[i][j]]=fenzi[i];
			}
			else
			{
				ll p1=fenmu[i]*num[i];
				ll a1=fenmu[hqy[i][j]],a2=fenzi[hqy[i][j]];
				if(fenzi[i]%p1==0)
				{
					fenmu[hqy[i][j]]=fenmu[hqy[i][j]];
					fenzi[hqy[i][j]]=fenzi[i]/p1*a1+a2;
					ll nn=gcd(fenmu[hqy[i][j]],fenzi[hqy[i][j]]);
					fenmu[hqy[i][j]]/=nn;
					fenzi[hqy[i][j]]/=nn;
				}
				else
				{
					fenmu[hqy[i][j]]=p1*fenmu[hqy[i][j]];
					fenzi[hqy[i][j]]=fenzi[i]*a1+p1*a2;
					ll nn=gcd(fenmu[hqy[i][j]],fenzi[hqy[i][j]]);
					fenmu[hqy[i][j]]/=nn;
					fenzi[hqy[i][j]]/=nn;
				}
			}
		}
	}
	for(int i=1;i<=n;++i)
	{
		ll mm=gcd(fenzi[i],fenmu[i]);
		if(num[i]==0)
		cout<<fenzi[i]/mm<<" "<<fenmu[i]/mm<<endl;
	}
}
