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
int n,m;
vector <int> edges[100005];
int out[100005];
int in[100005];
vector<int> order;
int visit[100005];

ll mgcd(ll a,ll b)
{
	if(b==0) return a;
	return mgcd(b,a%b);
}

struct FenShu
{
	ll p;
	ll q;
	FenShu(){p=0;q=1;}
	FenShu(ll a,ll b):p(a),q(b){}
	FenShu operator + (const FenShu &x)
	{
		ll g=mgcd(q,x.q);
		ll nq=q/g*x.q;
		ll np=nq/q*p+nq/x.q*x.p;
		g=mgcd(np,nq);
		np/=g;
		nq/=g;
		return FenShu(np,nq);
	}
	FenShu operator / (int x)
	{
		ll nq=q*x;
		ll np=p;
		ll g=mgcd(np,nq);
		np/=g;
		nq/=g;
		return FenShu(np,nq);
	}
	inline void print()
	{
		printf("%lld %lld\n",p,q);
	}
}res[100005];

void dfs(int x)
{
	visit[x]=1;
	for(int it=0;it<(int)edges[x].size();it++)
	{
		int u=edges[x][it];
		if(visit[u]) continue;
		dfs(u);
	}
	order.push_back(x);
}

int main()
{
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++)
	{
		scanf("%d",out+i);
		for(int j=0;j<out[i];j++)
		{
			int x;
			scanf("%d",&x);
			x--;
			in[x]++;
			edges[i].push_back(x);
		}
	}
	for(int i=0;i<n;i++)
	{
		if(visit[i]) continue;
		dfs(i);
	}
	reverse(order.begin(),order.end());
	for(int it=0;it<n;it++)
	{
		int x=order[it];
		if(x<m) res[x]=FenShu(1,1);
		for(int i=0;i<out[x];i++)
		{
			int u=edges[x][i];
			res[u]=res[u]+(res[x]/out[x]);
		}
	}
	for(int i=0;i<n;i++)
	{
		if(out[i]==0) res[i].print();
	}
	return 0;
}
