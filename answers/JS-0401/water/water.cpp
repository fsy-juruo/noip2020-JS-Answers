#include<bits/stdc++.h>
using namespace std;
int n,m,vis[100007],anss[100007][15],t[100007];
long long ans1,ans2;
vector<int> q[100007];
void work(int s)
{
	long long k;
	ans1=1;
	ans2=anss[s][1];
	if(t[s]==1)
	{
		ans2=anss[s][1];
		return;
	}
	for(int i=2;i<=t[s];i++)
	{
	    ans1=ans1*anss[s][i]+ans2;
		ans2*=anss[s][i];
		k=__gcd(ans1,ans2);
		ans1/=k;
		ans2/=k;
	}
}
void dfs(int s,int p)
{
	for(int i=0;i<q[s].size();i++)
	{
		int v=q[s][i];
		if(vis[v]==1)
		{
			t[v]++;
			anss[v][t[v]]=p*q[s].size();
		}
		else dfs(v,p*q[s].size());
	}
}
int main()
{
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		int di;
		scanf("%d",&di);
		for(int j=1;j<=di;j++)
		{
			int xx;
			scanf("%d",&xx);
			q[i].push_back(xx);
		}
		if(di==0)
		vis[i]=1;
	}
	for(int i=1;i<=m;i++)
	dfs(i,1);
	for(int i=1;i<=n;i++)
	{
		if(vis[i]==1)
		{
			if(t[i]==0)
			{
				cout<<0<<" "<<1<<endl;
				continue;
			}
			work(i);
			printf("%lld %lld\n",ans1,ans2);
		}
	}
	return 0;
}
