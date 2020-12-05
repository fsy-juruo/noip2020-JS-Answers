#include<bits/stdc++.h>
using namespace std;
inline int du()
{
	int x=0,f=1;
	char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') {x=x*10+(int)(ch-'0');ch=getchar();}
	return x*f;
}
vector<int> guan[100010];
vector<int> chu;
int d[100010];
struct node
{
	unsigned long long p,q;
}qwq[100010];
int n,m;
queue<int> q;
int vis[100010];

unsigned long long gcd(unsigned long long a,unsigned long long b)
{
	if (b==0) return a;
	return gcd(b,a%b);
}

inline void bfs()
{
	int i;
	unsigned long long k,e;
	while (q.size())
	{
		int x=q.front();
		q.pop();
		e=gcd(qwq[x].p,qwq[x].q);
		qwq[x].p=qwq[x].p/e;
		qwq[x].q=qwq[x].q/e;
		k=qwq[x].q*d[x];
		for (i=0;i<d[x];++i)
		{
			unsigned long long z=(k*qwq[guan[x][i]].q)/gcd(k,qwq[guan[x][i]].q);
			qwq[guan[x][i]].p=qwq[guan[x][i]].p*(z/qwq[guan[x][i]].q)+qwq[x].p*(z/k);
			qwq[guan[x][i]].q=z;
			if (z>100000000)
			{
				e=gcd(qwq[guan[x][i]].p,qwq[guan[x][i]].q);
				qwq[guan[x][i]].p=qwq[guan[x][i]].p/e;
				qwq[guan[x][i]].q=qwq[guan[x][i]].q/e;
			}
			if (vis[guan[x][i]]==0) 
			{
				q.push(guan[x][i]);
				vis[guan[x][i]]=1;
			}
		}
		if (d[x]>0) 
		{
			qwq[x].p=0;
			qwq[x].q=1;
		}
		vis[x]=0;
	}
	
}

int main()
{
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	int i,j,k;
	n=du();
	m=du();
	for (i=1;i<=n;++i)
	{
		d[i]=du();
		if (d[i]==0)
		{
			chu.push_back(i);
		}
		for (j=1;j<=d[i];++j)
		{
			k=du();
			guan[i].push_back(k);
		}
		if (i<=m)
		{
			qwq[i].p=1;
		}
			else qwq[i].p=0;
		qwq[i].q=1;
	}
	for (i=1;i<=m;++i) q.push(i);
	bfs();
	for (i=0;i<chu.size();++i)
	{
		cout<<qwq[chu[i]].p<<' '<<qwq[chu[i]].q<<endl;
	}

	return 0;
}

