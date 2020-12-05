#include<bits/stdc++.h>
using namespace std;
int ver[1000010],Next[1000010],head[100010],i,j,n,m,tot,x,z,p,a[100010];
struct node
{
  int fm,fz;
}ans[100010];
void add(int x,int y)
{
  ver[++tot]=y;Next[tot]=head[x];head[x]=tot;
}
int gcd(int x,int y)
{
  if(x<y)return gcd(y,x);
  if(y==0)return x;
  return gcd(y,x%y);
}
void getw(node x,int y)
{
  node q=ans[y];
  if(ans[y].fm==0){ans[y]=x;return;}
  int k=gcd(q.fm,x.fm);
  int FM=q.fm/k*x.fm,FZ=x.fm/k*q.fz+q.fm/k*x.fz;
  q.fm=FM;q.fz=FZ;
  k=gcd(FM,FZ);
  q.fm/=k;q.fz/=k;
  ans[y]=q;
  return;
}
node cny(node x,int y)
{
  if(x.fm==0){x.fm=1;return x;}
  x.fm*=y;
  int k=gcd(x.fz,x.fm);
  x.fm=x.fm/k;x.fz=x.fz/k;
  return x;
}
int main()
{
  freopen("water.in","r",stdin);
  freopen("water.out","w",stdout);
  scanf("%d%d",&n,&m);
  for(i=1;i<=n;i++)
  {
  	scanf("%d",&a[i]);
  	for(j=1;j<=a[i];j++)
  	{
  	  scanf("%d",&x);
  	  add(i,x);
	}
  }
  for(i=1;i<=n;i++)
  {
  	if(i<=m)
  	{
  	  node p;
  	  p.fz=1;p.fm=a[i];
  	  for(j=head[i];j;j=Next[j])
  	  {
  	  	getw(p,ver[j]);
	  }
	  continue;
	}
    if(a[i]>0)
	{
	  z=a[i];
	  if(ans[i].fz==0)continue;
	  node p=ans[i];
	  p=cny(p,z);
	  for(j=head[i];j;j=Next[j])
	    getw(p,ver[j]);
	  continue;
	}
	if(a[i]==0)
	{
	  printf("%d %d\n",ans[i].fz,ans[i].fm);
	}
  }
  //printf("\n");
  //for(i=1;i<=n;i++)
  //{
  //	printf("%d %d\n",ans[i].fz,ans[i].fm);
  //}
  return 0;
}
