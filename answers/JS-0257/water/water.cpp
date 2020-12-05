#include<bits/stdc++.h>
using namespace std;

typedef long long lint;

struct node{
	lint p, q;
}inwater[100005];

lint gcds(lint a, lint b) { return (b==0 ? a : gcds(b, a%b)); }
lint lcms(lint a, lint b) { return a*(b/gcds(a, b)); }

node clear(node a)
{
	lint x=gcds(a.p, a.q);
	a.p/=x; a.q/=x;
	return a;
}

node dele(node a, lint b)
{
	a.q*=b;
	return clear(a);
}

node pluss(node a, node b)
{
	node c;
	c.q=lcms(a.q, b.q);
	c.p=(a.p*(c.q/a.q)+b.p*(c.q/b.q));
	return clear(c);
}

lint reads()
{
	char c; lint returns;
	c=getchar();
	while((c<'0' || c>'9') && c!='-') c=getchar();
	returns=c-'0';
	
	c=getchar();
	while(c>='0' && c<='9') returns=returns*10+c-'0', c=getchar();
	
	return returns;
}

vector<lint> g[100005];
lint inums[100005], v[100005];

int main()
{
	
	freopen("water.in", "r", stdin);
	freopen("water.out", "w", stdout);
	
	queue<int> q;
	lint n, m, a;
	lint i, j, k;
	n=reads(), m=reads();
	for(i=1; i<=n; i++) inwater[i].p=0, inwater[i].q=1;
	for(i=1; i<=n; i++)
	{
		k=reads();
		for(j=1; j<=k; j++)
		{
			a=reads();
			g[i].push_back(a);
			inums[a]++;
		}
	}
	for(i=1; i<=n; i++) if(inums[i]==0)
	{
		inwater[i].p=1;
		q.push(i);
	}
	while(!q.empty())
	{
		a=q.front(); q.pop();
		lint nums=g[a].size();
		node x=inwater[a]; x.q*=nums;
		for(i=0; i<nums; i++)
		{
			lint nows=g[a][i];
			v[nows]++;
			inwater[nows]=pluss(inwater[nows], x);
			if(v[nows]==inums[nows]) q.push(nows);
		}
	}
	for(i=1; i<=n; i++) if(g[i].size()==0)
	{
		cout<<inwater[i].p<<" "<<inwater[i].q<<endl;
	}
	
	return 0;
}
