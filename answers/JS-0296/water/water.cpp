#include <algorithm>
#include <cstdio>
#include <iostream>
#include <stack>
#include <queue>
#include <cstring>
#include <string>
#include <vector>
using namespace std;

long long gcd(long long a,long long b)
{
	return b==0?a:gcd(b,a%b);
}
struct fs
{
	long long a,b;
};
fs check(fs x)
{
	fs c;
	c.a=x.a/gcd(x.a,x.b);
	c.b=x.b/gcd(x.a,x.b);
	return c;
}
fs operator +(fs x,fs y)
{
	if(x.a==0)
		return y;
	if(y.a==0)
		return x;
	fs c;
	c.a=x.a*y.b+y.a*x.b;
	c.b=x.b*y.b;
	return check(c);	
}
fs operator /(fs x,int y)
{
	if(x.a==0)
		return x;
	fs c;
	c.a=x.a;
	c.b=x.b*y;
	return check(c);
}
fs operator *(fs x,fs y)
{
	if(x.a==0)
		return x;
	if(y.a==0)
		return y;
	fs c;
	c.a=x.a*y.a;
	c.b=x.b*y.b;
	return check(c);	
}
fs waters[100005];
vector<int> co[100005];
int main()
{
	long long m,n,now,d;
	fs zero;
	zero.a=0;
	zero.b=0;
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>d;
		for(int j=0;j<d;j++)
		{
			cin>>now;
			co[i].push_back(now);
		}
		waters[i]=zero;
	}
	fs nw;
	nw.a=1;
	nw.b=1;
	for(int i=1;i<=m;i++)
	{
		waters[i]=nw;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			for(int k=0;k<co[j].size();k++)
			{
				waters[co[j][k]]=waters[co[j][k]]+(waters[j]/co[j].size());
			}
			if(co[j].size()!=0)
				waters[j]=zero;
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(waters[i].a!=0)
			cout<<waters[i].a<<' '<<waters[i].b<<'\n';
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
