#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN=2000006;
int cnt[30],pre[MAXN],dp[MAXN][30],pst[MAXN];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int tt;
	cin>>tt;
	while(tt--)
	{
		ll ans=0ll;
		string s;
		cin>>s;
		s=' '+s;
		memset(cnt,0,sizeof(cnt));
		memset(dp,0,sizeof(dp));
		pre[0]=0;
		for(int i=1;i<s.size();i++)
		{
			cnt[s[i]-'a']++;
			if(cnt[s[i]-'a']%2)pre[i]=pre[i-1]+1;
			else pre[i]=pre[i-1]-1;
		}
		for(int i=1;i<s.size();i++)
		{
			for(int j=0;j<26;j++)
			{
				dp[i][j]=dp[i-1][j]+(pre[i]<=j);
//				cout<<dp[i][j]<<' ';
			}
//			cout<<endl;
		}
		memset(cnt,0,sizeof(cnt));
		pst[s.size()]=0;
		for(int i=s.size()-1;i>0;i--)
		{
			cnt[s[i]-'a']++;
			if(cnt[s[i]-'a']%2)pst[i]=pst[i+1]+1;
			else pst[i]=pst[i+1]-1;
		}
		for(int i=2;i<s.size()-1;i++)
		{
			ans+=dp[i-1][pst[i+1]];
//			cout<<i<<' '<<pst[i+1]<<endl;
			for(int k=2;k*i<s.size()-1;k++)
			{
				bool ok=1;
				for(int j=1;j<=i;j++)
				{
					if(s[i*(k-1)+j]!=s[i*(k-2)+j])ok=0;	
				}
				if(!ok)break;
				ans+=dp[i-1][pst[k*i+1]];
//				cout<<i<<' '<<pst[k*i+1]<<endl;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}

