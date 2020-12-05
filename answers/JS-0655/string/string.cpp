#include<bits/stdc++.h>
#define mod 998244353
#define p 13131
using namespace std;
typedef long long ll;
const int maxn=(1<<20)+5;
string str;
bool suf[maxn];
int n,a[maxn],bucket[maxn][27],sum[maxn][27];
int f[maxn];
inline int getPre(int pos)
{
	int s=0;
	for(int i=0;i<26;++i)
		if(bucket[pos][i]&1)
			++s;
	return s;
}
inline int getSuf(int pos)
{
	int s=0;
	for(int i=0;i<26;++i)
		if((bucket[n][i]-bucket[pos-1][i])&1)
			++s;
	return s;
}
int len[maxn];
int Hash[maxn];
inline ll qpow(ll x,ll y)
{
	ll ans=1,base=x;
	while(y)
	{
		if(y&1)
			ans=ans*base%mod;
		base=base*base%mod;
		y>>=1;
	}
	return ans;
}
inline void init()
{
	len[0]=1;
	for(int i=1;i<=1000000;++i)
		len[i]=(ll)len[i-1]*p%mod;
}
inline int get(int l,int r)
{
	return (((ll)Hash[r]-(ll)Hash[l-1]*len[r-l+1])%mod+mod)%mod;
}
inline void solve()
{
	cin>>str;
	n=str.size();
	for(int i=1;i<=n;++i)
		a[i]=str[i-1]-'a';
	memset(bucket,0,sizeof(bucket));
	memset(sum,0,sizeof(sum));
	for(int i=1;i<=n;++i)
		Hash[i]=((ll)Hash[i-1]*(ll)p+(ll)str[i-1])%mod;
	for(int i=1;i<=n;++i)
	{
		for(int j=0;j<26;++j)
			bucket[i][j]=bucket[i-1][j],sum[i][j]=sum[i-1][j];
		++bucket[i][a[i]];
		++sum[i][getPre(i)];
	}
	for(int i=1;i<=n;++i)
		f[i]=getSuf(i);
	for(int i=1;i<=n;++i)
		for(int j=1;j<=26;++j)
			sum[i][j]+=sum[i][j-1];
	ll ans=0;
	for(int len=2;len<n;++len)
	{
		int base=get(1,len);
		for(int i=len;i<n;i+=len)
		{
			if(get(i-len+1,i)!=base)
				break;
			int d=f[i+1];
			ans+=sum[len-1][d];
		}
	}
	cout<<ans<<endl;
}
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	init();
	int T;
	cin>>T;
	while(T--)
		solve();
	return 0;
}

