#include<bits/stdc++.h>
#define _for(i,a,b) for(int i=a;i<b;i++)
#define pb push_back
#define pq priority_queue
#define ff first
#define ss second
#define isnum(c) (('0'<=c)&&(c<='9'))
#define ll long long
#define pii pair<ll,ll>
#define plus fuck
using namespace std;
const int MAXN=1e5+10,INF=2e9+7;
vector<int> edge[MAXN],t;
int N,M,in[MAXN],out[MAXN];
pii sum[MAXN];
queue<int> q;
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
	return;
}
inline ll gcd(ll a,ll b)
{
	if(b==0)
		return a;
	return gcd(b,a%b);
}
inline void yue(pii &a)
{
	int g=gcd(a.ff,a.ss);
	a.ff/=g;
	a.ss/=g;
	return;
}
inline pii plus(pii a,pii b)
{
	pii ret;
	ret.ff=a.ff*b.ss+b.ff*a.ss;
	ret.ss=a.ss*b.ss;
	yue(ret);
	return ret;
}
inline void init()
{
	_for(i,0,MAXN)
		sum[i].ss=1;
	return;
}
inline void input()
{
	read(N);
	read(M);
	int k,v;
	_for(u,1,N+1)
	{
		read(k);
		if(k==0)
			t.pb(u);
		_for(i,0,k)
		{
			read(v);
			edge[u].pb(v);
			in[v]++;
			out[u]++;
		}
	}
	return;
}
inline void solve()
{
	_for(i,1,M+1)
	{
		sum[i].ff=sum[i].ss=1;
		q.push(i);
	}
	int u,v;
	pii sum0;
	while(!q.empty())
	{
		u=q.front();
		q.pop();
		sum0=sum[u];
		sum0.ss*=out[u];
		yue(sum0);
		_for(i,0,edge[u].size())
		{
			v=edge[u][i];
			in[v]--;
			if(!in[v])
				q.push(v);
			sum[v]=plus(sum0,sum[v]);
		}
	}
	return;
}
inline void print()
{
	_for(i,1,N+1)
		if(!out[i])
			printf("%lld %lld\n",sum[i].ff,sum[i].ss);
	return;
}
int main()
{
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	init();
	input();
	solve();
	print();
	return 0;
}
