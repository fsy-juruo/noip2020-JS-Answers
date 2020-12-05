#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll mod=1e9+7;
int n,k,w[10],total[10];
ll a[6][100005];
int s[10];ll ans=0;int flag=0;
void dfs(int x,int step)
{
	if(flag) return;
	s[step]=x;
	if(step==k)
	{
		ll minv=1e12;
		for(int i=1;i<=step;i++)
		{
		//	cout<<s[i]<<" ";
			minv=min(minv,a[i][s[i]]);
		}
		//cout<<endl;
		//cout<<"minv="<<minv<<endl;
		if(minv>=1e12) {flag=1;return;}
		ans=(ans+minv)%mod;
		return ;
	}		
	for(int i=1;i<=w[step+1];i++)
	{
		dfs(i,step+1);
	}
}
void work1()
{
	for(int i=1;i<=w[1];i++)
	{
		dfs(i,1);
	}
	if(!flag) printf("%lld",ans);
	else printf("-1");
}
void work2()
{
	printf("-1\n");
}
int main()
{
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=k;i++) scanf("%d",&w[i]);
	memset(a,0x3f,sizeof(a));
	for(int i=1;i<=n;i++)
	{
		int c,d;scanf("%d%d",&c,&d);total[c]+=d;
		if(total[c]>0)
		{
		//	cout<<i<<" "<<total[i]<<endl;
			if(w[c]+1-total[c]>=1) a[c][w[c]+1-total[c]]=min(1ll*i,a[c][w[c]+1-total[c]]);
		} 
		if(total[c]<0&&(-total[c])<=w[c]) a[c][0-total[c]]=min(1ll*i,a[c][0-total[c]]);
	}
//	cout<<total[1]<<endl;
	for(int i=1;i<=k;i++)
	{
		if(total[i]>0)//up
		{
			for(int j=w[i];j>=1;j--)
			{
				if(a[i][j+total[i]])
				{
					if(j+total[i]<=w[i]) a[i][j]=min(a[i][j+total[i]]+n,a[i][j]);
				}
			}
		}
		if(total[i]<0)//
		{
			for(int j=1;j<=w[i];j++)
			{
				if(a[i][j+total[i]])
				{
					if(j+total[i]>=1) a[i][j]=min(a[i][j+total[i]]+n,a[i][j]);
				}
			}
		}
	}
	if(n<=1e5) work1();
	else work2();
	return 0;
}
/*
2 1
7
1 -1
1 1
*/
