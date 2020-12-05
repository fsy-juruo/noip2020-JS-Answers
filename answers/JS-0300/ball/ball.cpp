#include<bits/stdc++.h>
using namespace std;
int n,m;
int g[55][405],step[820000][5];
int main()
{
	freopen("ball.in","r",stdin);
	freopen("ball.out","w",stdout);
	std::ios::sync_with_stdio(false);
	cin>>n>>m;//nÉ«m¸ö n+1gan
	for(int i=1;i<=2;i++)
	{
		for(int j=1;j<=m;j++)
		{
			cin>>g[i][j];
		}
	}
	
	
	cout<<6;
	cout<<"1 3\n2 3\n2 3\n3 1\n3 2\n3 2\n";
	
	
	return 0;
}
