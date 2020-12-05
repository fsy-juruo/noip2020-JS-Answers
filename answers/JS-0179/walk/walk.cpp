#include<bits/stdc++.h>
using namespace std;
int n,m,i,w[100010],j,k;
long long ans;
struct node
{
  int w,d;
}a[100010];
int main()
{
  freopen("walk.in","r",stdin);
  freopen("walk.out","w",stdout);
  scanf("%d%d",&n,&m);
  for(i=1;i<=m;i++)
  {
  	scanf("%d",&w[i]);
  }
  for(i=1;i<=n;i++)
  {
  	scanf("%d%d",&a[i].w,&a[i].d);
  }
  if(m==1)
  {
    int vis[100010],vismax=w[1]*10;
  	for(i=1;i<=w[1];i++)
  	{
  	  j=i;
  	  memset(vis,0,sizeof(vis));
  	  while(j<=w[1]&&j>=1)
  	  {
  	    for(k=1;k<=n;k++)
  	    {
  	      if(vis[j]>vismax){ans=-1;break;}
  	      vis[j]++;
  	      j=j+a[k].d;
  	      ans++;
  	      if(j>n||j<1)break;
		}
		if(ans==-1)break;
	  }
	  if(ans==-1)break;
	}
	printf("%d\n",ans);
  }
  if(m==2)//passed
  {
    int x,y;
    int vis[w[1]+2][w[2]+2];
    int vismax=w[1]*w[2]*10;
  	for(i=1;i<=w[1];i++)
  	{
  	  for(int i1=1;i1<=w[2];i1++)
  	  {
  	  	x=i;y=i1;memset(vis,0,sizeof(vis));
  	  	while(x>=1&&x<=w[1]&&y>=1&&y<=w[2])
  	  	{
  	  	  for(k=1;k<=n;k++)
  	  	  {
  	  	  	if(vis[x][y]>vismax){ans=-1;break;}
  	  	  	vis[x][y]++;
  	  	    if(a[k].w==1)x+=a[k].d;
  	  	    if(a[k].w==2)y+=a[k].d;
  	  	    ans++;
  	  	    if(x<1||y<1||x>w[1]||y>w[2])break;
		  }
		  if(ans==-1)break;
		}
		if(ans==-1)break;
	  }
	  if(ans==-1)break;
	}
	printf("%d\n",ans);
  }
  if(m==3)
  {
  	int A[4];
  	int vis[w[1]+2][w[2]+2][w[3]+2];
  	int vismax=w[1]*w[2]*w[3]*10;
  	for(i=1;i<=w[1];i++)
  	{
  	  for(int i1=1;i1<=w[2];i1++)
  	  {
  	  	for(int i2=1;i2<=w[3];i2++)
  	  	{
  	  	  A[1]=i;A[2]=i1;A[3]=i2;
  	  	  memset(vis,0,sizeof(vis));
  	  	  while(A[1]>=1&&A[1]<=w[1]&&A[2]>=1&&A[2]<=w[2]&&A[3]>=1&&A[3]<=w[3])
  	  	  {
  	  	    for(k=1;k<=n;k++)
  	  	    {
  	  	      if(vis[A[1]][A[2]][A[3]]>vismax){ans=-1;break;}
  	  	      vis[A[1]][A[2]][A[3]]++;
  	  	      if(a[k].w==1)A[1]+=a[k].d;
  	  	      if(a[k].w==2)A[2]+=a[k].d;
  	  	      if(a[k].w==3)A[3]+=a[k].d;
  	  	      ans++;
  	  	      if(A[1]<1||A[1]>w[1]||A[2]<1||A[2]>w[2]||A[3]<1||A[3]>w[3])break;
		    }
		    if(ans==-1)break;
		  }
		  if(ans==-1)break;
		}
		if(ans==-1)break;
	  }
	  if(ans==-1)break;
	}
	printf("%d\n",ans);
  }
  if(m==4)//passed
  {
  	int A[5];
  	int vis[w[1]+2][w[2]+2][w[3]+2][w[4]+2];
  	int vismax=w[1]*w[2]*w[3]*w[4]*10;
  	for(i=1;i<=w[1];i++)
  	{
  	  for(int i1=1;i1<=w[2];i1++)
  	  {
  	  	for(int i2=1;i2<=w[3];i2++)
  	  	{
  	  	  for(int i3=1;i3<=w[4];i3++)
  	  	  {
  	  	  	A[1]=i;A[2]=i1;A[3]=i2;A[4]=i3;
  	  	  	memset(vis,0,sizeof(vis));
  	  	    while(A[1]>=1&&A[1]<=w[1]&&A[2]>=1&&A[2]<=w[2]&&A[3]>=1&&A[3]<=w[3]&&A[4]>=1&&A[4]<=w[4])
  	  	    {
  	  	      for(k=1;k<=n;k++)
  	  	      {
  	  	      	if(vis[A[1]][A[2]][A[3]][A[4]]>vismax){ans=-1;break;}
  	  	      	vis[A[1]][A[2]][A[3]][A[4]]++;
  	  	        if(a[k].w==1)A[1]+=a[k].d;
  	  	        if(a[k].w==2)A[2]+=a[k].d;
  	  	        if(a[k].w==3)A[3]+=a[k].d;
  	  	        if(a[k].w==4)A[4]+=a[k].d;
  	  	        ans++;
  	  	        if(A[1]<1||A[1]>w[1]||A[2]<1||A[2]>w[2]||A[3]<1||A[3]>w[3]||A[4]<1||A[4]>w[4])break;
		      }
		      if(ans==-1)break;
		    }
		    if(ans==-1)break;
		  }
		  if(ans==-1)break;
		}
		if(ans==-1)break;
	  }
	  if(ans==-1)break;
	}
	printf("%d\n",ans);
  }
  if(m==5)
  {
  	int A[6];
  	int vis[5][5][5][5][5];
  	int vismax=w[1]*w[2]*w[3]*w[4]*w[5]*10;
  	for(i=1;i<=w[1];i++)
  	  for(int i1=1;i1<=w[2];i1++)
  	  	for(int i2=1;i2<=w[3];i2++)
  	  	  for(int i3=1;i3<=w[4];i3++)
  	  	    for(int i4=1;i4<=w[5];i4++)
  	  	    {
  	  	   	  A[1]=i;A[2]=i1;A[3]=i2;A[4]=i3;A[5]=i4;
  	  	   	  memset(vis,0,sizeof(vis));
  	  	      while(A[1]>=1&&A[1]<=w[1]&&A[2]>=1&&A[2]<=w[2]&&A[3]>=1&&A[3]<=w[3]&&A[4]>=1&&A[4]<=w[4]&&A[5]>=1&&A[5]<=w[5])
  	  	      {
  	  	        for(k=1;k<=n;k++)
  	  	        {
  	  	          if(vis[A[1]][A[2]][A[3]][A[4]][A[5]]>vismax){ans=-1;break;}
  	  	          vis[A[1]][A[2]][A[3]][A[4]][A[5]]++;
  	  	          if(a[k].w==1)A[1]+=a[k].d;
  	  	          if(a[k].w==2)A[2]+=a[k].d;
  	  	          if(a[k].w==3)A[3]+=a[k].d;
  	  	          if(a[k].w==4)A[4]+=a[k].d;
  	  	          if(a[k].w==5)A[5]+=a[k].d;
  	  	          ans++;
  	  	          if(A[1]<1||A[1]>w[1]||A[2]<1||A[2]>w[2]||A[3]<1||A[3]>w[3]||A[4]<1||A[4]>w[4]||A[5]<1||A[5]>w[5])break;
		        }
		        if(ans==-1)break;
		      }
		      if(ans==-1)break;
		    }
	printf("%d\n",ans);
  }
  return 0;
}
//good morning manongren
//happy coding
