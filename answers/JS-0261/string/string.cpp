#include<bits/stdc++.h>
#define ll int
#define ull unsigned long long
#define N 100001
#define P 131
#define rg register
#define m_p make_pair
using namespace std;
ll n,m,T,len,f,nex[1<<17],v[26],b[1<<17][27];
ull ans,a[1<<17],p[1<<17];
string s;
inline ll read()
{
	ll sum=0,f=1;
	char c=getchar();
	while (c<'0'||c>'9')
	{
		if (c=='-') f=-1;
		c=getchar();
	}
	while (c>='0'&&c<='9')
	{
		sum=sum*10+c-'0';
		c=getchar();
	}
	return f*sum;
}
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	T=read();
	while (T--)
	{
		cin>>s;len=s.size();
		memset(v,0,sizeof(v));f=0;ans=0;
		for (rg int i=0;i<len;i++)
		{
			ll k=s[i]-'a';
			v[k]++;
			if (v[k]&1) f++;  else f--;
			for (rg int j=1;j<=26;j++)
			{
				if (i) b[i][j]=b[i-1][j]; 
				else b[i][j]=0;
				if (j>=f) b[i][j]++;
			}
		}
		memset(v,0,sizeof(v));f=0;
		for (rg int i=len-1;i>=2;i--)
		{
			ll k=s[i]-'a';
			v[k]++;
			if (v[k]&1) f++;else f--;
			ans+=b[i-2][f];
		}
		printf("%lld\n",ans);
	}
	return 0;
}
