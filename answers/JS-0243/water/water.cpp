#include<bits/stdc++.h>
#define ll long long
#define N 505000
using namespace std;
int tot,ver[2*N],Next[2*N],head[N],d[N];
int n,m,ans[N],ans1[N];
void add(int x,int y)
{
	ver[++tot]=y,Next[tot]=head[x],head[x]=tot;
}
int gcd(int a,int b)
{
	if (b==0)return a;
	return gcd(b,a%b);
}
void dfs(int x,int fa,int fz,int fm)
{
	
	for (int i=head[x];i;i=Next[i])
	{
		int y=ver[i];
		if (y==fa)continue;
		if (d[y]==0)
		{
			//¼Ó 
			fm*=d[x];
			
			int s=fm/gcd(fm,ans1[y])*ans1[y];
			ans[y]=ans[y]*(s/ans1[y])+fz*(s/fm);
			int c=gcd(ans[y],s);
			ans[y]/=c;
			ans1[y]=s/c;
		
			fm/=d[x];
		}
		else{
			dfs(y,x,fz,fm*d[x]);
		}
	}
}
int main()
{
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>n>>m;
//	scanf("%d %d",n,m);
	for (int i=1;i<=n;i++)
	{
		ans1[i]=1;
		ans[i]=0;
		cin>>d[i];
		for (int j=1,y;j<=d[i];j++)
		{
			cin>>y;
			add(i,y);
		}
	}
	for (int i=1;i<=m;i++)
	{
		dfs(i,0,1,1); 
	}
	for (int i=1;i<=n;i++)
	if (d[i]==0)printf("%d %d\n",ans[i],ans1[i]);
	//cout<<ans[i]<<' '<<ans1[i]<<endl;
	return 0;
}

