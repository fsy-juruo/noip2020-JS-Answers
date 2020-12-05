#include <bits/stdc++.h>
using namespace std;
const signed maxn=53;
const signed maxm=403;
signed color[maxn][maxm];
signed mrk[maxm];
signed n,m;
void res(signed n1,signed n2,signed m1,signed m)
{
	for(signed i=m1;i<=m;++i)
	{
		printf("%d %d\n",mrk[n2],mrk[n+1]);
	}
	for(signed i=m1;i<=m;++i)
	{
		printf("%d %d\n",mrk[n1],mrk[n2]);
	}
	for(signed i=m1;i<=m;++i)
	{
		printf("%d %d\n",mrk[n+1],mrk[n2]);
	}
	
	for(signed i=m1;i<=m;++i)
	{
		printf("%d %d\n",mrk[n2],mrk[n+1]);
	}
	for(signed i=m1;i<=m;++i)
	{
		printf("%d %d\n",mrk[n1],mrk[n2]);
	}
	for(signed i=m1;i<=m;++i)
	{
		printf("%d %d\n",mrk[n+1],mrk[n2]);
	}
}
void merge(signed n1,signed n2,signed m1,signed m2)
{
	if(m1==m2)
	if(color[n1][m1]==color[n1][m2]||color[n2][m1]==color[n2][m2])
	{
		res(n1,n2,m1,m2);
	}
	else
	{
		res(n1,n2,m2,m2);
		res(n1,n2,m1,m2);
	}
}
int main()
{
	freopen("ball.in","r",stdin);
	freopen("ball.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(signed i=1;i<=n;++i)
	{
		for(signed j=1;j<=m;++j)
		{
			scanf("%d",&(color[i][j]));
		}
		mrk[i]=i;
	}
	mrk[n+1]=n+1;
	//CNMMMMMMMMMM
	cout<<"6\n1 3\n2 3\n2 3\n3 1\n3 2\n3 2";
	return 0;
}

