#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN=100005;
int n,m;
int d[MAXN],adj[MAXN][10];
ll p[MAXN],q[MAXN];
ll gcd(ll x,ll y)
{
	if(y==0ll)return x;
	else return gcd(y,x%y);
}
void dfs(int pre,int pst)
{
//	cout<<pre<<endl;
//	cout<<p[pre]<<' '<<q[pre]<<endl;
	if(d[pre]==0)return;
	for(int i=0;i<d[pre];i++)
	{
		int to=adj[pre][i];
		if(to==pst)continue;
		p[to]*=q[pre]*d[pre];
		p[to]+=q[to]*p[pre];
		q[to]*=q[pre]*d[pre];
		ll x=gcd(p[to],q[to]);
		p[to]/=x;
		q[to]/=x;
		dfs(to,pre);
	}
	p[pre]=0ll;
	q[pre]=1ll;
}
int main()
{
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",d+i);
		for(int j=0;j<d[i];j++)
			scanf("%d",&adj[i][j]);
	}
	for(int i=1;i<=n;i++)
	{
		p[i]=0ll;
		q[i]=1ll;
	}
	for(int i=1;i<=m;i++)
	{
		p[i]=1ll;
		q[i]=1ll;
		dfs(i,0);
	}
	for(int i=1;i<=n;i++)if(d[i]==0)
		printf("%lld %lld\n",p[i],q[i]);
	return 0;
}
