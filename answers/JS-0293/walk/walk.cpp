#include <bits/stdc++.h>
using namespace std;
const int K=15;
const int N=500005;
const int mod=1000000007;
int c[N],d[N],w[K],now[K],t[K];
int n,k,ans=0;

int calc()
{
	int anss=0;
	for(int i=1;i<=k;i++)
	  t[i]=now[i];
	for(int ii=1;;ii++)
	{
		int i=(ii-1)%n+1;
		t[c[i]]+=d[i],(anss+=1)%=mod;
		if(t[c[i]]>w[c[i]]||t[c[i]]<1) return anss;
	}
	return anss;
}

void dfs(int dim)
{
	if(dim>k)
	{
		(ans+=calc())%=mod;
		return;
	}
	for(int i=1;i<=w[dim];i++)
	{
		now[dim]=i;
		dfs(dim+1);
	}
}

void subtask1()
{
	dfs(1);
}

int main()
{
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=k;i++)
	  scanf("%d",w+i);
	for(int i=1;i<=n;i++)
	  scanf("%d%d",c+i,d+i);
	if(k>1000) puts("-1");
	else subtask1();
	printf("%d\n",ans);
	return 0;
}
