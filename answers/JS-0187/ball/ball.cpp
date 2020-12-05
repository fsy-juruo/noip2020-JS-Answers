#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m,a[55][405],b[55][405],ans=0;
int main()
{
	freopen("ball.in","r",stdin);
	freopen("ball.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)for(int j=0;j<m;j++)
	{
		scanf("%d",&a[i][j]);
		b[i][j]=a[i][j];
	}
	for(int i=1;i<=n;i++)
	{
		int j=0,goal=b[i][0];
		while(j<m&&b[i][j]==goal)j++;
		int r=m-j;
		int mm=j;
		ans+=r;
		for(int k=i+1;k<=n;k++)
		{
			int y=0;
			for(int l=m-1;l>=0;l--)
			{
				if(b[k][l]==goal)
				{
					int t=m-l-1;
					int cr=min(t,m-r-1);
					ans+=cr;
					int rem=max(0,t-cr);
					ans+=rem;
					ans++;
					ans+=rem;
					ans++;
					for(int o=l;o<m-1;o++)b[k][o]=b[k][o+1];
					ans+=cr;
					if(b[i][mm]==goal)
					{
						ans++;
						mm++;
						r--;
					}
					b[k][m-1]=b[i][mm];
//					cout<<t<<' '<<cr<<' '<<rem<<endl;
					r--;
					mm++;
					ans++;
				}
			}
		}
		if(mm!=m)
		{
			ans+=m-mm;
		}
	}
	printf("%d\n",ans);
	for(int i=1;i<=n;i++)
	{
		int j=0,goal=a[i][0];
		while(j<m&&a[i][j]==goal)j++;
		int r=m-j;
		int mm=j;
		for(int x=0;x<r;x++)printf("%d %d\n",i,n+1);
		for(int k=i+1;k<=n;k++)
		{
			int y=0;
			for(int l=m-1;l>=0;l--)
			{
				if(a[k][l]==goal)
				{
					int t=m-l-1;
					int cr=min(t,m-r-1);
					for(int x=0;x<cr;x++)printf("%d %d\n",k,n+1);
					int rem=max(0,t-cr);
					for(int x=0;x<rem;x++)printf("%d %d\n",k,i);
					printf("%d %d\n",k,n+1);
					for(int x=0;x<rem;x++)printf("%d %d\n",i,k);
					printf("%d %d\n",n+1,i);
					for(int o=l;o<m-1;o++)a[k][o]=a[k][o+1];
					for(int x=0;x<cr;x++)printf("%d %d\n",n+1,k);
					if(a[i][mm]==goal)
					{
						printf("%d %d\n",n+1,i);
						mm++;
						r--;
					}
					a[k][m-1]=a[i][mm];
					printf("%d %d\n",n+1,k);
//					cout<<t<<' '<<cr<<' '<<rem<<endl;
					r--;
					mm++;
				}
			}
		}
		if(mm!=m)
		{
			for(int x=0;x<m-mm;x++)printf("%d %d\n",n+1,i);
		}
	}
	return 0;
}

