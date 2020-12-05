#include<bits/stdc++.h>
using namespace std;
const int maxn=100005;
struct e
{
	int nxt,to;
}edge[maxn*5];
int num=0,head[maxn]={},a[maxn]={},b[maxn]={},d[maxn]={};
long long n,m,x,y,yueshu=1;
long long zi[maxn]={},mu[maxn]={};
inline long long gc(long long x,long long y)
{
	long long res2;
	if(x==0||y==0)
	{
		return 1;
	}
	if(x>y)
	{
	    res2=x;
		x=y;
		y=res2;
	}
	if((y%x)==0)
	{
		return x;
	}
    long long res=(y%x);
	return gc(res,x);	
}
inline void adde(int u,int v)
{
	a[v]++;//入度 
	edge[++num].nxt=head[u];
	head[u]=num;
	edge[num].to=v;
	return;
}
void dfs(int u)
{
	
	int v;
	for(int i=head[u];i;i=edge[i].nxt)
	{
		v=edge[i].to;
		zi[v]=(zi[v]*mu[u]*b[u]+zi[u]*mu[v]);
		mu[v]=mu[u]*b[u]*mu[v];
		long long xx=gc(zi[v],mu[v]);
		zi[v]/=xx;
		mu[v]/=xx;
		if(a[v]==1)//最后一条
		{
			dfs(v);
		}
		a[v]--;
	}
	return;
}
int main()
{
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>x;
		b[i]=x; 
		for(int j=1;j<=x;j++)
		{
			cin>>y;
			adde(i,y);
		}
	}
	for(int i=1;i<=n;i++)
	{
		mu[i]=1;
		d[i]=a[i];
	}
	for(int i=1;i<=n;i++)
	{
		if(d[i]==0)
		{
			zi[i]=1;
			dfs(i);
		}
		
	}
	for(int i=1;i<=n;i++)
	{
		if(!b[i])
		{
			yueshu=gc(zi[i],mu[i]);
			zi[i]/=yueshu;
			mu[i]/=yueshu;
			cout<<zi[i]<<" "<<mu[i]<<endl;
		}
	}
	return 0;
}
