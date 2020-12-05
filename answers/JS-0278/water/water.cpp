#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int N=100000+5;
int d[N][15],rd[N];
int n,m,mi[N],cnt;
ll fz[N],fm[N];
bool vis[N];

ll gcd(ll a,ll b)
{
	if(!b) return a;
	return gcd(b,a%b);
}

void bfs(int s)
{
	queue<pair<int,ll> > q;
	q.push(make_pair(s,1));
	while(!q.empty())
	{
		int x=q.front().first;
		ll num=q.front().second;
		q.pop();
		for(int i=1;i<=d[x][0];++i)
		{
			int y=d[x][i];ll nn=num*(ll)d[x][0];
			q.push(make_pair(y,nn));
			if(mi[y]&&vis[mi[y]]) 
			{	
			    int g=gcd(fz[mi[y]]*nn,fm[mi[y]]*nn+fz[mi[y]]);
			    fm[mi[y]]=(fm[mi[y]]*nn+fz[mi[y]])/g;
			    fz[mi[y]]=(fz[mi[y]]*nn)/g;	
			} 
			else 
			{
				fm[mi[y]]=1;
				fz[mi[y]]=nn;
				vis[mi[y]]=true;
			}
		}
	}
}

int main()
{
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i)
	{
		scanf("%d",&d[i][0]);
		if(!d[i][0]) mi[i]=++cnt;
		for(int j=1;j<=d[i][0];++j)
		{
			 scanf("%d",&d[i][j]);
			 rd[d[i][j]]++;
	    }
	}
	for(int i=1;i<=n;++i)
	    if(!rd[i]) bfs(i);
	for(int i=1;i<=cnt;++i)
		printf("%lld %lld\n",fm[i],fz[i]);
	return 0;
}
