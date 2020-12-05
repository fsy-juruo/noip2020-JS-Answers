#include<bits/stdc++.h>
using namespace std;
int a[51][405],tot=820000,oto=0,n,m;
bool d[404];
pair<int,int> c[820001],b[820001];
void dfs(int o,int e)
{
	a[e][++a[e][0]]=a[o][a[o][0]];
	a[o][a[o][0]]=0;
	a[o][0]--;
	oto++;
	if(oto>820000)
	return;
	bool q;
	for(int i=0;i<n;i++)
	{
		q=true;
		for(int j=1;j<=a[i][0];j++)
		{
			if(a[i][j]!=a[i][j-1]&&j!=1)
			q=false;
		}
		if(q)
		d[i]=true;
	}
	q=true;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<=n;j++)
		{
			if(a[j][0]<m-1&&!d[i])
			{
				q=false;
				b[oto].first=i;
				b[oto].second=j;
				dfs(i,j);
				b[oto].first=i;
				b[oto].second=j;
			}
		}
	}
	if(q&&oto<=tot)
	{
		int t=0;
		tot=oto;
		while(t<oto)
		{
			c[t].first=b[t].first;
			c[t].second=b[t].second;
			t++;
		}
	}
	oto--;
	return;
}
int main()
{
	freopen("ball.in","r",stdin);
	freopen("ball.out","w",stdout);
	int i,j,k,l;
	bool p;
	scanf("%d%d",&n,&m);
	for(i=0;i<n;i++)
	{
		a[i][0]=m;
		p=true;
		for(j=1;j<=m;j++)
		{
			scanf("%d",&k);
			a[i][j]=k;
			if(a[i][j]!=a[i][j-1]&&j!=1)
			p=false;
		}
		if(p)
		{
			i--;
			n--;
		}
	}
	if(n==0)
	{
		printf("0");
		return 0;
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<=n;j++)
		{
			if(a[j][0]<m-1)
			{
				b[oto].first=i;
				b[oto].second=j;
				dfs(i,j);
				b[oto].first=i;
				b[oto].second=j;
			}
		}
	}
	printf("%d\n",tot);
	for(i=0;i<tot;i++)
	printf("%d %d\n",c[i].first,c[i].second);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

