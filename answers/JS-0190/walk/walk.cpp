#include <bits/stdc++.h>
#define inf 1000000007
#define mod 1000000007
#define int long long
using namespace std;
template<typename T> void read(T &x){
	x=0;char ch=getchar();int fh=1;
	while(ch<'0'||ch>'9'){if(ch=='-')fh=-1;ch=getchar();}
	while(ch>='0'&&ch<='9')x=x*10+ch-'0',ch=getchar();
	x*=fh;
}
template<typename T> void write(T x){
	if(x<0) x=-x,putchar('-');
	if(x>9) write(x/10);
	putchar(x%10+'0');
}
template<typename T> void writeln(T x){
	write(x);
	puts("");
}
int qpow(int a,int b)
{
	int res=1;
	while(b)
	{
		if(b&1) res=res*a;
		a=a*a;
		b>>=1;
	}
	return res;
}
int n,k;
int w[15];
int c[500005],d[500005];
int l[15],r[15];
int a[15];
int del[15];
signed main()
{
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	read(n);read(k);
	long long chk=1;
	for(register int i=1;i<=k;++i)
	{
		read(w[i]);
		chk*=w[i];
		if(chk>inf) chk=inf;
		l[i]=1,r[i]=w[i];
	}
	for(register int i=1;i<=n;++i)
	{
		read(c[i]);read(d[i]);
	}
	if(chk>=inf)
	{
		writeln(-1);
		return 0;
	}
	memset(del,0,sizeof(del));
	for(register int i=1;i<=n;++i)
	{
		del[c[i]]+=d[i];
		l[c[i]]=max(l[c[i]],1-del[c[i]]);
		r[c[i]]=min(r[c[i]],w[c[i]]-del[c[i]]);
	}
	long long ans=0;
	for(register int i=0;i<chk;++i)
	{
		int tmp=i;
		for(register int j=1;j<=k;++j)
		{
			a[j]=tmp%w[j]+1;
			tmp/=w[j];
		}
		bool ok=true;
		for(register int j=1;j<=k;++j)
			if(a[j]<l[j]||a[j]>r[j])
			{
				ok=false;
				break;
			}
		int ll=-1,rr=2*inf;
		for(register int j=1;j<=k;++j)
			if(del[j]>0)
				rr=min(rr,(r[j]-a[j])/del[j]);
			else if(del[j]<0)
				rr=min(rr,(l[j]-a[j])/del[j]);
		if(rr==2*inf)
		{
			writeln(-1);
			return 0;
		}
		if(ll<=rr&&ok) ans=(ans+(long long)(rr+1)*(long long)n%mod)%mod;
		else rr=-1;
		for(register int j=1;j<=k;++j)
			a[j]+=del[j]*(rr+1);
		for(register int j=1;j<=n;++j)
		{
			bool flag=true;
			for(register int id=1;id<=k;++id)
				if(a[id]<1||a[id]>w[id])
				{
					flag=false;
					break;
				}
			if(!flag) break;
			a[c[j]]+=d[j];
			ans++;
			ans%=mod;
		}
		for(register int j=1;j<=n;++j)
		{
			bool flag=true;
			for(register int id=1;id<=k;++id)
				if(a[id]<1||a[id]>w[id])
				{
					flag=false;
					break;
				}
			if(!flag) break;
			a[c[j]]+=d[j];
			ans++;
			ans%=mod;
		}
	}
	writeln(ans);
	return 0;
}

