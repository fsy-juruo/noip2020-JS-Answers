#include<bits/stdc++.h>
using namespace std;
struct node{
	int x,y;
	node(int _x=0,int _y=0):x(_x),y(_y){}
}ste[100001];
bool flag=1;
long long ans=0;
int n,k,a[100001],cnt=0,z[100001],ma[100001];
void dfs(int x,int y,int z,int s,int tot)
{
	int w=ste[s].x,num=ste[s].y;
	if(w==1)x+=num;
	else if(w==2)y+=num;
	else if(w==3)z+=num;
	if(x<=a[1]&&y<=a[2]&&z<=a[3])
	{
		if(s+1==n+1)s=0;
		dfs(x,y,z,s+1,tot+1);		
	}
	else ans+=tot;
}
int main()
{
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=k;i++)cin>>a[i];
	for(int i=1,x,y;i<=n;i++)
	{
		cin>>x>>y;
		z[x]+=y;
		if(z[x]>a[x])flag=0;
		ste[++cnt].x=x;
		ste[cnt].y=y;
	}
	for(int i=1;i<=k;i++)
		if(z[i])flag=0;
	if(flag==1)
	{
		cout<<-1<<endl;	
		return 0;	
	}
	if(k==3)
	{
		ans=0;
		for(int i=1;i<=a[1];i++)
			for(int j=1;j<=a[2];j++)
				for(int k=1;k<=a[3];k++)	
					dfs(i,j,k,1,1);	
		cout<<ans<<endl;
	}
	return 0;
}
