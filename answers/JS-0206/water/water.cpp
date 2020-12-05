#include<cstdio>
#include<vector>

#define _N 100001

#define int long long

int gcd(int a,int b)
{
	return b==0?a:gcd(b,a%b);
}

struct Frac
{
	int a,b;
	Frac()
	{
		a=0;b=1;
	}
	Frac(int x,int y)
	{
		a=x;
		b=y;
	}
};

Frac operator +(const Frac& left,const Frac& right)
{
	int c=left.a*right.b+left.b*right.a;
	int d=left.b*right.b;
	int e=gcd(c,d);
	c/=e;
	d/=e;
	return Frac(c,d);
}
Frac operator /(const Frac& left,int right)
{
	int c=left.a;
	int d=left.b*right;
	int e=gcd(c,d);
	c/=e;
	d/=e;
	return Frac(c,d);
}

int n,m;

int deg[_N];
Frac v[_N];
std::vector<int> sides[_N];

void calc(int x)
{
//	printf("calc: %lld %lld %lld\n",x,v[x].a,v[x].b);
	int siz=sides[x].size();
	for(int i=0;i<siz;i++)
	{
		int y=sides[x][i];
		v[y]=v[y]+v[x]/siz;
		deg[y]--;
		if(deg[y]==0)
		{
			calc(y);
		}
	}
}

signed main()
{
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++)
	{
		int d;
		scanf("%lld",&d);
		while(d--)
		{
			int di;
			scanf("%lld",&di);
			sides[i].push_back(di);
			deg[di]++;
		}
	}
	for(int i=1;i<=m;i++)
	{
		v[i]=Frac(1,1);
		sides[0].push_back(i);
		deg[i]++;
	}
	calc(0);
	for(int i=1;i<=n;i++)
	{
		if(!sides[i].size())
		{
			printf("%lld %lld\n",v[i].a,v[i].b);
		}
	}
	return 0;
}
