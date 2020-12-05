#include<bits/stdc++.h>
#define ll long long
#define N 100001
#define P 1000000007
#define rg register
#define m_p make_pair
using namespace std;
ll n,m,ans,t=1,w[N],b[11],c[11];
struct node
{
	ll k[11];
}a[N],f[20];
node operator + (node a,node b)
{
	for (rg int i=1;i<=m;i++)
	a.k[i]+=b.k[i];
	return a;
}
inline ll read()
{
	ll sum=0,f=1;
	char c=getchar();
	while (c<'0'||c>'9')
	{
		if (c=='-') f=-1;
		c=getchar();
	}
	while (c>='0'&&c<='9')
	{
		sum=sum*10+c-'0';
		c=getchar();
	}
	return f*sum;
}
bool ok(node a)
{
	for (rg int i=1;i<=m;i++)
	if (a.k[i]<1||a.k[i]>w[i]) return 0;
	return 1;
}
void do1()
{
	for (rg int i=1;i<=w[1];i++)
	for (rg int j=1;j<=w[2];j++)
	for (rg int jj=1;jj<=w[3];jj++)
	{
	node p;ll sum=0;
	p.k[1]=i;p.k[2]=j;p.k[3]=jj;
	for (rg int c=1;c<=n;c++)
	{
	    ans++;
		if (!ok(p+a[c])) break;
		if (c==n) p=p+a[n],c=0;
	}
	ans%=P;
	}
}
void do2()
{
	for (rg int i=1;i<=w[1];i++)
	for (rg int j=1;j<=w[2];j++)
	{
	node p;ll sum=0;
	p.k[1]=i;p.k[2]=j;
	for (rg int c=1;c<=n;c++)
	{
	    ans++;
		if (!ok(p+a[c])) break;
		if (c==n) p=p+a[n],c=0;
	}ans%=P;
	}
}
void do3()
{
	for (rg int i=1;i<=w[1];i++)
	for (rg int j=1;j<=w[2];j++)
	for (rg int ii=1;ii<=w[3];ii++)
	for (rg int jj=1;jj<=w[4];jj++)
	{
	node p;ll sum=0;
	p.k[1]=i;p.k[2]=j;p.k[3]=ii;p.k[4]=jj;
	for (rg int c=1;c<=n;c++)
	{
	    ans++;
		if (!ok(p+a[c])) break;
		if (c==n) p=p+a[n],c=0;
	}
	ans%=P;
	}
}
void do4()
{
	for (rg int i=1;i<=w[1];i++)
	for (rg int j=1;j<=w[2];j++)
	for (rg int ii=1;ii<=w[3];ii++)
	for (rg int jj=1;jj<=w[4];jj++)
	for (rg int kk=1;kk<=w[5];kk++)
	{
	node p;ll sum=0;
	p.k[1]=i;p.k[2]=j;p.k[3]=ii;p.k[4]=jj;p.k[5]=kk;
	for (rg int c=1;c<=n;c++)
	{
	    ans++;
		if (!ok(p+a[c])) break;
		if (c==n) p=p+a[n],c=0;
	}
	ans%=P;
	}
}
int main()
{
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	n=read();m=read();
	for (rg int i=1;i<=m;i++) w[i]=read();
	for (rg int i=1;i<=n;i++)
	{
		ll x=read(),y=read();
		for (rg int j=1;j<=m;j++) a[i].k[j]=a[i-1].k[j];
		a[i].k[x]+=y;b[x]=max(b[x],a[i].k[x]);b[x]=max(b[x],abs(a[i].k[x]));//cout<<a[i].k[j]<<endl;
	}
	for (rg int i=1;i<=m;i++) 
	{
		if (b[i]>=w[i]) break;
		if (a[n].k[i]!=0) break;
		if (i==m) {cout<<-1;return 0;}
	}
	if (n<=100) 
	{
		if (m==3) do1();
		if (m==2) do2();
		if (m==4) do3();
		if (m==5) do4();
	}
	cout<<ans;
	//for (rg int i=0;(1<<i)<=n;i++)
	//for (rg int j=1;j<=m;j++)
	//f[i].k[j]=a[1<<i].k[j];
	return 0;
}
