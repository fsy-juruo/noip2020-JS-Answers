#include<bits/stdc++.h>
#define vi vector<int>
#define pb push_back
using namespace std;
int n,m,x,y,cnt;vi v[5];
int main()
{
	freopen("ball.in","r",stdin);
	freopen("ball.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<2;i++)
	{
		for(int j=0;j<m;j++)
		{
			int x;
			cin>>x;
			v[i].pb(x);
		}
	}
	//x = 3,y = 1
	x=v[1][m-1];
	y=(x==1?2:1);
	for(int i=0;i<m;i++)
		if(v[0][i]==x)
			cnt++;
	cout<<"2 3\n";
	v[2].pb(v[1].back());
	v[1].pop_back();
	for(int i=0;i<cnt;i++)
	{
		while(v[0].back()!=x)
		{
			cout<<1<<" "<<3<<"\n";
			v[2].pb(v[0].back());
			v[0].pop_back();
		}
		cout<<1<<" "<<2<<"\n";
		v[0].pop_back();
		while(v[2].back()==y)
		{
			cout<<3<<" "<<1<<"\n";
			v[0].pb(v[2].back());
			v[2].pop_back();
		}
		cout<<2<<" "<<3<<"\n";
	}
	for(int i=0;i<v[1].size();i++)
	{
		if(v[1][i]==x)
			cout<<"2 1\n";
		else
			cout<<"2 3\n";
	}
	return 0;
}
