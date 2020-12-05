#include<bits/stdc++.h>
using namespace std;
long long p[300001],q[300001];
int ver[300001],tot,h[200001],nex[300001],head[300001],n,m,a,b,sum,so[100001],A;
long long gcd(long long x,long long y)
{
	if(y==0)
	return x;
	else return gcd(y,x%y);
}
void dfs(int x)
{
	if(h[x])
	return ;
	for(int i=head[x];i;i=nex[i])
	{
		int g=ver[i];	
		dfs(g);
			if(p[g]!=0)
			{
				if(p[x]==0)
				{
					p[x]=p[g];
					q[x]=q[g];
				}
				else
				{
					
					long long dc=q[x]*q[g]/gcd(q[x],q[g]);	
					p[x]=p[x]*dc/q[x]+p[g]*dc/q[g];
					q[x]=dc;
				}
			}
	}
	h[x]=1;
	if(so[x]!=0)
	q[x]=q[x]*so[x];
}
void add(int x,int y)
{
	ver[++tot]=y;
	nex[tot]=head[x];
	head[x]=tot;
}
int main()
{
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	cin>>n>>m;
	for(int i=m+1;i<=n;i++)
	{
		q[i]=1;
	}
	for(int i=1;i<=m;i++)
	{
		p[i]=1;
		h[i]=1;
	}
	for(int i=1;i<=n;i++)
	{
		cin>>sum;
		for(int j=1;j<=sum;j++)
		{
			cin>>A;
			add(A,i);
		}
		so[i]=sum;
		if(i<=m)
		q[i]=sum;
	}
	for(int i=1;i<=n;i++)
	{
		if(so[i]==0)
		{
		dfs(i);
		if(p[i]==0)
		{
				cout<<0<<' '<<1<<endl;
		}
		else
		{
			long long ff=gcd(p[i],q[i]);
		cout<<p[i]/ff<<' '<<q[i]/ff<<endl;
		}
		
		}
	
	}
	return 0;
}
