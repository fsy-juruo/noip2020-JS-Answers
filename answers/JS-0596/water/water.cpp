#include<bits/stdc++.h>
#define v V[u][i]
using namespace std;

vector <int> V[100050];
int n,m;
struct fs{
	long long fz,fm;
} f[100050];

long long read()
{
	long long k=0;
	char c=getchar();
	while(c<'0'||c>'9')c=getchar();
	while(c>='0'&&c<='9')
	{
		k=(k<<1)+(k<<3)+c-'0';
		c=getchar();
	}
	return k;
}

long long gcd(long long x,long long y)
{
	if(y==0)return x;
	return gcd(y,x%y);
}

fs jia(fs x,fs y)
{
	if(x.fm==0)x.fm=1;
	if(y.fm==0)y.fm=1;
	long long lcm=(x.fm/gcd(x.fm,y.fm)*y.fm);
	x.fz*=lcm/x.fm;
	y.fz*=lcm/y.fm;
	fs k;
	k.fm=lcm,k.fz=x.fz+y.fz;
	long long qwq=gcd(k.fm,k.fz);
	k.fm/=qwq,k.fz/=qwq;
	return k;
}
bool vis[100050];
int tot[100050];
int nex[100050];
void dfs(int u)
{
	vis[u]=1;
	for(int i=0;i<V[u].size();i++)
	{
		if(vis[v])continue;
		tot[v]--;
		fs qaq;
		qaq.fz=f[u].fz,qaq.fm=f[u].fm*nex[u];
		f[v]=jia(f[v],qaq);
		if(tot[v]==0)dfs(v);
	}
}
void output(fs x)
{
	if(x.fm==0)x.fm=1;
	else
	{
		long long qwq=gcd(x.fm,x.fz);
		x.fm/=qwq,x.fz/=qwq;
	}
	cout<<x.fz<<' '<<x.fm<<endl;
}
int main()
{
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=n;i++)
	{
		int y;
		nex[i]=read();
		for(int j=1;j<=nex[i];j++)
		{
			y=read();
			V[i].push_back(y);
			tot[y]++;
		}
	}
	for(int i=1;i<=n;i++)if(!tot[i])f[i].fm=1,f[i].fz=1;
	for(int i=1;i<=n;i++)
	{
		if(!tot[i]&&!vis[i])dfs(i);
		
	}
	for(int i=1;i<=n;i++)
	{
		if(!nex[i])
		{
			output(f[i]);
		}
	}
	return 0;
}

