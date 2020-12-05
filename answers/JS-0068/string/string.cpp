#include<bits/stdc++.h>
using namespace std;
const long long mod=998244853;
const long long mul=37;
char s[150000];
int num[26];
int t[150000],t2[150000];
set<int> S[150000];
long long hsh[150000];
long long bse[150000];
long long f[150000][26],dp[150000][26];
long long hs(int l,int r)
{
	return ((hsh[r]-hsh[l-1]*bse[r-l+2]%mod)%mod+mod)%mod;
}
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int T;scanf("%d",&T);
	bse[1]=1;
	for(int i=2;i<150000;i++)
		bse[i]=bse[i-1]*mul%mod;
	while(T--)
	{
		scanf("%s",s+1);s[0]='#';
		int n=strlen(s)-1;
		memset(num,0,sizeof(num));
		memset(t,0,sizeof(t));
		memset(t2,0,sizeof(t2));
		memset(hsh,0,sizeof(hsh));
		memset(dp,0,sizeof(dp));
		memset(f,0,sizeof(f));
		for(int i=1;i<=n;i++)
		{
			S[i].clear();
			hsh[i]=hsh[i-1]*mul%mod+s[i]-'a';
			num[s[i]-'a']++;
			if(num[s[i]-'a']%2==0)
				t[i]=t[i-1]-1;
			else t[i]=t[i-1]+1;
			for(int j=0;j<26;j++)
				f[i][j]=f[i-1][j]+(t[i]<=j);
		}
		memset(num,0,sizeof(num));
		for(int i=n;i>=1;i--)
		{
			S[i].insert(i);
			num[s[i]-'a']++;
			if(num[s[i]-'a']%2==0)
				t2[i]=t2[i+1]-1;
			else t2[i]=t2[i+1]+1;
		}
		long long ans=0;
		for(int i=1;i<n;i++)
		{
			for(set<int>::iterator it=S[i].begin();it!=S[i].end();it++)
			{
				int tmp=(*it);
				if(i+tmp<=n&&hs(i+1,i+tmp)==hs(1,tmp))
					S[i+tmp].insert(tmp);
				//for(int j=0;j<=t2[i+1];j++)
				//	dp[i][j]+=f[tmp][j];
				ans+=f[tmp-1][t2[i+1]];
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
