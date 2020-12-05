#include <bits/stdc++.h>
using namespace std;

#define int long long

int n,m,a[100005],b[100005];
int ee,h[100005],nex[500005<<1],to[500005<<1];
int cdu[100005],rdu[100005];

void addedge(int x,int y)
{
	nex[++ee] = h[x];
	to[ee] = y;
	h[x] = ee;
}

void addwater(int x,int wa,int wb)
{
	int ra=a[x]*wb+b[x]*wa,rb=b[x]*wb;
	int gcd=__gcd(ra,rb);
	a[x] = ra/gcd, b[x] = rb/gcd;
}

void topo()
{
	queue<int> q;
	for(int i=1;i<=n;i++)
		if(rdu[i]==0)
			q.push(i);
	while(!q.empty())
	{
		int x=q.front();
		q.pop();
		int wa=a[x],wb=b[x]*cdu[x];
		int gcd=__gcd(wa,wb);
		wa /= gcd, wb /= gcd;
		for(int i=h[x];i;i=nex[i])
		{
			addwater(to[i],wa,wb);
			if((--rdu[to[i]])==0)
				q.push(to[i]);
		}
	}
}

signed main()
{
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n&&scanf("%lld",cdu+i);i++)
	{
		for(int j=1,x;j<=cdu[i]&&scanf("%lld",&x);j++)
			addedge(i,x), rdu[x]++;
	}
	for(int i=1;i<=n;i++)
		b[i] = 1;
	for(int i=1;i<=m;i++)
		a[i] = 1;
	topo();
	for(int i=1;i<=n;i++)
		if(cdu[i]==0)
		{
			int gcd=__gcd(a[i],b[i]);
			a[i] /= gcd, b[i] /= gcd;
			printf("%lld %lld\n",a[i],b[i]);
		}
	
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
