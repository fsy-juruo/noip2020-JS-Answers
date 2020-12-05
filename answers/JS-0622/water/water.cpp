#include<bits/stdc++.h>

using namespace std;
int nn,m,d[100005][105];
struct num
{
	int p,q;
}a[100005];
int gcd(int x,int y)
{
	if (x<y) swap(x,y);
	if (x%y==0) return y;
	else
	return gcd(y,x%y);
}
num clean(num x)
{
	int a=__gcd(x.p,x.q);
	x.p/=a;
	x.q/=a;
	return x;
}

void go(int m)
{
	if (d[m][0]==0) return;
	a[m].q*=d[m][0];
	for (int i=1;i<=d[m][0];i++)
	{
		num n,x=a[m],y=a[d[m][i]];
		n.q=x.q*y.q;
		n.p=x.p*y.q+x.q*y.p;
		a[d[m][i]]=n;
		clean(a[d[m][i]]);
		go(d[m][i]);
	}
	a[m].p=0;
	a[m].q=1;
}
int main()
{
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	scanf("%d%d",&nn,&m);
	for (int i=1;i<=nn;i++)
	{
		a[i].q=1;
		if (i<=m)
		a[i].p=1;
		scanf("%d",&d[i][0]);
		if (d[i][0]!=0)
		{
			for (int j=1;j<=d[i][0];j++)
			scanf("%d",&d[i][j]);
			sort(d[i]+1,d[i]+d[i][0]+1);
		}
	}
	//for (int i=1;i<=n;i++)
	//printf("%d %d\n",a[i].p,a[i].q);
	for (int i=1;i<=m;i++)
	{
		go(i);
	}
	for (int i=1;i<=nn;i++)
	{
		if (d[i][0]==0)
		{
			a[i]=clean(a[i]);
			printf("%d %d\n",a[i].p,a[i].q);
		}
	}
	return 0;
}
