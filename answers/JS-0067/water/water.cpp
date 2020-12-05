#include<bits/stdc++.h>
#define ll long long 
using namespace std;

const int MAXN=100005;
struct node{
	ll p,q;
	node(){}
	node(ll tp,ll tq)
	{
		p=tp;q=tq;
	}
}sum[MAXN];

int n,m;
int d[MAXN];

vector<int> gra[MAXN];
int inde[MAXN];
queue<int> q;

template <typename _T>
inline void read(_T &x)
{
	x=0;char ch=getchar();int sign=0;
	while(ch>'9'||ch<'0') sign|=(ch=='-'),ch=getchar();
	while(ch>='0'&&ch<='9') x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	x= sign? -x:x ; 
}

ll gcd(ll a,ll b)
{
	if(b==0) return a;
	return gcd(b,a%b);
}

void Get(node &x)
{
	if(x.p==0) return ;
	ll D=gcd(x.p,x.q);
	x.p/=D;
	x.q/=D;
}

node add(node x,node y)
{
	if(y.p==0) return x;
	if(x.p==0) return y;
	node res=node(y.p*x.q + y.q*x.p , y.q*x.q);
	Get(res);
	return res;
}

void toposort()
{
	for(int i=1;i<=n;++i)
	{
		if( inde[i]==0 ) 
			q.push(i);
	}
	
	while(!q.empty())
	{
		int u=q.front();q.pop();
		
		node tmp= node ( sum[u].p , sum[u].q * d[u] ) ; 
		Get(tmp);
		for(int i=0;i<gra[u].size();++i)
		{
			int v=gra[u][i];
			sum[v]=add(tmp,sum[v]);	
			if( ( --inde[v]) == 0 ) q.push(v);
		}
	}	
}

void in_put()
{
	read(n);read(m);
	for(int i=1;i<=n;++i)
	{
		read(d[i]);

		for(int j=1,x;j<=d[i];++j)
		{
			read(x);
			gra[i].push_back(x);
			++inde[x];
		}
	}
	for(int i=1;i<=m;++i)
	{
		sum[i]=node(1,1);
	}
}

void out_put()
{
	for(int i=1;i<=n;++i)
	{
		if(d[i]==0)
		{
			cout<<sum[i].p<<' '<<sum[i].q<<endl;
		}
	}
}

int main()
{
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);

	in_put();
	toposort();
	out_put();
	
	
	return 0;
}
