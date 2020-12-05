#include<bits/stdc++.h>
using namespace std;
struct node
{
	bool ru;
	bool chu;
	long long release;
	long long re[10001];
	long long now;
}a[10001];
long long gcd(long long x,long long y)
{
	if (y==0)
	{
		return x;
	}
	return gcd(y,x%y);
}
int main()
{
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	long long n,m,gcdn;
	scanf("%lld %lld",&n,&m);
	for (long long i=1;i<=n;i++)
	{
		if (m>0)
		{
			a[i].ru=true;
			m--;
		}
		long long index;
		scanf("%lld",&index);
		if (index==0)
		{
			a[i].chu=true;
		}
		a[i].release=index;
		for (long long j=1;j<=index;j++)
		{
			long long index1;
			scanf("%lld",&index1);
			a[i].re[j]=index1;
		}
	}
	bool flag1=false;
	for (long long i=1;i<=n;i++)
	{
		if (a[i].chu!=true)
		{
			if (flag1==false)
			{
				gcdn=a[i].release;
				flag1=true;
			}
			else
			{
				gcdn=gcdn*a[i].release/gcd(gcdn,a[i].release);
			}
		}
	}
	//printf("%d\n",gcdn);
	for (long long i=1;i<=n;i++)
	{
		if (a[i].ru==true)
		{
			a[i].now=gcdn;
		}
	}
	bool flag2=true;
	while (flag2)
	{
		for (long long i=1;i<=n;i++)
		{
			if (a[i].now!=0&&a[i].chu!=true)
			{
				for (long long j=1;j<=a[i].release;j++)
				{
					long long index6=a[i].re[j];
					a[index6].now+=a[i].now/a[i].release;
					//printf("%d\n",a[index6].now);
				}
				a[i].now=0;
			}
		}
		bool flag3=true;
		for (long long i=1;i<=n;i++)
		{
			if (a[i].chu!=true&&a[i].now!=0)
			{
				flag3=false;
				break;
			}
		}
		if (flag3==true)
		{
			flag2=false;
		}
	}
	/*for (int i=1;i<=n;i++)
	{
		printf("%d\n",a[i].now);
	}*/
	for (long long i=1;i<=n;i++)
	{
		if (a[i].chu==true)
		{
			long long index5=gcdn;
			long long index4=gcd(a[i].now,gcdn);
			a[i].now=a[i].now/index4;
			index5=index5/index4;
			printf("%lld",a[i].now);
			printf(" ");
			printf("%lld\n",index5);
		}
	}
	return 0;
}
