#include<bits/stdc++.h>
using namespace std;
#define long long int
struct node
{
	int out,fz,fm;
}d[100005];
int n,m,gfz=0,gfm=0;
int gcd(int a,int b)
{
	if(b==0) return a;
	return gcd(b,a%b);
}
int gbs(int a,int b)
{
	return a*b/gcd(a,b);
}
void add(node a,node b)
{
	int fz,fm;
	b.fz/=gcd(b.fz,b.fm);
	b.fm/=gcd(b.fz,b.fm);
	
	fm=gbs(a.fm,b.fm);
	fz=a.fz*fm/a.fm+b.fz*fm/b.fm;
	
	int x=gcd(fz,fm);
	fz/=x;
	fm/=x;
	//printf("b%d %d\n",fz,fm);
	gfz=fz,gfm=fm;
	return;
}
int main()
{
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		d[i].fz=0;
		d[i].fm=1;
	}
	for(int i=1;i<=m;i++) d[i].fz=1;
	int go;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&d[i].out);
		if(d[i].out!=0) d[i].fm*=d[i].out;
		node b;
		b.fz=d[i].fz,b.fm=d[i].fm,b.out=d[i].out;
		for(int j=1;j<=b.out;j++)
		{
			scanf("%d",&go);
			node a;
			a.fz=d[go].fz,a.fm=d[go].fm,a.out=d[go].out;
			add(a,b);
			d[go].fz=gfz,d[go].fm=gfm;
			//printf("a%d %d %d\n",go,d[go].fz,d[go].fm);
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(d[i].out==0) printf("%d %d\n",d[i].fz,d[i].fm);
	}
	return 0;
}
