#include<bits/stdc++.h>
#define maxn 100010
using namespace std;

inline void read(int &x)
{
	int y=1;
	x=0;
	char ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-')y=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		x=x*10+ch-'0';
		ch=getchar();
	}
	x*=y;
}

inline int gongyue(int x,int y)
{
	if(x<y)swap(x,y);
	if(x%y==0)return y;
	while(x%y!=0)
	{
		x%=y;
		if(x<y)swap(x,y);
	}
	return y;
}

inline void yuefen(int &p,int &q)
{
	int g=gongyue(p,q);
	p/=g;
	q/=g;
}

inline void plus_(int &p,int &q,int ap,int aq)
{
	int g=gongyue(q,aq);
	int fenmu=q/g*aq;
	int fenzi=p*aq/g+ap*q/g;
	yuefen(fenzi,fenmu);
	p=fenzi;
	q=fenmu;
}

int n,m;
int ind[maxn],zi[maxn],mu[maxn];
vector<int> g[maxn];
int print[maxn];

inline void add(int u,int v)
{
	g[u].push_back(v);
}

queue<int> q;
inline void topsort()
{
	for(int i=1;i<=n;i++)
	{
		if(ind[i]==0)
		{
			q.push(i);
			zi[i]=mu[i]=1;
		}
	}
	for(int i=1;i<=n;i++)mu[i]=1;
	while(q.size())
	{
		int u=q.front();
		q.pop();
		int num=g[u].size();
		for(int i=0;i<g[u].size();i++)
		{
			int v=g[u][i];
			plus_(zi[v],mu[v],zi[u],mu[u]*num);
			ind[v]--;
			if(ind[v]==0)q.push(v);
		}
	}
}

int main()
{
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	read(n),read(m);
	int d,v;
	int cnt=0;
	for(int i=1;i<=n;i++)
	{
		read(d);
		for(int j=1;j<=d;j++)
		{
			read(v);
			add(i,v);
			ind[v]++;
		}
		if(d==0)print[++cnt]=i;
	}
	
	topsort();
	
	for(int i=1;i<=cnt;i++)
	{
		int j=print[i];
		printf("%d %d\n",zi[j],mu[j]);
	}
	return 0;
}

