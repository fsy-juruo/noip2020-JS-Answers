#include <bits/stdc++.h>
using namespace std;
const int Mod=1000000007;
long long n,k,ans,w[11],dir[11],x,y,dep,dp1[200000],tt,depx,depy,dp2[2000][2000];
struct node{
	int fx,jl;
}cz[200000];
long long work1(long long wz)
{
	long long bs=0;
	for (int i=1;i<=n;i++)
	{
		wz=wz+cz[i].jl;
		bs=bs+abs(cz[i].jl);
		if(wz<=0||wz>w[1])
		{
			wz-=cz[i].jl;
			bs-=abs(cz[i].jl);
			if(wz+cz[i].jl<=0)
			{
				bs=bs+wz-1;
			}
			else
			{
				bs=bs+w[1]-wz+1;
			}
			return bs;
		}
	}
	return bs;
}
long long work2(long long dx,long long cy)
{
	long long bs=0;
	for (int i=1;i<=n;i++)
	{
		if(cz[i].fx==1)
		{
			dx+=cz[i].jl;
			bs+=abs(cz[i].jl);
			if(dx<=0||dx>w[1])
			{
				dx-=cz[i].jl;
				bs-=abs(cz[i].jl);
				if(dx+cz[i].jl<=0)
				{
					bs=bs+dx-1;
				}
				else
				{
					bs=bs+w[1]-dx+1;
				}
				return bs;
			}
		}
		else
		{
			cy+=cz[i].jl;
			bs+=abs(cz[i].jl);
			if(cy<=0||cy>w[2])
			{
				cy-=cz[i].jl;
				bs-=abs(cz[i].jl);
				if(cy+cz[i].jl<=0)
				{
					bs=bs+cy-1;
				}
				else
				{
					bs=bs+w[2]-cy+1;
				}
				return bs;
			}
		}
	}
	return bs;
}
int main()
{
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	scanf("%lld%lld",&n,&k);
	for (int i=1;i<=k;i++)
	{
		scanf("%lld",&w[i]);
	}
	for (int i=1;i<=n;i++)
	{
		scanf("%lld%lld",&x,&y);
		dir[x]+=y;
		cz[i].fx=x;
		cz[i].jl=y;
		tt+=abs(y);
	}
	int f=0;
	for (int i=1;i<=k;i++)
	{
		if(dir[i]!=0)
		{
			f=1;
			break;
		}
	}
	if(f==0)
	{
		cout<<-1<<endl;
		return 0;
	}
	if(k==1)
	{
		dep=dir[1];
		if(dep<0)
		{
			for (int i=1;i<=-dep;i++)
			{
				dp1[i]=work1(i);
			}
			for (int i=-dep+1;i<=w[1];i++)
			{
				dp1[i]=dp1[i+dep]+tt;;
			}
		}
		else
		{
			for (int i=w[1]-dep+1;i<=w[1];i++)
			{
				dp1[i]=work1(i);
			}
			for (int i=w[1]-dep;i>=1;i--)
			{
				dp1[i]=dp1[i+dep]+tt;
			}
		}
		for (int i=1;i<=w[1];i++)
		{
			ans=(ans+dp1[i])%Mod;
		}
		cout<<ans<<endl;
		return 0;
	}
	if(k==2)
	{
		depx=dir[1];
		depy=dir[2];
		if(depx<0)
		{
			for (int i=1;i<=-depx;i++)
			{
				for (int j=1;j<=w[2];j++)
				{
					dp2[i][j]=work2(i,j);
				}
			}
		}
		else
		{
			for (int i=w[1]-depx+1;i<=w[1];i++)
			{
				for (int j=1;j<=w[2];j++)
				{
					dp2[i][j]=work2(i,j);
				}
			}
		}
		if(depy<0)
		{
			for (int j=1;j<=-depy;j++)
			{
				for (int i=1;i<=w[1];i++)
				{
					dp2[i][j]=work2(i,j);
				}
			}
		}
		else
		{
			for (int j=w[2]-depy+1;j<=w[2];j++)
			{
				for (int i=1;i<=w[1];i++)
				{
					dp2[i][j]=work2(i,j);
				}
			}
		}
		if(depx<0&&depy<0)
		{
			for(int i=-depx+1;i<=w[1];i++)
			{
				for (int j=-depy+1;j<=w[2];j++)
				{
					dp2[i][j]=dp2[i+depx][j+depy]+tt;
				}
			}
		}
		if(depx>0&&depy<0)
		{
			for(int i=w[1]-depx;i>=1;i++)
			{
				for (int j=-depy+1;j<=w[2];j++)
				{
					dp2[i][j]=dp2[i+depx][j+depy]+tt;
				}
			}	
		}
		if(depx<0&&depy>0)
		{
			for(int i=-depx+1;i<=w[1];i++)
			{
				for (int j=w[2]-depy;j>=1;j++)
				{
					dp2[i][j]=dp2[i+depx][j+depy]+tt;
				}
			}
		}
		if(depx>0&&depy>0)
		{
			for(int i=w[1]-depx;i>=1;i++)
			{
				for (int j=w[2]-depx;j>=1;j++)
				{
					dp2[i][j]=dp2[i+depx][j+depy]+tt;
				}
			}
		}
		for (int i=1;i<=w[1];i++)
		{
			for (int j=1;j<=w[2];j++)
			{
				ans=(ans+dp2[i][j])%Mod;
			}
		}
		return 0;
	}
	return 0;
}
