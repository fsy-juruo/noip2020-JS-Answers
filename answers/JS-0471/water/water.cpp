#include <bits/stdc++.h>
using namespace std;
int gcd(int a,int b)
{
	if (b==0)
	{
		return a;
	}
	else
	{
		return (gcd(b,a%b));
	}
}
pair<int,int> depart_water(pair<int,int> a,int b)
{
	int fen=gcd(max(a.first,a.second),min(a.first,a.second));
	a.first/=fen;
	a.second/=fen;
	a.second*=b;
	int fen2=gcd(max(a.first,a.second),min(a.first,a.second));
	a.first/=fen2;
	a.second/=fen2;
	return a;
}
pair<int,int> plus_fen(pair<int,int> a,pair<int,int> b)
{
	int mu=a.second*b.second,zi=a.first*b.first;
	int fen=gcd(max(mu,zi),min(mu,zi));
	mu/=fen;
	zi/=fen;
	return make_pair(zi,mu);
}
int main()
{
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	int n,m,a[100010][10],jie[20],pai[20],now_jie=0,now_pai=0;			//5*10^6=5000000 byte<2.5 MB
	pair<int,int> water[100010];
	bool can_be_jie[100010]={true};
	queue<int> q;
	cin>>n>>m;
	for (int i=0;i<n;i++)
	{
		cin>>a[i][0];
		if (a[i][0]==0)
		{
			pai[now_pai]=i+1;
			now_pai++;
			continue;
		}
		for (int j=1;j<=a[i][0];j++)
		{
			cin>>a[i][j];
		}
	}
	for (int i=0;i<n;i++)
	{
		for (int j=1;j<=a[i][0];j++)
		{
			can_be_jie[a[i][0]]=false;
		}
	}
	for (int i=0;i<n;i++)
	{
		if (can_be_jie[i]==true)
		{
			jie[now_jie]=i+1;
			water[i]=make_pair(1,1);
			now_jie++;
			q.push(i);
		}
	}
	while (!q.empty())
	{
		int x=q.front();
		q.pop();
		for (int i=1;i<=a[x-1][0];i++)
		{
			q.push(a[x-1][i]);
			water[(a[x-1][i])-1]=plus_fen(depart_water(water[x-1],a[x-1][0]),water[(a[x-1][i])-1]);
		}
	}
	for (int i=0;i<now_pai;i++)
	{
		int fen=gcd(max(water[(pai[i])-1].first,water[pai[i]-1].second),min(water[pai[i]-1].first,water[pai[i]-1].second));
		water[pai[i]-1].first/=fen;
		water[pai[i]-1].second/=fen;
		cout<<water[pai[i]-1].first<<" "<<water[pai[i]-1].second;
		if (i!=(now_pai-1))
		{
			cout<<endl;
		}
	}
	return 0;
}
