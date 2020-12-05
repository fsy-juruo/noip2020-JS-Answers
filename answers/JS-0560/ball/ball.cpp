#include<cstdio>
#include<algorithm>
using namespace std;
int a[58][408],p[820008][2],ans,n,m,i,j,k,x,y,z,l[51],q[51],r1=123456,r2=141323;
int rnd()
{
	r1=(r1*24<<2)+r2;
	r2=((r2-23423)<<5)^r1;
	return abs(r1+r2);
}
int main()
{
	freopen("ball.in","r",stdin);
	freopen("ball.out","w",stdout);

	scanf("%d %d",&n,&m);
	for(i=1;i<=n;i++)
	  for(j=m;j>=1;j--)
	    scanf("%d",&a[i][j]);
	/*if(n!=2)
	{
		int p1=1,p2=2,p3=3,l1=1,l2=1,l3=m+1;
		while(true)
		{
			while(l3!=1)
			{
				bool tt=false;
				while(a[p1][l1]==a[p3][l3]&&(l3!=1))
				{
					p[++ans][0]=p1;
					p[ans][1]=p3;
					a[p3][l3-1]=a[p1][l1];a[p1][l1]=0;
					l1++;l3--;tt=true;
					
				}
				while((a[p2][l2]==a[p3][l3]||!tt)&&l3!=1)
				{
					p[++ans][0]=p2;
					p[ans][1]=p3;
					a[p3][l3-1]=a[p2][l2];a[p2][l2]=0;
					l2++;l3--;tt=true;
				}
			}
			p2^=p3^=p2^=p3;
			p1^=p2^=p1^=p2;
			l2^=l3^=l2^=l3;
			l1^=l2^=l1^=l2;
			a[1][0]=0;a[2][0]=0;a[3][0]=0;
			for(i=1;i<=m;i++)
			for(j=1;j<=3;j++){
				a[j][0]+=a[j][i];
			}
			if((a[1][0]+1)*(a[2][0]+1)*(a[3][0]+1)==(m+1)*(m*2+1))break;
		}
	}
	else*/

	{
		//int p1=1,p2=2,p3=3,l1=1,l2=1,l3=m+1;
		for(i=1;i<=n+1;i++)q[i]=i,l[i]=1;l[n+1]=m+1;
		while(true)
		{
			while(l[n+1]!=1)
			{
				bool tt=false;
				for(i=1;i<=n;i++)
				while((a[q[i]][l[i]]==a[q[n+1]][l[n+1]])&&(l[n+1]!=1))
				{
					p[++ans][0]=q[i];
					p[ans][1]=q[n+1];
					a[q[n+1]][l[n+1]-1]=a[q[i]][l[i]];a[q[i]][l[i]]=0;
					l[i]++;l[n+1]--;tt=true;
				}
				if(!tt)
				{
					i=rnd()%n+1;
					p[++ans][0]=q[i];
					p[ans][1]=q[n+1];
					a[q[n+1]][l[n+1]-1]=a[q[i]][l[i]];a[q[i]][l[i]]=0;
					l[i]++;l[n+1]--;tt=true;
				}
			}
			bool is=true;
			for(i=0;i<=n;i++)
			{
			  if(l[i+1]!=1&&l[i+1]!=m+1)is=false;
			  q[i]=q[i+1],l[i]=l[i+1];
			}
			q[n+1]=q[0];l[n+1]=l[0];
			if(is)for(i=1;i<=n;i++)
			  for(j=2;j<=m;j++)
			    if(a[i][j]!=a[i][j-1])is=false;
			if(is)break;
		}
	}
	printf("%d\n",ans);
	for(i=1;i<=ans;i++)
	  printf("%d %d\n",p[i][0],p[i][1]);
	return 0;
}
/*
2 4
1 2 1 2
2 2 1 1
*/

