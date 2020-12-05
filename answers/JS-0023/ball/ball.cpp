#include <bits/stdc++.h>
#define MAXN 100000
#define MAXD 30
#define INF 0x7fffffff
#define MOD 1000000007
using namespace std;
int inline read(void)
{
	int x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}
	return x*f;
}
int a[60][420]={0},k[60]={0};
int n,m;
struct pan
{
	int num,x;
}ps[60]={0};
bool cmp(pan p1,pan p2)
{
	return p1.x>p2.x;
}
bool judge(void)
{
	for(int i=1;i<=n;i++)
		for(int j=1;j<m;j++)
			if(a[i][j]!=a[i][j+1])	return true;
	return false;
}
int main()
{
	freopen("ball.in","r",stdin);
	freopen("ball.out","w",stdout);
	n=read(),m=read();

	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			a[i][j]=read();
			
	for(int i=1;i<=n;i++)	k[i]=m;
	k[n+1]=0;
	int ans=0;
	int anss[82000][2]={0};
	while(judge())
	{
		for(int i=1;i<=n;i++) ps[i]=pan{0,0};	
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
				if((a[i][j]!=i)&&ps[i].num==0&&ps[i].x==0&&a[i][j]!=0)
					ps[i]=pan{i,j};	
		sort(ps+1,ps+n+1,cmp);
		int t=n+1;
		for(int i=m;i>=ps[1].x;i--)
		{
			anss[ans][0]=ps[1].num;
			anss[ans++][1]=t;
			k[t]++;
			a[t][k[t]]=a[ps[1].num][k[ps[1].num]];
			a[ps[1].num][k[ps[1].num]]=0;
			k[ps[1].num]--;
			
		}
		for(int i=1;i<=n;i++)
		{			
			if(i==ps[1].num)	continue;
			for(;k[t]<=m&&k[ps[1].num]<m;)
			{
				if(a[i][k[i]]==ps[1].num)
				{
					anss[ans][0]=i;
					anss[ans++][1]=ps[1].num;
					k[ps[1].num]++;
					a[ps[1].num][k[ps[1].num]]=a[i][k[i]];
					a[i][k[i]]=0;
					k[i]--;					
				}
				else
				{
					k[t]++;	
					a[t][k[t]]=a[i][k[i]];
					a[i][k[i]]=0;
					anss[ans][0]=i;
					anss[ans++][1]=t;
					k[i]--;
								
				}
			}
			if(k[t]==m)
			{
				for(int j=1;j<=n+1;j++)
					if(i!=j&&j!=ps[1].num&&k[j]<m)
					{
						t=j;
						break;
					}
			}		
		}
		for(;k[n+1]>0;)
		{
			for(int i=1;i<=n;i++)
				if(k[i]!=m)
				{
					k[i]++;	
					a[i][k[i]]=a[t][k[t]];
					a[t][k[t]]=0;
					anss[ans][0]=t;
					anss[ans++][1]=i;
					k[t]--;
				}
		}
			
	}
	printf("%d\n",ans);
	for(int i=0;i<ans;i++)
		printf("%d %d\n",anss[i][0],anss[i][1]);
	return 0;
}
