#include<bits/stdc++.h>
using namespace std;
struct node{
	long long w1,w2;
	node(long long _w1=0,long long _w2=0):w1(_w1),w2(_w2){	}
};
int n,m,ou[100010],com[100010];
vector<int>mp[100010];
vector<node>wa[100010];
void dfs(int x,long long w1,long long w2)
{
	if(ou[x]==0)wa[x].push_back(node(w1,w2));
	long long per=mp[x].size();
	for(int i=0;i<mp[x].size();i++)
	{
		int u=mp[x][i];
		dfs(u,w1,w2*per);
	}
}
long long gcd(long long x,long long y)
{
	if(x%y==0)return y;
	return gcd(y,x%y);
}
node chang(int x)
{
	long long w1=wa[x][0].w1,w2=wa[x][0].w2;
	for(int i=1;i<wa[x].size();i++)
	{
		long long v1=wa[x][i].w1,v2=wa[x][i].w2;
		long long ys=gcd(w2,v2);
		long long bs=w2*v2/ys;
		w1=bs/w2*w1+bs/v2*v1;
		w2=bs;
	}
	long long mys=gcd(w1,w2);
	return node(w1/mys,w2/mys);
}
int main() 
{
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		int num;
		scanf("%d",&num);
		for(int j=1,x;j<=num;j++)
		{
			scanf("%d",&x);
			mp[i].push_back(x);
			ou[i]++;
		}
	}
	for(int i=1;i<=m;i++)dfs(i,1,1);
/*	for(int i=1;i<=n;i++)
	{
		if(ou[i]==0)
			for(int j=0;j<wa[i].size();j++)
				cout<<wa[i][j].w1<<"-"<<wa[i][j].w2<<" ";
		cout<<endl;
	}*/
	for(int i=1;i<=n;i++)
	{
		if(ou[i]==0)
		{
			node tmp=chang(i);
			cout<<tmp.w1<<" "<<tmp.w2<<endl;
		}
	}
	return 0;
}
