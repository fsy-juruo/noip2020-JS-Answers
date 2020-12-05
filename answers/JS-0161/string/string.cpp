#include<bits/stdc++.h>
using namespace std;
int q;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>q;
	string s;
	long long i,j,k;
	long long an=0;
	for(i=1;i<=q;i++)
	{
		cin>>s;
		int n=s.size();
		for(j=1;j<=n-2;j++)
		{
			int r=n-j;
			bool da=false;
			if(j%2==0)
				da=true;
			for(k=1;k<=r;k++)
			{
				if(r%k==0)
				{
					if(da)
						an+=(r/k-1)/2;
					else
						an+=r/k-1;
				}
			}
		}
		cout<<an<<endl;
	}
	return 0;
}
