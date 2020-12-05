#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
inline int read()
{
	int s=0,f=1;
	char ch=getchar();
	for(;!isdigit(ch);ch=getchar())
		if(ch=='-')
			f*=-1;
	for(; isdigit(ch);ch=getchar())
		s*=10,s+=ch-'0';
	return s*f;
}
vector<int> v[N];
int n,m,gs[N];
int fina[N],len;
struct fs{
	int fz,fm;
}water[N];
int gcd(int a,int b)
{
	if(b==0) return a;
	return gcd(b,a%b);
}
fs yf(fs a)
{
	int x=gcd(a.fm,a.fz);
	a.fm/=x;
	a.fz/=x;
	return a;
}
fs jia(fs a,fs b)
{
	int x=(a.fm*b.fm)/gcd(a.fm,b.fm);
	a.fz*=x/a.fm;
	b.fz*=x/b.fm;
	a.fm=x,b.fm=x;
	fs c;
	c.fm=x;
	c.fz=a.fz+b.fz;
	c=yf(c);
	//cout<<a.fz<<'/'<<a.fm<<'+'<<b.fz<<'/'<<b.fm<<'='<<c.fz<<'/'<<c.fm<<endl;;
	return c;
}
fs mul(fs a,fs b)
{
	fs c;
	c.fm=a.fm*b.fm;
	c.fz=a.fz*b.fz;
	c=yf(c);
	return c;
}
void dfs(int x)
{
	if(gs[x]==0) return;
	for(int i=0;i<gs[x];i++)
	{
		int to=v[x][i];
		fs c;
		c.fm=gs[x],c.fz=1;
		c=mul(c,water[x]);
		water[to]=jia(water[to],c);
		dfs(to);
	}
}
int main()
{
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=n;i++)
	{
		int x=read();
		gs[i]=x;
		for(int j=1;j<=x;j++)
		{
			int to=read();
			v[i].push_back(to);
		}
		if(x==0)
			fina[++len]=i;
	}
	for(int i=1;i<=n;i++)
		water[i].fm=1;
	for(int i=1;i<=m;i++)
		water[i].fm=1,water[i].fz=1;
	for(int i=1;i<=m;i++)
		dfs(i);
	for(int i=1;i<=len;i++)
		cout<<water[fina[i]].fz<<' '<<water[fina[i]].fm<<endl;
	return 0;
}

