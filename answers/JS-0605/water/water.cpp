#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ULL;
const int N=1e5+7;
int res=0,d[N];
int next[N<<2],head[N],to[N<<2];
ULL ans[N][2];int sc[N],ls=0;
bool pd[N];
void add(int,int);
void ps(int);
void jf(ULL,ULL,int);
ULL gcd(ULL,ULL);
int main()
{
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i)
	{
		scanf("%d",&d[i]);
		if(d[i]==0)
		{
			pd[i]=1;
			sc[++ls]=i;
		}
		else
		for(int j=1,a;j<=d[i];++j)
		{
			scanf("%d",&a);
			add(i,a);
		}
	}
	for(int i=1;i<=m;++i)
	{
		ans[i][0]=1;
		ans[i][1]=1;
		ps(i);
	}
	for(int i=1;i<=ls;++i)
	{
		if(ans[sc[i]][1]==0)ans[sc[i]][1]=1;
		cout<<ans[sc[i]][0]<<" "<<ans[sc[i]][1]<<"\n";
	}
	return 0;
}

void add(int u,int v)
{
	res++;
	next[res]=head[u];
	head[u]=res;
	to[res]=v;
}
void ps(int i)
{
	if(pd[i]==1)
	{
		return;
	}
	else
	{
		ULL x=ans[i][0],y=ans[i][1];
		ans[i][0]=0;ans[i][1]=1;
		y*=d[i];
		for(int j=head[i];j;j=next[j])
		{
			jf(x,y,to[j]);
			ps(to[j]);
		}
	}
}
void jf(ULL x,ULL y,int i)
{
	if(ans[i][1]==0)
	{
		ans[i][1]=1;
	}
	ULL a=ans[i][0],b=ans[i][1];
	ULL g=gcd(y,b);
	g=y*b/g;
	x*=(g/y);
	a*=(g/b);
	a+=x;b=g;
	g=gcd(a,b);
	a/=g;b/=g;
	ans[i][0]=a;
	ans[i][1]=b;
/*	
	int g=gcd(y,ans[i][1]);
	g=y*ans[i][1]/g;
	x*=(g/y);
	ans[i][0]*=(g/ans[i][1]);
	ans[i][0]+=x;ans[i][1]=g;
	g=gcd(ans[i][0],ans[i][1]);
	ans[i][0]/=g;
	ans[i][1]/=g;
*/
}
ULL gcd(ULL a,ULL b)
{
	return b==0?a:gcd(b,a%b);
}
