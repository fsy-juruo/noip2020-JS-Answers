#include<bits/stdc++.h>
using namespace std;
long long gcd(long long a,long long b)
{
	if(!b)
		return a;
	return gcd(b,a%b);
}
struct fraction
{
	long long p,q;
	void reset(long long val)
	{
		p=val;
		q=1ll;
	}
	void refresh()
	{
		long long g=gcd(p,q);
		p/=g;
		q/=g;
	}
	const fraction operator +(const fraction &b)
	{
		fraction ret;
		ret.reset(0);
		ret.q=q*b.q;
		ret.p=p*b.q+b.p*q;
		ret.refresh();
		return ret;
	}
	const fraction operator /(const long long &b)
	{
		fraction ret;
		ret.reset(0);
		ret.p=p;
		ret.q=q*b;
		ret.refresh();
		return ret;
	}
	void o()
	{
		cout<<p<<" "<<q<<endl;
	}
};
int ind[100100],oud[100100];
vector<int> to[100100];
fraction water[100100];
int main()
{
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=m;i++)
		water[i].reset(1);
	for(int i=m+1;i<=n;i++)
		water[i].reset(0);
	for(int i=1;i<=n;i++)
	{
		cin>>oud[i];
		for(int j=0;j<oud[i];j++)
		{
			int x;
			cin>>x;
			to[i].push_back(x);
			ind[x]++;
		}
	}
	queue<int> Q;
	for(int i=1;i<=m;i++)
		Q.push(i);
	while(!Q.empty())
	{
		int u=Q.front();
		Q.pop();
		for(int i=0;i<oud[u];i++)
		{
			ind[to[u][i]]--;
			water[to[u][i]]=water[to[u][i]]+(water[u]/oud[u]);
			if(!ind[to[u][i]])
				Q.push(to[u][i]);
		}
	}
	for(int i=1;i<=n;i++)
		if(!oud[i])
			water[i].o();
	return 0;
}
