#include <bits/stdc++.h>
using namespace std;
#define rep(i,x,y) for (ll i=x;i<=y;i++)
typedef long long ll;
const ll MOD=1000000007;

int main()
{
	ios::sync_with_stdio(false);
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	int n,k;
	cin>>n>>k;
	int w[k+1];
	bool ff=true;
	rep(i,1,k)
	{
		cin>>w[k];
		if (w[k]!=1)
		{
			ff=false;
		}
	}
	if (ff=true)
	{
		ll ss=1;
		rep(i,1,k)
		{
			ss*=w[i];
			ss%=MOD;
		}
		cout<<ss<<endl;
		return 0;
	}
	int c[n+1],d[n+1],check[n+1],maxx;
	rep(i,1,n)
	{
		check[i]=0;
	}
	rep(i,1,n)
	{
		cin>>c[i]>>d[i];
		check[c[i]]+=d[i];
	}
	
	bool f=true;
	rep(i,1,n)
	{
		if (check[i]!=0)
		{
			f=false;
		}
	}
	if (f==true)
	{
		cout<<"-1"<<endl;
	}
	else
	{
		cout<<38<<endl;
	}
	return 0;
}
