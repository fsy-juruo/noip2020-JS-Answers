#include<bits/stdc++.h>
using namespace std;
long long n,m,k,a[100005],p[100005],q[100005],d[100005],maxn[100005],ax[100005],in[7],minn[100005],u,b[7],ans;
void did()
{
	for(int i=1;i<=6;i++) in[i]=b[i];
	long long x=99999990;
	for(int i=1;i<=m;i++)
	{
		if(d[i]>0)
		{
			x=min(x,(a[i]-maxn[p[i]]-b[i]+d[i])/d[i]);
		}
		else if(d[i]<0)
		{
			x=min(x,(b[i]+minn[p[i]]+1+d[i])/(-d[i]));
		}
	}
	x=max(x,(long long)0);
	ans+=x*n;
	for(int i=1;i<=m;i++)
	{
		in[i]+=d[i]*x;
	}
	for(int i=1;i<=n;i++)
	{
		in[p[i]]+=q[i];ans++;
		if(in[p[i]]>a[i]||in[p[i]]<1) break;
	}
	ans=ans%1000000007;
}
void dfs(int x)
{
	if(x>m) did();
	else for(int i=1;i<=a[x];i++)
	{
		b[x]=i;
		dfs(x+1);
	}
}
int main()
{
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		cin>>a[i];u=max(u,a[i]);
	}
	for(int i=1;i<=n;i++)
	{
		cin>>p[i]>>q[i];
		d[p[i]]+=q[i];
		if(d[p[i]]>maxn[p[i]])
		{
			maxn[p[i]]=d[p[i]];
		}
		if(d[p[i]]<minn[p[i]])
		{
			minn[p[i]]=d[p[i]];
		}
	}
	for(int i=1;i<=m;i++)
	{
		k+=abs(d[i]);
	}
	if(k==0)
	{
		cout<<-1<<endl;
	}k=0;
	dfs(1);
	cout<<ans<<endl;
	return 0;
}
