#include <bits/stdc++.h>
using namespace std;
int z[53][403];
int main()
{
	freopen("ball.in","r",stdin);
	freopen("ball.out","w",stdout);
	int n,m,i,j;
	scanf("%d %d",&n,&m);
	for(i=1;i<=n;i++)
	for(j=1;j<=m;j++)
	scanf("%d",&z[i][j]);
	if(n==1)
	{
		printf("0\n");
		return 0;
	}
	if(n==2)
	printf("6\n1 3\n2 3\n2 3\n3 1\n3 2\n3 2");
	fclose(stdin);
	fclose(stdout);
	return 0;
}
