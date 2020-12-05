#include<bits/stdc++.h>
using namespace std;

inline void read(int &x)
{
	int y=1;
	x=0;
	char ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-')y=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		x=x*10+ch-'0';
		ch=getchar();
	}
	x*=y;
}

int n,m;
int a[60][90];
int ans[820000][2];
int cnt=0;

int main()
{
	freopen("ball.in","r",stdin);
	freopen("ball.out","w",stdout);
	read(n),read(m);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			read(a[i][j]);
		}
	}
	int top1=m,top2=m,top3=0,d1=1,d2;
	for(int i=2;i<=m;i++)
	{
		if(a[1][i]==a[1][i-1])d1++;
	}
	int c=a[1][1];
	for(int i=m;i>d1;i--)
	{
		cnt++;
		ans[cnt][0]=1;
		ans[cnt][1]=3;
		top1--;
		top3++;
		a[3][top3]=a[1][top1+1];
	}
	for(int i=m;i>=1;--i)
	{
		if(a[2][i]==c)
		{
			cnt++;
			ans[cnt][0]=2;
			ans[cnt][1]=1;
			top2--;
			top1++;
			a[1][top1]=a[2][top2+1];
		}
		else
		{
			cnt++;
			ans[cnt][0]=2;
			ans[cnt][1]=3;
			top2--;
			top3++;
			a[3][top3]=a[2][top2+1];
			if(top3==m&&top1!=m)
			{
				while(top2<m)
				{
					cnt++;
					ans[cnt][0]=3;
					ans[cnt][1]=2;
					top3--;
					top2++;
					a[2][top2]=a[3][top3+1];
				}
				i=m;
			}
		}
	}
	while(top3>0)
	{
		cnt++;
		ans[cnt][0]=3;
		ans[cnt][1]=2;
		top3--;
		top2++;
	}
		
	printf("%d\n",cnt);
	for(int i=1;i<=cnt;i++)
	{
		printf("%d %d\n",ans[i][0],ans[i][1]);
	}
	return 0;
}

