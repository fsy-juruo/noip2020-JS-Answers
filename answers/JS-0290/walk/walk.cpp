#include<bits/stdc++.h>
using namespace std;

const int N=500005,K=15,INF=2147483647,MOD=1000000007;
int n,k;
int w[K],c[N],d[N];
int maxn[K],minn[K],walk[K];
bool flag=1;

int main()
{
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=k;i++)
	{
		cin>>w[i];
		maxn[i]=1;
		minn[i]=1;
		walk[i]=1;
	}
	for(int i=1;i<=n;i++)
	{
		cin>>c[i]>>d[i];
		walk[c[i]]+=d[i];
		maxn[c[i]]=max(maxn[c[i]],walk[c[i]]);
		minn[c[i]]=min(minn[c[i]],walk[c[i]]);
	}
	for(int i=1;i<=k;i++)
		if(walk[i]!=1) flag=0;
	if(flag)
	{
		bool pd=0;
		for(int i=1;i<=k;i++)
		{
			if(maxn[i]-minn[i]+1>w[i]) pd=1;
		}
		if(!pd)
		{
			cout<<-1;
			return 0;
		}
	}
	if(k==1)
	{
		long long cnt=0;
		for(int i=1;i<=w[1];i++)
		{
			int now=i,step=1;
			while(now<=w[1]&&now>=1)
			{
				if(step==n+1) step=1;
				now+=d[step];
				cnt++;
				cnt=cnt%MOD;
				step++;
			}
		}
		cout<<cnt;
		return 0;
	}
	if(k==2)
	{
		long long cnt=0;
		for(int i=1;i<=w[1];i++)
		for(int j=1;j<=w[2];j++)
		{
			int now[3],step=1;
			now[1]=i;now[2]=j;
			while(now[1]<=w[1]&&now[1]>=1&&now[2]<=w[2]&&now[2]>=1)
			{
				if(step==n+1) step=1;
				now[c[step]]+=d[step];
				cnt++;
				cnt=cnt%MOD;
				step++;
			}
		}
		cout<<cnt;
		return 0;
	}
	if(k==3)
	{
		long long cnt=0;
		for(int i=1;i<=w[1];i++)
		for(int j=1;j<=w[2];j++)
		for(int p=1;p<=w[3];p++)
		{
			int now[10],step=1;
			now[1]=i;now[2]=j;now[3]=p;
			while(now[1]<=w[1]&&now[1]>=1&&now[2]<=w[2]&&now[2]>=1&&now[3]<=w[3]&&now[3]>=1)
			{
				if(step==n+1) step=1;
				now[c[step]]+=d[step];
				cnt++;
				cnt=cnt%MOD;
				step++;
			}
		}
		cout<<cnt;
		return 0;
	}
	if(k==4)
	{
		long long cnt=0;
		for(int i=1;i<=w[1];i++)
		for(int j=1;j<=w[2];j++)
		for(int p=1;p<=w[3];p++)
		for(int q=1;q<=w[4];q++)
		{
			int now[10],step=1;
			now[1]=i;now[2]=j;now[3]=p;now[4]=q;
			while(now[1]<=w[1]&&now[1]>=1&&now[2]<=w[2]&&now[2]>=1&&now[3]<=w[3]&&now[3]>=1&&now[4]<=w[4]&&now[4]>=1)
			{
				if(step==n+1) step=1;
				now[c[step]]+=d[step];
				cnt++;
				cnt=cnt%MOD;
				step++;
			}
		}
		cout<<cnt;
		return 0;
	}
	if(k==5)
	{
		long long cnt=0;
		for(int i=1;i<=w[1];i++)
		for(int j=1;j<=w[2];j++)
		for(int p=1;p<=w[3];p++)
		for(int q=1;q<=w[4];q++)
		for(int r=1;r<=w[5];r++)
		{
			int now[10],step=1;
			now[1]=i;now[2]=j;now[3]=p;now[4]=q;now[5]=r;
			while(now[1]<=w[1]&&now[1]>=1&&now[2]<=w[2]&&now[2]>=1&&now[3]<=w[3]&&now[3]>=1&&now[4]<=w[4]&&now[4]>=1&&now[5]<=w[5]&&now[5]>=1)
			{
				if(step==n+1) step=1;
				now[c[step]]+=d[step];
				cnt++;
				cnt=cnt%MOD;
				step++;
			}
		}
		cout<<cnt;
		return 0;
	}
	cout<<-1;
	return 0;
}
