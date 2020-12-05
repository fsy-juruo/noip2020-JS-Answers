#include<bits/stdc++.h>
#define fi first
#define se second
using namespace std;

typedef long long ll;

const int maxn=100010;
const int maxm=500010;

int n,m,tot;
int deg[maxn],chu[maxn];
int ver[maxm],nxt[maxm],head[maxn];
pair<ll,ll> val[maxn];

vector<int> g;
queue<int> q;

template<typename Tp>
void read(Tp &x)
{
	x=0;int f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}x*=f;
}

void add(int u,int v)
{
	ver[++tot]=v;
	nxt[tot]=head[u];
	head[u]=tot;
}

ll gCd(ll x,ll y)
{
	if(y==0) return x;
	return gCd(y,x%y);
}

void addfs(int x,int y)
{
	if(val[y].fi==0&&val[y].se==0)
	{
		val[y].fi=val[x].fi;
		val[y].se=val[x].se;
		return;
	}
	ll a=val[x].fi,b=val[x].se;
	ll c=val[y].fi,d=val[y].se;
	ll GCd=gCd(a*d+b*c,b*d);
	val[y].fi=(a*d+b*c)/GCd;
	val[y].se=b*d/GCd;
}

void work(int x)
{
	ll GCd=gCd(val[x].fi,val[x].se*chu[x]);
	val[x].fi=val[x].fi/GCd;
	val[x].se=val[x].se*chu[x]/GCd;
}

int main()
{
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	read(n),read(m);
	for(int i=1;i<=n;i++)
	{
		int d;
		read(d);
		if(!d) g.push_back(i);
		chu[i]=d;
		for(int j=1;j<=d;j++)
		{
			int x;
			read(x);
			add(i,x);
			deg[x]++;
		}
	}
	for(int i=1;i<=n;i++) if(!deg[i]) q.push(i),val[i].fi=val[i].se=1;
	while(!q.empty())
	{
		int now=q.front();
		q.pop();
		if(!chu[now]) continue;
		work(now);
		for(int i=head[now];i;i=nxt[i])
		{
			int y=ver[i];
			addfs(now,y);
			deg[y]--;
			if(!deg[y]) q.push(y);
		}
	}
	for(int i=0;i<g.size();i++) printf("%lld %lld\n",val[g[i]].fi,val[g[i]].se);
	return 0;
}
/*
5 1
3 2 3 5
2 4 5
2 5 4
0
0
*/
