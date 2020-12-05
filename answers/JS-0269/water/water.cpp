//AFO
/*
	Accepted
	Wrong Answer
	Compile Error
	Time Limited Error
	Memory Limited Error
	Unknown Error
	Runtime Error
*/
/*
	puzzing!
*/
//utmost_DT

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define maxn 100010
inline int read()
{
	char c;int sign=1;
	while((c=getchar())<'0'||c>'9') if(c=='-') sign=-1;
	int ret=c-'0';
	while((c=getchar())>='0'&&c<='9') ret=ret*10+c-'0';
	return ret*sign;
}
int n,m;
struct ed
{
	int u,v;
};
struct sum
{
	ll a1,a2;
};
sum a[maxn];
vector<ed>g[maxn];
vector<int>l;
void bfs();
void plu(ll,ll,ll);
queue<int>q;
int vis[maxn];
int main()
{
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	n=read();
	m=read();
	for(int i=1;i<=n;i++)
	{
		a[i].a1=0;
		a[i].a2=1;
	}
	for(int i=1;i<=m;i++)
	{
		a[i].a1=1;
		a[i].a2=1;
	}
	for(int i=1;i<=n;i++)
	{
		int x=read();
		if(x==0)
		{
			l.push_back(i);
			continue;
		}
		for(int j=1;j<=x;j++)
		{
			int y=read();
			ed z;
			z.u=i;
			z.v=y;
			g[i].push_back(z);
		}
	}
	bfs();
/*	for(int i=1;i<=n;i++)
	{
		int an1=a[i].a1;
		int an2=a[i].a2;
		for(int i=2;i<=an1;i++)
		{
			if(an1%i==0)
			{
				if(an2%i==0)
				{
					an1=an1/i;
					an2=an2/i;
				}
			}
		}
		cout<<an1<< " ";
		cout<<an2<<endl;
	}
	cout<<endl<<endl;
	*/
	for(int i=0;i<l.size();i++)
	{
		int an1=a[l[i]].a1;
		int an2=a[l[i]].a2;
		for(int i=2;i<=an1;i++)
		{
			if(an1%i==0)
			{
				if(an2%i==0)
				{
					an1=an1/i;
					an2=an2/i;
				}
			}
		}
		cout<<an1<< " ";
		cout<<an2<<endl;
	}
	return 0;
}
void bfs()
{
		
	for(int i=1;i<=m;i++)
	{
		q.push(i);
	}
	while(!q.empty())
	{
		int x=q.front();
		q.pop();
		int am=g[x].size();
		ll am1=a[x].a1;
		ll am2=a[x].a2;
		if(am==0)
		{
			continue;
		}
		am2*=am;
		for(int i=2;i<=am1;i++)
		{
			if(am1%i==0)
			{
				if(am2%i==0)
				{
					am1=am1/i;
					am2=am2/i;
				}
			}
		}
		for(int i=0;i<g[x].size();i++)
		{
			ll y=g[x][i].v;
			plu(y,am1,am2);
			if(vis[y]==0)
			{
				q.push(y);
				vis[y]=1;
			}
			
		}
	}
	
}
void plu(ll x,ll x1,ll x2)
{
	int an1=a[x].a1;
	int an2=a[x].a2;
	an1*=x2;x1*=an2;
	an2*=x2;
	
	
	an1+=x1;
	for(int i=2;i<=an1;i++)
	{
		if(an1%i==0)
		{
			if(an2%i==0)
			{
				an1=an1/i;
				an2=an2/i;
			}
		}
	}
	a[x].a1=an1;
	a[x].a2=an2;
}

