#include<bits/stdc++.h>
using namespace std;
bool AC_AK=true;
int n,m;
int d[100010];
vector<int> e[100010];
int qu[1000010];
int fr,re;
bool in[100010];
long long p[100010];
long long q[100010];
long long gcd(long long a,long long b)
{
	long long c=a%b;
	while(c)
	{
		a=b;
		b=c;
		c=a%b;
	}
	return b;
}
int tmp[100010],l;
int main()
{
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	scanf("%d%d",&n,&m);
	int x;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&d[i]);
		if(!d[i]) tmp[++l]=i;
		for(int j=1;j<=d[i];j++)
		{
			scanf("%d",&x);
			e[i].push_back(x);
		}
	}
	for(int i=1;i<=n;i++)
		q[i]=1;
	for(int i=1;i<=m;i++)
	{
		p[i]=1;
		in[i]=1;
		qu[++re]=i;
	}
	long long p1,q1,g,t1,t2;
	while(fr<re)
	{
		++fr;
		x=qu[fr];
		p1=p[x];
		if(!p1||!d[x]) continue;
		q1=q[x];
		g=gcd(p1,(long long)d[x]);
		p1=p1/g;
		q1=q1*((long long)d[x]/g);
		for(int i=0;i<d[x];i++)
		{
			if(!p[e[x][i]])
			{
				p[e[x][i]]=p1;
				q[e[x][i]]=q1;
			}
			else
			{
				g=gcd(q1,q[e[x][i]]);
				t1=q[e[x][i]]*(q1/g);
				t2=p[e[x][i]]*(q1/g)+p1*(q[e[x][i]]/g);
				g=gcd(t1,t2);
				t1/=g;
				t2/=g;
				p[e[x][i]]=t2;
				q[e[x][i]]=t1;
			}
			if(!in[e[x][i]]&&d[x])
			{
				qu[++re]=e[x][i];
				in[e[x][i]]=1;
			}
		}
		p[x]=0;
		q[x]=1;
		in[x]=0;
	}
	for(int i=1;i<=l;i++)
	{
		printf("%lld %lld\n",p[tmp[i]],q[tmp[i]]);
	}
	return 0;
}
