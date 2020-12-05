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
const int mod=1e9+7;

struct Int
{
	int x;
	Int(){x=0;}
	Int(int a){x=a%mod;}
	Int(ll a){x=a%mod;}
	Int& operator += (const Int &a)
	{
		x+=a.x;
		if(x>=mod) x-=mod;
		return (*this);
	}
	Int operator + (const Int &a)
	{
		return Int(*this)+=a;
	}
	Int& operator *= (const Int &a)
	{
		x=1LL*x*a.x%mod;
		return (*this);
	}
	Int operator * (const Int &a)
	{
		return Int(*this)*=a;
	}
};

int n,k;
int w[500005];
int dir[500005];
int a[500005];
int l[15];
int r[15];
int cl[15];
int cr[15];
Int res;

int main()
{
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
//	freopen("input.txt","r",stdin);
	scanf("%d%d",&n,&k);
	int maxTurns=0;
	for(int i=0;i<k;i++)
	{
		scanf("%d",w+i);
		cl[i]=l[i]=1;
		cr[i]=r[i]=w[i];
		chmax(maxTurns,w[i]+1);
	}
	for(int i=0;i<n;i++)
	{
		scanf("%d%d",dir+i,a+i);
		dir[i]--;
	}
	int allEnd=false;
	Int steps=0;
	for(int turn=0;turn<=maxTurns;turn++)
	{
		for(int i=0;i<n;i++)
		{
			steps+=1;
			cl[dir[i]]+=a[i];
			cr[dir[i]]+=a[i];
			if(cl[dir[i]]>l[dir[i]])
			{
				l[dir[i]]=cl[dir[i]];
				Int mj=1;
				for(int d=0;d<k;d++)
				{
					if(d==dir[i]) continue;
					mj*=Int(r[d]-l[d]+1);
				}
				res+=steps*mj;
				if(l[dir[i]]>r[dir[i]])
				{
					allEnd=true;
					break;
				}
			}
			if(cr[dir[i]]<r[dir[i]])
			{
				r[dir[i]]=cr[dir[i]];
				Int mj=1;
				for(int d=0;d<k;d++)
				{
					if(d==dir[i]) continue;
					mj*=Int(r[d]-l[d]+1);
				}
				res+=steps*mj;
				if(l[dir[i]]>r[dir[i]])
				{
					allEnd=true;
					break;
				}
			}
		}
		if(allEnd) break;
	}
	if(!allEnd)
	{
		cout<<-1<<endl;
		return 0;
	}
	cout<<res.x<<endl;
	return 0;
}
