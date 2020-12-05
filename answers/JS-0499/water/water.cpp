#include<bits/stdc++.h>
using namespace std;
struct ins{
	template<typename T>void read(T &n)
	{
		n=0;char c=getchar();bool f=1;
		while(!isdigit(c)){if(c=='-')f=0;c=getchar();}
		while(isdigit(c)){n=n*10+c-'0';c=getchar();}
		if(f==0)n=-n;
	}
	template<typename T>ins operator >>(T &n)
	{
		this->read(n);
		return *this;
	}
}yin;
long long gcd(long long a,long long b)
{
	if(b==0)return a;
	return gcd(b,a%b);
}
const int maxn=1e5+10;
struct fs{
	long long a,b;
	friend fs operator /(fs c,long long d)
	{
		fs a;
		a.a=c.a;a.b=c.b;
		a.b*=d;
		long long gc=gcd(a.a,a.b);
		a.a/=gc;a.b/=gc;
		return a;
	}
	friend fs operator +(fs a,fs b)
	{
		fs c;
		c.a=a.a*b.b+a.b*b.a;
		c.b=a.b*b.b;
		long long gc=gcd(c.a,c.b);
		c.a/=gc;c.b/=gc;
		return c;
	}
}f[maxn];
int n,m;
int d[maxn];
vector<int> v[maxn];
queue<int> q;
int vis[maxn];
int main()
{
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>d[i];
		for(int j=1;j<=d[i];j++)
		{
			int x;
			cin>>x;
			v[i].push_back(x);++vis[x];
		}
	}
	for(int i=1;i<=n;i++)
	{
		f[i].b=1;
	}
	for(int i=1;i<=m;i++)
	{
		q.push(i);
		f[i].a=1;
//		f[i].b=1;
	}
	while(!q.empty())
	{
		int u=q.front();
		q.pop();
		if(d[u]==0)continue;
		fs c=f[u]/d[u];
		for(int i=0;i<d[u];i++)
		{
			--vis[v[u][i]];
			if(!vis[v[u][i]])
			{
				q.push(v[u][i]);
			}
			f[v[u][i]]=f[v[u][i]]+c;
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(!d[i])
		{
			cout<<f[i].a<<" "<<f[i].b<<endl;
//			ans=ans+f[i];
		}
	}
//	cout<<ans.a<<" "<<ans.b<<endl;
	return 0;
}

