#include <bits/stdc++.h>
using namespace std;
vector<long long>a[100005];
long long p[100005],q[100005],d[100005];
bool v[100005];
queue<long long>g;
long long n,m;
long long read1()
{
	char cc=getchar();
	while(!(cc>=48&&cc<=57))
	{
		if(cc=='-')
		{
			break;
		}
		cc=getchar();
	}
	bool f=false;
	long long s=0;
	if(cc=='-')
	{
		f=true;
	}
	else
	{
		s=cc-48;
	}
	while(1)
	{
		cc=getchar();
		if(cc>=48&&cc<=57)
		{
			s=s*10+cc-48;
		}
		else
		{
			break;
		}
	}
	if(f==true)
	{
		s=-s;
	}
	return s;
}
long long gcd(long long n,long long m)
{
	if(m==0)
	{
		return n;
	}
	return gcd(m,n%m);
}
void add(long long u,long long v)
{
	long long tmppu=p[u],tmpqu=q[u]*(a[u].size());
	long long tmppv=p[v],tmpqv=q[v];
	long long g=gcd(tmpqu,tmpqv);
	long long tmp=tmpqu/g*tmpqv;
	tmppv=tmppv*(tmp/tmpqv)+(tmp/tmpqu)*tmppu;
	tmpqv=tmp;
	g=gcd(tmppv,tmpqv);
	tmppv/=g;
	tmpqv/=g;
	p[v]=tmppv;
	q[v]=tmpqv;
}
void topsort()
{
	for(long long i=m+1;i<=n;i++)
	{
		if(d[i]==0)
		{
			g.push(i);
		}
	}
	while(!g.empty())
	{
		long long n1=g.front();
		g.pop();
		for(long long i=0;i<a[n1].size();i++)
		{
			add(n1,a[n1][i]);
			d[a[n1][i]]--;
			if(d[a[n1][i]]==0)
			{
				g.push(a[n1][i]);
			}
		}
	}
}
int main()
{
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++)
	{
		long long q=read1();
		if(q==0)
		{
			v[i]=true;
		}
		for(long long j=1;j<=q;j++)
		{
			long long v=read1();
			a[i].push_back(v);
			d[v]++;
		}
	}
	for(long long i=1;i<=m;i++)
	{
		p[i]=1;
		q[i]=1;
		g.push(i);
	}
	for(long long i=m+1;i<=n;i++)
	{
		p[i]=0;
		q[i]=1;
	}
	topsort();
	for(long long i=1;i<=n;i++)
	{
		if(v[i]==true)
		{
			printf("%lld %lld\n",p[i],q[i]);
		}
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

10 1
5 2 3 4 5 6
2 7 8
2 8 10
2 9 7
1 9
3 7 8 9
1 10
0
1 10
0

4 15
11 15

*/
//100 points
