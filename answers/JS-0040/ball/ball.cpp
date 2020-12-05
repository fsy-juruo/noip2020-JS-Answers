#include<bits/stdc++.h>
using namespace std;
int n,m,ys[52][401],l[52],k,fa[1000000][2];
int ad(int x,int y)
{
	if(x==y)
	return 0;
//	cout<<x<<" lll "<<y<<endl;
	fa[k][0]=x;
	fa[k][1]=y;
	l[y]++;
	ys[y][l[y]]=ys[x][l[x]];
	ys[x][l[x]]=0;
	l[x]--;
	k++;
//	for(int i=1;i<=n+1;i++)
//	{
//		for(int j=1;j<=l[i];j++)
//		cout<<ys[i][j]<<' ';
//		cout<<endl;
//	}
//	cout<<endl;
}
int chg(int sx,int sy,int tx,int ty)
{
	ad(n,n+1);
	for(int i=l[sx];i>sy;i--)
	{
		ad(sx,n+1);
	}
	ad(sx,n);
	ad(tx,sx);
	while(l[n+1]>=1)
	{
		ad(n+1,sx);
	}
	
	while(l[tx]>=ty)
	{
		ad(tx,n+1);
	}
	ad(n,tx);
	while(l[tx]<m)
	{
		ad(n+1,tx);
	}
	ad(n+1,n);
	return 0;
}
int doo(int x,int co)
{
	int de=2;
	for(int i=2;i<=m;i++)
	{
		if(ys[x][i]==co)
		{
			chg(x,i,x,de);
			de++;
		}
	}
	for(int i=x+1;i<=n;i++)
	{
		for(int j=m;j>=1;j++)
		{
			if(ys[i][j]==co)
			chg(i,j,x,de);
			de++;
			if(de==m+1)
			break;
		}
		if(de==m+1)
		break;
	}
	return 0;
}
int main()
{
	freopen("ball.in","r",stdin);
	freopen("ball.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			cin>>ys[i][j];
		}
		l[i]=m;
	}
	for(int i=1;i<n;i++)
	{
		doo(i,ys[i][1]);
	}
	printf("%d\n",k);
	for(int i=0;i<k;i++)
	{
		printf("%d %d\n",fa[i][0],fa[i][1]);
	}
	return 0;
}
