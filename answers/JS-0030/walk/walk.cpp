#include<bits/stdc++.h>
using namespace std;
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
const int K=10;
int mod=1e9+7;
int n,k;
int w[K],s[K];
struct zb{
	int wd[K];
}a[K];
struct bs{
	int l;
	int mov;
}step[500010];
int dke[K],ekd[K];
int sum;
void next()
{
	bool flag=0;
	for(int i=1;i<=k;i++)
		if(dke[i]<w[i]) 
			flag=1;
	if(flag==0)
	{
		cout<<sum%mod<<endl;
		exit(0);
	}
	dke[k]++;
	for(int i=k;i>=1;i--)
		if(dke[i]>w[i])
			dke[i]=1,dke[i-1]++;
}
bool yj()
{
	bool flag=0;
	for(int i=1;i<=k;i++)
		if(ekd[i]>w[i] || ekd[i]<1) 
			flag=1;
	if(flag==0) return 1;
	return 0;
}
int main()
{
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	n=read(),k=read();
	for(int i=1;i<=k;i++)
	{
		w[i]=read();
	}
	for(int i=1;i<=n;i++)
	{
		int c=read();
		int x=read();
		s[c]+=x;
		step[i].l=c;
		step[i].mov=x;
	}
	bool flag=0;
	for(int i=1;i<=k;i++)
		if(w[i]!=0)
			flag=1;
	if(flag==0)
	{
		cout<<-1<<endl;
		return 0;
	}
	for(int i=1;i<=k;i++)
		dke[i]=1;
	while(1)
	{
		for(int i=1;i<=k;i++)
			ekd[i]=dke[i];
		int djb=1;
		while(yj())
		{
			sum++;
			sum%=mod;
			int l=step[djb].l;
			int mov=step[djb].mov;
			ekd[l]+=mov;
			djb++;
			if(djb>n)
				djb=1;
		}
		sum+=mod;
		sum%=mod;
		next();
	}
	return 0;
}

