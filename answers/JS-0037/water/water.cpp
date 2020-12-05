#include <bits/stdc++.h>
#define ll long long
const int MAXN=100005;
using namespace std;
inline void read(int &x)
{
	short negative=1;
	x=0;
	char c=getchar();
	while (c<'0' || c>'9')
	{
		if (c=='-')
			negative=-1;
		c=getchar();
	}
	while (c>='0' && c<='9')
		x=(x<<3)+(x<<1)+(c^48),c=getchar();
	x*=negative;
}
inline void print(ll x)
{
	if (x<0)
		putchar('-'),x=-x;
	if (x>9)
		print(x/10);
	putchar(x%10+'0');
}
inline ll gcd(ll a,ll b){return b==0?a:gcd(b,a%b);}
inline ll lcm(ll a,ll b){return a*b/gcd(a,b);}
struct frac
{
	ll p,q;
	inline void init(ll x){p=x,q=1;}
	inline void yuefen(void)
	{
		ll g=gcd(p,q);
		p/=g,q/=g;
	}
	inline void heibing(frac x)
	{
		ll l=lcm(q,x.q);
		p=p*(l/q)+x.p*(l/x.q),q=l;
		yuefen();
	}
	inline void pri(void){print(p),putchar(' '),print(q),putchar('\n');}
}a[MAXN],qaq;
int n,m,i,j,d,x,u,v,in[MAXN];
vector<int> G[MAXN],b,ans;
queue<int> q;
signed main(void)
{
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	read(n),read(m);
	for (i=1;i<=n;i++)
	{
		read(d);
		if (!d)
			ans.push_back(i);
		for (j=1;j<=d;j++)
		{
			read(x);
			in[x]++;
			G[i].push_back(x);
		}
	}
	for (i=1;i<=n;i++)
		if (!in[i])
			q.push(i),b.push_back(i);
	while (!q.empty())
	{
		u=q.front();
		q.pop();
		for (i=0;i<G[u].size();i++)
		{
			v=G[u][i];
			in[v]--;
			if (!in[v])
				q.push(v),b.push_back(v);
		}
	}
	for (i=1;i<=m;i++)
		a[i].init(1);
	for (i=m+1;i<=n;i++)
		a[i].init(0);
	for (j=0;j<b.size();j++)
	{
		u=b[j];
		qaq=a[u];
		qaq.q*=G[u].size();
		qaq.yuefen();
		for (i=0;i<G[u].size();i++)
		{
			v=G[u][i];
			a[v].heibing(qaq);
		}
	}
	for (i=0;i<ans.size();i++)
		a[ans[i]].pri();
	return 0;
}
