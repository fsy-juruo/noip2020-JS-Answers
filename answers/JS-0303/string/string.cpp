#include<bits/stdc++.h>
using namespace std;

const int N=1500005;
const long long B=23,M=998244353;
int t,n,a[N];
int mx[N],ps[N],ss[N];
long long ans,c[N];
long long h[N],f[N];
char str[N];

void add(int x,long long val)
{
	for(int i=x+1;i<=n+1;i+=i&-i) c[i]+=val;
}

long long sum(int x)
{
	long long res=0;
	for(int i=x+1;i>=1;i-=i&-i) res+=c[i];
	return res;
}

int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&t),f[0]=1;
	for(int i=1;i<=1050000;i++) f[i]=f[i-1]*B%M;
	while(t--)
	{
		scanf("%s",str+1),n=strlen(str+1),ans=0;
		for(int i=0;i<26;i++) a[i]=0;
		for(int i=1;i<=n;i++)
		{
			a[str[i]-'a']^=1;
			if(a[str[i]-'a']) ps[i]=ps[i-1]+1;
			else ps[i]=ps[i-1]-1;
		}
		for(int i=0;i<26;i++) a[i]=0;
		for(int i=n;i>=1;i--)
		{
			a[str[i]-'a']^=1;
			if(a[str[i]-'a']) ss[i]=ss[i+1]+1;
			else ss[i]=ss[i+1]-1;
		}
		if(n<=1000)
		{
			for(int len=1;len<=n;len++)
			{
				mx[len]=1;
				for(int l=len;l<n-len;l+=len)
				{
					int jd=0;
					for(int i=1;i<=len;i++)
					{
						if(str[l+i]!=str[i])
						{
							jd=1;
							break;
						}
					}
					if(!jd) mx[len]++;
					else break;
				}
//				cout<<len<<' '<<mx[len]<<endl;
			}
			for(int i=2;i<n;i++)
			{
				add(ps[i-1],1);
				int sa=ss[i*mx[i]+1],sb=ss[i*mx[i]-i+1];
				int ca=(mx[i]+1)/2,cb=mx[i]/2;
//				cout<<i<<' '<<sa<<' '<<ca<<' '<<sum(sa)*ca<<endl;
				ans+=sum(sa)*ca;
				if(mx[i]>1) ans+=sum(sb)*cb;
			}
			for(int i=2;i<n;i++) add(ps[i-1],-1);
			printf("%lld\n",ans);
			continue;
		}
		for(int i=1;i<=n;i++)
		{
			h[i]=(h[i-1]*B+str[i])%M;
		}
		for(int len=1;len<=n;len++)
		{
			mx[len]=1;
			for(int l=len;l<n-len;l+=len)
			{
				int r=l+len;
				long long hsa=h[len];
				long long hsb=(h[r]-h[l]*f[len]%M+M)%M;
				if(hsa==hsb) mx[len]++;
				else break;
			}
		}
		for(int i=2;i<n;i++)
		{
			add(ps[i-1],1);
			int sa=ss[i*mx[i]+1],sb=ss[i*mx[i]-i+1];
			int ca=(mx[i]+1)/2,cb=mx[i]/2;
//			cout<<i<<' '<<sa<<' '<<ca<<' '<<sum(sa)*ca<<endl;
			ans+=sum(sa)*ca;
			if(mx[i]>1) ans+=sum(sb)*cb;
		}
		for(int i=2;i<n;i++) add(ps[i-1],-1);
		printf("%lld\n",ans);
	}
}
