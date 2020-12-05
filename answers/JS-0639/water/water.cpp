#include <bits/stdc++.h>
using namespace std;

long long a[100005];

void gcdx(long long x)
{
	long long k=60*60*60*60*60;
	if((60*60*60*60*60)%x==0)
		cout<<"1 "<<(60*60*60*60*60)/x;
	else
	{
		for(long long i=60;i>=2;i--)
		{
			while(x%i==0 && k%i==0)
			{
				x/=i;
				k=k/i;
			}
		}
		cout<<x<<" "<<k<<endl;
	}
}

int main()
{
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	int n,m,i,j,k,k1;
	memset(a,0,sizeof(a));
	a[1]=60*60*60*60*60;
	cin>>n>>m;
	for(i=1;i<=n;i++)
	{
		cin>>k;
		if(k==0)
		{
			gcdx(a[i]);
		}
		
		else
		{
			for(j=1;j<=k;j++)
			{
				cin>>k1;
				a[k1]+=a[i]/k;
			}
			a[i]=0;
		}
	}	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
