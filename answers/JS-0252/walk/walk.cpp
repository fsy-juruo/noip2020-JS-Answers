#include <bits/stdc++.h>
#define N 1000000007
using namespace std;
int w[11]={};
int c[500005]={};
int d[500005]={};
int weidu[11]={1};
int ans=0;
bool next(int x);
bool l[100000][10]={false};
int main()
{
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	int n,k;scanf("%d%d",&n,&k);
	int i,j;
	for(i=1; i<=k; i++)
		scanf("%d",&w[i]);
	for(i=1; i<=n; i++)
		scanf("%d%d",&c[i],&d[i]);
	int now=1;
	for(i=1; i<=k; i++)
		weidu[i]=1;
	int giao=0;
	if(n<=100)
	{
		while(true)
		{
			int wei[11];
			for(j=1; j<=k; j++)
			{
				wei[j]=weidu[j];
				//cout<<wei[j]<<" "<<weidu[j]<<endl;
			}
			i=n+1;
			while(i>n)
			{
				for(i=1; i<=n; i++)
				{
					ans++;
					if(ans>=180000000)
					{
						cout<<-1;
						return 0;
					}
					//cout<<c[i]<<endl;
					//cout<<wei[c[i]]<<endl;
					if(wei[c[i]]+d[i]>w[c[i]]||wei[c[i]]+d[i]<1)
						break;
					wei[c[i]]+=d[i];
				}
				//system("pause");
			}
			
			bool f=next(k);
			if(f==false) break;
		}
	}
	else
	{
		ans=-1;
	}
	cout<<ans;
	return 0;
}
bool next(int x)
{
	if(x==0) return false;
	if(weidu[x]+1<=w[x])
	{
		weidu[x]+=1;
	}
	else
	{
		weidu[x]=1;
		return next(x-1);
	}
	return true;
}
