#include<iostream>
#include<cstdio>
#include<cstring>

#define N 1048600
using namespace std;
char s[N];
int nxt[N];
int l[30],r[30];
int a[N][27];

int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int T;
	scanf("%d",&T);
	while(T--)
	{
		memset(l,0,sizeof l);
		memset(r,0,sizeof r);
		int n;
		scanf("%s",s+1);
		n=strlen(s+1);
		for(int i=2,j=1;i<=n;++i)
		{
			while(j&&s[i]!=s[j]) j=nxt[j];
			nxt[i]=j;
			j=j+1;
		}
		for(int i=1;i<=n;++i)
		{
			++l[s[i]-'a'];
			int cnt=0;
			a[i][0]=a[i-1][0];
			for(int j=0;j<26;++j)
			{
				a[i][j+1]=a[i-1][j+1];
				if(l[j]&1) ++cnt;
			}
			for(int j=cnt;j<=26;++j)
			{
				++a[i][j];
			}
		}
		for(int i=2;i<=n;++i)
		{
			++r[s[i]-'a'];
		}
		long long ans=0;
		for(int i=2;i<n;++i)
		{
			--r[s[i]-'a'];
			int f=0;
			for(int j=0;j<26;++j)
			{
				if(r[j]&1) ++f;
			}
			if(i%(i-nxt[i])==0)
			{
				int k=i/(i-nxt[i]),l=i-nxt[i];
				for(int j=1;j*j<=k;++j)
				{
					if(k%j==0)
					{
						ans+=a[j*l-1][f];
						if(j!=k/j) ans+=a[(k/j)*l-1][f];
					}
				}
			}
			else ans+=a[i-1][f];
		}
		printf("%lld\n",ans);
	}
	return 0;
}
