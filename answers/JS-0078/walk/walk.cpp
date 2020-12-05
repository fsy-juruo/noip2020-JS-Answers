#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll mod=100000007;
ll n,k,w[15],pos[15],pos2[15],c[500005],d[500005],ans,del[15][3];
bool add()
{
	for(int i=1;i<=k;i++) if(pos2[i]+del[i][1]>w[i]||pos2[i]+del[i][0]<1) return 0;
	for(int i=1;i<=k;i++) pos2[i]+=del[i][2];
	return 1;
}
bool check_0()
{
	for(int i=1;i<=k;i++) if(del[i][2]!=0) return 0;
	return 1;
}
void dfs(int now)
{
	if(now==k+1)
	{
		for(int i=1;i<=k;i++) pos2[i]=pos[i];
		while(add()) 
		{
			ans+=n;
			if(ans>=mod) ans-=mod;
			if(check_0())
			{
				puts("-1");
				exit(0);
			}
		}
		for(int i=1;i<=n;i++)
		{
			pos2[c[i]]+=d[i];
			ans++;
			if(pos2[c[i]]>w[c[i]]||pos2[c[i]]<1) break;
			if(ans>=mod) ans-=mod;
		}
		return;
	}
	for(int i=1;i<=w[now];i++) 
	{
		pos[now]=i;
		dfs(now+1);
	}
}
int main()
{
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=k;i++) scanf("%lld",&w[i]),del[i][0]=0x3f3f3f3f,del[i][1]=-0x3f3f3f3f;
	for(int i=1;i<=n;i++) scanf("%lld%lld",&c[i],&d[i]);
	for(int i=1;i<=n;i++) 
	{
		del[c[i]][2]+=d[i];
		del[c[i]][0]=min(del[c[i]][0],del[c[i]][2]);
		del[c[i]][1]=max(del[c[i]][1],del[c[i]][2]);
	}
	dfs(1);
	cout<<ans;
	return 0;
}
