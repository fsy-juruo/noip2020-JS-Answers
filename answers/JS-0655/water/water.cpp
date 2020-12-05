#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1E6+5;
const ll limit=(ll)604661760000000000;
int n,m;
int size,head[maxn];
int TI,what[maxn],deg[maxn],out[maxn];
struct edge
{
	int to,next;
}E[maxn*2];
inline void add(int u,int v)
{
	E[++size].to=v;
	E[size].next=head[u];
	head[u]=size;
}
ll gcd(ll x,ll y)
{
	if(y==0)
		return x;
	return x%y==0?y:gcd(y,x%y);
}
ll f[maxn];
inline void solve()
{
	queue<int>Q;
	for(int i=1;i<=n;++i)
		f[i]=0;
	for(int i=1;i<=m;++i)
		if(deg[i]==0)
		{
			Q.push(i);
			f[i]=limit;
		}
	while(!Q.empty())
	{
		int u=Q.front(),d=0;
		Q.pop();
		what[++TI]=u;
		for(int i=head[u];i;i=E[i].next)
		{
			int v=E[i].to;
			++d;
			--deg[v];
			if(deg[v]==0)
				Q.push(v);
		}
		if(d!=0)
		{
			ll x=f[u]/d;
			for(int i=head[u];i;i=E[i].next)
			{
				int v=E[i].to;
				f[v]+=x;
			}
		}
	}
}
int main()
{
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>n>>m;
	for(int i=1;i<=n;++i)
	{
		int k;
		cin>>k;
		if(k)
			out[i]=1;
		for(int j=1;j<=k;++j)
		{
			int x;
			cin>>x;
			add(i,x);
			++deg[x];
		}
	}
	solve();
	for(int i=1;i<=n;++i)
		if(!out[i])
		{
			ll x=f[i],y=limit;
			ll d=gcd(x,y);
			cout<<x/d<<" "<<y/d<<'\n';
		}
	return 0;
}

