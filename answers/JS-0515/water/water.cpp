#include<bits/stdc++.h>
using namespace std;
struct sg
{
	long long fm,fz;
}a[100010];
template<typename T>void Read(T &cn)
{
	char ch;
	int f=0;
	cn=0;
	while(!isdigit(ch=getchar()))if(ch=='-')f=1;
	if(f){cn=cn*10+48-ch;while(isdigit(ch=getchar()))cn=cn*10+48-ch;}
	else {cn=cn*10+ch-48;while(isdigit(ch=getchar()))cn=cn*10+ch-48;}
}
long long n,m,gn[100010],sc[100010],k;
vector<long long>g[100010];
void prnt(sg x)
{
	printf("%lld %lld\n",x.fz,x.fm);
}
long long gcd(long long x,long long y)
{
	long long r=x%y;
	while(r){x=y;y=r;r=x%y;}
	return y;
}
sg yf(sg x)
{
	long long gx=gcd(x.fm,x.fz);
	sg ans;
	ans.fm=x.fm/gx;
	ans.fz=x.fz/gx;
	return ans;
}
sg ad(sg x,sg y)
{
//	cout<<"\nadd:\n";
//	prnt(x);
//	prnt(y);
	long long lcm=x.fm*y.fm/gcd(x.fm,y.fm);
	long long cx=lcm/x.fm,cy=lcm/y.fm;
//	cout<<"lcm:"<<lcm;
//	cout<<"\ncx:"<<cx;
//	cout<<"\ncy:"<<cy<<endl;
	sg ans;
	ans.fm=lcm;
	ans.fz=cx*x.fz+cy*y.fz;
	return yf(ans);
}
sg dv(sg x,long long y)
{
	sg ans;
	ans.fm=x.fm*y;
	ans.fz=x.fz;
	return yf(ans);
}
void pn(long long u,sg p)
{
//	cout<<"*"<<u<<' ';
//	prnt(p);
	if(g[u].size()==0)
	{
//		cout<<"qaq";
//		prnt(a[u]);
		sg ans;
		ans.fm=ad(a[u],p).fm;
		ans.fz=ad(a[u],p).fz;
		a[u].fm=ans.fm;
		a[u].fz=ans.fz;
//		cout<<"a[8]:";
//		prnt(a[8]);
//		cout<<"a[10]:";
//		prnt(a[10]);
		return ;
	}
//	cout<<"a[8]:";
//	prnt(a[8]);
//	cout<<"a[10]:";
//	prnt(a[10]);
	int gsss=g[u].size();
	for(int i=0;i<gsss;i++)
	{
		long long v=g[u][i];
		pn(v,dv(p,g[u].size()));
	}
}
int main()
{
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	Read(n);
	Read(m);
	long long x;
	for(int i=1;i<=n;i++)
	{
		Read(gn[i]);
		for(int j=1;j<=gn[i];j++)
			Read(x),g[i].push_back(x);
	}
	for(int i=1;i<=n;i++)
	{
		if(g[i].size()==0)sc[++k]=i;
	}
	for(int i=1;i<=n;i++)
	{
		a[i].fm=1;
		a[i].fz=0;
	}
	sg p;
	p.fm=1;
	p.fz=1;
	for(int i=1;i<=m;i++)
	{
		pn(i,p);
	}
	for(int i=1;i<=k;i++)
		prnt(a[sc[i]]);
	return 0;
}


