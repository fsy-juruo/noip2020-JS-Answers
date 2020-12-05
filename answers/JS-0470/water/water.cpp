#include<bits/stdc++.h>
using namespace std;

int n,m;
struct Node{
	int v,nex;
}edge[4*100001];
int head[4*100001],cnt;
int out[100001];
bool final[100001],sour[100001];
int ans[100001][2];

void add(int x,int y)
{
	edge[++cnt].v=y;
	edge[cnt].nex=head[x];
	head[x]=cnt;
}

void doit(int pos,int x,int y)
{
	if (ans[pos][0]==0)
	{
		ans[pos][0]=x;
		ans[pos][1]=y;
	}
	else
	{
		if (ans[pos][1]==y)
		{
			ans[pos][0]+=x;
			int rest=__gcd(ans[pos][0],ans[pos][1]);
			while (rest>1)
			{
				ans[pos][0]/=rest;
				ans[pos][1]/=rest;
				rest=__gcd(ans[pos][0],ans[pos][1]);
			}
		}
		else
		{
			ans[pos][0]=ans[pos][0]*y+x*ans[pos][1];
			ans[pos][1]*=y;
			int rest=__gcd(ans[pos][0],ans[pos][1]);
			while (rest>1)
			{
				ans[pos][0]/=rest;
				ans[pos][1]/=rest;
				rest=__gcd(ans[pos][0],ans[pos][1]);
			}
		}
	}
}

int q[4*100001][2];
int f,r;

int main()
{
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;++i)
	{
		scanf("%d",&out[i]);
		if (out[i]==0)
		{
			final[i]=1;
			continue;
		}
		for (int j=1;j<=out[i];++j)
		{
			int x;
			scanf("%d",&x);
			sour[x]=1;
			add(i,x);
		}
	}
	for (int i=1;i<=n;++i)
	  if (sour[i]==0)
	    {
	    	f=0;
	    	r=1;
	    	q[1][0]=i;
	    	q[1][1]=1;
	    	while (f<r)
	    	{
	    		int x=q[++f][0];
	    		int y=q[f][1];
	    		for (int j=head[x];j;j=edge[j].nex)
	    		{
					if (final[edge[j].v]==1)
	    			  doit(edge[j].v,1,out[x]*y);
	    			else
	    			{
	    				q[++r][0]=edge[j].v;
	    				q[r][1]=out[x]*y;
					}
				}
			}
		}
	for (int i=1;i<=n;++i)
	  if (final[i]==1)
	    printf("%d %d\n",ans[i][0],ans[i][1]);
	return 0;
}
//60 1h9min 
