#include<bits/stdc++.h>
using namespace std;
int n,m,a[55][810],l=0,k=0,c[8400][3];

int main()
{
	freopen("ball.in","r",stdin);
	freopen("ball.out","w",stdout);
	cin>>n>>m;
	int h=m;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			cin>>a[i][j];
		}
	}
	for(int i=m;i>=1;i--)
    {
    	//cout<<1<<" "<<3<<endl;
    	k++;
    	c[k][1]=1;
    	c[k][2]=3;
    	a[3][m-i+1]=a[1][i];
	}
	for(int i=m;i>=1;i--)
    {
    	if(a[3][i]==1)
    	{
    		l++;
    		a[1][l]=1;
			k++;
    		c[k][1]=3;
    	    c[k][2]=1;
    		//cout<<3<<" "<<1<<endl;
    		
		}
		else
    	{
    		h++;
    		a[2][h]=2;
			k++;
    		c[k][1]=3;
    		c[k][2]=2;
		}
	}
	for(int i=h;i>=1;i--)
    {
    	//cout<<1<<" "<<2<<endl;
    	a[3][h-i+1]=a[2][i];
    	c[k][1]=2;
		k++;
    	c[k][2]=3;
	}
	for(int i=h;i>=1;i--)
    {
    	if(a[3][i]==1)
    	{
    		l++;
    		a[1][l]=1;
			k++;
    		c[k][1]=3;
    	    c[k][2]=1;
    		//cout<<3<<" "<<1<<endl;
    		
		}
		else
    	{
    		a[2][h++]=2;
			k++;
    		c[k][1]=3;
    		c[k][2]=2;
		}
	}
	cout<<k<<endl;
	for(int i=1;i<=k;i++)
	{
		cout<<c[i][1]<<" "<<c[i][2]<<endl;
	}
	return 0;
}

