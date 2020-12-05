#include<bits/stdc++.h>
#define ll long long
#define N 500500
#define K 20
using namespace std;
int n,k,c[N],d[N];
int s,ans,f[N],t[K],w[K],minn,g[K],ma[K],mi[K];
void dfs(int x)
{
	if (x>k)
	{
	//	for (int i=1;i<=k;i++)cout<<t[i]<<' ';
	//	cout<<endl;
		minn=INT_MAX;
		for (int i=1;i<=k;i++)
		{
			g[i]=t[i];
			int z=w[i]-g[i]+1,z1=g[i];
			if (z<=ma[i]||z1<=mi[i])
			{
				minn=0;break;
			}
			if (f[i]>0)
			{
				minn=min(minn,(w[i]+2-ma[i]-t[i])/f[i]);
			} 
			if (f[i]<0){
				minn=min(minn,(g[i]-mi[i])/(-f[i]));
			}
		}//minn=min(minn,t[x]/f[i]);
		//cout<<"!"<<endl;
		for (int i=1;i<=n;i++)
		{
			g[i]=t[i]+minn*f[i];
		//	cout<<g[i]<<' ';
		}
		s=ans;
		ans=(ans+minn*n)%1000000007;
	//	cout<<minn<<' ';
		for (int i=1;i<=n;i++)
		{
			g[c[i]]+=d[i];
			ans++;
			if (g[c[i]]<1||g[c[i]]>w[c[i]])
			{
				break;
			}
		}
		
	//	cout<<ans-s<<endl;
		return ;
	}
	for (int i=1;i<=w[x];i++)
	{
		t[x]=i;
		dfs(x+1);
	}
}
int main()
{
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	cin>>n>>k;
	for (int i=1;i<=k;i++)cin>>w[i],ma[i]=INT_MIN,mi[i]=INT_MAX;
	for (int i=1;i<=n;i++)
	{
		cin>>c[i]>>d[i];
		f[c[i]]+=d[i];
		ma[c[i]]=max(ma[c[i]],f[c[i]]);
		mi[c[i]]=min(mi[c[i]],f[c[i]]);
	}
//	cout<<endl;
//	for (int i=1;i<=k;i++)
//	cout<<f[i]<<' ';
//	cout<<endl<<endl;
//	for (int i=1;i<=k;i++)cout<<ma[i]<<' ';
//	cout<<endl;
	for (int i=1;i<=k;i++)mi[i]=-mi[i];
//cout<<mi[i]<<' ';
//	cout<<endl;
	bool flag=0;
	for (int i=1;i<=k;i++)
	if (f[i]==0&&(ma[i]<w[i]&&-mi[i]<w[i]));
	else flag=1;
	if (flag==0)puts("-1");
	else{
		dfs(1);cout<<ans%1000000007<<endl;
	}
	
	return 0;
}

