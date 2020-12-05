#include<bits/stdc++.h>
using namespace std;
const int MAXK=10+5;
const int MAXN=500000+5;
const int MAXW=100000+5;
const int MOD=1e9+7;
#define ll long long
int n,k;
int dx,dy;
int step[MAXN][2],w[MAXK]; ll res[MAXK],ans;
int s_sum[MAXK],dmin[MAXK],umax[MAXK];
int dmove[MAXK][MAXW],umove[MAXK][MAXW];
int lmove[MAXN],rmove[MAXN];
int pos[MAXK];
bool dame;
void solve1()
{
	memset(lmove,0x3f,sizeof(lmove));
	memset(rmove,0x3f,sizeof(rmove));
	int sum=0,lmin=0,rmax=0;
	for(int i=1;i<=n;i++)
	{
		sum+=step[i][1];
		if(sum<0)
			lmove[-sum]=min(lmove[-sum],i);
		if(sum>0)
			rmove[sum]=min(rmove[sum],i);
		lmin=min(lmin,sum);
		rmax=max(rmax,sum);
	}
	for(int i=1;i<=min(-lmin,w[1]);i++)
		ans=(ans+lmove[i])%MOD;
	for(int i=w[1];i>=max(1,w[1]-rmax+1);i--)
		ans=(ans+rmove[w[1]+1-i])%MOD;
	for(int i=min(-lmin,w[1])+1;i<max(1,w[1]-rmax+1);i++)
	{
		if(sum==0)
		{
			printf("-1\n");
			return;
		}
		if(sum<0)
		{
			int cnt=(i+lmin)/(-sum);
			if((i+lmin)%(-sum)!=0) cnt++;
			int nowpos=i+sum*cnt;
			ans=(ans+lmove[nowpos]+cnt*n)%MOD;
		}
		if(sum>0)
		{
			int cnt=(w[1]-rmax+1-i)/(sum);
			if((w[1]-rmax+1-i)%(sum)!=0) cnt++;
			int nowpos=i+sum*cnt;
			ans=(ans+rmove[w[1]+1-nowpos]+cnt*n)%MOD;
		}
	}
	printf("%lld\n",ans);
}
void calc();
void dfs(int x)
{
	if(x>k)
	{
		calc();
		return;
	}
	for(int i=1;i<=w[x];i++)
	{
		pos[x]=i;
		dfs(x+1);
	}
}
void solve()
{
	memset(dmove,0x3f,sizeof(dmove));
	memset(umove,0x3f,sizeof(umove));
	for(int i=1;i<=k;i++)
		s_sum[k]=dmin[k]=umax[k]=0;
	for(int i=1;i<=n;i++)
	{
		int dir=step[i][0];
		s_sum[dir]+=step[i][1];
		if(s_sum[dir]<0)
			dmove[dir][-s_sum[dir]]=min(dmove[dir][-s_sum[dir]],i);
		if(s_sum[step[i][0]]>0)
			umove[dir][s_sum[dir]]=min(umove[dir][s_sum[dir]],i);
		dmin[dir]=min(dmin[dir],s_sum[dir]);
		umax[dir]=max(umax[dir],s_sum[dir]);
	}
	dfs(1);
	if(dame)
		printf("-1\n");
	else
		printf("%lld\n",ans);
}
void calc()
{
	ll tmin=(1LL<<60);
	for(int dir=1;dir<=k;dir++)
	{
		int np=pos[dir];
		if(np<=dmin[dir])
			res[dir]=dmove[dir][np];
		else if(np>=w[dir]-umax[dir]+1)
			res[dir]=umove[dir][w[dir]+1-np];
		else
		{
			if(s_sum[dir]==0)
				res[dir]=-1;
			if(s_sum[dir]<0)
			{
				int cnt=(np+dmin[dir])/(-s_sum[dir]);
				if((np+dmin[dir])%(-s_sum[dir])!=0) cnt++;
				int nowpos=np+s_sum[dir]*cnt;
				res[dir]=(dmove[dir][nowpos]+cnt*n)%MOD;
			}
			if(s_sum[dir]>0)
			{
				int cnt=(w[dir]-umax[dir]+1-np)/(s_sum[dir]);
				if((w[dir]-umax[dir]+1-np)%(s_sum[dir])!=0) cnt++;
				int nowpos=np+s_sum[dir]*cnt;
				res[dir]=(umove[dir][w[dir]+1-nowpos]+cnt*n)%MOD;
			}
		}
	}
	bool flag=1;
	for(int i=1;i<=k;i++)
		if(res[i]!=-1)
		{
			flag=0;
			tmin=min(tmin,res[i]);
		}
	if(flag)
		dame=1;
	else
		ans=(ans+tmin)%MOD;
}
int main()
{
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=k;i++)
		scanf("%d",w+i);
	for(int i=1;i<=n;i++)
		scanf("%d%d",&step[i][0],&step[i][1]);
	if(k==1)
		solve1();
	else
		solve();
	return 0;
}
