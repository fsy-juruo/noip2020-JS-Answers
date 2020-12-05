#include<bits/stdc++.h>
using namespace std;
int n,m;

struct node
{
	long long son,moth;
}val[100010];

long long gcd(long long u,long long v)
{
	if(u<v) swap(u,v);
	if(v==0) return u;
	return gcd(v,u%v);
}

node add(node p,node q)
{
	long long lcm=p.moth/gcd(p.moth,q.moth)*q.moth;
	node r;
	r.moth=lcm;
	r.son= lcm/p.moth*p.son + lcm/q.moth*q.son;
	
	long long tmp=gcd(r.moth,r.son);
	r.son/=tmp;
	r.moth/=tmp;
	
	return r;
}

node divi(node p,int q)
{
	p.moth*=q;
	long long tmp=gcd(p.moth,p.son);
	p.son/=tmp;
	p.moth/=tmp;
	return p;
}

vector<int> vec[100010];
int deg1[100010],deg2[100010];
queue<int> q;

int main()
{
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&deg2[i]);
		for(int j=1;j<=deg2[i];j++)
		{
			int a;
			scanf("%d",&a);
			vec[i].push_back(a);
			deg1[a]++;
		}
	}
	
	for(int i=1;i<=m;i++) q.push(i),val[i].son=val[i].moth=1;
	
	for(int i=m+1;i<=n;i++) val[i].moth=1;

	while(!q.empty())
	{
		
		int u=q.front();
		q.pop();
		if(deg2[u]==0) continue;
		
		node now=divi(val[u],deg2[u]);
		for(int i=0;i<vec[u].size();i++) 
		{
			
			val[vec[u][i]]=add(now,val[vec[u][i]]);
			deg1[vec[u][i]]--;
			if(deg1[vec[u][i]]==0) q.push(vec[u][i]);
		}
	}
	
	for(int i=1;i<=n;i++)
		if(deg2[i]==0) printf("%lld %lld\n",val[i].son,val[i].moth);
	
	return 0;
}
