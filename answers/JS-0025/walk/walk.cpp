#include<bits/stdc++.h>
#define mod 1000000007

using namespace std;
int w[20];
int c[100010],d[100010],dir[100010],fst[200020],hcq[100010];
int n,k;
int pos[20];
long long ans;
bool flag=0;

bool check(int now[])
{
	for(int i=1;i<=k;i++) if(now[i]<1||now[i]>w[i]) return 0;
	return 1;
}

bool ok(int now[],int pos[])
{
	for(int i=1;i<=k;i++) if(now[i]!=pos[i]) return 1;
	return 0;
}

void dfs(int layer)
{
	if(flag) return;
	if(layer==k+1)
	{
		int now[20]={};
		for(int i=1;i<=k;i++) now[i]=pos[i];
		for(int i=1;i<=n;i++)
		{
			if(ans!=-1) ans++;
			now[c[i]]+=d[i];
			if(!check(now)) break;
			if(i==n)
			{
				if(!ok(now,pos))
				{
					ans=-1;
					flag=1;
					break;
				}
				else if(check(now)) i=0; 
			}
		}
		return;
	}
	for(int i=1;i<=w[layer];i++)
	{
		pos[layer]=i;
		dfs(layer+1);
		if(flag) return;
	}
}

int main()
{
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	
	scanf("%d%d",&n,&k);
	for(int i=1;i<=k;i++) scanf("%d",&w[i]);
	for(int i=1;i<=n;i++) scanf("%d%d",&c[i],&d[i]);
	
	if(n<=110)
	{
		dfs(1);
		printf("%lld",ans%mod);
		return 0;
	}
	
	if(k==1)
	{
		int minn,maxn;

		maxn=-1000000;
		minn=1000000;

		for(int i=1;i<=n;i++) 
		{
			dir[i]=dir[i-1]+d[i];
			maxn=max(dir[i],maxn);
			minn=min(dir[i],minn);
			if(!fst[dir[i]+100010]) fst[dir[i]+100010]=i;
		}

		if(dir[n]==0)
		{
			if(maxn-minn<w[1]) puts("-1");
			return 0;
		}

		for(int i=1;i<=-minn;i++) hcq[i]=fst[100010-i];

		for(int i=w[1]-maxn+1;i<=w[1];i++) hcq[i]=fst[w[1]-i+100011];

		if(dir[n]>0)  for(int i=w[1]-maxn;i>=-minn+1;i--) hcq[i]=(hcq[i+dir[n]]+n)%mod;
		else for(int i=-minn+1;i<=w[1]-maxn;i++) hcq[i]=(hcq[i+dir[n]]+n)%mod;
		
		for(int i=1;i<=w[1];i++) ans=(ans+hcq[i])%mod;
		
		
		printf("%lld",ans%mod);
		
		return 0;
	}
	
	puts("-1");
	return 0;
}
