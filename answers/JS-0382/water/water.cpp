#include<bits/stdc++.h>
using namespace std;
int k[10002][10010];
bool pl(int a,int b)
{
	if(k[b][10006]==0||k[b][10005]==0)
	{
		k[b][10006]=k[a][10006];
		k[b][10005]=k[a][10005];
		return 0;
	}
	int y=__gcd(k[a][10006],k[b][10006]);
	int m=k[a][10005];
	m*=(k[b][10006]/y);
	k[b][10006]*=(k[a][10006]/y);
	k[b][10005]*=(k[a][10006]/y);
	k[b][10005]+=m ;
	/*int f=__gcd(k[b][10005],k[b][10006]);
	k[b][10005]/=f;
	k[b][10006]/=f;*/
	return 0;
}
int main ()
{
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	int n,m ,i,j,ne;
	int num ;
	cin>>n>>m ;
	for(j=1;j<=m ;++j)
	{
		k[j][10005]=1;
		k[j][10006]=1;	
	}
	for(i=1;i<=n;i++)
	{
		cin>>num ;
		
		if(num==0)
		{
			int f=__gcd(k[i][10005],k[i][10006]);
			k[i][10005]/=f;
			k[i][10006]/=f;
			cout<<k[i][10005]<<' '<<k[i][10006]<<endl;
			continue;
		}
		k[i][10006]*=num ;
		for(j=1;j<=num ;++j)
		{
			cin>>ne;
			pl(i,ne);
		}
	}
	return 0;
}
/*int main ()
{
	k[5][10005]=9;
	k[5][10006]=14;
	k[6][10005]=8;
	k[6][10006]=49;
	pl(5,6);
	cout<<k[6][10005]<<k[6][10006];
}*/
/*int main ()
{
	cout<<__gcd(0,49);
}*/
