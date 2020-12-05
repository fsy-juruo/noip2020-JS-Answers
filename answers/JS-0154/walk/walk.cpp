#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
#include <set>
#include <cstring>

using namespace std;
const int INF=0x3f3f3f3f,maxn=5e5+10; 
int n,m,w[11],go[10],ans,pl=0,rd[maxn][2],now[11];
void dfs(int x)
{
	if(x==m+1)
	{
		while(1)
		{
			bool f=0;
			for(int i=1;i<=n;i++)
			{
				int x=rd[i][0],y=rd[i][1];
				if(now[x]+y>w[x] || now[x]+y<=0)
				{
					f=1;
					now[x]+=y;
					if(now[x]<=0)
						ans+=y-abs(now[x]);
					else
						{
							ans+=now[x]-w[x]+1;
						}
				}
				else
				{
					ans+=abs(y);
					now[x]+=y;
				}
			}
			if(f==1)
				break;
		}
	}
	for(int i=1;i<=w[x];i++)
	{
		now[x]=i;		
		dfs(x+1);
		now[x]=1;
	}
}
int main()
{
	int i,j,k;
	freopen ("walk.in","r",stdin);
	freopen ("walk.out","w",stdout);
	cin>>n>>m;
//	cout<<m;
	for(i=1;i<=m;i++)
	{
		cin>>w[i];
		//cout<<w[i]<<endl;
	}		
	for(i=0;i<n;i++)
	{
		cin>>rd[i][0]>>rd[i][1];
		go[rd[i][0]]+=rd[i][1];
	}
	dfs(1);	
	cout<<ans<<endl;
	return 0;
}
