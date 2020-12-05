#include<bits/stdc++.h>
using namespace std;
string s;
int cnt1[26],cnt2[26];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int T;
	cin>>T;
	while(T--)
	{
		cin>>s;
		int n=(int)s.size();
		memset(cnt1,0,sizeof(cnt1));
		long long ans=0LL;
		int cc=1;
		cnt1[s[n-1]-'a']++;
		for(int sz=n-1;sz>=2;sz--)
		{
			for(int i=1;i*i<=sz;i++)
			{
				if(sz%i==0)
				{
					bool flag=true;
					for(int j=0;j<sz;j++)
					{
						if(s[j]!=s[j%i])
						{
							flag=false;
							break;
						}
					}
					if(flag)
					{
						memset(cnt2,0,sizeof(cnt2));
						int ca=0;
						for(int j=0;j<i-1;j++)
						{
							cnt2[s[j]-'a']++;
							if(cnt2[s[j]-'a']%2)
							{
								ca++;
							}
							else
							{
								ca--;
							}
							if(ca<=cc)
							{
								ans++;
							}
						}
					}
					int ii=sz/i;
					if(i==ii)
					{
						continue;
					}
					flag=true;
					for(int j=0;j<sz;j++)
					{
						if(s[j]!=s[j%ii])
						{
							flag=false;
							break;
						}
					}
					if(flag)
					{
						memset(cnt2,0,sizeof(cnt2));
						int ca=0;
						for(int j=0;j<ii-1;j++)
						{
							cnt2[s[j]-'a']++;
							if(cnt2[s[j]-'a']%2)
							{
								ca++;
							}
							else
							{
								ca--;
							}
							if(ca<=cc)
							{
								ans++;
							}
						}
					}
				}
			}
			cnt1[s[sz-1]-'a']++;
			if(cnt1[s[sz-1]-'a']%2)
			{
				cc++;
			}
			else
			{
				cc--;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
/*
check array size
check initilize
check int and long long
check freopen
*/
