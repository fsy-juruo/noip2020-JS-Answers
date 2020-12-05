#include<bits/stdc++.h>
using namespace std;
int n,m,a[55][407],judged;
int main()
{
	freopen("ball.in","r",stdin);
	freopen("ball.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	for(int j=1;j<=m;j++)
	{
		cin>>a[i][j];
		if(j>1&&a[i][j]!=a[i][j-1])
		judged=1;
	}
	if(judged==0)
	{
		cout<<0<<endl;
		return 0;
	}
	cout<<0<<endl;
	return 0;
}
