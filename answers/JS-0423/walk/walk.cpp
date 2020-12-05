#include<bits/stdc++.h>
#define _for(i,a,b) for(int i=a;i<b;i++)
#define pb push_back
#define pq priority_queue
#define ff first
#define ss second
#define isnum(c) (('0'<=c)&&(c<='9'))
#define ll long long
#define pii pair<int,int>
#define update(a,b) a=max(a,b)
using namespace std;
const int MAXN=5e5+10,MAXK=12,INF=2e9+7,MOD=1e9+7;
int N,K;
int cur[MAXN][MAXK],mi[MAXN][MAXK],ma[MAXN][MAXK],w[MAXK],c[MAXN],d[MAXN],mw,ans;
struct node
{
	int x[MAXK];
	bool operator <(node b) const
	{
		_for(i,1,K+1)
			if(x[i]!=b.x[i])
				return x[i]<b.x[i];
		return 0;
	}
};
set<node> s;
inline void read(int &a)
{
	char c=getchar();
	bool f=0;
	a=0;
	while(!isnum(c))
	{
		f|=(c=='-');
		c=getchar();
	}
	while(isnum(c))
	{
		a=(a<<3)+(a<<1)+c-'0';
		c=getchar();
	}
	a=f?-a:a;
	return;
}
bool check(node n,int d)
{
	int x0;
	_for(k,1,K+1)
	{
		x0=n.x[k];
		if(((x0+mi[d][k])<1)||((x0+ma[d][k])>w[k]))
			return 0;
	}
	return 1;
}
inline void init()
{
	return;
}
inline void input()
{
	read(N);
	read(K);
	_for(i,1,K+1)
		read(w[i]);	
	_for(i,1,N+1)
	{
		read(c[i]);
		read(d[i]);
	}
	return;
}
inline void solve()
{
	ll sum=1;
	_for(i,1,K+1)
		sum*=w[i];
	if(sum>=1e8)
	{
		cout<<"-1"<<endl;
		return;
	}
	_for(i,1,MAXN)
	{
		_for(k,1,K+1)
		{
			ma[i][k]=ma[i-1][k];
			mi[i][k]=mi[i-1][k];
			cur[i][k]=cur[i-1][k];
		}
		cur[i][c[(i-1)%N+1]]+=d[(i-1)%N+1];
		update(ma[i][c[(i-1)%N+1]],cur[i][c[(i-1)%N+1]]);
		mi[i][c[i]]=min(mi[i][c[(i-1)%N+1]],cur[i][c[(i-1)%N+1]]);
	}
	queue<node> q;
	node n0,n1;
	_for(i,1,K+1)
	{
		n0.x[i]=1;
	} 
	q.push(n0);
	while(!q.empty())
	{
		n0=q.front();
		q.pop();
		int l=0,r=MAXN+1,mid;
		while(r-l>1)
		{
			mid=(l+r)>>1;
			if(check(n0,mid))
				l=mid;
			else
				r=mid;
		}
		if(l==MAXN)
		{
			cout<<"-1"<<endl;
			return;
		}
		ans=(ll)((ll)ans+l+1)%MOD;
		_for(k,1,K+1)
		{
			n1=n0;
			n1.x[k]++;
			if((n1.x[k]<=w[k])&&(!s.count(n1)))
			{
				s.insert(n1);
				q.push(n1);
			}
		}
	}
	cout<<ans<<endl;
	return;
}
inline void print()
{
	return;
}
int main()
{
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	init();
	input();
	solve();
	print();
	return 0;
}
