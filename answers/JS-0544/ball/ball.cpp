#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define x0 xasdsajldk
#define x1 xklasjdklsa
#define y0 ysjaldksla
#define y1 yaklsdnwad
const int INF=0x3f3f3f3f,N=50+5,M=400+5;
int n,m;
int a[N][M];
int b[N][M];
int ans=0;
void print()
{
	int i,j;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
			cout<<a[i][j]<<" ";
		cout<<endl;	
	}

}
void slove(int cur)
{
	int i,j,k;
	for(j=m;j>=1;j--)
	{
		if(a[cur][j]==cur)
		{
			ans+=2*m+2*j;
			for(k=j+1;k<=m;k++)
				a[cur][k-1]=a[cur][k];
			a[cur][m]=cur;
		}
	}
//	print();
	for(j=m;j>=1;j--)
	{
		if(a[cur][j]!=cur) break;
	}
	int j1=j;
	for(i=cur+1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			if(a[i][j]==cur)
			{
				ans+=2*j+2*m+3;
				swap(a[i][j],a[cur][j1]);
				j1--;
			}
		}
	}
}
void down1(int cur,int k)
{
	int i;
	int xd=cur+1;
	for(i=1;i<=k;i++)
	{
		printf("%d %d\n",xd,n+1);
	}
	for(i=1;i<=k;i++)
	{
		printf("%d %d\n",cur,xd);
	}
	for(i=1;i<=m-k;i++)
	{
		printf("%d %d\n",cur,n+1);
	}
	
	printf("%d %d\n",xd,cur);
	
	for(i=1;i<=m-k;i++)
	{
		printf("%d %d\n",n+1,cur);
	}
	for(i=1;i<=k-1;i++)
	{
		printf("%d %d\n",xd,cur);
	}
	for(i=1;i<=k;i++)
	{
		printf("%d %d\n",n+1,xd);
	}
}
void jiaohuan(int cur,int xd,int k)
{
	int i;
	for(i=1;i<=k-1;i++)
	{
		printf("%d %d\n",xd,n+1);
	}
//	printf("%d %d\n",n+1,xd);
	printf("%d %d\n",cur,n+1);
	printf("%d %d\n",xd,cur);
	
	for(i=1;i<=k;i++)
	{
		printf("%d %d\n",n+1,xd);
	}
}
void slove2(int cur)
{
	int i,j,k;
	for(j=m;j>=1;j--)
	{
		if(a[cur][j]==cur)
		{
			down1(cur,j);
			ans+=2*m+2*j;
			for(k=j+1;k<=m;k++)
				a[cur][k-1]=a[cur][k];
			a[cur][m]=cur;
		}
	}
	for(j=m;j>=1;j--)
	{
		if(a[cur][j]!=cur) break;
	}
	int j1=j;
	for(i=cur+1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			if(a[i][j]==cur)
			{
//				cout<<"asda"<<endl;
				jiaohuan(cur,i,j);
				down1(cur,1);
				ans+=2*j+2*m+3;
				swap(a[i][j],a[cur][j1]);
				j1--;
			}
		}
	}
}
int main()
{
	freopen("ball.in","r",stdin);
	freopen("ball.out","w",stdout);
	int i,j;
	cin>>n>>m;
	for(i=1;i<=n;i++)
	{
		for(j=m;j>=1;j--)
		{
			scanf("%d",&a[i][j]);
			b[i][j]=a[i][j];
		}
	}
	
	for(i=1;i<n;i++)
	{
		slove(i);
	}
	cout<<ans<<endl;
//	for(i=1;i<=n;i++)
//	{
//		for(j=1;j<=m;j++)
//			cout<<a[i][j]<<" ";	
//		cout<<endl;	
//	}
	for(i=1;i<=n;i++)
	{
		for(j=m;j>=1;j--)
		{
			a[i][j]=b[i][j];
		}
	}
	for(i=1;i<n;i++)
	{
		slove2(i);
	}
//	for(i=1;i<=n;i++)
//	{
//		for(j=1;j<=m;j++)
//			cout<<a[i][j]<<" ";	
//		cout<<endl;	
//	}
	return 0;
	
}
