#include<bits/stdc++.h>
using namespace std;
struct node{
	int x,y;
};
int n,m,ma=INT_MIN,mai,ms,tot=0;
int a[55][405],h[55][405],ha[55];
bool f=true;
stack <int>q;
node stp[820010];
int main()
{
	freopen("ball.in","r",stdin);
	freopen("ball.out","w",stdout);
	cin>>n>>m;
	memset(h,0,sizeof(h));
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			cin>>a[i][j];
			h[i][a[i][j]]++;
		}
	}
	for(int i=1;i<=n;i++)
	{
		ma=INT_MIN;
		for(int j=1;j<=m;j++)
		if(h[i][j]>ma)
		{
			ma=a[i][j];
			mai=j;
			ms=a[i][j];
		}
		ha[i]=ms;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=m;j>=1;j--)
		{
			f=true;
			for(int k=1;k<=n;k++)
			{
				for(int p=1;p<=j;p++)
				if(a[k][p]!=ha[k])f=false;	
			}
			if(f)break;
			else 
			{
				tot++;
				stp[tot].x=i;
				stp[tot].y=n+1;
				q.push(a[i][j]);
			}
		}
	}
	while(!q.empty())
	{
		tot++;
		stp[tot].x=n+1;
		for(int i=1;i<=n;i++)
		if(ha[i]==q.top())
		{
			stp[tot].y=i;
			break;
		}
		q.pop();
	}
	cout<<tot<<endl;
	for(int i=1;i<=tot;i++)
	cout<<stp[i].x<<" "<<stp[i].y<<endl;
	return 0;
}

