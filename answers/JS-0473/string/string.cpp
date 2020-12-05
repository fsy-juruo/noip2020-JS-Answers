#include<bits/stdc++.h>
using namespace std;
int t,d[6000000],e[400],f[40000],sum,g[40000],h[400],k[4001];
unsigned long long ans;
string s;

void q()
{
	for(int i=1;i<=30;i++)
	{
	h[i]=0;
	e[i]=0;
	}
	for(int j=0;j<=2000;j++)
	{
		f[j]=0;
		g[j]=0;
	}
	for(int i=s.length()-1;i>=0;i--)
	{
		e[s[i]-'a']++;
		if(e[s[i]-'a']%2==0)
		{
			f[i]=f[i+1]-1;
		}
		else
		{
			f[i]=f[i+1]+1;
			
		}
	}
	h[s[0]-'a']++;
	g[0]=1;
	for(int i=1;i<=s.length()-1;i++)
	{
		h[s[i]-'a']++;
		if(h[s[i]-'a']%2==0)
		{
			g[i]=g[i-1]-1;
		}
		else
		{
			g[i]=g[i-1]+1;
		}
	}
	for(int i=0;i<=s.length()-1;i++)
	{
		for(int j=i+2;j<=s.length()-1;j++)
		{
			if(g[i]<=f[j])
			{
					ans++;
					k[i]++;
			}
		}
	}

}
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++)
	{
		cin>>s;
		ans=0;
			q();
		cout<<ans<<endl;
	}
	return 0;
}
