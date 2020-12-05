#include<bits/stdc++.h>
using namespace std;
int n,k,c[500005],d[500005],i,w[15];
int l,h,ans,s,yy,p;
int main()
{
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	cin>>n>>k;
	for(i=1;i<=k;i++)
	cin>>w[i];
	for(i=1;i<=n;i++)
	{
		cin>>c[i]>>d[i];
		l+=d[i];
	}
	
	if(k==1)
	{
		if(l==0)
		{	
			cout<<-1;
			return 0;
		}
		for(i=1;i<=w[1];i++)
		{
			h=i;
			if(l>0)
			{
				s=w[1]-h;
				ans+=int(s/l)*n;
				yy=s-(int(s/l)*l);
				for(p=1;p<=n;p++)
				{
					yy-=d[p];
					if(yy<0)break;
				}
				ans+=p;
			}
			else
			{
				s=h-w[1];
				ans+=int(s/l)*n;
				yy=s-(int(s/l)*l);
				for(p=1;p<=n;p++)
				{
					yy-=d[p];
					if(yy<0)break;
				}
				ans+=p;
			}
		}
		cout<<ans;
		return 0;
	}
	cout<<-1;
	
}
