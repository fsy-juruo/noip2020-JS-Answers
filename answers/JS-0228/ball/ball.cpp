#include <bits/stdc++.h>
#define int long long 
using namespace std;
signed main ( )
{
	freopen("ball.ans","r",stdin);
	freopen("ball.out","w",stdout);
	int n;
	scanf("%lld %lld",&n);
	int b[2][n];
	cout<<n<<endl;
		for(int j=1;j<=n;j++)
		{
			cin>>b[1][j]>>b[2][j];
			cout<<b[1][j]<<" "<<b[2][j]<<endl;
		}
		return 0;
}
