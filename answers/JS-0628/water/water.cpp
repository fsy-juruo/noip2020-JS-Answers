/*
file name:water.cpp
time limit:1.0s
memory limit:512 MB
*/
#include <bits/stdc++.h>
#define endl '\n'
#define int long long

using namespace std;
const int MAX_N=100005;
int n,m;
vector<int> g[MAX_N];
struct node
{
	int p,q;
	node(){}
	node(int _p,int _q)
	{
		p=_p;
		q=_q;
	}
};
int gcd(int a,int b)
{
	return b?gcd(b,a%b):a;
}
void update(node &x)
{
	int g=gcd(x.p,x.q);
	x.p/=g;
	x.q/=g;
}
node operator + (node a,node b)
{
	node ret=node(a.p*b.q+a.q*b.p,a.q*b.q);
	update(ret);
	return ret;
}
node divd(node x,int y)
{
	x.q*=y;
	update(x);
	return x;
}
node dp[MAX_N];
int in[MAX_N];
signed main()
{
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	srand(time(0));
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		int k;
		cin>>k;
		g[i].resize(k);
		for(int j=0;j<k;j++)
		{
			cin>>g[i][j];
			in[g[i][j]]++;
		}
	}
	queue<int> q;
	for(int i=1;i<=n;i++)
	{
		if(in[i]==0)
		{
			q.push(i);
			dp[i]=node(1,1);
		}
		else dp[i]=node(0,1);
	}
	while(!q.empty())
	{
		int v=q.front();
		q.pop();
	//	cout<<dp[v].p<<' '<<dp[v].q<<endl;
		for(int i=0;i<g[v].size();i++)
		{
			int to=g[v][i];
			dp[to]=dp[to]+divd(dp[v],(int)g[v].size());
			in[to]--;
			if(!in[to])q.push(to);
		}
	}
	for(int i=1;i<=n;i++)if(g[i].size()==0)cout<<dp[i].p<<' '<<dp[i].q<<endl;
	return 0;
}

