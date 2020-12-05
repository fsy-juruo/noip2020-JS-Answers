#include <bits/stdc++.h>
using namespace std;
struct lsy
{
	int fenzi;
	int fenmu;
};
struct gd
{
	int k;
	int b[6];
};
int plus1(lsy x,lsy y);
int plus2(lsy x,lsy y);
gd a[100005];
lsy c[100005];
lsy nowsum;
int main()
{
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	int n,m;scanf("%d%d",&n,&m);
	int i,j;
	memset(a,0,sizeof(a));
	for(i=1; i<=n; i++)
	{
		scanf("%d",&a[i].k);
		for(j=1; j<=a[i].k; j++)
			scanf("%d",&a[i].b[j]);
		c[i].fenzi=0;
		c[i].fenmu=1;
	}
	/*
	lsy alp,bt;
	alp.fenmu=6;alp.fenzi=4;
	bt.fenmu=21;bt.fenzi=14;
	cout<<plus1(alp,bt)<<" "<<plus2(alp,bt)<<endl;
	*/
	//if(m==1)
	//{
	
	for(i=1; i<=m; i++)
		c[i].fenzi=1;
	nowsum.fenzi=0;nowsum.fenmu=1;
	for(i=1; i<=n; i++)
	{
		if(a[i].k==0)
		{
			nowsum.fenzi=plus1(nowsum,c[i]);
			nowsum.fenmu=plus2(nowsum,c[i]);
			continue;
		}
		c[i].fenmu*=a[i].k;
		for(j=1; j<=a[i].k; j++)
		{
			lsy cmp;
			cmp.fenzi=c[a[i].b[j]].fenzi;
			cmp.fenmu=c[a[i].b[j]].fenmu;
			c[a[i].b[j]].fenzi=plus1(c[i],cmp);
			c[a[i].b[j]].fenmu=plus2(c[i],cmp);
		}
		c[i].fenmu=1;c[i].fenzi=0;
	}
	for(i=1; i<=n; i++)
	{
		if(a[i].k==0)
			printf("%d %d\n",c[i].fenzi,c[i].fenmu);
	}
	//}
	return 0;
}
int plus1(lsy x,lsy y)
{
	int now=x.fenzi*y.fenmu;
	now+=x.fenmu*y.fenzi;
	int nfm=x.fenmu*y.fenmu;
	int i,j,gan;
	int nnfm=nfm,nnow=now;
	if(abs(now-nfm)==1) return now;
	if(abs(now-nfm)==2&&now%2==1) return now;
	while(now!=nfm)
	{
		if(now>nfm) now-=nfm;
		else nfm-=now;
	}
	return nnow/now;
}

int plus2(lsy x,lsy y)
{
	int now=x.fenzi*y.fenmu;
	now+=x.fenmu*y.fenzi;
	int nfm=x.fenmu*y.fenmu;
	int i,j,gan=min(now,nfm);
	int nnfm=nfm,nnow=now;
	if(abs(now-nfm)==1) return nfm;
	if(abs(now-nfm)==2&&now%2==1) return nfm;
	while(now!=nfm)
	{
		if(now>nfm) now-=nfm;
		else nfm-=now;
	}
	return nnfm/now;
}
/*
5 1
3 2 3 5
2 4 5
2 5 4
0
0
*/
