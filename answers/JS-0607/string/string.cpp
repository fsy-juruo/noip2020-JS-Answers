#include<bits/stdc++.h>
#define vi vector<int>
#define pb push_back
#define ll long long
using namespace std;
const int N=(1<<20)+5;
const int mod[]={1e9+7,1e9+9};
const int p[]={11,13};
vi v[N];ll dp[N][28];
void readint(int &x)
{
	x=0;
	char c=getchar();
	while(!isdigit(c))c=getchar();
	while(isdigit(c))x=x*10+c-'0',c=getchar();
}
bool IsLetter(char c){return (c>='a'&&c<='z');}
void readstring(string &s)
{
	s="";
	char c=getchar();
	while(!IsLetter(c))c=getchar();
	while(IsLetter(c))s+=c,c=getchar();
}
void dfs(ll x)
{
	if(!x)return;
	else{
		dfs(x/10);
		putchar('0'+x%10);
	}
}
void write(ll x)
{
	if(!x)putchar('0');
	else dfs(x);
	putchar('\n');
}
struct HASH{
	string s;int sz;
	ll h[N][2],pw[N][2];
	void initpw()
	{
		pw[0][0]=pw[0][1]=1;
		for(int i=1;i<=(1<<20);i++)
			for(int j=0;j<2;j++)
				pw[i][j]=pw[i-1][j]*p[j]%mod[j];
	}
	void initstring()
	{
		sz=s.size();
		for(int i=0;i<sz;i++)
		{
			v[i].clear();
			for(int j=0;j<2;j++)
			{
				h[i][j]=pw[i][j]*(s[i]-'a'+1)%mod[j];
				if(i)h[i][j]=(h[i][j]+h[i-1][j])%mod[j];
			}
		}
	}
	bool IsSame(int l,int r,int L,int R)
	{
		for(int i=0;i<2;i++)
		{
			ll qwq=(h[r][i]-(l==0?0:h[l-1][i])+mod[i])%mod[i];
			ll qaq=(h[R][i]-(L==0?0:h[L-1][i])+mod[i])%mod[i];
			qwq=qwq*pw[sz-r][i]%mod[i];qaq=qaq*pw[sz-R][i]%mod[i];
			if(qwq!=qaq)return false;
		}
		return true;
	}
}S;//Hash has no problem!
void solve()
{
	readstring(S.s);
	S.initstring();
	int now=0,sum=0,l[30],cnt[30];ll ans=0;
	for(int i=0;i<=26;i++)l[i]=cnt[i]=0;
	for(int i=0;i<S.sz;i++)
	{
		for(int j=i+i+1;j<S.sz;j+=i+1)
		{
			if(S.IsSame(0,i,j-i,j)){
				v[j].pb(i);
			}else break;
		}
	}
	for(int i=0;i<S.sz;i++)
	{
		int k=S.s[i]-'a';
		l[k]=!l[k];
		if(l[k])sum++;
		else sum--;
		for(int j=0;j<26;j++)
			dp[i][j]=cnt[j];
		cnt[sum]++;
	}sum=0;
	for(int i=S.sz;i>=0;i--)
		for(int j=0;j<26;j++)
			for(int k=0;k<v[i].size();k++)
				dp[i][j]+=dp[v[i][k]][j];
//	return;//当把前i个字符串划分成A,B两部分时,A字符串中出现奇数次字符的数量为j的方案数 
	for(int i=0;i<=26;i++)l[i]=0;
	for(int i=S.sz-1;i>=2;i--)
	{
		int j=S.s[i]-'a';
		l[j]=!l[j];
		if(l[j])sum++;
		else sum--;
		for(j=0;j<=sum;j++)
			ans+=dp[i-1][j];
	}
	write(ans);
	return;
}
int T;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	S.initpw();
	readint(T);
	while(T--)solve();
	return 0;
}//11:35 80pts
