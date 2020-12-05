#include <bits/stdc++.h>
#define bug cout<<"bug "<<__LINE__<<endl
#define index xedni
#define int long long
using namespace std;
const int iuf=1e9+7;
const int MOD=1e9+7;
const int MAXN=(1<<16)+10;
int n,dp[MAXN],cnt[MAXN],rcnt[MAXN],times[MAXN],used[MAXN];
int f[30][MAXN],g[30][MAXN];
string s;
char c[MAXN];
int inp[MAXN],p[MAXN],index;
void prime()
{
	inp[1]=1; inp[2]=0;
	for(int i=2;i<MAXN;i++)
		if(!inp[i])
		for(int j=i*i;j<MAXN;j+=i) inp[i]=1;
	for(int i=1;i<MAXN;i++)
		if(!inp[i]) p[++index]=i;
}
signed main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
//	prime();
	int T; cin>>T;
	while(T--)
	{
		memset(c,0,sizeof(c));
		memset(dp,0,sizeof(dp));
		cin>>s;
		n=(int)s.size();
//		if(n<=1000)
//		{
			for(int i=0;i<n;i++) c[i+1]=s[i];
			for(int i=1;i<=n;i++) dp[i]=i;
			for(int i=1;i<=n;i++)
			{
				int len=dp[i];
				for(int j=i+1;j<=n;j+=len)
				{
					bool flag=1;
					for(int k=1;k<=len;k++)
					{
						if(c[k]!=c[j+k-1]) flag=0;
					}
					if(flag) dp[j+len-1]=len,used[len]=1;
					else break;
				}
			}
			memset(cnt,0,sizeof(cnt));
			memset(times,0,sizeof(times));
			for(int i=1;i<=n;i++)
			{
				cnt[i]=cnt[i-1];
				times[c[i]-'a'+1]++;
				
				if(times[c[i]-'a'+1]%2==1) cnt[i]++;
				else cnt[i]--;
			}
			memset(rcnt,0,sizeof(rcnt));
			memset(times,0,sizeof(times));
			for(int i=n;i>=1;i--)
			{
				rcnt[i]=rcnt[i+1];
				times[c[i]-'a'+1]++;
				if(times[c[i]-'a'+1]%2==1) rcnt[i]++;
				else rcnt[i]--;
			}
			memset(g,0,sizeof(g));
			memset(f,0,sizeof(f));
			for(int i=1;i<=n;i++)
			{
				for(int j=0;j<=26;j++)
				{
					g[j][i]=g[j][i-1];
					if(cnt[i]==j) g[j][i]++;
				}
			}
			for(int lim=0;lim<=26;lim++)
			{
				for(int i=1;i<=n;i++)
				{
					int all=i/dp[i];
					int len=dp[i];
					for(int j=1;j<=all;j++)
					{
						if(all%j!=0) continue;
						if(j*len-1>=1) f[lim][i]+=g[lim][j*len-1];
					}				
				}
			}
			for(int i=1;i<=n;i++)
				for(int lim=1;lim<=26;lim++) f[lim][i]+=f[lim-1][i];
			int ans=0;
			for(int i=2;i<=n;i++) ans+=f[rcnt[i]][i-1];
			cout<<ans<<endl;
//		}
//		else
//		{
//			int ans=0;
//			for(int i=1;i<=n-2;i++)
//			{
//				int lef=n-i;
//				if(i%2==0)
//				{
//					
//				}
//			}
//			cout<<ans<<endl;
//		}
	}
	return 0;
}
