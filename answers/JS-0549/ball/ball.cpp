#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int a[100][500];
string s;
int main()
{
	ios::sync_with_stdio(0);
	freopen("ball.in","r",stdin);
	freopen("ball.out","w",stdout);
	stringstream ss(s);
	cin>>n>>m;
	for(int i=1; i<=n; i++)
	{
		for(int j=1; j<=m; j++)
		{
			cin>>a[i][j];
		}
	}
	for(int i=1; i<=n; i++)
	{
		for(int j=1; j<=m; j++)
		{
			if(a[i][j]!=i)
			{
				int g=0;
				while(a[a[i][j]][n-g]==a[i][j]&&g<n)
				{
					k++;
					g++;
					ss>>a[i][j]>>" "<<n+1>>endl;
				}
				g--;
				k++;
				ss>>a[i][j]>>" ">>n+1>>endl;
				k++;
				ss>>i>>" ">>a[i][j]>>endl;
				k++;
				ss>>n+1>>" ">>i>>endl;
				while(g>0)
				{
					g--;
					k++;
					ss>>n+1>>" ">>a[i][j]>>endl;
				}
			}
		}
	}
	cout<<k<<endl<<s;
	return 0;
}
