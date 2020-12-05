#include<bits/stdc++.h>
#define R register
using namespace std;

struct node
{
	long long a,b;
};
int n,m,k,x,y,qb;
vector <int> c[400100];
vector <int> q;
node s[400100];
node l,p,dx,ls,pl;
long long r,gc,A,B;

long long g(long long a,long long b)
{
	A=a;B=b;
	if (A<B)
	swap(A,B);
	while (B!=0)
	{
		r=A%B;A=B;B=r;
	}
	return A;
}

node tz(node a)
{
	if (a.a==0&&a.b==0)
	return a;
	ls=a;
	gc=g(ls.a,ls.b);
	if (gc!=1)
	{
		ls.a/=gc;ls.b/=gc;
	}
	return ls;
}

node add(node x,node y)
{
	if (x.a==0&&x.b==0)
	return y;
	else
	if (y.a==0&&y.b==0)
	return x;
	pl.b=x.b*y.b;
	pl.a=x.a*y.b+x.b*y.a;
	return tz(pl);
}

void dfs(int x,node nw)
{
	if (c[x].size()==0)
	return;
	for (R int i=0;i<c[x].size();i++)
	{
		ls.b=c[x].size()*nw.b;ls.a=nw.a;l=tz(ls);
		s[c[x][i]]=add(s[c[x][i]],l);
		dfs(c[x][i],l);
	}
}

int main()
{
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin >> n >> m;
	for (R int i=1;i<=n;i++)
	{
		cin >> x;
		if (x==0)
		{
			q.push_back(i);
		}
		for (R int j=1;j<=x;j++)
		{
			cin >> y;
			c[i].push_back(y);
		}
	}
	for (R int i=1;i<=m;i++)
	{
		l.a=1;l.b=1;
		dfs(i,l);
	}
	for (R int i=0;i<q.size();i++)
	{
		cout << s[q[i]].a << ' ' << s[q[i]].b << endl;
	}
	return 0;
}

