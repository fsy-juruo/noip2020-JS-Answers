#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+10;
int n,m;
vector<int> edge[maxn];
vector<int> pos;
vector<pair<long long,long long> > ans[maxn];
void dfs(int x,long long p,long long q)
{
	ans[x].push_back(make_pair(p,q));
	int sz=(int)edge[x].size();
	for(int i=0;i<sz;i++)
	{
		int to=edge[x][i];
		dfs(to,p,q*(long long)sz);
	}
}
long long GCD(long long a,long long b)
{
	if(b==0LL)
	{
		return a;
	}
	return GCD(b,a%b);
}
long long LCM(long long a,long long b)
{
	return a/GCD(a,b)*b;
}
int main()
{
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		int d;
		cin>>d;
		if(d==0)
		{
			pos.push_back(i);
		}
		for(int j=1;j<=d;j++)
		{
			int x;
			cin>>x;
			edge[i].push_back(x);
		}
	}
	for(int i=1;i<=m;i++)
	{
		dfs(i,1LL,1LL); 
	}
	for(int i=0;i<(int)pos.size();i++)
	{
		int x=pos[i];
		long long fenzi=0LL,fenmu=1LL;
		for(int j=0;j<(int)ans[x].size();j++)
		{
			long long p=ans[x][j].first,q=ans[x][j].second;
			long long cc=GCD(p,q);
			p/=cc;
			q/=cc;
			long long nwl=LCM(fenmu,q);
			fenzi*=(nwl/fenmu);
			fenzi+=(nwl/q*p);
			fenmu=nwl;
			long long nwg=GCD(fenzi,fenmu);
			fenzi/=nwg;
			fenmu/=nwg;
		}
		cout<<fenzi<<" "<<fenmu<<endl;
	}
	return 0;
}
/*
check array size
check initilize
check int and long long
check freopen
*/
