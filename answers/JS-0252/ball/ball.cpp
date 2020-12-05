#include <bits/stdc++.h>
using namespace std;
int a[1000][1000]={};
int main()
{
	freopen("ball.in","r",stdin);
	freopen("ball.out","w",stdout);
	int n,m;cin>>n>>m;
	int i,j;
	for(i=0; i<n; i++)
		for(j=0; j<m; j++)
			cin>>a[i][j];
	if(a[0][0]==a[0][m-1])
	{
		cout<<0;
		return 0;
	}
	else
	{
		cout<<(n+1)*(m-1);
		return 0;
	}
	return 0;
}
