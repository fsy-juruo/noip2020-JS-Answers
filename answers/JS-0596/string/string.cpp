#include<bits/stdc++.h>
#define MAXN (1<<20)+50
using namespace std;
string s;
int ji[MAXN];
int app[28];
int f[28][MAXN];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int t;
	cin>>t;
	while(t--)
	{
		long long ans=0;
		cin>>s;
		int n=s.size();
		memset(app,0,sizeof(app));
		memset(ji,0,sizeof(ji));
		for(int i=n-1;i>=0;i--)
		{
			app[s[i]-'a']++;
			if(app[s[i]-'a']%2)ji[i]=ji[i+1]+1;
			else ji[i]=ji[i+1]-1;
		}
		memset(app,0,sizeof(app));
		int cnt=0;
		for(int i=0;i<n-1;i++)
		{
			app[s[i]-'a']++;
			if(app[s[i]-'a']%2)cnt++;
			else cnt--;
			for(int j=0;j<=26;j++)
			{
				f[j][i]=f[j][i-1];
				if(cnt<=j)f[j][i]++;
			}
		}
		for(int i=2;i<n;i++)//len i
		{
			string now=s.substr(0,i);
			for(int j=i;j<n;j+=i)
			{
				if(s.substr(j-i,i)!=now)break;
				ans+=f[ji[j]][i-2];
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}

