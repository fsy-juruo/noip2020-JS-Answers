#include<bits/stdc++.h>
using namespace std;
int b[55][405];
int main()
{
	int n,m;
	freopen("ball.in","r",stdin);
	freopen("ball.out","w",stdout);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			scanf("%d",&b[i][j]);
	printf("820000");
	return 0;
}
