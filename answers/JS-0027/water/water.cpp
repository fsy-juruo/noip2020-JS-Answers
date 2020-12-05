#include<bits/stdc++.h>
using namespace std;
struct node{
	int fz,fm;
};
int n,m,bm,bz;
int a[10010][5],k[10010];
node h[10010];
int gbs(int a,int b)
{
	if(a==0)return b;
	int a1=a,b1=b,c=a%b;
	while(c)
	{
		a=b;b=c;c=a%b;
	}
	return a1*b1/b;
}
int gys(int a,int b)
{
	int c=a%b;
	while(c)
	{
		a=b;b=c;c=a%b;
	}
	return b;
}
int pls(int fz,int fm,int pz,int pm)
{
	if(fm==0)return pz;
	int gfm=gbs(fm,pm);
	fz=fz*gfm/fm;
	pz=pz*gfm/pm;
	return fz+pz;
}
int main()
{
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>k[i];
		if(k[i]==0)continue;
		for(int j=1;j<=k[i];j++)
		cin>>a[i][j];
	}
	memset(h,0,sizeof(h));
	for(int i=1;i<=m;i++)
	{
		h[i].fz=1;
		h[i].fm=m;
	}
	for(int i=1;i<=m;i++)
	{
		for(int j=m;j<=n;j++)
		{
			if(k[j]==0)continue;
			for(int p=1;p<=k[j];p++)
			{
				bm=h[a[j][p]].fm;bz=h[a[j][p]].fz;
				h[a[j][p]].fm=gbs(bm,k[j]*h[j].fm);
				h[a[j][p]].fz=pls(bz,bm,h[j].fz,k[j]*h[j].fm);
				if(h[a[j][p]].fm)
				{
					bm=h[a[j][p]].fm;bz=h[a[j][p]].fz;
					h[a[j][p]].fm/=gys(bm,bz);
					h[a[j][p]].fz/=gys(bm,bz);	
				}
			}
			h[j].fm=0;h[j].fz=0;
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(k[i]==0)cout<<h[i].fz<<" "<<h[i].fm<<endl;
	}
	return 0;
}

