#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#define ll long long 
#define pii pair<int,int>
#define mp(a,b) make_pair(a,b)
const int inf=1039714778;
const ll llinf=1LL*inf*inf;
template <typename T> inline void chmin(T &x,const T &b) {if(b<x) x=b;}
template <typename T> inline void chmax(T &x,const T &b) {if(b>x) x=b;}
using namespace std;
template <typename T>
ostream & operator << (ostream &cout,const vector <T> &v)
{
	cout<<"{";
	for(int i=0;i<(int)v.size();i++)
	{
		cout<<v[i];
		if(i==(int)v.size()-1) cout<<'}';else cout<<',';
	}
	if(v.empty()) cout<<"}";
	return cout;
}
template <typename T1,typename T2>
ostream & operator << (ostream &cout,const pair<T1,T2> &p)
{
	cout<<"("<<p.first<<","<<p.second<<")";
	return cout;
}
/*********************template codes end here*********************/
const int MaxN=(1<<20);
int isprime[MaxN+5];
vector <int> primes;
int phi[MaxN+5];
char c[MaxN+5];
int n;
int pre[MaxN+5][27];
int suf[MaxN+5];
int s[26];
int fail[MaxN+5];
int a[30];
int b[30];
int lim;
int l;
int mut;
ll res;
int di;
vector <int> facs[MaxN+5];

void dfs(int x)
{
	if(x==l)
	{
//		if(di==6) cout<<mut<<endl;
		if(mut>1) res+=pre[mut-2][lim];
		return;
	}
	int tm=mut;
	for(int i=0;i<=b[x];i++)
	{
		dfs(x+1);
		mut*=a[x];
	}
	mut=tm;
}

inline void build()
{
	int j=fail[0]=-1;
	for(int i=1;i<=n;i++)
	{
		while(j>=0 && c[j]!=c[i-1]) j=fail[j];
		fail[i]=++j;
	}
}

inline void solve()
{
	res=0;
	scanf("%s",c);
	n=strlen(c);
	for(int i=0;i<n;i++) c[i]-='a';
	memset(s,0,sizeof(s));
	for(int i=0;i<n;i++)
	{
		s[(int)c[i]]++;
		int t=0;
		for(int j=0;j<26;j++)
		{
			t+=(s[j]&1);
		}
		for(int j=0;j<=26;j++)
		{
			pre[i][j]=(i?pre[i-1][j]:0);
		}
		for(int j=t;j<=26;j++)
		{
			pre[i][j]++;
		}
	}
	memset(s,0,sizeof(s));
	for(int i=n-1;i>=0;i--)
	{
		s[(int)c[i]]++;
		int t=0;
		for(int j=0;j<26;j++)
		{
			t+=(s[j]&1);
		}
		suf[i]=t;
	}
	build();
	for(int i=2;i<n;i++)
	{
		int k=i-fail[i];
		int m=i/k;
		di=i;
		if(i%k!=0)
		{
			m=1;
			k=i;
		}
		l=0;
		while(m!=1)
		{
			if(l && phi[m]==a[l-1])
			{
				b[l-1]++;
			}
			else
			{
				a[l]=phi[m];
				b[l]=1;
				l++;
			}
			m/=phi[m];
		}
		mut=k;
		lim=suf[i];
		dfs(0);
	}
	cout<<res<<endl;
}

inline void init()
{
	memset(isprime,1,sizeof(isprime));
	isprime[0]=isprime[1]=false;
	for(int i=2;i<=MaxN;i++)
	{
		if(isprime[i])
		{
			primes.push_back(i);
			phi[i]=i;
		}
		for(int j=0;j<(int)primes.size();j++)
		{
			if(i*primes[j]>MaxN) break;
			isprime[i*primes[j]]=false;
			phi[i*primes[j]]=primes[j];
			if(i%primes[j]==0) break;
		}
	}
}

int main()
{
//	freopen("input.txt","r",stdin);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	init();
	int T;
	scanf("%d",&T);
	while(T--)
	{
		solve();
	}
	return 0;
}
