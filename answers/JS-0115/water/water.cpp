# include<bits/stdc++.h>
using namespace std;
long long a[100005][6],x,t[100005],b[100005],c[100005],d[100005],n,j,m,i;
long long gcd(long long n,long long m)
{
	if (m==0) return n;
	long long r=n%m;
	return gcd(m,r);
}
void dg(long long p,long long x,long long y)
{
	if (b[p]==0&&c[p]==0) {
		b[p]=x; c[p]=y;
	}
	else {
	b[p]=b[p]*y+c[p]*x;
	c[p]=c[p]*y;
    }
   /* x=gcd(b[p],c[p]);
    b[p]=b[p]/x;
    c[p]=c[p]/x;*/
	for (int i=1;i<=d[p];i++)
	{
		dg(a[p][i],x,y*d[p]);
	}
}
int main()
{
  freopen("water.in","r",stdin);
 freopen("water.out","w",stdout);
  cin>>n>>m;
  for (i=1;i<=n;i++)
  {
  	cin>>d[i];
  	for (j=1;j<=d[i];j++)
  	{
  		cin>>x;
  		a[i][j]=x;
  		t[x]=1;
	  }
  }
  for (i=1;i<=n;i++)
  {
  	if (t[i]==0) {
  		dg(i,1,1);
	  }
  }
  for (i=1;i<=n;i++)
  {
  	if (d[i]==0) {
  		x=gcd(b[i],c[i]);
  		cout<<b[i]/x<<' ';
  		cout<<c[i]/x<<endl;
	  }
  }
  return 0;
}

