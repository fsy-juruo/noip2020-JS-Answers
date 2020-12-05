#include<bits/stdc++.h>
#define int long long
using namespace std;
struct node{
	int next;
	int to;
}edge[500005];
int head[100005],cnt,in[100005],tag1[15],tag2[100005],m,cnt2,cnt3,n;
struct frac{
	int p,q;
}ans[100005];
void add(int u,int v)
{
	edge[++cnt].next=head[u];
	edge[cnt].to=v;
	head[u]=cnt;
}
int gcd(int a,int b)
{
	if(a>b) swap(a,b);
	if(a==0) return b;
	else return gcd(b%a,a);
}
void dfs(int u,frac val)
{
	if(ans[u].q==0)
	{
		ans[u].p=val.p;
		ans[u].q=val.q;
	}
	else
	{
		ans[u].p=ans[u].p*(ans[u].q*val.q/gcd(ans[u].q,val.q))/(ans[u].q)+val.p*(ans[u].q*val.q/gcd(ans[u].q,val.q))/(val.q);
		ans[u].q=ans[u].q*val.q/gcd(ans[u].q,val.q);
	}
//	cout<<u<<' '<<ans[u].p<<' '<<ans[u].q<<endl;
	int sum=0;
	for(int i=head[u];i;i=edge[i].next)
		sum++;
	for(int i=head[u];i;i=edge[i].next)
	{
		int v=edge[i].to;
		dfs(v,(frac){val.p,val.q*sum});
	}
}
int read()
{
	int x=0;char c=getchar();
	while(c<'0'||c>'9') c=getchar();
	while(c>='0'&&c<='9') x=(x<<1)+(x<<3)+(c-'0'),c=getchar();
	return x;
}
signed main()
{
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=n;i++)
	{
		int d=read();
		if(d==0) tag2[++cnt3]=i;
		while(d--)
		{
			int x=read();
			in[x]++;
			add(i,x);
		}
	}
	for(int i=1;i<=n;i++)
		if(!in[i])
			tag1[++cnt2]=i;
	for(int i=1;i<=m;i++)
		dfs(tag1[i],(frac){1,1});
	for(int i=1;i<=cnt3;i++)
	{
		int qwq=gcd(ans[tag2[i]].p,ans[tag2[i]].q);
		printf("%lld %lld\n",ans[tag2[i]].p/qwq,ans[tag2[i]].q/qwq);
	}
}
