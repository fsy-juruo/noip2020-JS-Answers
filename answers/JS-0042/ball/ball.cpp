#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
template <typename T> int read(T &x)
{
		 x=0;
		 int f=1;
		 char c=getchar();
		 for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
		 for(;isdigit(c);c=getchar())x=x*10+c-'0';
		 x*=f;
}
int n,m,ans;
int a[60][410];
struct DY{
	int x, y;
}bz[852000];
int main()
{
	freopen("ball.in","r",stdin);
 	freopen("ball.out","w",stdout);	
	read(n);
	read(m);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		read(a[i][j]);
	}
	if(n==1)
	{
		puts("0");
		return 0;
	}
	if(n==2)
	{
		int t1=n,t2=n,x=0,t=0;
		a[3][++x]=a[1][t1];
		t1--;
		for(int i=1;i<=820000;i++)
		{
			while(a[2][t2]==a[3][x]&&t2&&x<m)
			{
				a[3][++x]=a[2][t2];
				a[2][t2]=0;
				bz[++t].x=2,bz[t].y=3;
				t2--;
				ans++;
			}
			while(a[1][t1]==a[3][x]&&t1&&x<m)
			{
				a[3][++x]=a[2][t1];
				a[2][t1]=0;
				bz[++t].x=1,bz[t].y=3;
				t1--;	
				ans++;			
			}
			while(a[2][t2]!=a[3][1]&&x<m&&t2)
			{
				a[3][++x]=a[2][t2];
				a[2][t2]=0;
				bz[++t].x=2,bz[t].y=3;
				t2--;
				ans++;
			}
			while(a[2][t2]!=a[3][1]&&t2&&t1<m)
			{
				a[1][++t1]=a[2][t2];
				a[2][t2]=0;
				bz[++t].x=2,bz[t].y=1;
				t2--;
				ans++;
			}
				if(a[3][x]==a[2][t2]&&t2)
				a[3][++x]=a[2][t2],ans++,a[2][t2]=0,bz[++t].x=2,bz[t].y=3,t2--;
				else
				{
					
					a[1][++t1]=a[2][t2];
					ans++;
					a[2][t2]=0;
					bz[++t].x=2,bz[t].y=1;
					t2--;
				}
				while(a[3][x]!=a[3][1]&&x&&t2<m)
				{
					a[2][++t2]=a[3][x];
					a[3][x]=0;
				bz[++t].x=3,bz[t].y=2;
				ans++;
					x--;
				}
				a[3][++x]=a[1][t1--];
				a[1][t1+1]=0;
				bz[++t].x=1,bz[t].y=3;
				ans++;
				bool flag=0;
				for(int i=1;i<=3;i++)
				{
					if(a[i][1]==0)
					{
						flag=1;
						break;
					}
				}
				if(flag==1)
				{
					printf("%d\n",ans);
					for(int i=1;i<=t;i++)
					printf("%d %d\n",bz[i].x,bz[i].y);
					return 0;
				}
		}
	}
	return 0;
}

