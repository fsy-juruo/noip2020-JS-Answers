#include<bits/stdc++.h>
using namespace std;
int n,m;
deque<int> q[52];
struct nn
{
	int sum,kind;
}num[51];
bool cmp(nn x,nn y)
{
	return x.sum==y.sum?x.kind>y.kind:x.sum>y.sum;
}
int main()
{
	freopen("ball.in","r",stdin);
	freopen("ball.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		num[i].kind=i;
	}
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=m;++j)
		{
			int x;
			scanf("%d",&x);
			num[x].sum++;	
			q[i].push_back(x);	
		}
		sort(num+1,num+1+m,cmp);
		
		for(int i=1;i<=n;i++)
		{
			num[i].sum=0;
		}
		
	}
	
	return 0;
}
