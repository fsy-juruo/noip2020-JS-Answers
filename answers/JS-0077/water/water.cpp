#include<bits/stdc++.h>
#define MAXN 100005
#define MAXM 1200005
using namespace std;
typedef long long ll;
struct edge{
	int to_,next_;
} e[MAXM];
int head[MAXN],tot;
void Add(int x,int y)
{
	e[++tot].to_=y;
	e[tot].next_=head[x];
	head[x]=tot;
}
ll gcd(ll a,ll b)
{
	if  (b==0)	return a;
		  else	return gcd(b,a%b);
}
template <typename qwq> void read(qwq &a)
{
	a=0;char c=getchar();int x=1;
	for  (;!isdigit(c);c=getchar())	if  (c=='-')	x=-x;
	for  (;isdigit(c);a=a*10+c-48,c=getchar());a*=x;
}
template <typename qwq> void write(qwq x)
{
	if (x>=10)	write(x/10);
	putchar(x%10+48);
}
template <typename qwq> void writeln(qwq x)
{
	if  (x>=0)	write(x);
		else	putchar('-'),write(-x);
	putchar('\n');
}
ll q[MAXN],p[MAXN];
int rudu[MAXN];
int chudu[MAXN];
int a[MAXN];
int main()
{
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	int N,M;read(N),read(M);
	for  (int i=1;i<=N;i++)
		{
			read(chudu[i]);
			for  (int j=1;j<=chudu[i];j++)
				{
					int y;read(y);
					Add(i,y);
					rudu[y]++;
				}
		}
	for  (int i=1;i<=N;i++)
		q[i]=1;
	for  (int i=1;i<=M;i++)
		p[i]=q[i]=1;
	int R=0;
	for  (int i=1;i<=N;i++)
		if  (rudu[i]==0)
			a[++R]=i;
	int L=1;
	while  (L<=R)
		{
			int x=a[L];
			if  (chudu[x]==0)
				{
					L++;
					continue;
				}
			ll A=p[x],b=q[x];
			b*=chudu[x];
			ll c=gcd(A,b);
			A/=c,b/=c;
			for  (int i=head[x];i;i=e[i].next_)
				{
					int y=e[i].to_;
					ll fmgcd=gcd(b,q[y]);
					ll aa=q[y]/fmgcd,bb=b/fmgcd;
					ll fm=q[y]/fmgcd*b;
					ll fz=A*aa+p[y]*bb;
					ll jggcd=gcd(fz,fm);
					fz/=jggcd,fm/=jggcd;
					p[y]=fz,q[y]=fm;
					rudu[y]--;
					if  (rudu[y]==0)	a[++R]=y;
				}
			p[x]=q[x]=0;
			L++;
		}
	for  (int i=1;i<=N;i++)
		if  (chudu[i]==0)
			{
				write(p[i]);
				putchar(' ');
				writeln(q[i]);
			}		
	return 0;
}
