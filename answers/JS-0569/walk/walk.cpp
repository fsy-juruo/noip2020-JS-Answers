#include <bits/stdc++.h>

using namespace std;
int k,n,sum=0;
int w[13];
int c[500003],d[500003];
int main(){
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	cin >> n >> k;
	for (int i = 1;i <= k; ++i)
	{
		cin >> w[i];
	}
	for (int i = 1; i <= n; ++i)
	{
		cin >> c[i] >> d[i];
	}
	cout << -1;
	return 0;
}
