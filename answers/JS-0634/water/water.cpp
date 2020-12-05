#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;
struct P
{
	int to,next;
}p[100001];
int n,m,top,h[100001],d[100001];
unsigned long long water[2][100001];
int gcd(int a,int b)
{
	if(a%b==0)return b;
	else return gcd(b,a%b);
}
void dfs(int x)
{
	if(!water[1][x])water[1][x]=1;
	for(int i=h[x];i;i=p[i].next)
	{
		if(!water[1][p[i].to])
		dfs(p[i].to);
		int add1=water[0][p[i].to],add2=water[1][p[i].to]*d[p[i].to];
		int fm=water[1][x]*add2/gcd(water[1][x],add2);
		add1*=fm/add2,water[0][x]*=fm/water[1][x];
		water[0][x]+=add1;water[1][x]=fm;
		int newgcd=gcd(water[0][x],water[1][x]);
		water[1][x]/=newgcd,water[0][x]/=newgcd;
	}
}
int main()
{
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)water[0][i]=water[1][i]=1;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&d[i]);
		for(int j=1;j<=d[i];j++)
		{
			int x;scanf("%d",&x);
			p[++top].next=h[x];
			p[top].to=i;
			h[x]=top;
		}
	}
	for(int i=1;i<=n;i++)
	if(!water[1][i])
	{
		dfs(i);
		if(!d[i])
		cout<<water[0][i]<<" "<<water[1][i]<<endl;
	}
	return 0;
}
