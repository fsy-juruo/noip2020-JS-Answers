#include <bits/stdc++.h>
#define int long long
using namespace std;
int read()
{
	int s=0,w=1;char ch=getchar();
	while (ch<'0'||ch>'9'){if (ch=='-')  w=-w;ch=getchar();}
	while (ch>='0'&ch<='9'){s=(s<<1)+(s<<3)+(ch^'0');ch=getchar();}
	return s*w;
}

int n,m,tmptmp,cnt=0;
int cnt_son[100005],dp1[100005],dp2[100005],inde[100005],head[100005];

struct edge{int next,to;}e[200005];

queue<int> qq;

void add_edge(int u,int v)
{
	cnt++;
	e[cnt].to=v,e[cnt].next=head[u];
	head[u]=cnt;
}

int ducati_gcd(int x,int y)
{
	if (y==0)  return x;
	else return ducati_gcd(y,x%y);
}

void ducati_add(int rt,int x,int y)
{
	int ducati_lcm=(dp2[rt]*y)/ducati_gcd(dp2[rt],y);
	dp1[rt]=(ducati_lcm/dp2[rt])*dp1[rt];
	dp1[rt]+=(ducati_lcm/y)*x;
	dp2[rt]=ducati_lcm;
}

signed main()
{
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	n=read(),m=read();
	for (int i=1;i<=n;i++)
	{
		if (i>m)  dp1[i]=0,dp2[i]=1;
		else dp1[i]=1,dp2[i]=1;
	}
	for (int i=1;i<=m;i++)  qq.push(i);
	for (int i=1;i<=n;i++)
	{
		cnt_son[i]=read();
		for (int j=1;j<=cnt_son[i];j++)
		{
			tmptmp=read();
			add_edge(i,tmptmp);
			inde[tmptmp]++;
		}
	}
	while (!qq.empty())
	{
		int now=qq.front();
		qq.pop();
		
		for (int i=head[now];i;i=e[i].next)
		{
			int y=e[i].to;
			ducati_add(y,dp1[now],dp2[now]*cnt_son[now]);
			inde[y]--;
			
			if (inde[y]==0)  qq.push(y);
		}
	}
	for (int i=1;i<=n;i++)
	{
		tmptmp=ducati_gcd(dp1[i],dp2[i]);
		dp1[i]/=tmptmp;
		dp2[i]/=tmptmp;
	}
	for (int i=1;i<=n;i++)
	{
		if (cnt_son[i]==0)  cout<<dp1[i]<<' '<<dp2[i]<<endl;
	}
	return 0;
}
