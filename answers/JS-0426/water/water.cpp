#include<bits/stdc++.h>
using namespace std;
inline long long fread()
{
	long long x=0,y=1;
	char c=getchar();
	while(c<'0' || c>'9')
	{
		if(c=='-')
		{
			y=-1;
		}
		c=getchar();
	}
	x=c-'0';
	c=getchar();
	while(c>='0' && c<='9')
	{
		x=x*10+c-'0';
		c=getchar();
	}
	return x*y;
}
int n,m,in[101010];
bool vis[101010];
long long p[101010],q[101010];
vector<int>v[101010];
void add(int x,int y)
{
	if(q[y]==0)
	{
		p[y]=p[x];
		q[y]=q[x];
		return;
	}
	long long gt=__gcd(q[x],q[y]);
	p[y]=(q[x]/gt)*p[y]+(q[y]/gt)*p[x];
	q[y]=q[x]/gt*q[y];
	gt=__gcd(q[y],p[y]);
	q[y]/=gt;
	p[y]/=gt;
}
void bfs(int x)
{
	int y;
	queue<int>qq;
	qq.push(x);
	while(!qq.empty())
	{
		x=qq.front();
		qq.pop();
		if(v[x].size()!=0)
		{
			if(p[x]==0 || q[x]==0)
			{
				continue;
			}
			if(p[x]%v[x].size()==0)
			{
				p[x]/=v[x].size();
			}
			else
			{
				if(p[x]%2==0 && v[x].size()==4)
				{
					p[x]/=2;
					q[x]*=2;
				}
				else
				{
					q[x]*=v[x].size();
				}
			}
			for(int i=0;i<(int)v[x].size();i++)
			{
				y=v[x][i];
				qq.push(y);
				add(x,y);
			}
			p[x]=0;
			q[x]=0;
		}
	}			
}
int main()
{
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	int dd,x;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		dd=fread();
		for(int j=0;j<dd;j++)
		{
			x=fread();
			v[i].push_back(x);
			in[x]++;
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(in[i]==0)
		{
			p[i]=1;
			q[i]=1;
			bfs(i);
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(v[i].size()==0)
		{
			printf("%lld %lld\n",p[i],q[i]);
		}
	}
	return 0;
}
