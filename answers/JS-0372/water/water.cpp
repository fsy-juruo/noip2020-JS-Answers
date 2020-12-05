#include<bits/stdc++.h>
#define int long long
using namespace std;
int read()
{
	int num=0;bool flg=false;char ch=getchar();
	while(!isdigit(ch)&&ch!='-') ch=getchar();
	if(ch=='-') flg=true;
	else num=ch^48;
	ch=getchar();
	while(isdigit(ch)) num=(num<<3)+(num<<1)+(ch^48),ch=getchar();
	return flg?-num:num;
}
void write(int x)
{
	if(x<0) putchar('-'),x=-x;
	if(x/10) write(x/10);
	putchar((x%10)^48);
}
void writeln(int x)
{
	write(x);
	putchar('\n');
}
const int N=1e5+5;
int to[N*5],nxt[N*5],h[N],tot;
void add_(int u,int v)
{
	to[++tot]=v;
	nxt[tot]=h[u];
	h[u]=tot;
}
int fz[N],fm[N],d[N],in_[N],q[N];
int gcd(int x,int y)
{
	return y?gcd(y,x%y):x;
}
void f(int a,int b)
{
	int tfm,tfz,g;
	tfm=fm[b]*d[b],tfz=fz[b];
	g=gcd(tfm,tfz);
	tfm/=g,tfz/=g;
	int tm=fm[a],tz=fz[a];
	fm[a]=tm*tfm,fz[a]=tz*tfm+tfz*tm;
	g=gcd(fm[a],fz[a]);
	fm[a]/=g,fz[a]/=g;
}
int head=1,tail=0,n,m,x;
signed main()
{
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=n;i++) 
	{
		d[i]=read();
		for(int j=1;j<=d[i];j++)
		{
			x=read();
			in_[x]++;
			add_(i,x);
		}
	}
	for(int i=1;i<=n;i++) fm[i]=1,fz[i]=0;
	for(int i=1;i<=n;i++) 
	{
		if(!in_[i])
		{
			q[++tail]=i;
			fz[i]=1;
		}
	}
	while(head<=tail)
	{
		int x=q[head++];
		for(int i=h[x];i;i=nxt[i])
		{
			int y=to[i];
			f(y,x);
			in_[y]--;
			if(!in_[y]) q[++tail]=y;
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(!d[i])
		{
			write(fz[i]),putchar(' '),writeln(fm[i]);
		}
	}
	return 0;
}

