//各位朋友们大家好啊 
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
struct node{
	LL p;
	LL q;
}f[100005];
int edg[100000005],fir[100005],cnt=1,m,n,d[100005],deg[100005],x,kkk;
int wor[100005],hea,tai;//hen,tai(?)
inline int read()
{
	int a=0;
	char c;
	do
	{
		c=getchar();
	}while(c>'9'||c<'0');
	while(c<='9'&&c>='0')
	{
		a=(a<<3)+(a<<1)+c-'0';
		c=getchar();
	}
	return a;
}
LL ggcd(LL a,LL b)
{
	a%=b;
	if(a==0)return b;
	ggcd(b,a);
}
node yf(node &a)
{
	kkk=ggcd(a.p,a.q);
	a.p/=kkk;
	a.q/=kkk;
	return a;
}
int main()
{
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	n=read();m=read();
	for(register int i=1;i<=n;++i)
	{
		d[i]=read();
		fir[i]=cnt;
		f[i].q=1;
		for(register int j=0;j<d[i];++j)
		{
			x=read();
			edg[cnt++]=x;
			++deg[x];
		}
	}
	for(register int i=1;i<=n;++i)
		if(deg[i]==0)
		{
			f[i].p=1;
			wor[hea++]=i;
		}
	while(hea!=tai)
	{
		x=wor[tai];
		++tai;
		if(d[x]==0)continue;
		f[x].q*=d[x];
		yf(f[x]);
		for(register int i=fir[x];i<fir[x]+d[x];++i)
		{
			f[edg[i]].p=f[edg[i]].p*f[x].q+f[edg[i]].q*f[x].p;
			f[edg[i]].q*=f[x].q;
			yf(f[edg[i]]);
			--deg[edg[i]];
			if(deg[edg[i]]==0)
			wor[hea++]=edg[i];
		}
	}
	for(register int i=1;i<=n;++i)
	if(d[i]==0)
	{
		cout<<f[i].p<<' '<<f[i].q<<'\n';
	} 
	return 0;
}
