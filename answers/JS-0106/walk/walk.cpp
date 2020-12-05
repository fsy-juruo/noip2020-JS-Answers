#include<bits/stdc++.h>
using namespace std;
int a[12][2],s[500010][2];
int main()
{
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	unsigned int i,j,k,l,m,n,o;
	bool c,d;
	scanf("%d%d",&n,&k);
	j=1;
	for(i=1;i<=k;i++)
	{
		scanf("%d",&a[i][0]);
		j*=a[i][0];
	}
	c=d=true;
	for(i=1;i<=n;i++)
	{
		scanf("%d%d",&s[i][0],&s[i][1]);
		a[s[i][0]][1]+=s[i][1];
		if(a[s[i][0]][1]>=a[s[i][0]][0]||a[s[i][0]][1]<=-a[s[i][0]][0])
		c=false;
	}
	for(i=1;i<=k;i++)
	{
		if(a[i][0]!=0)
		{
			d=false;
			break;
		}
	}
	if(c&&d)
	{
		cout<<"-1";
		return 0;
	}
	m=0;
	for(i=0;i<j;i++)
	{
		c=true;
		o=i;
		for(l=1;l<=k;l++)
		{
			a[l][1]=o%a[l][0];
			o/=a[l][0];
		}
		while(c)
		{
			for(l=1;l<=n;l++)
			{
				m=(m+1)%1000000007;
				a[s[l][0]][1]+=s[l][1];
				if(a[s[l][0]][1]>=a[s[l][0]][0]||a[s[l][0]][1]<0)
				{
					c=false;
					break;
				}
			}
		}
	}
	printf("%d",m);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

