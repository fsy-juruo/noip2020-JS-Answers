#include<bits/stdc++.h>
using namespace std;
const int mod=1000000007;
int n,k,w[15],c[500010],d[500010],pos[15],p[15];
long long ans;
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
inline void write(int x)
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
	int sta[10],tp=0;
	while(x)
	{
		sta[++tp]=x%10;
		x/=10;
	}
	while(tp)
		putchar(sta[tp--]+'0');
}
inline void calc()
{
	int i;
	for(i=1;i<=k;i++)
		p[i]=pos[i];
	for(i=1;;i++)
	{
		int x=(i-1)%n+1;
		p[c[x]]+=d[x];
		ans=(ans+1)%mod;
		if(p[c[x]]<1||p[c[x]]>w[c[x]])
			break;
	}
}
void dfs(int d)
{
	if(d>k)
	{
		calc();
		return;
	}
	for(int i=1;i<=w[d];i++)
	{
		pos[d]=i;
		dfs(d+1);
	}
}
int main()
{
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	int i;
	n=read();
	k=read();
	for(i=1;i<=k;i++)
		w[i]=read();
	for(i=1;i<=n;i++)
	{
		c[i]=read();
		d[i]=read();
		pos[c[i]]+=d[i];
	}
	for(i=1;i<=k;i++)
		if(pos[i])
			break;
	if(i>k)
	{
		write(-1);
		fclose(stdin);
		fclose(stdout);
		return 0;
	}
	dfs(1);
	write(ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
