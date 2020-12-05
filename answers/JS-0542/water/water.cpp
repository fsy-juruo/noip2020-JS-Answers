#include<bits/stdc++.h>
using namespace std;
struct fs{
	long long fm,fz;
}dis[100010];
long long n,m,k[100010],rd[100010],hyy;
vector<long long> g[100010];
template<typename T> void read(T &x)
{
	long long f=1;x=0;char c=getchar();
	while(!isdigit(c)){if(c=='-') f=-1;c=getchar();}
	while(isdigit(c)){x=(x<<1)+(x<<3)+c-48;c=getchar();}
	x*=f;
}
template<typename T> void write(T x)
{
	if(x<0){putchar('-');x=-x;}
	if(x>9) write(x/10);
	putchar(x%10+48);
}
template<typename T> void writeln(T x)
{
	write(x);putchar('\n');
}
long long gcd(long long a,long long b)
{
	if(a%b==0) return b;
	return gcd(b,a%b);
}
void yf(long long &a,long long &b)
{
	long long e=gcd(a,b);
	a=a/e;b=b/e;
}
fs jf(long long a,long long b,long long c,long long d)
{
	fs l;
	if(a==0&&b==0)
	{
		l.fz=c;l.fm=d;return l;
	}
	l.fm=b*d/gcd(b,d);
	l.fz=a*l.fm/b+c*l.fm/d;
	yf(l.fz,l.fm);
	return l;
}
void dfs(long long x,long long gg,long long st)
{
	long long p=dis[x].fz,q=dis[x].fm;
	if(g[x].size()==0){dis[x]=jf(p,q,gg,st);return;}
	if(st!=0&&gg!=0){dis[x].fm=st;dis[x].fz=gg;}
	long long s=dis[x].fz,ss=dis[x].fm*g[x].size();dis[x].fm=0;dis[x].fz=0;
	yf(s,ss);
	for(int i=0;i<g[x].size();i++)
	{
		dfs(g[x][i],s,ss);
	}
}
int main()
{
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	read(n);read(m);memset(rd,0,sizeof(rd));
	for(int i=1;i<=n;i++){dis[i].fm=0;dis[i].fz=0;}
	for(int i=1;i<=n;i++)
	{
		read(k[i]);
		for(int j=1;j<=k[i];j++)
		{
			read(hyy);rd[hyy]++;g[i].push_back(hyy);
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(rd[i]>0) continue;
		dis[i].fm=1;dis[i].fz=1;
		dfs(i,0,1);
	}
	for(int i=1;i<=n;i++) 
	if(g[i].size()==0) 
	{
		write(dis[i].fz);putchar(' ');writeln(dis[i].fm);
	}
	return 0;
}

