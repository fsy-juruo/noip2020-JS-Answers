#include<bits/stdc++.h>
#define int long long 
using namespace std;
const int N = 1e5+5;
int n,m;
int outdeg[N],indeg[N];
int v;
vector<int> ver[N];
inline int gcd(int a,int b)
{
	return b?gcd(b,a%b):a;
}
queue<int> q;
int fm[N],fz[N];
inline void pluss(int x,int y)
{
	fm[x]*=outdeg[x];
	fz[y]=fz[x]*fm[y]+fm[x]*fz[y];
	fm[y]*=fm[x];
	int tt=gcd(fz[y],fm[y]);
	fz[y]/=tt,fm[y]/=tt;
	fm[x]/=outdeg[x];
}
signed main()
{
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;++i)
	{
		scanf("%lld",&outdeg[i]);
		for(int j=1;j<=outdeg[i];++j)
		{
			scanf("%lld",&v);
			++indeg[v];
			ver[i].push_back(v);
		}
	}
	for(int i=1;i<=m;++i) q.push(i),fm[i]=fz[i]=1;
	for(int i=m+1;i<=n;++i) fm[i]=1;
	while(!q.empty())
	{
		int p=q.front();
		q.pop();
		for(int i=0;i<ver[p].size();++i)
		{
			int to=ver[p][i];
			pluss(p,to);
			--indeg[to];
			if(!indeg[to]) q.push(to);
		}
	}
	for(int i=1;i<=n;++i) if(!outdeg[i]) printf("%lld %lld\n",fz[i],fm[i]);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
