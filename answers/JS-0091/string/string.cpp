#include <bits/stdc++.h>
#define int long long
#define rg register
#define power ghgkgaggilio
using namespace std;
const int mod=1e9+7,base=13331,maxl=(1ll<<17)+5;

int t,n,Pre_Ji,ans=0;
int a[maxl],haxi[maxl],power[maxl],lis[40];
int pre[maxl][27];

vector<int> ve[maxl];

void clear()
{
	ans=0;
	for (int i=0;i<26;i++)  lis[i]=0;
	Pre_Ji=0;
}

void init()
{
	power[0]=1;
	for (int i=1;i<=maxl-5;i++)  power[i]=(power[i-1]*base)%mod;
	for (rg int i=1;i<=maxl-5;++i)
	{
		for (rg int j=i;j<=maxl-5;j+=i)  ve[j].push_back(i);
	}
}

int ducati_get_haxi(int l,int r)
{
	return ((haxi[r]-haxi[l-1]*power[r-l+1])%mod+mod)%mod;
}

bool is_xvn_huan(int pp,int len)//3 1
{
	if (haxi[pp-len]==ducati_get_haxi(len+1,pp))  return true;
	else return false;
}

signed main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>t;
	init();
	while (t--)
	{
		string s;
		cin>>s;
		n=s.size();
		clear();
		for (int i=1;i<=n;i++)
		{
			for (int j=0;j<26;j++)  pre[i][j]=0;
		}
		for (int i=1;i<=n;i++)  a[i]=s[i-1]-'a';
		for (int i=1;i<=n;i++)  haxi[i]=(haxi[i-1]*base+a[i])%mod;
		for (int i=1;i<=n;i++)
		{
			lis[a[i]]++;
			if (lis[a[i]]%2==1)  Pre_Ji++;
			else Pre_Ji--;
			pre[i][Pre_Ji]=1;
		}
		for (int i=1;i<=n;i++)
		{
			for (int j=0;j<26;j++)  pre[i][j]+=pre[i-1][j];
		}
		clear();
		Pre_Ji=1;
		lis[a[n]]=1;
		for (int i=1;i<=n;i++)
		{
			for (int j=1;j<26;j++)  pre[i][j]+=pre[i][j-1];
		}
		for (int i=n-1;i>=2;i--)//¥”i+1µΩn «C 
		{
			for (int j=0;j<ve[i].size();j++)
			{
				if (is_xvn_huan(i,ve[i][j]))
				  ans+=pre[ve[i][j]-1][Pre_Ji];
			}
			lis[a[i]]++;
			if (lis[a[i]]&1)  Pre_Ji++;
			else Pre_Ji--;
		}
		cout<<ans<<endl;
	}
	return 0;
}
