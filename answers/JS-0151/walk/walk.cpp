#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
inline int du()
{
	int x=0,f=1;
	char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') {x=x*10+(int)(ch-'0');ch=getchar();}
	return x*f;
}

int k,n;
int w[6];
int c[6];
struct node
{
	int a,d;
}qaq[100010];
long long ans=0;
int ca[6];

inline int dfs()
{
	int i,l;
	for (i=1;i<=n;i++)
	{
		ca[qaq[i].a]+=qaq[i].d;
		ans=(ans+1)%MOD;
		if (ca[qaq[i].a]>w[qaq[i].a]||ca[qaq[i].a]<=0)	return 0;
	}
	l=0;
	for (i=1;i<=k;i++) if (ca[i]!=c[i]) l=1;
	if (l==0) return -1;
	while (1)
	{
		for (i=1;i<=n;i++)
		{
			ca[qaq[i].a]+=qaq[i].d;
			ans=(ans+1)%MOD;
			if (ca[qaq[i].a]>w[qaq[i].a]||ca[qaq[i].a]<0)	return 0;
		}
	}
}

inline int azzz(int a)
{
	if (a==k)
	{
		for (int i=1;i<=w[a];++i)
		{	
			c[a]=i;
			for (int j=1;j<=k;j++) ca[j]=c[j];
			if (dfs()==-1) return -1;
		}
		return 0;
	}
	for (int i=1;i<=w[a];++i)
	{
		c[a]=i;
		if (azzz(a+1)==-1) return -1;
	}
	return 0;
}

int main()
{
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	int i,j;
	n=du();
	k=du();
	for (i=1;i<=k;i++)
	{
		w[i]=du();
	}
	for (i=1;i<=n;i++)
	{
		qaq[i].a=du();
		qaq[i].d=du();
	}
	if (azzz(1)==-1) 
	{
		cout<<-1;
		return 0;
	}
	cout<<ans;

	return 0;
}

