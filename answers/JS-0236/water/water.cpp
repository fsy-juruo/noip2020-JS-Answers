#include<bits/stdc++.h>
using namespace std;
int a[100][100];
int cou1,cou2,ans;
int main()
{	
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			cin>>a[i][j];
			if(a[i][j]==1)cou1++;
			else cou2++;
		}
		if(cou1>cou2)
		{
			for(int j=0;j<m;j++)
			{
				if(a[i][j]==2)
					ans+=j+1;
			}	
			cou1=0;cou2=0;
		}
		else 
		{
			for(int j=0;j<m;j++)
			{
				if(a[i][j]==1)
					ans+=j+1;
			}	
			cou1=0;cou2=0;
		}
	}
		
	cout<<ans+1<<endl;
	return 0;
}
