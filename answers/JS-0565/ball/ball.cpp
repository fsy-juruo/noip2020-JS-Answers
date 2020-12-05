#include<bits/stdc++.h>
using namespace std;

int b[55][505];
int opt[1050505][2];
int total;
int e[505];
int top[55];
int n,m;

void solve(int v,int tarpos,int u,int pos)
{
	if (u==v)
	{
		opt[++total][0]=u+1;
		opt[total][1]=n+1;
		opt[++total][0]=v;
		opt[total][1]=u+1;
		opt[++total][0]=n+1;
		opt[total][1]=u;
		u=u+1;
		pos=m;
	}
	while (top[u]!=pos) 
	{
		opt[++total][0]=u;
		opt[total][1]=n+1;
		top[n+1]++;
		e[top[n+1]]=b[u][top[u]];
		top[u]--;
	}
	while ((top[v]+1)!=tarpos && top[n+1]<m)
	{
		opt[++total][0]=v;
		opt[total][1]=n+1;
		top[n+1]++;
		e[top[n+1]]=b[v][top[v]];
		top[v]--;
	}
	if (top[v]+1==tarpos && top[u]==pos) 
	{
		opt[++total][0]=u;
		opt[total][1]=v;
		top[v]++;
		b[v][top[v]]=b[u][top[u]];
		top[u]--;
	}
	else
	{
		top[u]--;
		top[v]++;
		b[v][top[v]]=e[m];
		e[m]=b[u][pos];
		opt[++total][0]=n+1;
		opt[total][1]=v;
		opt[++total][0]=u;
		opt[total][1]=n+1;
		while ((top[v]+1)!=tarpos)
		{
			opt[++total][0]=v;
			opt[total][1]=u;
			top[u]++;
			b[u][top[u]]=b[v][top[v]];
			top[v]--;
		}
		top[v]++;
		b[v][top[v]]=e[m];
		top[n+1]--;
		opt[++total][0]=n+1;
		opt[total][1]=v;
	}
	while (top[n+1]>0)
	{
		while (top[u]<m&&top[n+1]>0) {b[u][++top[u]]=e[top[n+1]];opt[++total][0]=n+1;opt[total][1]=u;}
		while (top[v]<m&&top[n+1]>0) {b[v][++top[v]]=e[top[n+1]];opt[++total][0]=n+1;opt[total][1]=v;}
	}
	return;
}

int main()
{
	freopen("ball.in","r",stdin);
	freopen("ball.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=m;j++)
		{
			cin>>b[i][j];
			top[i]=m;
		}
	}
	top[n+1]=0;
	for (int i=1;i<=n-1;i++)
	{
		for (int j=1;j<=m;j++)
		{
			if (b[i][j]!=i)
			{
				for (int tarj=j+1;tarj<=m;tarj++) if (b[i][tarj]==i) {solve(i,j,i,tarj);break;}
				if (b[i][j]!=i)
				{
					for (int tari=i+1;tari<=n;tari++)
					{
						for (int tarj=1;tarj<=m;tarj++)
						{
							if (b[tari][tarj]==i) {solve(i,j,tari,tarj);break;}
						}
						if (b[i][j]==i) break;
					}
				}
			}
		}
	}
	cout<<total<<endl;
	for (int i=1;i<=total;i++)
	{
		printf("%d %d\n",opt[i][0],opt[i][1]);
	}
	return 0;
}

