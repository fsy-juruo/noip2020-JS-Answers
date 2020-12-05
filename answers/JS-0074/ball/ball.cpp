#include<bits/stdc++.h>
#include<stack>
using namespace std;

int n,m;
//int a[51][401];
stack<int> a[51];

int main()
{
////	srand(time(0));
	freopen("ball.in","r",stdin);
	freopen("ball.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		for(int i=1;i<=m;i++)
		{
			int x;
			scanf("%d",&x);
			a[i].push(x);
		}
	}
	if(n==2)
	{
		stack<int> b=a[2];
		int res=0;
		while(!b.empty())
		{
			int x=b.top();
			b.pop();
			if(x==1)
			{
				res++;
			}
		}
		printf("%d\n",2*m+res);
		while(!a[2].empty())
		{
			int x=a[2].top();
			a[2].pop();
			if(x==1)
			{
				a[1].push(x);
				puts("2 1");
			}
			else
			{
				a[3].push(x);
				puts("2 3");
			}
		}
		while(!a[1].empty())
		{
			int x=a[1].top();
			a[1].pop();
			if(x==1)
			{
				a[2].push(x);
				puts("1 2");
			}
			else
			{
				a[3].push(x);
				puts("1 3");
			}
		}
	}
	return 0;
}
