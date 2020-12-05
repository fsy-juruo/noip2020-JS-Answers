#include<bits/stdc++.h>
#define R register
using namespace std;

int ii,n,m,k,l,sl;
long long w[100100];
long long a[100100],b[100100];
long long x[100100],d[100100];
long long mv[100100];
long long ans=0;
bool f;
long long s;

void wk()
{
	f=true;
	for (R int i=1;i<=k;i++)
	b[i]=a[i];
	memset(mv,0,sizeof(mv));
	for (R int i=1;i<=n;i++)
	{
		ans=(ans+1)%1000000007;
		mv[x[i]]+=d[i];l=b[x[i]]+d[i];
		if (l<1||l>w[x[i]])
		{
			f=false;return;
		}		
		b[x[i]]+=d[i];
	}
	f=true;
	for (R int i=1;i<=k;i++)
	{
		if (mv[i]!=0)
		{
			f=false;break;
		}
	}
	if (f==true)
	{
		cout << "-1" << endl;exit(0);
	}
	ii=0;
	while (ii<=n)
	{
		ii++;if (ii!=n) ii%=n;
		ans=(ans+1)%1000000007;
		l=b[x[ii]]+d[ii];
		if (l<1||l>w[x[ii]])
		{
			return;
		}
		b[x[ii]]+=d[ii];
	}
}

void dfs(int dep)
{
	if (dep>k)
	{
		wk();
	}
	else
	{
		for (R int i=1;i<=w[dep];i++)
		{
			a[dep]=i;
			dfs(dep+1);
		}
	}
}

int main()
{
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin >> n >> k;
	s=1;
	for (R int i=1;i<=k;i++)
	{
		cin >> w[i];s*=w[i];
	}
	for (R int i=1;i<=n;i++)
	{
		cin >> x[i] >> d[i];
	}
	if (s*n<=100000000)
	{
		dfs(1);
		cout << ans%1000000007 << endl;
	}
	else
	{
		cout << "-1" << endl;
	}
	return 0;
}

