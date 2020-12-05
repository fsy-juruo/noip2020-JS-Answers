#include<bits/stdc++.h>
using namespace std;
const int N=1e6+1e5;
typedef long long ll;
int f[N],d[26],n,g[N],dp[N],c[N],ssum[N];
char s[N];
ll ans;bool ok;
int check(int x)
{
	if(ok) return (n-1)/x;
	if(ssum[x]) return ssum[x];
	int cnt=1;
	for(int i=x;i+x<n;i+=x)
	{
		for(int k=1;k<=x;k++)
		{
			if(c[i+k]!=c[k]) return cnt;
		}
		cnt++;
	}
	ssum[x]=cnt;
	for(int i=1;i*x<n;i++)
	{
		ssum[i*x]=cnt/i;
	}
	return cnt;
}
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int T;
	scanf("%d",&T);
	while(T--)
	{
		memset(dp,0,sizeof(dp));ans=0;memset(ssum,0,sizeof(ssum));memset(f,0,sizeof(f));memset(g,0,sizeof(g));
		scanf("%s",s);
		n=strlen(s);
		for(int i=1;i<=n;i++) c[i]=s[i-1]-'a';
		ok=1;
		for(int i=2;i<=n;i++)
			if(c[i]!=c[i-1])
			{
				ok=0;
				break;
			}
		memset(d,0,sizeof(d));
		for(int i=n;i>=1;i--)
		{
			d[c[i]]++;
			if(d[c[i]]%2) f[i]=f[i+1]+1;
			else f[i]=f[i+1]-1;
		}
		memset(d,0,sizeof(d));
		for(int i=1;i<=n;i++)
		{
			d[c[i]]++;
			if(d[c[i]]%2) g[i]=g[i-1]+1;
			else g[i]=g[i-1]-1;
		}
		dp[g[1]]++;
		for(int i=2;i<n;i++)
		{
			int k=check(i),cnt1=0,cnt2=0;
			for(int j=0;j<=f[i+1];j++) cnt1+=dp[j];
			if(k>1) for(int j=0;j<=f[i+i+1];j++) cnt2+=dp[j];
			int h=k/2;
			//cerr<<"## "<<k<<' '<<h<<" ## "<<h*cnt2+(k-h)*cnt1<<'\n';
			ans+=(ll)h*cnt2+(k-h)*cnt1;
			dp[g[i]]++;
		}
		printf("%lld\n",ans);
	}
	return 0;
}
