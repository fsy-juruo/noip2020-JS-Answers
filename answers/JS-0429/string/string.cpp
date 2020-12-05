#include <bits/stdc++.h>
using namespace std;
string st;
int n,ans,a[34];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for (int i=1;i<=n;i++)
	{
		int ans=0;
		cin>>st;
		int p=st.size();
		for (int j=p-1;j>1;j--)
		{
			memset(a,0,30);
			int y=0;
			for	(int k=j;k<p;k++)
			  {
			  	if (a[(int)st[k]-'a']==0)
			  	{
			  		a[(int)st[k]-'a']=1;
			  		y++;
				  }
				else
				{
					a[(int)st[k]-'a']=0;
			  		y--;
				}
			  }
			for (int k=1;k<=j;k++)//kweixunhuan
			  {
			  	
			  	if (j%k==0)
			  	{
			  		int g=0;
			  		for (int p=0;p<=j;p++)
			  		  if (st[p]!=st[p%k])
			  		  {
						g=1;break;
						}
					if (g==1)
					continue;
					memset(a,0,30);
					for (int p=0;p<k-1;p++)
				 {
					  if (a[(int)st[p]-'a']==0)
			  		{
			  			a[(int)st[p]-'a']=1;
			  			g++;
				 	 }
					else
					{
						a[(int)st[p]-'a']=0;
			  			g--;
					}
					if (g<=y) ans++;
					
					  }
					}
			  }
			
		}
		cout<<ans<<endl;
	}
	return 0;
}

