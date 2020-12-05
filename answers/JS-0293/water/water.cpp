#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=100005;
vector<int>a[N];
pair<LL,LL>fl[N];
int d[N],out[N];
bool receive[N];
int n,m,tmp,into,outn=0;

LL gcd(LL a,LL b)
{
	return b?gcd(b,a%b):a;
}

inline void fropt(pair<LL,LL>& c1,pair<LL,LL>c2,bool opt)
{
	LL p=c1.first,q=c1.second,r=c2.first,s=c2.second,nt,nb,ng;
	if(opt) nt=p*s+r*q,nb=q*s;
	else nt=p*r,nb=q*s;
	ng=gcd(nt,nb);
	nt/=ng,nb/=ng;
	c1.first=nt,c1.second=nb;
}

void dfs(int cur,LL r,LL s)
{
	pair<LL,LL>divd=make_pair(1ll,d[cur]),flow=make_pair(r,s);
	if(d[cur]==0)
	{
		fropt(fl[cur],flow,true);
		return;
	}
	fropt(divd,flow,false);
	for(int i=0;i<d[cur];i++)
	  dfs(a[cur][i],divd.first,divd.second);
}

int main()
{
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	  fl[i].first=0,fl[i].second=1;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",d+i);
		if(!d[i]) out[++outn]=i;
		for(int j=1;j<=d[i];j++)
		{
			scanf("%d",&tmp);
			receive[tmp]=true;
			a[i].push_back(tmp);
		}
	}
	for(int i=1;i<=n;i++)
	  if(!receive[i])
	  {
		  into=i;
		  break;
	  }
	dfs(into,1ll,1ll);
	for(int i=1;i<=outn;i++)
	  printf("%lld %lld\n",fl[out[i]].first,fl[out[i]].second);
	return 0;
}
