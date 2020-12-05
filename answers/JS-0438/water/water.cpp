#include<bits/stdc++.h>
using namespace std;
int n,m;
struct uu
{
	long long x,y;
}d[100005];
vector<int>v[100005];
void read(int &s)
{
	s=0;
	int f=1;
	char c=getchar();
	while(!isdigit(c))
	{
		if(c=='-')f=-1;
		c=getchar();
	}
	while(isdigit(c))
	{
		s=(s<<3)+(s<<1)+(c-48);
		c=getchar();
	}
	s=s*f;
}
long long gcd(long long x,long long y)
{
	if(!y)return x;
	else return gcd(y,x%y);
}
void yf(int x)
{
	long long e=gcd(d[x].x,d[x].y);
	d[x].x/=e;
	d[x].y/=e;
}
void ss(int x)
{
	if(!v[x].size())return;
	for(int i=0;i<v[x].size();i++)
	{
		int y=v[x][i];
		d[y].y=d[y].y*v[x].size()*d[x].x+d[y].x*d[x].y;
		d[y].x*=v[x].size()*d[x].x;
		yf(y);
		ss(y);
	}
	d[x].x=1;
	d[x].y=0;
}
int main()
{
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	read(n);
	read(m);
	for(int i=1;i<=n;i++)
	{
		int s;
		read(s);
		for(int j=1;j<=s;j++)
		{
			int x;
			read(x);
			v[i].push_back(x);
		}
		d[i].x=1;
	}
	for(int i=1;i<=m;i++)
	{
		d[i].x=1;
		d[i].y=1;
		ss(i);
	}
	for(int i=1;i<=n;i++)
	{
		if(!v[i].size())printf("%lld %lld\n",d[i].y,d[i].x);
	}
	return 0;
}
