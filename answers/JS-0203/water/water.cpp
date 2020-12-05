#include<bits/stdc++.h>
using namespace std;
const long long maxn=100010;
long long gcd(long long a,long long b)
{
	if(a%b==0) return b;
	return gcd(b,a%b);
}
struct num{
	long long x,y;
	// x/y
}water[maxn],res[maxn];
num add(num a,num b)
{
	long long x=a.x*b.y+a.y*b.x;
	long long y=a.y*b.y;
	long long d=gcd(x,y);
	num ret;
	ret.x=x/d;
	ret.y=y/d;
	return ret;
}
num mul(num a,num b)
{
	long long x=a.x*b.x;
	long long y=a.y*b.y;
	long long d=gcd(x,y);
	num ret;
	ret.x=x/d;
	ret.y=y/d;
	return ret;
}
struct node{
	long long u,v,nxt;
}edge[maxn];
long long head[maxn],tot;
void addedge(long long u,long long v)
{
	edge[tot].v=v;
	edge[tot].nxt=head[u];
	head[u]=tot++;
}
void init()
{
	memset(head,-1,sizeof head);
	tot=0;
}
long long n,m;
long long outdu[maxn];
long long indu[maxn];
long long q[maxn];
long long coutt=0;
queue<long long>topo;
void f()
{
	while(!topo.empty())
	{
		long long u=topo.front();
		topo.pop();
		long long sum=0;
		for(long long i=head[u];i!=-1;i=edge[i].nxt) sum++;
		num ans;
		ans.x=1;
		ans.y=sum;
		for(long long i=head[u];i!=-1;i=edge[i].nxt)
		{
			long long v=edge[i].v;
			water[v]=add(water[v],mul(water[u],ans));
			indu[v]--;
			if(indu[v]==0) topo.push(v);
		}
	}
}
int main()
{
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	cin>>n>>m;
	init();
	for(long long i=1;i<=n;i++)
	{
		long long j;
		cin>>j;
		for(long long k=1;k<=j;k++)
		{
			long long g;
			cin>>g;
			addedge(i,g);
			outdu[i]++;
			indu[g]++;
		}
	}
	for(long long i=1;i<=n;i++)
	{
		if(outdu[i]==0)
		{
			q[++coutt]=i;
		}
	}
	sort(q+1,q+coutt+1);
	for(long long j=1;j<=n;j++)
	{
		water[j].x=0;
		water[j].y=1;
	}
	for(long long i=1;i<=m;i++)
	{	
		water[i].x=1;
	}
	while(!topo.empty())
	{
		topo.pop();
	}
	for(int i=1;i<=m;i++) topo.push(i);
	f();
	for(long long i=1;i<=coutt;i++)
	{
		cout<<water[q[i]].x<<" "<<water[q[i]].y<<endl;
	}
	return 0;
}
/*
5 1
3 2 3 5
2 4 5
2 5 4
0
0
*/
