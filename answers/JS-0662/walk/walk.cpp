#include<bits/stdc++.h>
using namespace std;
const long long inf=1e18;
const int maxn=1e6,mod=1e9+7;
int n,k,w[11],c[555555],d[555555],cnt,p[555555],delta,l,r,rd[2222222],cur,stp,cn,lst[11],inv[1111111],curp,ans;
long long nw;
struct item
{
	int id;
	long long x;
	bool operator < (const item &u) const
	{
		if (x!=u.x) return x<u.x;
		return id<u.id;
	}
}all[11111111];
int main()
{
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	scanf("%d%d",&n,&k);
	for (int i=1;i<=k;i++) scanf("%d",&w[i]);
	for (int i=1;i<=n;i++) scanf("%d%d",&c[i],&d[i]);
	for (int i=1;i<=k;i++)
	{
		delta=0;
		for (int j=1;j<=n;j++)
		{
			if (c[j]==i) p[j]=d[j];
			else p[j]=0;
			delta+=p[j];
		}
		l=0;r=0;cur=0;
		for (int j=0;j<=2*maxn;j++) rd[j]=1e9;
		rd[maxn]=0;
		for (int j=1;j<=n;j++)
		{
			cur+=p[j];
			l=max(l,-cur);
			r=max(r,cur);
			rd[maxn+cur]=min(rd[maxn+cur],j);
		}
		if (delta==0)
		{
			for (int j=1;j<=w[i];j++) 
			{
				cur=min(rd[maxn-j],rd[maxn+w[i]+1-j]);
				if (cur>n) all[++cnt]=(item){i,inf};
				else all[++cnt]=(item){i,(long long)cur};
			}
		}
		else if (delta<0)
		{
			for (int j=1;j<=w[i];j++) 
			{
				cur=min(rd[maxn-j],rd[maxn+w[i]+1-j]);
				if (cur<=n) all[++cnt]=(item){i,(long long)cur};
				else
				{
					stp=(j-l-delta-1)/(-delta);
					cn=j+stp*delta;
					all[++cnt]=(item){i,1ll*stp*n+rd[maxn-cn]};
				}
			}
		}
		else
		{
			for (int j=1;j<=w[i];j++) 
			{
				cur=min(rd[maxn-j],rd[maxn+w[i]+1-j]);
				if (cur<=n) all[++cnt]=(item){i,(long long)cur};
				else
				{
					stp=(w[i]+1-r-j+delta-1)/delta;
					cn=j+stp*delta;
					all[++cnt]=(item){i,1ll*stp*n+rd[maxn+w[i]+1-cn]};
				}
			}
		}
	}
	inv[1]=1;
	for (int i=2;i<=maxn;i++) inv[i]=-1ll*inv[mod%i]*(mod/i)%mod;
	sort(all+1,all+cnt+1);curp=1;
	for (int i=1;i<=k;i++)
	{
		lst[i]=w[i];
		curp=1ll*curp*w[i]%mod;
	}
	for (int i=1;i<=cnt;i++)
	{
		if (!curp) break;
		if (all[i].x>1e17) 
		{
			printf("-1\n");
			return 0;
		}
		curp=1ll*curp*inv[lst[all[i].id]]%mod;
		ans=(1ll*curp*(all[i].x%mod)+ans)%mod;
		lst[all[i].id]--;
		curp=1ll*curp*lst[all[i].id]%mod;
	}
	printf("%d\n",(ans+mod)%mod);
	return 0;
}
