#include<bits/stdc++.h>
using namespace std;
const long long mod=1e9+7;
long long n,m,k,w[15],s[15],sm[15],smin[15],a[10007][3],judged,now[15],noww[15];
long long ans;
long long stepp()
{
	long long anss=0;
	long long l=0,r=INT_MAX;
	while(l<r)
	{
		judged=0;
		long long mid=(l+r+1)>>1;
		for(int i=1;i<=k;i++)
		{
			if(mid>=1)
			{
				now[i]+=s[i]*(mid-1);
			    if(now[i]+sm[i]>w[i]||now[i]+smin[i]<=0)
			    judged=1;
			    now[i]-=s[i]*(mid-1);
			}	
		}
		if(judged==1) r=mid-1;
		else l=mid;
	}
	if(l==INT_MAX)
	{
		cout<<-1<<endl;
		return 0;
	}
	anss=(l%mod*n%mod)%mod;
	for(int i=1;i<=k;i++)
	now[i]+=s[i]*l;
	for(int i=1;i<=n;i++)
	{
	    anss++;
		now[a[i][1]]+=a[i][2];
		for(int i=1;i<=k;i++)
		if(now[i]>w[i]||now[i]<=0)
		return anss;	
	}
	return anss;
}
void dfs(int p)
{
	for(int i=1;i<=w[p];i++)
	{
		noww[p]=i;
		if(p==k)
		{	
		    for(int j=1;j<=k;j++)
		    now[j]=noww[j];
			ans+=stepp();
			ans%=mod;
		}
		else dfs(p+1);
	}
}
int main()
{
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=k;i++)
	scanf("%d",&w[i]);
	memset(sm,-127,sizeof(sm));
	memset(smin,127,sizeof(smin));
	for(int i=1;i<=n;i++)
	{
		int ci,di;
		scanf("%d%d",&ci,&di);
		s[ci]+=di;
		sm[ci]=max(sm[ci],s[ci]);
		smin[ci]=min(smin[ci],s[ci]);
		a[i][1]=ci;
		a[i][2]=di;
	}
	dfs(1);
	cout<<ans<<endl;
	return 0;
}
