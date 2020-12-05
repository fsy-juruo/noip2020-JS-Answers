#include <bits/stdc++.h>
using namespace std;
const int maxn=1e5+10,mod=1e9+7;
int w[6],c[maxn],d[maxn],a[6];
int main()
{
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	int n,k,i;
	scanf("%d %d",&n,&k);
	if(k==1)
	{
		int c1,w1,max1=-maxn,min1=maxn,now=0,cur; 
		long long ans=0;
		scanf("%d",&w1);
		for(i=1;i<=n;i++)
		{
			if(now>max1) max1=now;
			if(now<min1) min1=now;
			scanf("%d %d",&c1,&d[i]);
			now+=d[i];
		}
		if(max1-min1<n && now==0)
		{
			printf("-1\n");
			return 0;
		}
		for(i=1;i<=w1;i++)
		{
			cur=i;
			while(cur>=1 && cur<=w1)
			{
				if(cur+max1>w1 || cur+min1<1)
				{
					for(int j=1;j<=n;j++)
					{
						cur+=d[j];
						ans++; ans%=mod;
						if(cur>w1 || cur<1)
						break;
					}
				}
				else
				cur+=now;
			}
		}
		printf("%lld\n",ans%mod);
		return 0;
	}
	for(i=1;i<=k;i++)
	scanf("%d",&w[i]);
	if(n<=100)
	{
		bool flg=false; long long ans=0;
		for(i=1;i<=n;i++)
		{
			scanf("%d %d",&c[i],&d[i]);
			a[c[i]]+=d[i];
		}
		for(i=1;i<=k;i++)
		{
			if(a[i]!=0)
			{
				flg=true;
				break;
			}
		}
		if(flg==false)
		{
			printf("-1\n");
			return 0;
		}
		if(k==2)
		{
			int j,k1;
			for(i=1;i<=w[1];i++)
			for(j=1;j<=w[2];j++)
			{
				a[1]=i; a[2]=j;
				while(a[1]>=1 && a[1]<=w[1] && a[2]>=1 && a[2]<=w[2])
				{
					for(k1=1;k1<=n;k1++)
					{
						a[c[k1]]+=d[k1];
						ans++; ans%=mod;
						if(a[1]<1 || a[1]>w[1] || a[2]<1 || a[2]>w[2])
						break;
					}
				}
			}
			printf("%lld\n",ans%mod);
			return 0;
		}
		if(k==3)
		{
			int j,h,k1;
			for(i=1;i<=w[1];i++)
			for(j=1;j<=w[2];j++)
			for(h=1;h<=w[3];h++)
			{
				a[1]=i; a[2]=j; a[3]=h;
				while(a[1]>=1 && a[1]<=w[1] && a[2]>=1 && a[2]<=w[2] && a[3]>=1 && a[3]<=w[3])
				{
					for(k1=1;k1<=n;k1++)
					{
						a[c[k1]]+=d[k1];
						ans++; ans%=mod;
						if(a[1]<1 || a[1]>w[1] || a[2]<1 || a[2]>w[2] || a[3]<1 || a[3]>w[3])
						break;
					}
				}
			}
			printf("%lld\n",ans%mod);
			return 0;
		}
		if(k==4)
		{
			int j,h,l,k1;
			for(i=1;i<=w[1];i++)
			for(j=1;j<=w[2];j++)
			for(h=1;h<=w[3];h++)
			for(l=1;l<=w[4];l++)
			{
				a[1]=i; a[2]=j; a[3]=h; a[4]=l;
				while(a[1]>=1 && a[1]<=w[1] && a[2]>=1 && a[2]<=w[2] && a[3]>=1 && a[3]<=w[3] && a[4]>=1 && a[4]<=w[4])
				{
					for(k1=1;k1<=n;k1++)
					{
						a[c[k1]]+=d[k1];
						ans++; ans%=mod;
						if(a[1]<1 || a[1]>w[1] || a[2]<1 || a[2]>w[2] || a[3]<1 || a[3]>w[3] || a[4]<1 || a[4]>w[4])
						break;
					}
				}
			}
			printf("%lld\n",ans%mod);
			return 0;
		}
		if(k==5)
		{
			int j,h,l,mm,k1;
			for(i=1;i<=w[1];i++)
			for(j=1;j<=w[2];j++)
			for(h=1;h<=w[3];h++)
			for(l=1;l<=w[4];l++)
			for(mm=1;mm<=w[5];mm++)
			{
				a[1]=i; a[2]=j; a[3]=h; a[4]=l; a[5]=mm;
				while(a[1]>=1 && a[1]<=w[1] && a[2]>=1 && a[2]<=w[2] && a[3]>=1 && a[3]<=w[3] 
					  && a[4]>=1 && a[4]<=w[4] && a[5]>=1 && a[5]<=w[5])
				{
					for(k1=1;k1<=n;k1++)
					{
						a[c[k1]]+=d[k1];
						ans++; ans%=mod;
						if(a[1]<1 || a[1]>w[1] || a[2]<1 || a[2]>w[2] || a[3]<1 || a[3]>w[3] 
						   || a[4]<1 || a[4]>w[4] || a[5]<1 || a[5]>w[5])
						break;
					}
				}
			}
			printf("%lld\n",ans%mod);
			return 0;
		}
	}
	printf("-1\n");
	fclose(stdin);
	fclose(stdout);
	return 0;
}
