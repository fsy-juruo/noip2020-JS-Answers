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
int a[55][405];
int len[55];
vector <pii> res;

inline void push(int x,int y)
{
	a[y][len[y]++]=a[x][--len[x]];
	res.push_back(mp(x,y));
}

inline void solve2(int pos,int id,int npos,int tpos)
{
//	cout<<pos<<' '<<id<<' '<<npos<<' '<<tpos<<endl;
	assert(len[npos]==0);
	int cnt=0;
	for(int i=0;i<len[pos];i++)
	{
		cnt+=(a[pos][i]==id);
	}
	for(int i=0;i<cnt;i++)
	{
		push(tpos,npos);
	}
	int lst=len[pos];
	for(int i=len[pos]-1;i>=0;i--)
	{
		if(a[pos][i]==id)
		{
			for(int j=lst-1;j>i;j--)
			{
				push(pos,npos);
			}
			lst=i;
			push(pos,tpos);
		}
	}
	while(len[npos]>cnt)
	{
		push(npos,pos);
	}
	for(int i=0;i<cnt;i++)
	{
		push(tpos,pos);
	}
	for(int i=0;i<cnt;i++)
	{
		push(npos,tpos);
	}
}

inline void solve(int k)
{
	for(int i=0;i<=k;i++)
	{
		solve2(i,k,k+1,(i!=0?0:(1!=k+1?1:n)));
	}
	for(int i=0;i<=k;i++)
	{
		while(len[i] && a[i][len[i]-1]==k)
		{
			push(i,k+1);
		}
	}
	assert(len[k+1]==m);
	for(int i=0;i<k;i++)
	{
		while(len[i]!=m) push(k,i);
	}
}

inline void print()
{
	cout<<res.size()<<endl;
	for(int i=0;i<(int)res.size();i++)
	{
		printf("%d %d\n",res[i].first+1,res[i].second+1);
	}
}

int main()
{
	freopen("ball.in","r",stdin);
	freopen("ball.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		len[i]=m;
		for(int j=0;j<m;j++)
		{
			scanf("%d",a[i]+j);
			a[i][j]--;
		}
	}
	for(int i=n-1;i>=0;i--)
	{
		solve(i);
	}
	print();
	return 0;
}
