#include<bits/stdc++.h>
using namespace std;
const int maxn=500005,mod=1e9+7;
int a[maxn][2]={},lm[maxn]={},rm[maxn]={},an[maxn]={},ans=0,res2=0;
int n,k,w[11]={};
void solve1()
{
	int l=0,r=0,now=0;
	{
		for(int i=1;i<=n;i++)
		{
			now+=a[i][1];
			if(now<=l&&res2>=l)
			{
				l=now;
				lm[-l]=i;
			}
			if(now>=r&&res2<=r)
			{
				r=now;
				rm[r]=i;
			}
			res2=0;
		}
		if(now==0&&(r-l<=w[1]))
		{
			cout<<-1;
			return;
		}
	}
	l=-l;
	if(now<0)
	{
		for(int i=1;i<=w[1];i++)
		{
			if((i-1)<l)
			{
				an[i]=lm[i-1];
			}
			else
			{
				if((w[1]-i)<r)
				{
					an[i]=rm[w[1]-i];
				}
				else
					{
						an[i]=n+an[i+now];
					}
			}
			ans+=an[i];
			ans%=mod;
		}
	}
	else
	{
		for(int i=w[1];i>0;i--)
		{
			if((i-1)<l)
			{
				an[i]=lm[i-1];
			}
			else
			{
				if((w[1]-i)<r)
				{
					an[i]=rm[w[1]-i];
				}
				else
					an[i]=n+an[i+now];
			}
			ans+=an[i];
			ans%=mod;
		}
	}
	cout<<ans;
	return;
}
int main()
{
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=k;i++)
	{
		cin>>w[i];
	}
	for(int i=1;i<=n;i++)
	{
		cin>>a[i][0]>>a[i][1];
	}
	if(k==1)
	{
		solve1();
	}
	else
	{
		cout<<-1<<endl;
	}
	return 0;
}
