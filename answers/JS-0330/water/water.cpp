#include<bits/stdc++.h>
using namespace std;
int n,m;
vector<int> g[100100];
pair<long long ,long long> outw[100100];
long long gcd(long long a,long long b)
{
	if(b==0)
	{
		return a;
	}
	a%=b;
	return gcd(b,a);
}
pair<long long ,long long> add(pair<long long ,long long> a1,pair<long long ,long long> b1)//be tested
{
	pair<long long ,long long> c1;
	c1.second=a1.second*b1.second;
	c1.first=a1.first*b1.second+b1.first*a1.second;
	long long gs=gcd(c1.first,c1.second);
	c1.first/=gs;
	c1.second/=gs;
	return c1;
} 
pair<long long ,long long> chu(pair<long long ,long long> a1,long long cs)//be tested
{
	pair<long long ,long long> c1;
	c1.second=a1.second*cs;
	c1.first=a1.first;
	long long gs=gcd(c1.first,c1.second);
	c1.first/=gs;
	c1.second/=gs;
	return c1;
} 
void work(int st,pair<long long ,long long> fs)//x/y
{
	if(g[st].size()==0)
	{
		if(outw[st].second==0)
		{
			outw[st]=fs;
		}
		else
		{
			outw[st]=add(fs,outw[st]);
		} 
		return;
	}
	pair<long long ,long long> flood=chu(fs,g[st].size());
	for(int i=0;i<g[st].size();i++)
	{
		work(g[st][i],flood);
	} 
}
int main()
{
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	scanf("%d",&n);
	scanf("%d",&m);
	for(int i=1;i<=n;i++)
	{
		int d;
		scanf("%d",&d);
		for(int j=1;j<=d;j++)
		{
			int to;
			scanf("%d",&to);
			g[i].push_back(to);
		}
	}
	for(int i=1;i<=m;i++)
	{
		work(i,make_pair(1,1));
	}
	for(int i=1;i<=n;i++)
	{
		if(outw[i].second!=0)
		{
			cout<<outw[i].first<<" "<<outw[i].second<<endl;
		 } 
	} 
	/*
	pair<long long,long long> test=chu(make_pair(4,8),4);
	cout<<test.first<<" "<<test.second;
	*/
}

