#include<bits/stdc++.h>
using namespace std;
const int MAXM=600005;
const int MAXN=100005;
int n,m;
int tot=0;
int ver[MAXM],head[MAXM],next[MAXM];
int d_i[MAXN];
int v[MAXN];
struct fs
{
	long long p,q;
};
fs f[MAXN];
long long gcd(long long a,long long b)
{
	return b?gcd(b,a%b):a;
}
fs divide(fs x)
{
	fs temp;
	long long a=x.p;
	long long b=x.q;
	long long c=gcd(a,b);
	a=a/c;
	b=b/c;
	temp.p=a;
	temp.q=b;
	return temp;
}
fs add(fs x,fs y)
{
	long long n=x.p;
	long long m=x.q;
	long long b=y.p;
	long long a=y.q;
	long long new_p=a*n+b*m;
	long long new_q=a*m;
	fs temp;
	temp.p=new_p;
	temp.q=new_q;
	temp=divide(temp);
	return temp;
}
void add_edge(int x,int y)
{
	ver[++tot]=y;
	next[tot]=head[x];
	head[x]=tot;
}
void bfs(int st)
{
	queue<int> que;
	que.push(st);
	while(!que.empty())
	{
		int x=que.front();que.pop();
		fs t=f[x];
		if(d_i[x]!=0)
		{
			t.q=t.q*d_i[x];
			t=divide(t);
			f[x].p=0;
			f[x].q=1;
		}
		for(int i=head[x];i;i=next[i])
		{
			int y=ver[i];
			que.push(y);
			f[y]=add(f[y],t);
			f[y]=divide(f[y]);
		}
	}
}
int main()
{
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	memset(v,0,sizeof(v));
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>d_i[i];
		for(int j=1;j<=d_i[i];j++)
		{
			int y;
			cin>>y;
			v[y]=1;
			add_edge(i,y);
		}
	}
	d_i[0]=m;
	for(int i=1;i<=n;i++)
		f[i].q=1;
	for(int i=1;i<=n;i++)
	{
		if(!v[i])
		{
			add_edge(0,i);
		}
	}
	f[0].p=m;f[0].q=1;
	bfs(0);
	for(int x=1;x<=n;x++)
	{
		if(f[x].p>0)
			cout<<f[x].p<<" "<<f[x].q<<endl;
	}
	return 0;
}
