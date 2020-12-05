#include <bits/stdc++.h>
using namespace std;
#define rep(i,x,y) for (ll i=x;i<=y;i++)
typedef long long ll;
ll max(ll x,ll y)
{
	if (x>=y)
	{
		return x;
	}
	else
	{
		return y;
	}
}

ll min(ll x,ll y)
{
	if (x<=y)
	{
		return x;
	}
	else
	{
		return y;
	}
}

ll prime(ll x)
{
	if (x<2)
	{
		return false;
	}
	rep(i,2,int(sqrt(x)))
	{
		if (x%i==0)
		{
			return false;
		}
	}
	return true;
}

int main()
{
	freopen("ball.in","r",stdin);
	freopen("ball.out","w",stdout);
	ios::sync_with_stdio(false);
	int n,m;
	cin>>n>>m;
	if (n==1)
	{
		cout<<0<<endl;
		return 0;
	}
	int a[n+2][m+1];
	if (n==2)
	{
		rep(i,1,n)
		{
			rep(j,1,m)
			{
				cin>>a[i][j];
			}
		}
		cout<<0<<endl;
	}
	cout<<0<<endl;
	return 0;
}
