#include<bits/stdc++.h>
using namespace std;

long long n,m,in,in2,ru[100010],zi[100010],mu[100010];
queue < long long > q;
vector < long long > way[100010];

long long find(long long a,long long b)
{
	if(a % b == 0) return b;
	return find(b,a % b);
}

void jia(long long a,long long b)
{
	long long he;
	zi[b] = zi[b] * mu[a] * way[a].size() + zi[a] * mu[b];
	mu[b] = mu[a] * mu[b] * way[a].size();
	he = find(zi[b],mu[b]);
	zi[b] /= he;
	mu[b] /= he;
}

int main()
{
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	cin>>n>>m;
	for(long long i = 1;i <= n;i++)
	{
		cin>>in;
		mu[i] = 1;
		for(long long j = 1;j <= in;j++)
		{
			cin>>in2;
			way[i].push_back(in2);
			ru[in2]++;
		}
	}
	for(long long i = 1;i <= n;i++)
	{
		if(ru[i] == 0)
		{
			zi[i] = 1,mu[i] = 1;
			q.push(i);
		}
	}
	while(!q.empty())
	{
		long long now = q.front();
		for(long long i = 0;i < way[now].size();i++)
		{
			jia(now,way[now][i]);
			ru[way[now][i]] --;
			if(ru[way[now][i]] == 0) q.push(way[now][i]);
		}
		q.pop();
	}
	for(long long i = 1;i <= n;i++)
	{
		if(way[i].size() == 0)
		cout<<zi[i]<<' '<<mu[i]<<endl;
	}
	
	
	return 0;
}
