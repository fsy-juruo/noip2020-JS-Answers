/*
file name:string.cpp
time limit:1.0 s
memory limit:512 MB
*/
#include <bits/stdc++.h>
#define endl '\n'

using namespace std;
const int MAX_N=(1<<20)|5;
char str[MAX_N];
int n;
int fail[MAX_N];
vector<int> part[MAX_N];
vector<int> g[MAX_N];
int cnt[MAX_N];
vector<int> fac[MAX_N];
void dfs(int v)
{
	for(int i=0;i<fac[v].size();i++)
	{
		int tp=fac[v][i];
		if(cnt[v-tp])part[v].push_back(tp);
	}
	cnt[v]++;
	for(int i=0;i<g[v].size();i++)
	{
		int to=g[v][i];
		dfs(to);
	}
	cnt[v]--;
}
void init()
{
	int pt=-1;
	fail[0]=-1;
	for(int i=1;i<=n;i++)
	{
		while(pt!=-1 && str[pt+1]!=str[i])pt=fail[pt];
		fail[i]=++pt;
	}
	for(int i=0;i<=n;i++)g[i].clear();
	for(int i=1;i<=n;i++)g[fail[i]].push_back(i);
	for(int i=0;i<=n;i++)part[i].clear();
	dfs(0);
/*	for(int i=1;i<=n;i++)
	{
		cout<<i<<":";
		for(int j=0;j<part[i].size();j++)cout<<part[i][j]<<' ';
		cout<<endl;
	}*/
}
int valc[MAX_N];
int sum[MAX_N];
int psum[MAX_N][27];
//sum[i] in [0,26]
void init_valc()
{
	bool ok[26]={};
	int cur=0;
	for(int i=n;i>=1;i--)
	{
		int c=str[i]-'a';
		if(ok[c])cur--;
		else cur++;
		ok[c]=!ok[c];
		valc[i]=cur;
	}
}
void init_psum()
{
	bool ok[26]={};
	int cur=0;
	for(int i=1;i<=n;i++)
	{
		int c=str[i]-'a';
		if(ok[c])cur--;
		else cur++;
		ok[c]=!ok[c];
		sum[i]=cur;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<=26;j++)
		{
			psum[i][j]=0;
		}
	}
	for(int i=1;i<=n;i++)
	{
	//	cout<<sum[i]<<endl;
		psum[i][sum[i]]++;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<=26;j++)
		{
			psum[i][j]+=psum[i-1][j];
		}
	/*	for(int j=0;j<=26;j++)
		{
			cout<<psum[i][j]<<" \n"[j==26];
		}*/
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=26;j++)
		{
			psum[i][j]+=psum[i][j-1];
		}
	}
}
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	srand(time(0));
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	for(int i=1;i<MAX_N;i++)
	{
		for(int j=i;j<MAX_N;j+=i)fac[j].push_back(i);
	}
	int T;
	cin>>T;
	while(T--)
	{
		cin>>str+1;
		n=strlen(str+1);
		init();
		init_valc();
		init_psum();
		long long ans=0;
		for(int i=1;i<=n;i++)
		{
			if(i==n)continue;
			for(int j=0;j<part[i].size();j++)
			{
				int tp=part[i][j];
				ans+=psum[tp][valc[i+1]];
			//	cout<<i<<' '<<tp<<' '<<psum[tp][valc[i+1]]<<endl;
				if(sum[tp]<=valc[i+1])ans--;
			}
		}
		cout<<ans<<endl;
		/*
		str[i+1,n]=C
		(AB) belong to part[i]
		*/
	}
	return 0;
}

