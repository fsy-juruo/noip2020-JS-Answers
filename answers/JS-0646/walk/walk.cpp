#include<bits/stdc++.h>
using namespace std;
int n,kk,w[100010]={0},a[100010]={0},b[100010]={0},k[11]={0},ans=0,modd=1e9+7,ppp[11]={0};
int main()
{
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	cin>>n>>kk;
	for(int i=1;i<=kk;i++)
	{
		scanf("%d",&w[i]);
	}
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d",&a[i],&b[i]);
		ppp[a[i]]+=b[i];
	}
	if(kk==1)
	{
		for(int i=1;i<=w[1];i++)
		{
			k[1]=i;
			for(int j=1;j<=n;j++)
			{
				if(k[1]+b[j]>=1&&k[1]+b[j]<=w[1])
				{
					k[1]+=b[j];
					ans++;
					ans=ans%modd;
				}
				else
				{
					break;
				}
				if(j==n)
				j=1;
			}
		}
	}
	else if(kk==2)
	{
	    for(int i=1;i<=w[1];i++)
		{
			for(int l=1;l<=w[2];l++)
			{
			k[1]=i;
			k[2]=l;
			for(int j=1;j<=n;j++)
			{
				if(k[a[j]]+b[j]>=1&&k[a[j]]+b[j]<=w[a[j]])
				{
					k[a[j]]+=b[j];
					ans++;
					ans=ans%modd;
				}
				else
				{
					ans++;
					break;
				}
				if(j==n)
				j=0;
			}	
			}
		}
	}
	else if(kk==3)
	{
	    for(int i=1;i<=w[1];i++)
		{
			for(int l=1;l<=w[2];l++)
			for(int l1=1;l1<=w[3];l1++)
			{
			k[1]=i;
			k[2]=l;
			k[3]=l1;
			for(int j=1;j<=n;j++)
			{
				if(k[a[j]]+b[j]>=1&&k[a[j]]+b[j]<=w[a[j]])
				{
					k[a[j]]+=b[j];
					ans++;
					ans=ans%modd;
				}
				else
				{
					ans++;
					break;
				}
				if(j==n)
				j=0;
			}	
			}
		}
	}
	else if(kk==4)
	{
	    for(int i=1;i<=w[1];i++)
		{
			for(int l=1;l<=w[2];l++)
			for(int l1=1;l1<=w[3];l1++)
			for(int l2=1;l2<=w[4];l2++)
			{
			k[1]=i;
			k[2]=l;
			k[3]=l1;
			k[4]=l2;
			for(int j=1;j<=n;j++)
			{
				if(k[a[j]]+b[j]>=1&&k[a[j]]+b[j]<=w[a[j]])
				{
					k[a[j]]+=b[j];
					ans++;
					ans=ans%modd;
				}
				else
				{
					ans++;
					break;
				}
				if(j==n)
				j=0;
			}	
			}
		}
	}
	else if(kk==5)
	{
	    for(int i=1;i<=w[1];i++)
		{
			for(int l=1;l<=w[2];l++)
			for(int l1=1;l1<=w[3];l1++)
			for(int l2=1;l2<=w[4];l2++)
			for(int l3=1;l3<=w[5];l3++)
			{
			k[1]=i;
			k[2]=l;
			k[3]=l1;
			k[4]=l2;
			k[5]=l3;
			for(int j=1;j<=n;j++)
			{
				if(k[a[j]]+b[j]>=1&&k[a[j]]+b[j]<=w[a[j]])
				{
					k[a[j]]+=b[j];
					ans++;
					ans=ans%modd;
				}
				else
				{
					ans++;
					break;
				}
				if(j==n)
				j=0;
			}	
			}
		}
	}
	cout<<ans;
	return 0;
}
