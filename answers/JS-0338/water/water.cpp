#include <bits/stdc++.h>
using namespace std;
int n,m;
struct node{
	int fenzi,fenmu;
}a[100001];
vector<vector<int> >v;
vector<int>empv,v1;
queue<int>q;
int gcd(int x,int y)
{
	if (x==0)
	return y;
	if (y==0)
	return x;
	int ys=x%y;
	while (ys!=0)
	{
		x=y;
		y=ys;
		ys=x%y;
	}
	return y;
}
int lcm(int x,int y)
{
	return x/gcd(x,y)*y;
}
node fsjia(node a,node b)
{
	int gcda=gcd(a.fenmu,a.fenzi),gcdb=gcd(b.fenmu,b.fenzi);
	a.fenzi/=gcda;
	a.fenmu/=gcda;
	b.fenzi/=gcdb;
	b.fenmu/=gcdb;
	int ca=lcm(a.fenmu,b.fenmu)/a.fenmu,cb=lcm(a.fenmu,b.fenmu)/b.fenmu;
	node c;
	c.fenmu=lcm(a.fenmu,b.fenmu);
	c.fenzi=a.fenzi*ca+b.fenzi*cb;
	int gcdc=gcd(c.fenmu,c.fenzi);
	c.fenzi/=gcdc;
	c.fenmu/=gcdc;
	return c;
}
node fschu(node a,int b)
{
	int gcda=gcd(a.fenmu,a.fenzi);
	a.fenzi/=gcda;
	a.fenmu/=gcda;
	node c;
	c.fenmu=a.fenmu*b;
	c.fenzi=a.fenzi;
	int gcdc=gcd(c.fenmu,c.fenzi);
	c.fenzi/=gcdc;
	c.fenmu/=gcdc;
	return c;
}
int main()
{
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	scanf("%d%d",&n,&m);
	for (int i=0;i<n;i++)
	{
		int k;
		scanf("%d",&k);
		if (k==0)
		v1.push_back(i);
		v.push_back(empv);
		for (int j=0;j<k;j++)
		{
			int l;
			scanf("%d",&l);
			l--;
			v[i].push_back(l);
		}
		a[i].fenmu=1;
	}
	for (int i=0;i<m;i++)
	{
		a[i].fenmu=1;
		a[i].fenzi=1;
		q.push(i);
	}
	while (!q.empty())
	{
		int f=q.front();
		q.pop();
		for (int i=0;i<v[f].size();i++)
		{
			a[v[f][i]]=fsjia(a[v[f][i]],fschu(a[f],v[f].size()));
			q.push(v[f][i]);
		}
		if (v[f].size()!=0)
		{
			a[f].fenzi=0;
			a[f].fenmu=1;
		}
	}
	for (int i=0;i<v1.size();i++)
	cout<<a[v1[i]].fenzi<<" "<<a[v1[i]].fenmu<<endl;
	return 0;
}
