#include<bits/stdc++.h>
using namespace std;
struct fract
{
	long long u,d;
	fract()
	{
		u=0;
		d=1;
	}
}ans[100010],t;
int d[100010],ind[100010];
vector<int>g[100010],ou;
queue<int>q;
inline int read()
{
	char c=getchar();
	int x=0,y=1;
	while(c<'0'||c>'9')
	{
		if(c=='-')
			y=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		x=x*10+c-'0';
		c=getchar();
	}
	return x*y;
}
inline void write(long long x)
{
	if(!x)
	{
		putchar('0');
		return;
	}
	if(x<0)
	{
		putchar('-');
		x=-x;
	}
	int sta[20],tp=0;
	while(x)
	{
		sta[++tp]=x%10;
		x/=10;
	}
	while(tp)
		putchar(sta[tp--]+'0');
}
long long gcd(long long x,long long y)
{
	if(!x)
		return y;
	if(!y)
		return x;
	return gcd(y,x%y);
}
int main()
{
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	int n=read(),m=read(),i,j,x,y;
	long long gc;
	for(i=1;i<=n;i++)
	{
		d[i]=read();
		if(!d[i])
			ou.push_back(i);
		for(j=0;j<d[i];j++)
		{
			x=read();
			g[i].push_back(x);
			ind[x]++;
		}
	}
	for(i=1;i<=n;i++)
		if(!ind[i])
		{
			q.push(i);
			ans[i].u=1;
		}
	while(q.size())
	{
		x=q.front();
		q.pop();
		t=ans[x];
		t.d*=g[x].size();
		gc=gcd(t.d,t.u);
		t.d/=gc;
		t.u/=gc;
		for(i=0;i<g[x].size();i++)
		{
			y=g[x][i];
			ind[y]--;
			if(!ind[y])
				q.push(y);
			ans[y].u=ans[y].u*t.d+ans[y].d*t.u;
			ans[y].d*=t.d;
			gc=gcd(ans[y].d,ans[y].u);
			ans[y].d/=gc;
			ans[y].u/=gc;
		}
	}
	for(i=0;i<ou.size();i++)
	{
		write(ans[ou[i]].u);
		putchar(' ');
		write(ans[ou[i]].d);
		putchar('\n');
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
