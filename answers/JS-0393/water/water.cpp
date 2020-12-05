#include<bits/stdc++.h>
using namespace std;
const int N=100005;
long long gcd(long long a,long long b){return b?gcd(b,a%b):a;}
struct num
{
	long long p,q;
	num(){}
	num(long long _p,long long _q):p(_p),q(_q){}
}a[N];
num add(num a,num b)
{
	long long x=a.p*b.q+a.q*b.p,y=a.q*b.q,g=gcd(x,y);
	x/=g,y/=g;
	return num(x,y);
}
num div(num a,long long v)
{
	long long x=a.p,y=a.q*v,g=gcd(x,y);
	x/=g,y/=g;
	return num(x,y);
}
int n,m,d[N],q[N],l,r;
vector<int>e[N];
int main()
{
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		int k;
		cin>>k;
		while(k--)
		{
			int x;
			cin>>x;
			e[i].push_back(x);
			d[x]++;
		}
	}
	for(int i=1;i<=m;i++)
		a[i]=num(1,1);
	for(int i=m+1;i<=n;i++)
		a[i]=num(0,1);
	for(int i=1;i<=n;i++)
		if(!d[i])
			q[r++]=i;
	while(l<r)
	{
		int u=q[l++];
		if(e[u].size()==0)
			continue;
		num x=div(a[u],e[u].size());
		for(int i=0;i<(int)e[u].size();i++)
		{
			int v=e[u][i];
			a[v]=add(a[v],x);
			d[v]--;
			if(!d[v])
				q[r++]=v;
		}
	}
	for(int i=1;i<=n;i++)
		if(e[i].size()==0)
			cout<<a[i].p<<' '<<a[i].q<<endl;
	return 0;
}

