#include <bits/stdc++.h>
using namespace std;

const int maxn=100010;

struct frc
{
	long long a,b; // a/b
} w[maxn];

int n,m,cnt[maxn];
vector<int> e[maxn];
queue<int> q;

inline long long mygcd(long long x,long long y)
{
	return (y==0?x:mygcd(y,x%y));
}

inline void frcadd(frc &x,frc y)
{
	x.a=x.a*y.b+x.b*y.a;
	x.b*=y.b;
	
	long long g=mygcd(x.a,x.b);
	x.a/=g;
	x.b/=g;
}

int main()
{
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		int d;scanf("%d",&d);
		while(d--)
		{
			int j;scanf("%d",&j);
			e[i].push_back(j);
			
			cnt[j]++;
		}
	}
	
	for(int i=1;i<=n;i++)
	{
		if(i<=m) w[i].a=1;
		w[i].b=1;
	}
	
	for(int i=1;i<=n;i++) if(cnt[i]==0) q.push(i);
	
	while(!q.empty())
	{
		int u=q.front();q.pop();
		
		frc wt=w[u];
		wt.b*=1ll*e[u].size();
		
		for(int i=0;i<e[u].size();i++)
		{
			int v=e[u][i];
			frcadd(w[v],wt);
			
			cnt[v]--;
			if(cnt[v]==0) q.push(v);
		}
	}
	
	for(int i=1;i<=n;i++) if(e[i].size()==0) printf("%lld %lld\n",w[i].a,w[i].b);

	return 0;
}
