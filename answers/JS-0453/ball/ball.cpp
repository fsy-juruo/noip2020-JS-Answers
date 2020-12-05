#include<bits/stdc++.h>
using namespace std;
int n,m,a[1010][1010],num[1000010],yo;
int main()
{
	freopen("ball.in","r",stdin);
	freopen("ball.out","w",stdout);
	cin>>n>>m;
	yo=n+1;
	for (int i=1;i<=n;i++)for (int j=1;j<=m;j++)cin>>a[i][j];
	for (int i=1;i<=n;i++)num[i]=m;
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=n;j++)
		{
			for (int k=1;k<=num[i];k++)
			{
				if (a[j][k]==i)
				{
					int movemental=num[i]-k;
					for (int l=1;l<=movemental;l++)
					{
						cout<<j<<' '<<yo<<endl;
						num[yo]++;
						a[yo][num[yo]]=a[j][num[j]];
						num[j]--;
					}
					int ano;
					if (j==1)ano=2;
					else ano=j-1;
					num[yo]++;
					a[yo][num[yo]]=a[ano][num[ano]];
					num[ano]--;
					cout<<ano<<' '<<yo<<endl;
					num[ano]++;
					a[ano][num[ano]]=a[j][num[j]];
					num[j]--;
					cout<<j<<' '<<ano<<endl;
					movemental++;
					for (int l=1;l<=movemental;l++)
					{
						cout<<yo<<' '<<j<<endl;
						num[j]++;
						a[j][num[j]]=a[yo][num[yo]];
						num[yo]--;
					}
					num[yo]++;
					a[yo][num[yo]]=a[ano][num[ano]];
					num[ano]--;
					cout<<ano<<' '<<yo<<endl;
				}
			}
		}
		yo--;
	}
	return 0;
}
