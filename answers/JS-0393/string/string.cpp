#include<bits/stdc++.h>
using namespace std;
const int N=1100000;
int n,z[N],pre[N][30],suf[N],c[30],h;
char s[N];
long long ans,sum[N];
void sol()
{
	scanf("%s",s+1);
	n=strlen(s+1);
	z[1]=n;
	for(int i=0;i<=n+5;i++)
	{
		suf[i]=sum[i]=0;
		for(int j=0;j<=26;j++)
			pre[i][j]=0;
	}
	for(int j=0;j<26;j++)
		c[j]=0;
	h=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<=26;j++)
			pre[i][j]=pre[i-1][j];
		int u=s[i]-'a';
		if(c[u]&1)
			h--;
		else
			h++;
		c[u]^=1;
		pre[i][h]++;		
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=26;j++)
			pre[i][j]+=pre[i][j-1];
	for(int j=0;j<26;j++)
		c[j]=0;
	h=0;
	for(int i=n;i>=1;i--)
	{
		int u=s[i]-'a';
		if(c[u]&1)
			h--;
		else
			h++;
		c[u]^=1;
		suf[i]=h;
	}
	int l=1,r=1;
	for(int i=2;i<=n;i++)
	{
		if(r<i)
		{
			l=r=i;
			while(r<=n&&s[r]==s[r-l+1])
				r++;
			z[i]=r-l;
			r--;
		}
		else
		{
			int k=i-l+1;
			if(z[k]<r-i+1)
				z[i]=z[k];
			else
			{
				l=i;
				while(r<=n&&s[r]==s[r-l+1])
					r++;
				z[i]=r-l;
				r--;
			}
		}
	}
	for(int i=2;i<=n;i++)
	{
		int len=i-1,x=z[i],y=i+z[i]-1;
		int d=y-y/len*len;
		x-=d,y-=d;
		while(1)
		{
			if(x<i-1)
				break;
			sum[y]+=pre[len-1][suf[y+1]];
			x-=len;
			y-=len;
		}
	}
	for(int i=2;i<=n;i++)
		sum[i]+=pre[i-1][suf[i+1]];
	ans=0;
	for(int i=n;i>1;i--)
		ans+=sum[i-1];
	printf("%lld\n",ans);
}
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int T;
	scanf("%d",&T);
	while(T--)
		sol();
	return 0;
}

