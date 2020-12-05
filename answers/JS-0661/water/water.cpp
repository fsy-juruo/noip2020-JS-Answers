#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define pii pair<LL,LL>
#define mp make_pair
#define LL long long
const int N=1e5+5;

int n,m;
vector<int> v[N];
int indeg[N];
queue<int> q;
pii ans[N];

LL gcd(LL x,LL y)
{
	if(y==0) return x;
	return gcd(y,x%y);
}
pii Add(pii x,pii y,LL num)
{
	LL a=x.first,b=x.second;
	LL c=y.first,d=y.second;
	LL e=a*d*num+b*c,f=b*d*num;
	LL g=gcd(e,f);
	return mp(e/g,f/g);
}

int main()
{
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		int sz;
		scanf("%d",&sz);
		while(sz--)
		{
			int x; scanf("%d",&x);
			v[i].pb(x);
			indeg[x]++;
		}
	}
	for(int i=1;i<=n;i++)
		ans[i].second=1LL;
	
	for(int i=1;i<=m;i++)
	{
		q.push(i);
		ans[i].first=1LL;
	}
	while(!q.empty())
	{
		int x=q.front(); q.pop();
		for(int i=0;i<v[x].size();i++)
		{
			int y=v[x][i];
			ans[y]=Add(ans[y],ans[x],(LL)v[x].size());
			indeg[y]--; if(!indeg[y]) q.push(y);
		}
	}
	for(int i=1;i<=n;i++)
		if(!v[i].size()) printf("%lld %lld\n",ans[i].first,ans[i].second);
	
	return 0;
}
