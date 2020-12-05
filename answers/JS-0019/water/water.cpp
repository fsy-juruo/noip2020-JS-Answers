#include<iostream>
#include<cstdio>
#include<iomanip>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<map>
#include<vector>
#include<queue>
using namespace std;
long long n,m,a[100005][8],b[100005],w[2][100005],q[100005],h=1,t;
long long dfs(long long x,long long y)
{
	if(y==0)return x;
	return dfs(y,x%y);
}
int main()
{
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	int i,j;
	cin>>n>>m;
	for(i=1;i<=n;i++)
	{
		cin>>a[i][0];
		for(j=1;j<=a[i][0];j++)
		{
			cin>>a[i][j];
			b[a[i][j]]++;
		}
	}
	t=m;
	for(i=1;i<=m;i++)
	{
		q[i]=i;
		w[0][i]=w[1][i]=1;
	}
	while(h<=t)
	{
		int s=q[h];
		h++;
		if(a[s][0]==0)continue;
		for(i=1;i<=a[s][0];i++)
		{
			int u=a[s][i];
			b[u]--;
			if(b[u]==0)
			{
				t++;
				q[t]=u;
			}
			if(w[0][u]!=0)
			{
				w[0][u]=w[0][u]*w[1][s]*a[s][0]+w[0][s]*w[1][u];
				w[1][u]=w[1][u]*w[1][s]*a[s][0];
			}
			else
			{
				w[0][u]=w[0][s];
				w[1][u]=w[1][s]*a[s][0];
			}
			long long v=dfs(w[0][u],w[1][u]);
			w[0][u]/=v;
			w[1][u]/=v;
		}
		w[0][s]=0;
	}
	for(i=1;i<=n;i++)
	if(w[0][i]!=0)
	cout<<w[0][i]<<' '<<w[1][i]<<endl;
	return 0;
}

