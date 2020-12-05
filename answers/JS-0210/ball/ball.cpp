#include<bits/stdc++.h>
using namespace std;
int n,m;
int ball[60][410],top[60];
int main()
{
	freopen("ball.in","r",stdin);
	freopen("ball.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		top[i]=m;
		for(int j=1;j<=m;j++)
			scanf("%d",&ball[i][j]);
	}
	top[n+1]=0;
	return 0;
}
