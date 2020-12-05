#include<bits/stdc++.h>
using namespace std;
int n,m;
int pai[100005],cnt;
int head[100005],to[25000005],nextt[25000005],tot;
bool vis[100005];
int rudu[100005],chudu[100005];
long long wa[100005],wb[100005];//fenzi fenmu
long long GCD(long long x,long long y)
{
	if(x<y)swap(x,y);
//	printf("    %lld %lld\n",x,y);
	if(y==0)return x;
	return GCD(y,x%y);
}
void gb(long long a,long long b,long long c,long long d,int y)
{
	if(wb[y]==0){wa[y]=b;wb[y]=a;return;}
	wa[y]=b*c+a*d;
	wb[y]=a*c;
	int gcd;gcd=GCD(wa[y],wb[y]);
	wa[y]/=gcd;wb[y]/=gcd;
	//gcd ?????
}
void dfs(int mark)
{
	vis[mark]=1;//printf("    %d\n",mark);
	for(int j=head[mark];j;j=nextt[j])
	{
		int y;y=to[j];
		if(vis[y])continue;
		gb(wb[mark]*chudu[mark],wa[mark],wb[y],wa[y],y);
		rudu[y]--;
//		for(int i=1;i<=n;i++)printf("%d ",rudu[i]);printf("\n");
		if(rudu[y]==0)dfs(y);
	}
}
int main()
{
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		int op;scanf("%d",&op);
		chudu[i]=op;
		if(op==0)pai[++cnt]=i;
		for(int j=1;j<=op;j++)
		{
			int g1,g2;scanf("%d",&g2);g1=i;
			to[++tot]=g2;nextt[tot]=head[g1];head[g1]=tot;
			rudu[g2]++;
		}
	}
/*	printf("\n\n");for(int i=1;i<=n;i++)
	{
		for(int j=head[i];j;j=nextt[j])printf("%d ",to[j]);printf("\n");
	}*/
	wa[1]=wb[1]=1;
	for(int i=1;i<=n;i++)
	{
		if(!vis[i]&&rudu[i]==0)dfs(i);
	}
	for(int i=1;i<=cnt;i++)
	{
		long long x,y;x=wb[pai[i]];y=wa[pai[i]];
		long long gcd;gcd=GCD(x,y);//printf("%lld %lld    %lld\n",x,y,gcd);
		x/=gcd;y/=gcd;
		printf("%lld %lld\n",y,x);
	}
}
/*
5 1
3 2 3 5
2 4 5
2 5 4
0
0
*/
