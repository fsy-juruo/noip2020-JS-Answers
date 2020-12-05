#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int n,k,w[15],c[105],d[105],sum,s,a[10],h[10];
bool b[11][11][11][11][11][1005];
int main()
{
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=k;i++)cin>>w[i];
	for(int i=0;i<n;i++)cin>>c[i]>>d[i];
	
	for( a[1]=0;a[1]<=w[1];a[1]++)
	 for( a[2]=0;a[2]<=w[2];a[2]++)
	  for( a[3]=0;a[3]<=w[3];a[3]++)
   	   for( a[4]=0;a[4]<=w[4];a[4]++)
	    for( a[5]=0;a[5]<=w[5];a[5]++)
		{
			memset(b,0,sizeof(b));
			s=0;
			for(int i=1;i<=k;i++)h[i]=a[i];
			while(h[1]>=0&&(h[1]==0||h[1]<w[1])&&h[2]>=0&&(h[2]==0||h[2]<w[2])&&h[3]>=0&&(h[3]==0||h[3]<w[3])&&h[4]>=0&&(h[4]==0||h[4]<w[4])&&h[5]>=0&&(h[5]==0||h[5]<w[5]))
			{
				s%=n;
				if(b[h[1]][h[2]][h[3]][h[4]][h[5]][s]==1)
				{
					cout<<"-1"<<endl;
					return 0;
				}
				b[h[1]][h[2]][h[3]][h[4]][h[5]][s]=1;
				h[c[s]]+=d[s];
				sum++;
				s++;
			}
		}
		cout<<sum<<endl;
		return 0;
}
