#include<bits/stdc++.h>
using namespace std;
struct node
{
	long long mu,zi;
}edge[100005];
int n,m,d[100005],a[100005][6],aa,jie,pai=0,shui[100005];
bool b[100005],f[100005],flag[100005];
int gcd(long long a,long long b)
{
	for(int i=b;i>=1;i--)
	{
		if(a%i==0) return i;
	}
}
int main()
{
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	scanf("%d%d",&n,&m);
	queue<int> q;
	memset(a,0,sizeof(a));
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&d[i]);
		if(d[i]>0)
		{
			for(int j=1;j<=d[i];j++)
			{
				scanf("%d",&aa);
				a[i][j]=aa;
				b[aa]=1;
			}
		}
		else
		{
			f[i]=1;
			pai++;
		}	
	}
//	for(int i=1;i<=n;i++)
//	{
//		cout<<f[i]<<" ";
//	}
//	cout<<endl;
	for(int i=1;i<=n;i++)
	{
		if(b[i]==0)
		{
			jie=i;
		}
	}
	for(int i=1;i<=n;i++)
	{
		edge[i].mu=0;
		edge[i].zi=0;
	}
	q.push(jie);
	edge[jie].mu=1;
	edge[jie].zi=1;
	flag[jie]=1;
	while(q.empty()!=1)
	{
		int x=q.front();
	//	printf("%d",x);
		q.pop();
		for(int i=1;i<=d[x];i++)
		{
			int y=a[x][i];
			if(flag[y]==0)
			{
				if(edge[y].mu==0||edge[y].zi==0)
				{
					edge[y].mu=d[x]*edge[x].mu;
					edge[y].zi=edge[x].zi;
				}
				else
				{
					edge[y].mu=d[x]*edge[x].mu*edge[y].mu;
					edge[y].zi=edge[y].mu*edge[x].zi+edge[y].zi*d[x]*edge[x].mu;
				}
				flag[y]=1;
				q.push(y);
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(f[i]==1)
		{
			edge[i].zi*=2;
			long long w=gcd(edge[i].mu,edge[i].zi);
			cout<<edge[i].zi/w<<" "<<edge[i].mu/w<<endl;
		}
	}
	return 0;
}
