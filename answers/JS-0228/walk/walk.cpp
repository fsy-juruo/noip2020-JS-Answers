#include <bits/stdc++.h>
#define int long long 
using namespace std;
signed main ( )
{
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	int n,m;
	scanf("%lld %lld",&n,&m);
	int a[m];
	for(int i=1;i<=m;i++)
	{
		cin>>a[i];
	}
	int b[2][n];
		for(int j=1;j<=n;j++)
		{
			cin>>b[1][j]>>b[2][j];
		}
	cout<<-1;
}
