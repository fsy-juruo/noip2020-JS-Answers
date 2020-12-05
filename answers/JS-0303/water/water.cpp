#include<bits/stdc++.h>
using namespace std;

const int N=100005;
int n,m,d[N],ch[N][10],rr[N];
struct node{long long p,q;}f[N];
queue<int> q;

long long gcd(long long a,long long b)
{
	while(b)
	{
		long long r=a%b;
		a=b,b=r;
	}
	return a;
}

node div(node a,long long b)
{
	node res;
	res.p=a.p,res.q=a.q*b;
	long long gd=gcd(res.p,res.q);
	res.p/=gd,res.q/=gd;
	return res;
}

node add(node a,node b)
{
//	cout<<a.p<<' '<<a.q<<' '<<b.p<<' '<<b.q<<endl;
	long long gd=gcd(a.q,b.q);
	long long lm=a.q/gd*b.q;
	node res;
	res.q=lm;
	res.p=a.p*(res.q/a.q);
	res.p+=b.p*(res.q/b.q);
	gd=gcd(res.p,res.q);
	res.p/=gd,res.q/=gd;
	return res;
}

int main()
{
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&ch[i][0]);
		for(int j=1;j<=ch[i][0];j++)
		{
			scanf("%d",&ch[i][j]);
			d[ch[i][j]]++;
		}
		f[i].p=0,f[i].q=1;
	}
	for(int i=1;i<=m;i++)
	{
		f[i].p=f[i].q=1;
		q.push(i);
	}
	while(!q.empty())
	{
		int u=q.front();
		q.pop();
		if(!ch[u][0]) continue;
		node w=div(f[u],ch[u][0]);
//		cout<<u<<' '<<f[u].p<<' '<<f[u].q<<endl;
		for(int i=1;i<=ch[u][0];i++)
		{
			int v=ch[u][i];
			f[v]=add(f[v],w);
			if(--d[v]==0) q.push(v);
		}
	}
	for(int i=m+1;i<=n;i++)
	{
		if(!ch[i][0])
		{
			printf("%lld %lld\n",f[i].p,f[i].q);
		}
	}
}
