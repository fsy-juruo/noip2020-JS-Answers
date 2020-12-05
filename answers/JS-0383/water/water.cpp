#include <bits/stdc++.h>
using namespace std;
int n,m,a[100010];
vector<int> edges[100010];
bool wtrin[100010];
struct num
{
	long long p,q;
	num()
	{
		p=0; q=1;
	}
	num(long long a,long long b)
	{
		p=a; q=b;
	}
};
num wtr[100010];
long long gcd(const long long &a,const long long &b)
{
	if(a%b==0) return b;
	return gcd(b,a%b);
}
void yuefen(num &a)
{
	int t=gcd(a.p,a.q);
	a.p/=t;
	a.q/=t;
}
num add(const num &a,const num &b)
{
	long long t=gcd(a.q,b.q);
	num ans=num(a.p*(b.q/t)+b.p*(a.q/t),a.q/t*b.q);
	yuefen(ans);
	return ans;
}
void bfs(int p)
{
	num t;
	queue<int> r;
	bool inque[100010]={0};
	r.push(p);
	inque[p]=1;
	while(!r.empty())
	{
		p=r.front();
		if(a[p]==0)
		{
			r.pop();
			inque[p]=0;
			continue;
		}
		t.p=wtr[p].p;
		t.q=wtr[p].q*(long long)(a[p]);
		yuefen(t);
		for(int i=0;i<a[p];++i)
		{
			wtr[edges[p][i]]=add(wtr[edges[p][i]],t);
			if(!inque[edges[p][i]])
			{
				inque[edges[p][i]]=1;
				r.push(edges[p][i]);
			}
		}
		r.pop();
		inque[p]=0;
		wtr[p]=num();
	}
}
int main()
{
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	scanf("%d%d",&n,&m);
	int t;
	for(int i=1;i<=n;++i)
	{
		scanf("%d",a+i);
		for(int j=1;j<=a[i];++j)
		{
			scanf("%d",&t);
			wtrin[t]=1;
			edges[i].push_back(t);
		}
	}
	for(int i=1;i<=n;++i)
	{
		if(wtrin[i]==0)
		{
			wtr[i]=num(1,1);
		}
	}
	for(int i=1;i<=n;++i)
	{
		if(wtrin[i]==0)
		{
			bfs(i);
		}
	}
	for(int i=1;i<=n;++i)
	{
		if(a[i]==0) printf("%lld %lld\n",wtr[i].p,wtr[i].q);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
