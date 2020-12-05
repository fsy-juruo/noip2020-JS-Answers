#include<bits/stdc++.h>
#define int long long 
using namespace std;
const int N = 5e5+5;
const int K = 13;
const int MOD = 1e9+7;
const int INF = 0x3f3f3f3f;
int n,k;
int w[N];
int c[N],d[N];
int a[K],tha[K];
int ans;
int pl[K];
inline void solve()
{
	int ret=0;
	int i=1;
	memcpy(tha,a,sizeof(tha));
	while(1)
	{
		tha[c[i]]+=d[i];
		ret+=abs(d[i]);
		if(tha[c[i]]<1||tha[c[i]]>w[c[i]]) break;
		++i;
		if(i==n+1) i=1;
	}
	ans+=ret;
}
inline void dfs(int step)
{
	if(step==k+1)
	{
		solve();	
		return ;
	}
	for(int i=1;i<=w[step];++i) 
	{
		a[step]=i;
		dfs(step+1);
	}
}
inline bool fail()
{
	for(int i=1;i<=k;++i) if(pl[i]) return 0;
	return 1;
}
int maxx,minx;
map<int,int> pos;
inline void sub1()
{
	int now=0;
	pos[0]=0;
	for(int i=1;i<=n;++i)
	{
		now+=d[i];
		if(!pos.count(now)) pos[now]=i;
		maxx=max(maxx,now);
		minx=min(minx,now);
	}
	for(int i=1;i<=w[1];++i)
	{
		int ret=INF;
		int th=i;
		bool suc=0;
		if(pos.count(w[1]+1-th)) ret=pos[w[1]+1-th],suc=1;
		if(pos.count(-th)) ret=min(ret,pos[-th]),suc=1;
		if(suc) 
		{
			ans+=ret;continue;
		}
		if(pl[1]<0)
		{
			int cir;
			int l=1,r=i;
			while(l<=r)
			{
				int mid=(l+r)>>1;
				if(pl[1]*mid+th>0)
				{
					cir=mid;
					r=mid-1;
				}
				else l=mid+1;
			}
			ret=min(ret,cir*n+pos[-pl[1]*cir-th]);
		}
		else
		{
			int cir;
			int l=1,r=w[1]-i;
			while(l<=r)
			{
				int mid=(l+r)>>1;
				if(pl[1]*mid+th<w[1])
				{
					cir=mid;
					r=mid-1;
				}
				else l=mid+1;
			}
			ret=min(ret,cir*n+pos[w[1]+1-pl[1]*cir-th]);
		}
		ans+=ret;
	}
	printf("%lld",ans);//ll&mod
	fclose(stdin);
	fclose(stdout);
	exit(0);
}
signed main()
{
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	scanf("%lld%lld",&n,&k);
	for(int i=1;i<=k;++i) scanf("%lld",&w[i]);
	for(int i=1;i<=n;++i) scanf("%lld%lld",&c[i],&d[i]),pl[c[i]]+=d[i];
	if(fail())
	{
		puts("-1");
		return 0;
	}
	if(n>100&&k==1) sub1();
	dfs(1);
	printf("%lld",ans);
	fclose(stdin);
	fclose(stdout);
}
