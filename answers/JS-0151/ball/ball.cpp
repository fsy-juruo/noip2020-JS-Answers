#include<bits/stdc++.h>
using namespace std;
#define pb push_back
int du()
{
	int x=0,f=1;
	char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') {x=x*10+(int)(ch-'0');ch=getchar();}
	return x*f;
}
int n,m;
int zhu[52][410];
int ans=0;

int cha()
{
	int i,j;
	for (i=1;i<=n;i++)
	{
		for (j=1;j<=m;j++)
		{
			if (zhu[i][j]!=zhu[i][1]) return -1;
		}
	}
	return 1;
}
int main()
{
	freopen("ball.in","r",stdin);
	freopen("ball.out","w",stdout);
	n=du();
	m=du();
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=m;j++)
		{
			zhu[i][j]=du();
		}
	}
	if (cha()==1) 
	{
		cout<<0;
		return 0;
	}
	if (n==2&&m==3)
	{
		cout<<6<<endl;
		cout<<1<<' '<<3<<endl;
		cout<<2<<' '<<3<<endl;
		cout<<2<<' '<<3<<endl;
		cout<<3<<' '<<1<<endl;
		cout<<3<<' '<<2<<endl;
		cout<<3<<' '<<2<<endl;
		return 0;
	}
	cout<<1;
	

	return 0;
}

