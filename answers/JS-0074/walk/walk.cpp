#include<bits/stdc++.h>
using namespace std;

#define int long long
#define _P 1000000007
#define _N 500001

int n,k;
int w[11];
int c[_N];
int d[_N];
int ans;

bool hf(int x,int p)
{
	if(x>=1&&x<=w[p])
	{
		return 1;
	}
	return 0;
}

int solve1(int x1)
{
	int res=0;
	int i=0;
	while(hf(x1,1))
	{
		res++;
		i++;
		if(i==n+1)
		{
			i=1;
		}
		if(c[i]==1)
		{
			x1+=d[i];
		}
	}
	return res%_P;
}


int solve2(int x1,int x2)
{
	int res=0;
	int i=0;
	while(hf(x1,1)&&hf(x2,2))
	{
		res++;
		i++;
		if(i==n+1)
		{
			i=1;
		}
		if(c[i]==1)
		{
			x1+=d[i];
		}
		if(c[i]==2)
		{
			x2+=d[i];
		}
	}
	return res%_P;
}

int solve3(int x1,int x2,int x3)
{
	int res=0;
	int i=0;
	while(hf(x1,1)&&hf(x2,2)&&hf(x3,3))
	{
		res++;
		i++;
		if(i==n+1)
		{
			i=1;
		}
		if(c[i]==1)
		{
			x1+=d[i];
		}
		if(c[i]==2)
		{
			x2+=d[i];
		}
		if(c[i]==3)
		{
			x3+=d[i];
		}
	}
	return res%_P;
}

int solve4(int x1,int x2,int x3,int x4)
{
	int res=0;
	int i=0;
	while(hf(x1,1)&&hf(x2,2)&&hf(x3,3)&&hf(x4,4))
	{
		res++;
		i++;
		if(i==n+1)
		{
			i=1;
		}
		if(c[i]==1)
		{
			x1+=d[i];
		}
		if(c[i]==2)
		{
			x2+=d[i];
		}
		if(c[i]==3)
		{
			x3+=d[i];
		}
		if(c[i]==4)
		{
			x4+=d[i];
		}
	}
	return res%_P;
}

int solve5(int x1,int x2,int x3,int x4,int x5)
{
	int res=0;
	int i=0;
	while(hf(x1,1)&&hf(x2,2)&&hf(x3,3)&&hf(x4,4)&&hf(x5,5))
	{
		res++;
		i++;
		if(i==n+1)
		{
			i=1;
		}
		if(c[i]==1)
		{
			x1+=d[i];
		}
		if(c[i]==2)
		{
			x2+=d[i];
		}
		if(c[i]==3)
		{
			x3+=d[i];
		}
		if(c[i]==4)
		{
			x4+=d[i];
		}
		if(c[i]==5)
		{
			x5+=d[i];
		}
	}
	return res%_P;
}

signed main()
{
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	scanf("%lld%lld",&n,&k);
	for(int i=1;i<=k;i++)
	{
		scanf("%lld",&w[i]);
	}
	for(int i=1;i<=n;i++)
	{
		scanf("%lld%lld",&c[i],&d[i]);
	}
	if(k>5||n>1000 )
	{
		puts("-1");
		return 0;
	}
	else if(k==1)
	{
		for(int x1=1;x1<=w[1];x1++)
		{
			ans+=solve1(x1);
			ans%=_P;
		}
	}
	else if(k==2)
	{
		for(int x1=1;x1<=w[1];x1++)
		{
			for(int x2=1;x2<=w[2];x2++)
			{
				ans+=solve2(x1,x2);
				ans%=_P;
			}
		}
	}
	else if(k==3)
	{
		for(int x1=1;x1<=w[1];x1++)
		{
			for(int x2=1;x2<=w[2];x2++)
			{
				for(int x3=1;x3<=w[3];x3++)
				{
					ans+=solve3(x1,x2,x3);
					ans%=_P;
				}
			}
		}
	}
	else if(k==4)
	{
		for(int x1=1;x1<=w[1];x1++)
		{
			for(int x2=1;x2<=w[2];x2++)
			{
				for(int x3=1;x3<=w[3];x3++)
				{
					for(int x4=1;x4<=w[4];x4++)
					{
						ans+=solve4(x1,x2,x3,x4);
						ans%=_P;
					}
				}
			}
		}
	}
	else if(k==5)
	{
		for(int x1=1;x1<=w[1];x1++)
		{
			for(int x2=1;x2<=w[2];x2++)
			{
				for(int x3=1;x3<=w[3];x3++)
				{
					for(int x4=1;x4<=w[4];x4++)
					{
						for(int x5=1;x5<=w[5];x5++)
						{
							ans+=solve5(x1,x2,x3,x4,x5);
							ans%=_P;				
						}
					}
				}
			}
		}
	}
	printf("%d\n",ans);
	
		
	return 0;
}
