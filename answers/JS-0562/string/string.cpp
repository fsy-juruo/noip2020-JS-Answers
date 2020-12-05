#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll read()
{
	ll x=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();
	return x*f;
}
ll t,s1[2000005],s2[2000005],a1[30],a2[30],ans;
string s;
ll check(ll r)
{
	ll len=r+1,sum=0;
	for(int i=0;i<r;i++)
	{
		if(s[i]==s[r])
		{
			ll l=i+1;
			bool f=0;
			if(len%l!=0) continue;
			for(int j=1;j<=len/l-1;j++)
			{
				for(int k=0;k<=i;k++)
				{
					if(s[k]!=s[k+j*l])
					{
						f=1;
						break;
					}
				}
				if(f==1) break;
			}
			if(f==0)
			{
				for(int j=0;j<i;j++)
				{
					if(s1[j+1]<=s2[r+2])
						sum++;
				}
			}
		}
	}
	return sum;
}
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	t=read();
	while(t--)
	{
		cin>>s;
		ans=0;
		ll n=s.size();
		for(int i=1;i<=n;i++) s1[i]=s2[i]=0;
		for(int i=1;i<=26;i++) a1[i]=a2[i]=0;
		for(int i=1;i<=n;i++)
		{
			ll x=s[i-1]-'a'+1;
			a1[x]++;
			if(a1[x]%2==0) s1[i]=s1[i-1]-1;
			else s1[i]=s1[i-1]+1;
		}
		for(int i=n;i;i--)
		{
			ll x=s[i-1]-'a'+1;
			a2[x]++;
			if(a2[x]%2==0) s2[i]=s2[i+1]-1;
			else s2[i]=s2[i+1]+1;
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=n;j>=i+2;j--)
			{
				if(s1[i]<=s2[j])
				{
					ans++;
				}
			}
		}
		for(int i=n-2;i>0;i--)
		{
			ans+=check(i);
		}
		printf("%lld\n",ans);
	}
	return 0;
}
