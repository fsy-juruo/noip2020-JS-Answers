#include<bits/stdc++.h>
using namespace std;
int n,k;
int w[15];
int a[15],p[15];
int limit=1;
struct sousa{
	int x,d;
}b[105];
int main()
{
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=k;i++)
		cin>>w[i];
	for(int j=1;j<=n;j++)
		cin>>b[j].x>>b[j].d;
	for(int i=1;i<=k;i++)
	{
		limit*=w[i];
		a[i]=1;
	}
	int now=k,ans=0;
	for(int i=1;i<=limit;i++)
	{
//		for(int j=1;j<=k;j++)
//			cout<<a[j]<<' ';
//		cout<<endl;
		int j=1;
		for(int i=1;i<=k;i++)
			p[i]=a[i];
		int flag=0;int lans=ans;
//		cout<<endl;
		while(1)
		{
			a[b[j].x]+=b[j].d;
			ans++;
			if(a[b[j].x]>w[b[j].x]||a[b[j].x]<1)
				break;
			
//			cout<<"Step: "<<b[j].x<<' '<<a[b[j].x]<<endl;
			j++;
			j=(j-1)%n+1;
			if(!flag)
			{
				for(int i=1;i<=k;i++)
					if(p[i]!=a[i])flag=1;
				if(!flag)
				{
					cout<<-1<<endl;
					return 0;
				}
			}
		}
//		cout<<ans-lans<<' ';
		for(int i=1;i<=k;i++)
			a[i]=p[i];
		a[now]++;
		while(a[now]>w[now])
		{
			a[now]=1;
			a[now-1]++;
			now--;
		}
		for(int j=n;j>=1;j--)
			if(a[j]<=w[j])
			{
				now=j;
				break;
			}
	}
	cout<<ans<<endl;
	return 0;
}
