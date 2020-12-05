#include<bits/stdc++.h>
#define ll long long
#define N 100010
#define rg register
#define m_p make_pair
using namespace std;
ll n,m,in[N],out[N],f[N][2],a[N];
ll tot,hea[N],nex[N],ver[N];
inline ll read()
{
	ll sum=0,f=1;
	char c=getchar();
	while (c<'0'||c>'9')
	{
		if (c=='-') f=-1;
		c=getchar();
	}
	while (c>='0'&&c<='9')
	{
		sum=sum*10+c-'0';
		c=getchar();
	}
	return f*sum;
}
void add(ll x,ll y)
{
	ver[++tot]=y;nex[tot]=hea[x];hea[x]=tot;
}
void topo()
{
	queue<ll> q;//cout<<q.size()<<endl;
	for (rg int i=1;i<=n;i++) if (!in[i]) q.push(i),f[i][0]=1;
	while (!q.empty())
	{
		ll x=q.front();q.pop();//cout<<x<<' ';
		if (!a[x]) continue;
		for (rg int i=hea[x];i;i=nex[i])
		{
			ll y=ver[i];
			ll p[2]={f[x][0],f[x][1]*a[x]};
			f[y][0]=f[y][0]*p[1]+f[y][1]*p[0];
			f[y][1]=f[y][1]*p[1];
			ll k=__gcd(f[y][0],f[y][1]);
			f[y][0]/=k,f[y][1]/=k;//cout<<y<<' '<<f[y][0]<<' '<<f[y][1]<<endl;
			in[y]--;
			if (!in[y]) q.push(y);
		}
	}
}
int main()
{
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	n=read();m=read();
	for (rg int i=1;i<=n;i++)
	{
		a[i]=read();f[i][0]=0;f[i][1]=1;
		for (rg int j=1;j<=a[i];j++)
		{
			ll y=read();
			add(i,y);in[y]++;out[i]++;
		}
	}
	topo();
	for (rg int i=1;i<=n;i++)
	if (!out[i]) printf("%lld %lld\n",f[i][0],f[i][1]);
	return 0;
}
