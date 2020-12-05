#include<bits/stdc++.h>
using namespace std;
int n,m;
int cs[25][25];
struct s{
	int zt[13][22];
	int qiu[13];
	int last;
	int from,to,step;
}a[820005];
int head,tail;
bool pd(int zb)
{
	for(int i=1;i<=n+1;i++)
	{
		int col;col=a[zb].zt[i][1];
		for(int j=2;j<=m;j++)if(a[zb].zt[i][j]!=col)return 0;
	}
	return 1;
}
void sc(int zb)
{
	if(!a[zb].last)return;
	if(a[zb].last)sc(a[zb].last);
	printf("%d %d\n",a[zb].from,a[zb].to);
}
int main()
{
	freopen("ball.in","r",stdin);
	freopen("ball.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)scanf("%d",&cs[i][j]);
	for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)a[1].zt[i][j]=cs[i][j];
	for(int i=1;i<=n;i++)a[1].qiu[i]=m;
	head=tail=1;
	while(head<=tail)
	{
		if(pd(head))
		{
			printf("%d\n",a[head].step);
			sc(head);return 0;
		}
		for(int i=1;i<=n+1;i++)
		{
			for(int j=1;j<=n+1;j++)
			{
				if(i==j)continue;
				if(i==a[head].to&&j==a[head].from)continue;
				if(a[head].qiu[j]>=m)continue;
				if(a[head].qiu[i]==0)continue;
				if(tail+1>820000)continue;
				tail++;
				a[tail].from=i;a[tail].to=j;a[tail].step=a[head].step+1;
				a[tail].last=head;
				for(int k=1;k<=n+1;k++)a[tail].qiu[k]=a[head].qiu[k];
				a[tail].qiu[i]--;a[tail].qiu[j]++;
				for(int x=1;x<=n;x++)
				{
					for(int y=1;y<=a[tail].qiu[x];y++)a[tail].zt[x][y]=a[head].zt[x][y];
				}
				a[tail].zt[j][a[tail].qiu[j]]=a[head].zt[i][a[head].qiu[i]];
				a[tail].zt[i][a[head].qiu[i]]=0;
			}
		}
		head++;printf("%d ",tail);
	}
}
/*
2 3
1 1 2
2 1 2

3 3
2 2 1
1 2 1
3 3 3
*/
