#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n,m,r[100005],c[100005],g[100005][20];
ll f[100005][2];
queue<int>q;
int gcd(ll a,ll b)
{
	if(b==0)return a;
	return gcd(b,a%b);
}
void cnt(ll a,ll b,int p)
{
	ll x=f[p][0],y=f[p][1];
	ll t1=a*y+b*x,t2=b*y;ll t3=gcd(t1,t2);
	f[p][0]=t1/t3,f[p][1]=t2/t3;
}
int main()
{
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		f[i][1]=1;
		scanf("%d",&c[i]);
		for(int j=1;j<=c[i];j++)
		{
			scanf("%d",&g[i][j]);
			r[g[i][j]]++;
		}
	}
    for(int i=1;i<=m;i++)
    {
    	f[i][0]=1,f[i][1]=1;
		q.push(i);
	}
	while(!q.empty())
	{
		int fa=q.front();
		q.pop();
		ll a=f[fa][0],b=f[fa][1]*c[fa];
		for(int i=1;i<=c[fa];i++)
		{
			int v=g[fa][i];
			cnt(a,b,v);
			r[v]--;
			if(r[v]==0)q.push(v);
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(c[i]==0)
		{
			printf("%lld %lld\n",f[i][0],f[i][1]);
		}
	}
	return 0;
}
