#include<bits/stdc++.h>
using namespace std;
inline long long fread()
{
	long long x=0,y=1;
	char c=getchar();
	while(c<'0' || c>'9')
	{
		if(c=='-')
		{
			y=-1;
		}
		c=getchar();
	}
	x=c-'0';
	c=getchar();
	while(c>='0' && c<='9')
	{
		x=x*10+c-'0';
		c=getchar();
	}
	return x*y;
}
string s;
int ct[33],fr[1050101];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int t;
	cin>>t;
	while(t--)
	{
		memset(ct,0,sizeof(ct));
		cin>>s;
		int n=s.size(),l=0;
		for(int i=0;i<n;i++)
		{
			ct[s[i]-'a']++;
			if(ct[s[i]-'a']%2==0)
			{
				l--;
			}
			else
			{
				l++;
			}
			fr[i]=l;
		}
		memset(ct,0,sizeof(ct));
		if(n<=1000)
		{
			long long ans=0;
			int all=n;
			for(int i=n-1;i>=0;i--)
			{
				all--;
				ct[s[i]-'a']++;
				int nw=0;
				for(int j=0;j<26;j++)
				{
					if(ct[j]%2==1)
					{
						nw++;
					}
				}
				for(int j=1;j<=all;j++)
				{
					if(all%j==0)
					{
						bool ok=true;
						for(int k=0;k+j<all;k++)
						{
							if(s[k]!=s[j+k])
							{
								ok=false;
								break;
							}
						}
						if(!ok)
						{
							continue;
						}
						for(int k=0;k<j-1;k++)
						{
							if(fr[k]<=nw)
							{
								ans++;
							}
						}
					}
				}
			}
			cout<<ans<<endl;
		}
	}
	return 0;
}
