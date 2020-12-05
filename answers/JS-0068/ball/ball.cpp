#include<bits/stdc++.h>
using namespace std;
stack<int> a[52];
int c[52],sz[52];
int t1[1000001],t2[1000001];
int main()
{
	freopen("ball.in","r",stdin);
	freopen("ball.out","w",stdout);
	int n,cc;scanf("%d%d",&n,&cc);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=cc;j++)
		{
			int x;scanf("%d",&x);
			if(j==1)c[i]=x;
			a[i].push(x);
			sz[i]=cc;
		}
	int m=0;
	if(n==2)
	{
		while(!a[1].empty())
			m++,t1[m]=1,t2[m]=3,a[3].push(a[1].top()),a[1].pop(),sz[3]++;
		while(!a[3].empty()&&a[3].top()==c[1])
			m++,t1[m]=3,t2[m]=1,a[1].push(a[3].top()),a[3].pop(),sz[3]--;
		while(!a[2].empty())
			if(a[2].top()==c[1])
			{
				m++,t1[m]=2,t2[m]=1,a[1].push(a[2].top()),a[2].pop();
			}
			else
			{
				if(sz[3]==cc)break;
				m++,t1[m]=2,t2[m]=3,a[3].push(a[2].top()),a[2].pop(),sz[3]++;
			}
		while(!a[3].empty())
			m++,t1[m]=3,t2[m]=2,a[2].push(a[3].top()),a[3].pop();
		printf("%d\n",m);
		for(int i=1;i<=m;i++)
			printf("%d %d\n",t1[i],t2[i]);
	}
	else cout<<0;
	return 0;
}
