#include<bits/stdc++.h>
using namespace std;
const int N=1004005;
int n,s[N][30],f[30];
long long h[N],p=131,mod=998244853,ans,t;
char c[N],cc;
int getsum1(int x)
{
	int sum=0;
	for(int i=0;i<26;i++)
	{
		int k=s[n][i]-s[x-1][i];
		if(k%2==1)sum++;
	}
	return sum;
}
int getsum2(int x)
{
	int sum=0;
	for(int i=0;i<26;i++)
	{
		int k=s[x][i];
		if(k%2==1)sum++;
	}
	return sum;
}
long long ksm(long long x,int pp)
{
	long long ans=1;
	while(pp)
	{
		if(pp%2)ans=(ans*x)%mod;
		x=(x*x)%mod;
		pp>>=1;
	}
	return ans;
}
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>t;
	gets(c);
	while(t--)
	{	
	memset(s,0,sizeof(s));
	memset(f,0,sizeof(f));
	memset(h,0,sizeof(h));
	ans=0;
	gets(c);
	n=strlen(c);
	//for(int i=0;i<n;i++)cout<<c[i];
	for(int i=n;i>=1;i--)
	c[i]=c[i-1];
	for(int i=1;i<=n;i++)
	{
		s[i][c[i]-'a']=1;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<26;j++)
		s[i][j]=s[i][j]+s[i-1][j];
	}
	for(int i=1;i<=n;i++)
	{
		h[i]=(h[i-1]*p+c[i]-'a')%mod;
	}
	for(int i=2;i<n;i++)
	{
		int pp=getsum2(i-1);
		for(int j=pp;j<26;j++)
		f[j]++;
		int hh=h[i];
		for(int j=i+1;j<=n;j+=i)
		{
			if((h[j-1]-h[j-1-i]*ksm(p,i)%mod+mod)%mod!=hh)break;
			int k=getsum1(j);
			ans+=f[k];
		}
	}
	cout<<ans<<endl;
	}
	return 0;
}
