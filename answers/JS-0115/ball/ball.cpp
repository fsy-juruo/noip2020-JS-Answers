# include<bits/stdc++.h>
using namespace std;
int n,m,i,j,k,o,di,dj,dk,x,b[55][100],c[100],t1[1000000],t2[1000000],tot;
int main()
{
  freopen("ball.in","r",stdin);
  freopen("ball.out","w",stdout);
  cin>>n>>m;
  for (i=1;i<=n;i++)
  {
  	for (j=1;j<=m;j++)
  	cin>>b[i][j];
   } 
   for (i=1;i<=n-2;i++)
   {
   	for (j=1;j<=m;j++)
   	{
   		if (b[i][j]==i) continue;
   		di=0; dj=0;
		for (k=i+1;k<=n;k++)
		{
		for (o=1;o<=m;o++)
		if (b[k][o]==i) {
				di=k;
				dj=o;
				break;
		}
		if (b[k][o]==i) break;
	   }
		if (di!=n) dk=di+1;
		else dk=n-1;
		for (k=m;k>=dj+1;k--)
		{
		tot++;	t1[tot]=di; t2[tot]=n+1;
		}
		tot++;  t1[tot]=dk; t2[tot]=n+1;
		tot++;  t1[tot]=di; t2[tot]=dk;
		for (k=m;k>=dj;k--)
		{
		tot++;	t1[tot]=n+1; t2[tot]=di;
		}
		/*for (k=dj+1;k<=m;k++)
		c[k]=b[di][k];
		for (k=dj+1;k<=m;k++)
		b[di][k]=c[m-k+dj+1];*/
		b[di][dj]=b[dk][m];
		b[dk][m]=i;//ÌáÈ¡i
		for (k=j;k<=m;k++) 
		{
		   tot++;	t1[tot]=i; t2[tot]=n+1;	
		}
		tot++; t1[tot]=dk; t2[tot]=i;
		tot++; t1[tot]=n+1; t2[tot]=dk;
		for (k=j+1;k<=m;k++)
		{
			tot++; t1[tot]=n+1; t2[tot]=i;
		}
		 b[dk][m]=b[i][j];b[i][j]=i;
		/* for (k=j+1;k<=m;k++)
		 c[k]=b[i][k];
		 for (k=j+1;k<=m;k++)
		 b[i][k]=c[m-k+j+1];*/ 
		}
   }
   i=n-1;
   for (j=1;j<=m;j++)
   {
   	    if (b[i][j]==i) continue;
   	  	di=0; dj=0;
		for (k=i+1;k<=n;k++)
		{
		for (o=1;o<=m;o++)
		if (b[k][o]==i) {
				di=k;
				dj=o;
				break;
		}
		if (b[k][o]==i) break;
	    }
		if (di!=n) dk=di+1;
		else dk=n-1;
		for (k=m;k>=dj+1;k--)
		{
		tot++;	t1[tot]=di; t2[tot]=n+1;
		}
		tot++;  t1[tot]=dk; t2[tot]=n+1;
		tot++;  t1[tot]=di; t2[tot]=dk;
		for (k=m;k>=dj;k--)
		{
		tot++;	t1[tot]=n+1; t2[tot]=di;
		}
		/*for (k=dj+1;k<=m;k++)
		c[k]=b[di][k];
		for (k=dj+1;k<=m;k++)
		b[di][k]=c[m-k+dj+1];*/
		b[di][dj]=b[dk][m];
		b[dk][m]=i;
		tot++; t1[tot]=n-1; t2[tot]=n+1;
		tot++; t1[tot]=n; t2[tot]=n-1;
		tot++; t1[tot]=n+1; t2[tot]=n;
		swap(b[n-1][m],b[n][m]);
		dk=n;//
		for (k=j;k<=m;k++) 
		{
		   tot++;	t1[tot]=i; t2[tot]=n+1;	
		}
		tot++; t1[tot]=dk; t2[tot]=i;
		tot++; t1[tot]=n+1; t2[tot]=dk;
		for (k=j+1;k<=m;k++)
		{
			tot++; t1[tot]=n+1; t2[tot]=i;
		}
		 b[dk][m]=b[i][j];b[i][j]=i;
		 /*for (k=j+1;k<=m;k++)
		 c[k]=b[i][k];
		 for (k=j+1;k<=m;k++)
		 b[i][k]=c[m-k+j+1];*/ 
		 /*for (k=1;k<=n;k++)
		 {
		 	for (o=1;o<=m;o++)
		 	cout<<b[k][o]<<' ';
		 	cout<<endl;
		 }*/
   }
   cout<<tot<<endl;
   for (i=1;i<=tot;i++)
   cout<<t1[i]<<' '<<t2[i]<<endl;
  return 0;
}

