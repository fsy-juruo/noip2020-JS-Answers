#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N=100005;
int n,m;
vector <int> fa[N];
int v[N];
int d[N];

struct dat{
	 ll x,y;
}a[N];

int read()
{
	int n=0,f=1;
	char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') {n=n*10+ch-'0';ch=getchar();}
	return n*f;
}

ll gcd(ll x,ll y)
{
	if (y==0) return x;
	return gcd(y,x%y);
}

void Add(int x,int t1,int t2)
{
	ll p1=a[x].x;
	ll p2=a[x].y;
	if (p2==0)
	{
		a[x].x=t1;
		a[x].y=t2;
		return;
	}
	ll h=gcd(p2,t2);
	ll f1=t2/h;
	ll f2=p2/h;
	ll f=p2*t2/h;
	ll mm=f1*p1+f2*t1;
	a[x].x=mm;
	a[x].y=f;
}

void dfs(int x)
{
	if (a[x].x>0) return;
	for (int i=0;i<fa[x].size();i++)
	{
		int y=fa[x][i];
		dfs(y);
		ll t1=a[y].x;
		ll t2=a[y].y;
		ll t3=a[y].y*ll(v[y]);
		Add(x,t1,t3);
	}
}

ll work(int i)
{
	ll x=a[i].x;
	ll y=a[i].y;
	ll h=gcd(x,y);
	a[i].x=x/h;
	a[i].y=y/h;
}


int main()
{
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	n=read();m=read();
	for (int i=1;i<=n;i++)
	{
		int x;
		x=read();
		if (x==0) continue;
		v[i]=x;
		for (int j=1;j<=x;j++)
		{
			int y;
			cin>>y;
			fa[y].push_back(i);
		}
	}
	for (int i=1;i<=m;i++)
	{
		d[i]=1;
		a[i].x=1;
		a[i].y=1;
	}
	for (int i=1;i<=n;i++)
	{
		if (v[i]==0)
		{
			dfs(i);
			work(i);
			cout<<a[i].x<<" "<<a[i].y<<endl;
		}
	}
	return 0;
}

