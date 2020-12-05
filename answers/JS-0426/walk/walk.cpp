#include<bits/stdc++.h>
using namespace std;
const long long md=1e9+7;
inline long long fread()
{
	long long x=0,y=1;
	char c=getchar();
	while(c<'0' || c>'9')
	{
		if(c=='-')
		{
			y=-1;
		}
		c=getchar();
	}
	x=c-'0';
	c=getchar();
	while(c>='0' && c<='9')
	{
		x=x*10+c-'0';
		c=getchar();
	}
	return x*y;
}
int n,k,mx[505050],mn[505050],cg[505050],c[505050],d[505050];
long long w[505050];
int main()
{
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=k;i++)
	{
		w[i]=fread();
	}
	for(int i=0;i<n;i++)
	{
		c[i]=fread();
		d[i]=fread();
		cg[c[i]]+=d[i];
		mx[c[i]]=max(mx[c[i]],cg[c[i]]);
		mn[c[i]]=min(mn[c[i]],cg[c[i]]);
	}
	bool ok=false;
	for(int i=1;i<=k;i++)
	{
		if(cg[i]!=0)
		{
			ok=true;
			break;
		}
	}
	if(!ok)
	{
		cout<<-1<<endl;
		return 0;
	}
	if(n<=100)
	{
		long long ans=0;
		if(k==1)
		{
			for(int i=1;i<=w[1];i++)
			{
				int a=i;
				while(a+mx[1]<=w[1] && a+mn[1]>=1)
				{
					a+=cg[1];
					ans+=n;
				}
				for(int t=0;t<n;t++)
				{
					ans++;
					if(a+d[t]<=w[1] && a+d[t]>=1)
					{
						a+=d[t];
					}
					else
					{
						break;
					}
				}
			}
		}
		else if(k==2)
		{
			for(int i=1;i<=w[1];i++)
			{
				for(int j=1;j<=w[2];j++)
				{
					int a[3];
					a[1]=i;
					a[2]=j;
					while(a[1]+mx[1]<=w[1] && a[1]+mn[1]>=1 && a[2]+mx[2]<=w[2] && a[2]+mn[2]>=1)
					{
						a[1]+=cg[1];
						a[2]+=cg[2];
						ans+=n;
					}
					for(int t=0;t<n;t++)
					{
						ans++;
						if(a[c[t]]+d[t]<=w[c[t]] && a[c[t]]+d[t]>=1)
						{
							a[c[t]]+=d[t];
						}
						else
						{
							break;
						}
					}
				}
			}
		}
		else
		{
			for(int i=1;i<=w[1];i++)
			{
				for(int j=1;j<=w[2];j++)
				{
					for(int k=1;k<=w[3];k++)
					{
						int a[4];
						a[1]=i;
						a[2]=j;
						a[3]=k;
						while(a[1]+mx[1]<=w[1] && a[1]+mn[1]>=1 && a[2]+mx[2]<=w[2] && a[2]+mn[2]>=1 && a[3]+mx[3]<=w[3] && a[3]+mn[3]>=1)
						{
							a[1]+=cg[1];
							a[2]+=cg[2];
							a[3]+=cg[3];
							ans+=n;
						}
						for(int t=0;t<n;t++)
						{
							ans++;
							if(a[c[t]]+d[t]<=w[c[t]] && a[c[t]]+d[t]>=1)
							{
								a[c[t]]+=d[t];
							}
							else
							{
								break;
							}
						}
					}
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
/*
3 2
3 3
1 1
2 -1
1 1
*/
