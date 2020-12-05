#include<iostream>
#include<cstdio>
#include<queue>

#define N 100005
#define ll long long

using namespace std;
int n,m;
int h[N],tot;

struct edge
{
	int to,nxt;
}e[N*5];

int deg[N];

void add_edge(int x,int y)
{
	++deg[y];
	e[++tot].to=y;
	e[tot].nxt=h[x];
	h[x]=tot;
}

queue<int> qe;
int d[N];
ll p[N],q[N];

ll gcd(ll x,ll y)
{
	if(y==0) return x;
	return gcd(y,x%y);
}
int main()
{
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i)
	{
		q[i]=1;
		scanf("%d",&d[i]);
		for(int j=1;j<=d[i];++j)
		{
			int x;
			scanf("%d",&x);
			add_edge(i,x);
		}
	}
	for(int i=1;i<=m;++i)
	{
		p[i]=q[i]=1;
		qe.push(i);
	}
	while(!qe.empty())
	{
		int x=qe.front();
		qe.pop();
		for(int i=h[x];i;i=e[i].nxt)
		{
			int y=e[i].to;
			--deg[y];
			p[y]=p[y]*q[x]*d[x]+p[x]*q[y];
			q[y]=q[y]*q[x]*d[x];
			ll g=gcd(p[y],q[y]);
			p[y]/=g,q[y]/=g;
			if(!deg[y]) qe.push(y);
		}
	}
	for(int i=1;i<=n;++i)
	{
		if(!d[i])
		{
			printf("%lld %lld\n",p[i],q[i]);
		}
	}
	return 0;
}
