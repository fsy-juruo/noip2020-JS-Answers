#include<bits/stdc++.h>
using namespace std;

const int N=500005;
const long long INF=0x3f3f3f3f3f3f3f3fll;
int n,k,w[N],len,jd;
int a[N];
long long mx[15][2],mn[15][2];
long long sx[N],sn[N],s[N][15];
long long ans;

void dfs(int dep)
{
	if(dep==k+1)
	{
//		for(int i=1;i<=k;i++)
//		{
//			cout<<a[i]<<' ';
//		}
//		cout<<endl;
		long long res=INF;
		for(int id=1;id<=k;id++)
		{
			if(mx[id][0]+a[id]>w[id])
			{
				for(int i=1;i<=n;i++)
				{
					if(a[id]+s[i][id]>w[id])
					{
						res=min(res,1ll*i);
						break;
					}
				}
			}
			else if(s[n][id]>0)
			{
				long long x=(w[id]-a[id]-mx[id][0]+s[n][id])/s[n][id];
				long long y=a[id]+x*s[n][id];
				for(int i=1;i<=n;i++)
				{
					if(y+s[i][id]>w[id])
					{
						res=min(res,x*n+i);
						break;
					}
				}
			}
			if(mn[id][0]+a[id]<1)
			{
				for(int i=1;i<=n;i++)
				{
					if(a[id]+s[i][id]<1)
					{
						res=min(res,1ll*i);
						break;
					}
				}
			}
			else if(s[n][id]<0)
			{
				long long x=(a[id]+mn[id][0]+(-s[n][id])-1)/(-s[n][id]);
				long long y=a[id]+x*s[n][id];
				for(int i=1;i<=n;i++)
				{
					if(y+s[i][id]<1)
					{
						res=min(res,x*n+i);
						break;
					}
				}
			}
		}
		if(res==INF) jd=1;
		ans+=res;
//		cout<<res<<endl;
		return;
	}
	for(int i=1;i<=w[dep];i++)
	{
		a[dep]=i,dfs(dep+1);
	}
}

int main()
{
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	scanf("%d%d",&n,&k),sx[0]=-INF,sn[0]=INF;
	for(int i=1;i<=k;i++)
	{
		scanf("%d",&w[i]);
		len=max(len,w[i]);
		mx[i][0]=-INF,mn[i][0]=INF;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=k;j++) s[i][j]=s[i-1][j];
		int x,y;
		scanf("%d%d",&x,&y);
		s[i][x]+=y;
		if(s[i][x]>mx[x][0])
		{
			mx[x][0]=s[i][x];
			mx[x][1]=i;
		}
		if(s[i][x]<mn[i][0])
		{
			mn[x][0]=s[i][x];
			mn[x][1]=i;
		}
		sx[i]=max(sx[i-1],s[i][1]);
		sn[i]=min(sn[i-1],s[i][1]);
	}
	if(n<=100&&(k<=5&&len<=3||k<=3&&len<=10))
	{
		dfs(1);
		if(jd==1) ans=-1;
		printf("%lld\n",ans);
		return 0;
	}
	if(k==1)
	{
		for(int i=1;i<=len;i++)
		{
			long long rr=INF;
			if(sx[n]+i>len)
			{
				int L=1,R=n;
				long long res=INF;
				while(L<=R)
				{
					int mid=(L+R)>>1;
					if(sx[mid]+i>len) res=mid,R=mid-1;
					else L=mid+1;
				}
				rr=min(rr,res);
			}
			else if(s[n][1]>0)
			{
				long long x=(len-i-mx[1][0]+s[n][1])/s[n][1];
				long long y=i+x*s[n][1];
				int L=1,R=n;
				long long res=0;
				while(L<=R)
				{
					int mid=(L+R)>>1;
					if(sx[mid]+y>len) res=mid,R=mid-1;
					else L=mid+1;
				}
				rr=min(rr,x*n+res);
			}
			if(sn[n]+i<1)
			{
				int L=1,R=n;
				long long res=INF;
				while(L<=R)
				{
					int mid=(L+R)>>1;
					if(sn[mid]+i<1) res=mid,R=mid-1;
					else L=mid+1;
				}
				rr=min(rr,res);
			}
			else if(s[n][1]<0)
			{
				long long x=(i+mn[1][0]+(-s[n][1])-1)/(-s[n][1]);
				long long y=i+x*s[n][1];
				int L=1,R=n;
				long long res=0;
				while(L<=R)
				{
					int mid=(L+R)>>1;
					if(sn[mid]+y<1) res=mid,R=mid-1;
					else L=mid+1;
				}
				rr=min(rr,x*n+res);
			}
			if(rr==INF) jd=1;
			ans+=rr;
//			cout<<i<<' '<<rr<<endl;
		}
		if(jd) ans=-1;
		printf("%lld\n",ans);
		return 0;
	}
	printf("-1\n");
}
