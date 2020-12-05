#include <bits/stdc++.h>
using namespace std;

#define int long long

const int B1 = 571;
const int B2 = 233;
const int M = 1e9+7ll;
const int N = (1<<17)+1;

int Q,n,ans=0;
char ch[200005];
int s1[200005][26],s2[200005][26],sj1[200005],sj2[200005],sum[200005][27];
int h1[200005],h2[200005],bp1[200005],bp2[200005];
int cnt[200005];
vector<int> xs1[200005],xs2[200005];

void init_()
{
	ans = sj2[n+1] = 0;
	for(int i=0;i<26;i++)
		s2[n+1][i] = 0;
	memset(cnt,0,sizeof(cnt));
}

int work(int m,int l,int lim)
{
	if(h1[l]*xs1[l][m/l-1]%M!=h1[m]%M)
		return 0;
	if(h2[l]*xs2[l][m/l-1]%M!=h2[m]%M)
		return 0;
	return sum[l-1][lim];
}

signed main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%lld",&Q);
	bp1[0] = bp2[0] = 1;
	for(int i=1;i<=N;i++)
		bp1[i] = bp1[i-1]*B1%M, bp2[i] = bp2[i-1]*B2%M;
	for(int i=1;i<=N;i++)
	{
		int s1=0,s2=0;
		for(int j=0;i*j<=N;j++)
		{
			s1 = (s1+bp1[i*j])%M;
			xs1[i].push_back(s1);
			s2 = (s2+bp2[i*j])%M;
			xs2[i].push_back(s2);
		}
	}
	while(Q--)
	{
		init_();
		scanf("%s",ch+1);
		n = strlen(ch+1);
		for(int i=1;i<=n;i++)
		{
			h1[i] = (h1[i-1]*B1+ch[i])%M;
			h2[i] = (h2[i-1]*B2+ch[i])%M;
			for(int j=0;j<26;j++)
				s1[i][j] = s1[i-1][j], sum[i][j] = sum[i-1][j];
			sum[i][26] = sum[i-1][26];
			s1[i][ch[i]-'a']++;
			sj1[i] = sj1[i-1]+(s1[i][ch[i]-'a']&1 ? 1 : -1);
			for(int j=sj1[i];j<=26;j++)
				sum[i][j]++;
		}
		for(int i=n;i>=1;i--)
		{
			for(int j=0;j<26;j++)
				s2[i][j] = s2[i+1][j];
			s2[i][ch[i]-'a']++;
			sj2[i] = sj2[i+1]+(s2[i][ch[i]-'a']&1 ? 1 : -1);
		}
		for(int i=2;i<=n-1;i++)
			for(int j=1;i*j<n;j++)
				cnt[i*j+1] += work(i*j,i,sj2[i*j+1]);
		for(int i=1;i<=n;i++)
			ans += cnt[i];
		printf("%lld\n",ans);
	}
	
	return 0;
}
/*
3
nnrnnr
zzzaab
mmlmmlo
5
kkkkkkkkkkkkkkkkkkkk
lllllllllllllrrlllrr
cccccccccccccxcxxxcc
ccccccccccccccaababa
ggggggggggggggbaabab
*/
