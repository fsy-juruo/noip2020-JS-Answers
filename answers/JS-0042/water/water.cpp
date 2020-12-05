#include<bits/stdc++.h>
using namespace std;
#define ull unsigned long long
const int maxn=1e5+10;
template <typename T> int read(T &x)
{
		 x=0;
		 int f=1;
		 char c=getchar();
		 for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
		 for(;isdigit(c);c=getchar())x=x*10+c-'0';
		 x*=f;
}
int n,m;
int a[maxn][10];
int vis[maxn];
int inq[maxn];
struct DY{
	ull p,q;
}ans[maxn];
queue<int>q;
int tot[maxn];
int t;
void add(DY x,DY y,int d,int i)
{
	x.q=x.q*d;
	if(y.q==0)
	{
		y.p=x.p;
		y.q=x.q;
		ull gcd=__gcd(y.p,y.q);
		y.p/=gcd;
		y.q/=gcd;
		ans[i]=(DY){y.p,y.q};
		return;
	}
	ull gcd=__gcd(x.q,y.q);
	ull bs=x.q*y.q/gcd;
	ull bsx=bs/x.q;
	ull bsy=bs/y.q;
	ull pp=x.p*bsx+y.p*bsy;
	ull gcdd=__gcd(bs,pp);
	bs/=gcdd;
	pp/=gcdd;
	ans[i]=(DY){pp,bs};
}
int main()
{
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	read(n);
	read(m);
	for(int i=1;i<=n;i++)
	{
		int d;
		read(d);
		vis[i]=d;
		if(!d)
		{
			tot[++t]=i;
		}
		for(int j=1;j<=d;j++)
		{
			read(a[i][j]);
			inq[a[i][j]]++;	
		}
	}
	for(int i=1;i<=m;i++)
	{
		ans[i].p=1,ans[i].q=1;
		for(int j=1;j<=vis[i];j++)
		{
			int x=a[i][j];
			inq[x]--;
			add(ans[i],ans[x],vis[i],x);
		}	
	}
	for(int i=m+1;i<=n;i++)
	{
		if(!inq[i])
		{
			q.push(i);		
		}		
	}
	while(!q.empty())
	{
		int u=q.front();
		q.pop();
		for(int i=1;i<=vis[u];i++)
		{
			int v=a[u][i];
			inq[v]--;
			add(ans[u],ans[v],vis[u],v);
			if(!inq[v])
			{
				q.push(v);
			}
		}
	}
	for(int i=1;i<=t;i++)
	printf("%llu %llu\n",ans[tot[i]].p,ans[tot[i]].q);
	return 0;
}

