#include<bits/stdc++.h>
using namespace std;
const int MAXN=1030*1030;
#define ll long long
int T,n;
int cnt_pre[27],cnt_nxt[27];
int pre[MAXN],nxt[MAXN];
int ok_cnt[27][MAXN];
ll ans;
char S[MAXN];
void solve()
{
	ans=0;
	scanf("%s",S+1);
	n=strlen(S+1);
	memset(cnt_nxt,0,sizeof(cnt_nxt));
	memset(cnt_pre,0,sizeof(cnt_pre));
	for(int i=1;i<=n;i++)
	{
		int id=(int) S[i]-'a';
		cnt_pre[id]++;
		if(cnt_pre[id]&1)
			pre[i]=pre[i-1]+1;
		else
			pre[i]=pre[i-1]-1;
	}
	for(int i=n;i>=1;i--)
	{
		int id=(int) S[i]-'a';
		cnt_nxt[id]++;
		if(cnt_nxt[id]&1)
			nxt[i]=nxt[i+1]+1;
		else
			nxt[i]=nxt[i+1]-1;
	}
	for(int i=0;i<=26;i++)
		ok_cnt[i][0]=0;
	for(int i=1;i<=n;i++)
		for(int lim=0;lim<=26;lim++)
			if(pre[i]<=lim)
				ok_cnt[lim][i]=ok_cnt[lim][i-1]+1;
			else
				ok_cnt[lim][i]=ok_cnt[lim][i-1];		
	for(int len=2;len<=n-1;len++)
	{
		for(int times=1;len*times<=n-1;times++)
		{
			int ed=len*times;
			int lim=nxt[ed+1];
			if(times>1)
			{
				bool flag=0;
				for(int i=1;i<=len;i++)
					if(S[i]!=S[ed-len+i])
					{
						flag=1;
						break;
					}
				if(flag)
					break;
			}
			ans+=ok_cnt[lim][len-1];
		}
	}
	printf("%lld\n",ans);
}
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&T);
	while(T--)
		solve();
	return 0;
}
