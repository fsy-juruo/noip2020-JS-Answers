#include<bits/stdc++.h>
using namespace std;
const int N=100005;
int n,m,ind[N],vis[N],outd[N],is[N];
struct ANS
{
	int p,q;
};
ANS ans[N];
int gcd(int a,int b)
{
	if(a%b==0) return b;
	return gcd(b,a%b);
}
ANS add(ANS a,ANS b)
{
	int GCD=gcd(a.q,b.q);
	int LCM=a.q*b.q/GCD;
	a.p*=(LCM/a.q);
	b.p*=(LCM/b.q);
	ANS tmp;
	tmp.p=a.p+b.p,tmp.q=LCM;
	GCD=gcd(tmp.p,tmp.q);
	tmp.p/=GCD,tmp.q/=GCD;
	return tmp;
}
vector <int> g[N];
void toposort(int s)
{
	vis[s]=1;
	queue <int> q;
	q.push(s);
	while(!q.empty())
	{
		int fr=q.front();
		q.pop();
		ANS tmp;
		tmp.p=ans[fr].p;
		tmp.q=ans[fr].q;
		if(g[fr].size()>1) tmp.q*=g[fr].size();
		int GCD=gcd(tmp.p,tmp.q);
		tmp.p/=GCD;tmp.q/=GCD;
		for(int i=0;i<g[fr].size();i++) 
		{
			int v=g[fr][i];
			ind[v]--;
			if(ind[v]==0) q.push(v),vis[v]=1;
			ans[v]=add(tmp,ans[v]);
		}
	}
}
int main()
{
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		ans[i].q=1;
		int d;
		scanf("%d",&d);
		if(d==0) is[i]=1;
		while(d--)
		{
			int tmp;
			scanf("%d",&tmp);
			g[i].push_back(tmp);
			ind[tmp]++;
		}
	}
	for(int i=1;i<=n;i++) 
		if(ind[i]==0) 
		{
			g[0].push_back(i);
			ind[i]++;
		}
	ans[0].p=g[0].size();
	ans[0].q=1;
	toposort(0);
	for(int i=1;i<=n;i++)
		if(is[i])
		{
			int GCD=gcd(ans[i].p,ans[i].q);
			printf("%d %d\n",ans[i].p/GCD,ans[i].q/GCD);
		}
	return 0;
}
