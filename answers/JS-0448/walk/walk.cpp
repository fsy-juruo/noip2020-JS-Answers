#include<bits/stdc++.h>
using namespace std;

const int mod=1e9+7;

long long n,k,w[10],c[105],d[105],p[105][10],lmax[10],rmax[10],x[15],y[15],z[15];

int main()
{
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	scanf("%lld%lld",&n,&k);
	for(int i=1;i<=k;i++)scanf("%lld",&w[i]);
	
	memset(p,0,sizeof(p));
	for(int i=1;i<=n;i++)
	{
		scanf("%lld%lld",&c[i],&d[i]);
		p[i][c[i]]=p[i-1][c[i]]+d[i];
	}
	
	memset(lmax,0,sizeof(lmax));
	memset(rmax,0,sizeof(rmax));
	for(int i=1;i<=k;i++)		
		for(int j=1;j<=n;j++)
		{
			if(p[j][i]>=0)rmax[i]=max(p[j][i],rmax[i]);
			else lmax[i]=min(p[j][i],lmax[i]);	
		}
		
	memset(x,0,sizeof(x));
	memset(y,0,sizeof(y));
	memset(z,0,sizeof(z));		
	for(int i=1;i<=w[1];i++)
	{
		if(i<1-lmax[1]||i>w[1]-rmax[1])
		{
			for(int j=1;j<=n;j++)
			{
				++x[i];
				if(i+p[j][1]<1||i+p[j][1]>w[1])break;
			}
		}
		else
		{
			long long ii;
			if(p[n][1]<0)
			{
				x[i]=(1-lmax[1]-i)/p[n][1]+1;
				ii=i+x[i]*p[n][1];
				x[i]*=n;	
			}
			else if(p[n][1]>0)
			{
				x[i]=(w[1]-rmax[1]-i)/p[n][1]+1;
				ii=i+x[i]*p[n][1];
				x[i]*=n;
			}
			else
			{
				x[i]=-1;
				continue;
			}
			for(int j=1;j<=n;j++)
			{
				++x[i];
				if(ii+p[j][1]<1||ii+p[j][1]>w[1])break;
			}				
		}
	}
	if(k==1)
	{
		long long ans=0;
		for(int i=1;i<=w[1];i++)
		{
			if(x[i]==-1)
			{
				puts("-1");
				return 0;
			}
			ans=(ans+x[i])%mod;
		}
		printf("%lld\n",ans);
		return 0;
	}
	if(k>=2)
	{
		for(int i=1;i<=w[2];i++)
		{
			if(i<1-lmax[2]||i>w[2]-rmax[2])
			{
				for(int j=1;j<=n;j++)
				{
					++y[i];
					if(i+p[j][2]<1||i+p[j][2]>w[2])break;
				}
			}
			else
			{
				long long ii;
				if(p[n][2]<0)
				{
					y[i]=(1-lmax[2]-i)/p[n][2]+1;
					ii=i+y[i]*p[n][2];
					y[i]*=n;	
				}
				else if(p[n][2]>0)
				{
					y[i]=(w[1]-rmax[2]-i)/p[n][2]+1;
					ii=i+y[i]*p[n][2];
					y[i]*=n;
				}
				else
				{
					y[i]=-1;
					continue;
				}
				for(int j=1;j<=n;j++)
				{
					++y[i];
					if(ii+p[j][2]<1||ii+p[j][2]>w[2])break;
				}				
			}
		}
		if(k==2)
		{
			long long ans=0;
			for(int i=1;i<=w[1];i++)
			{
				for(int j=1;j<=w[2];j++)
				{
					if(x[i]==-1&&y[j]==-1)
					{
						puts("-1");
						return 0;
					}
					else
					{
						if(x[i]==-1)ans=(ans+y[j])%mod;
						else if(y[j]==-1)ans=(ans+x[j])%mod;
						else ans=(ans+min(x[j],y[j]))%mod;
					}
				}
			}
			printf("%lld\n",ans);
			return 0;
		}
	}
	if(k>=3)
	{
		for(int i=1;i<=w[3];i++)
		{
			if(i<1-lmax[3]||i>w[3]-rmax[3])
			{
				for(int j=1;j<=n;j++)
				{
					++z[i];
					if(i+p[j][3]<1||i+p[j][3]>w[3])break;
				}
			}
			else
			{
				long long ii;
				if(p[n][3]<0)
				{
					z[i]=(1-lmax[3]-i)/p[n][3]+1;
					ii=i+z[i]*p[n][3];
					z[i]*=n;	
				}
				else if(p[n][3]>0)
				{
					z[i]=(w[3]-rmax[1]-i)/p[n][1]+1;
					ii=i+z[i]*p[n][1];
					z[i]*=n;
				}
				else
				{
					z[i]=-1;
					continue;
				}
				for(int j=1;j<=n;j++)
				{
					++z[i];
					if(ii+p[j][3]<1||ii+p[j][3]>w[3])break;
				}				
			}
		}
		if(k==3)
		{
			long long ans=0;
			for(int i=1;i<=w[1];i++)
			{
				for(int j=1;j<=w[2];j++)
				{
					for(int k=1;k<=w[3];k++)
					{
						if(x[i]==-1&&y[j]==-1&&z[k]==-1)
						{
							puts("-1");
							return 0;
						}
						if(x[i]==-1&&y[j]!=-1&&z[k]!=-1)ans=(ans+min(y[j],z[k]))%mod;
						else if(x[i]!=-1&&y[j]==-1&&z[k]!=-1)ans=(ans+min(x[i],z[k]))%mod;
						else if(x[i]!=-1&&y[j]!=-1&&z[k]==-1)ans=(ans+min(x[i],y[j]))%mod;
						else if(x[i]!=-1&&y[j]==-1&&z[k]==-1)ans=(ans+x[i])%mod;
						else if(x[i]==-1&&y[j]!=-1&&z[k]==-1)ans=(ans+y[j])%mod;
						else if(x[i]==-1&&y[j]==-1&&z[k]!=-1)ans=(ans+z[k])%mod;
						else ans=(ans+min(min(x[i],y[j]),z[k]))%mod;
					}
				}
			}
			printf("%lld\n",ans);
			return 0;
		}
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
