#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int bh[N],a,n,m,tot,t;
vector<int> b;
vector<long long> fz;
long long size[N],ss,d[N],maxs,si,g;
struct E
{
	int head,to,nxt;
}e[N*2];
inline int read()
{
	int s=0;
	char ch=getchar();
	while(ch<'0'||ch>'9')
		ch=getchar();
	while(ch>='0'&&ch<='9')
	{
		s=s*10+ch-'0';
		ch=getchar();
	}
	return s;
}
void add(int x,int y)
{
	e[++tot].to=y;
	e[tot].nxt=e[x].head;
	e[x].head=tot;
}
long long gcd(long long x,long long y)
{
	if(x%y==0) return y;
	return gcd(y,x%y);
}
void dfs1(int x,long long s)
{
	if(d[x]==0)
	{
		if(size[x]>s&&size[x]%s!=0) size[x]=size[x]*s/gcd(size[x],s);
	    else
	        if(s%size[x]!=0) size[x]=size[x]*s/gcd(s,size[x]);
	        else size[x]=s;
	    return;
	}
	ss=s*d[x];
	for(int i=e[x].head;i;i=e[i].nxt)
		dfs1(e[i].to,ss);
}
void dfs2(int x,long long sum)
{
	long long f=sum/d[x];
	for(int i=e[x].head;i;i=e[i].nxt)
	    if(d[e[i].to]==0) fz[bh[e[i].to]]+=f;
	    else dfs2(e[i].to,f);
}
int main()
{
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	n=read();
	m=read();
	for(int i=1;i<=n;++i)
	{
		d[i]=read();
		if(!d[i])
		{
			bh[i]=t++;
			b.push_back(i);
			fz.push_back(0);
		}
		else
		    for(int j=1;j<=d[i];++j)
		        add(i,read());
	}
	for(int i=1;i<=n;++i)
	    size[i]=1;
	dfs1(1,1);
	maxs=size[b[0]];
	for(int i=1;i<b.size();++i)
	{
		si=size[b[i]];
		if(si>maxs)
		    if(si%maxs==0) maxs=si;
		    else maxs=maxs*si/gcd(si,maxs);
		else if(si<maxs&&maxs%si!=0) maxs=maxs*si/gcd(maxs,si);
	}
	dfs2(1,maxs);
	for(int i=0;i<fz.size();++i)
	{
		if(maxs%fz[i]==0) printf("%d %lld\n",1,maxs/fz[i]);
		else
		{
			g=gcd(maxs,fz[i]);
			printf("%lld %lld\n",fz[i]/g,maxs/g);
		}
	}
	return 0;
}
