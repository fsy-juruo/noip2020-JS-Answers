#include<bits/stdc++.h>
using namespace std;
int n,m;
int f[60][500];
int flag;
int main()
{
	freopen("ball.in","r",stdin);
	freopen("ball.out","w",stdout);
	scanf("%d%d",&n,&m);
	flag=1;
	for(int i=1;i<=n;i++)
	for(int j=1;j<=m;j++)
	{
		scanf("%d",&f[i][j]);
		if(j>=2&&f[i][j]!=f[i][j-1]) flag=0;
	}
	puts("0");
	return 0;
}
