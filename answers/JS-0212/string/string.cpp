#include<bits/stdc++.h>
#define int long long 
using namespace std;
const int N = 1100000;
int T;
char s[N];
int pre[N],bac[N],sum[30];
int n;
inline bool check(int l1,int r1,int l2,int r2)
{
	for(int i=1;i<=r1-l1+1;++i) if(s[l1+i-1]!=s[l2+i-1]) return 0;
	return 1;
}
int ans;
int cnt[N];
int pl[N][28];
signed main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%lld",&T);
	while(T--)
	{
		ans=0;
		scanf("%s",s+1);
		n=strlen(s+1);
		bac[n+1]=0,memset(sum,0,sizeof(sum));
		for(int i=n;i>=1;--i)
		{
			++sum[s[i]-'a'];
			if(sum[s[i]-'a']&1) bac[i]=bac[i+1]+1;
			else bac[i]=bac[i+1]-1;
		}
		memset(sum,0,sizeof(sum));
		for(int i=1;i<=n;++i)
		{
			cnt[i]=0;
			++sum[s[i]-'a'];
			if(sum[s[i]-'a']&1) pre[i]=pre[i-1]+1;
			else pre[i]=pre[i-1]-1;
			for(int j=0;j<=25;++j)
			{
				if(pre[i]<=j) pl[i][j]=pl[i-1][j]+1;
				else pl[i][j]=pl[i-1][j];
			}
		}
		for(int i=1;i<=n;++i)
		{
			if(!cnt[i])
			{
				int to=1;
				for(int j=2;i*j<=n;++j)
				{
					if(!check(1,i,(j-1)*i+1,j*i)) break;
					to=j;
				}
				cnt[i]=to;
				for(int j=i*2;j<=n;j+=i) if(!cnt[j]) cnt[j]=i*cnt[i]/j;
			}
			for(int j=1;j<=cnt[i];++j)
			{
				if(i*j+1>n) break;
				ans+=pl[i-1][bac[i*j+1]];
			}
		}
		printf("%lld\n",ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
