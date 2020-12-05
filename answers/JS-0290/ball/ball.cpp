#include<bits/stdc++.h>
using namespace std;

const int M=405,N=55,K=820005;
int n,m;
int num[N],a[N][M],top[N];
int fr[K],to[K],cnt=0;
bool vis[N][N][M][M];

void dfs(int x,int y)
{
	vis[x][y][num[x]][num[y]]=1;
//	cout<<x<<"->"<<y<<endl;
	fr[++cnt]=x;
	to[cnt]=y;
	num[y]++;
	a[y][num[y]]=a[x][num[x]];
	a[x][num[x]]=0;
	num[x]--;
	if(num[y]==top[y]+1&&a[y][num[y]]==a[y][top[y]]) top[y]++;
	bool pd=1;
	for(int i=1;i<=n;i++)
	if(top[i]!=num[i]) pd=0;
	if(pd) 
	{
		cout<<cnt<<endl;
		for(int i=1;i<=cnt;i++)
		{
			cout<<fr[i]<<" "<<to[i]<<endl;
		}
		exit ;
	}
	for(int i=1;i<=n+1;i++)
	{
		for(int j=1;j<=n+1;j++)
		{
			if(vis[i][j][num[i]][num[j]]) continue;
			if(i==j) continue;
			if(i==n+1&&num[i]==0) continue;
			if(j==n+1&&num[j]==m) continue;
			if((num[j]==m||top[i]==num[i])&&i!=n+1&&j!=n+1) continue;
			dfs(i,j);
			vis[i][j][num[i]][num[j]]=0;
			cnt--;
			num[i]++;
			a[i][num[i]]=a[j][num[j]];
			a[j][num[j]]=0;
			num[j]--;
		}
	}
}

int main()
{
	freopen("ball.in","r",stdin);
	freopen("ball.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		top[i]=1;
		for(int j=1;j<=m;j++)
		{
			cin>>a[i][j];
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=2;j<=m;j++)
		{
			if(a[i][j]==a[i][j-1]) top[i]++;
			else break;
		}
	}
	for(int i=1;i<=n;i++)
		dfs(i,n+1);
	return 0;
}
