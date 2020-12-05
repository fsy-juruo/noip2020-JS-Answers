#include<bits/stdc++.h>
using namespace std;
int m,n,a[105][1005];
int main()
{
	freopen("ball.in","r",stdin);
	freopen("ball.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			scanf("%d",&a[i][j]);
	if(n==1)
		printf("0\n");
	fclose(stdin);
	fclose(stdout);
	return 0;
}
