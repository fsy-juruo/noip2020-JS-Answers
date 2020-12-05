#include<bits/stdc++.h>
using namespace std;
int k,n,w[15],c[500005],d[500005],sum=0;
void zou(int x)
{
	bool b=0;
	while(b==0)
	{
		for(int i=1;i<=n;i++)
		{
			x+=d[i];
		//	printf("%d\n",x);
			sum++;
			if(x<1||x>w[1])
			{
				b=1;
				break;
			}
		}
	}
}
int main()
{
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=k;i++)
	{
		scanf("%d",&w[i]);
	}
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d",&c[i],&d[i]);
	}
	for(int i=1;i<=w[1];i++)
	{
		int a=i;
		zou(a);
	}
	printf("%d",sum);
	return 0;
}
